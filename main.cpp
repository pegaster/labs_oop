#include <iostream>
#include <map>
#include <algorithm>
#include "Allocator.h"
#include "DynamicArray.h"

int main(){
    std::map<int, int, std::less<int>, Allocator<std::pair<const int, int>>> map;

    map.insert(std::pair<int, int>(0, 1));
    map.insert(std::pair<int, int>(1, 1));
    map.insert(std::pair<int, int>(2, 2));
    // fill_map<9>(map);
    for (auto p : map)
        std::cout << p.first << " " << p.second << std::endl;

        std::cout << "-----------------------------------------\n";

    DynamicArray<int, Allocator<int>> vect{};
    for (int i = 0; i < 10; ++i){
        vect.push_back(i);
    }

    for (auto e : vect){
        std::cout << e << "\n";
    }
    
}