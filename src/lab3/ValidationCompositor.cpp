#include "ValidationCompositor.h"
#include <vector>
#include "TriangleValidationHandler.h"
#include "HexagonValidationHandler.h"
#include "OctagonValidationHandler.h"
#include <memory>


template<class T> void ValidationCompositor<T>::validate(Figure<T>& figure) const{
    for (std::shared_ptr<ValidationHandler<T>> validator : validations){
       // VaLidationHandler* validator = validations[i];
       
        if (validator.get()->isAllowed(figure)){
            validator.get()->validate(figure);
            return;
        }
    }
}

template<class T> ValidationCompositor<T>::ValidationCompositor(){
   
    validations.push_back(  std::shared_ptr< ValidationHandler<T> >(dynamic_cast<ValidationHandler<T> *>(new TriangleValidationHandler<T>())));
    validations.push_back(  std::shared_ptr< ValidationHandler<T> >(dynamic_cast<ValidationHandler<T> *>(new HexagonValidationHandler<T>())));
    validations.push_back(  std::shared_ptr< ValidationHandler<T> >(dynamic_cast<ValidationHandler<T> *>(new OctagonValidationHandler<T>())));

}
