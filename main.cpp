#include <iostream>
#include "lib.h"

int main() {
    int m, n;
    std::cin >> n >> m;

    int result {calculaclateAmmountOfBreaks(n, m)};
    if (result != -1) {
        std::cout << result << std::endl;
    }
}