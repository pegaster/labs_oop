#include <iostream>
#include "lib.h"

int main() {
    int m, n;
    std::cin >> n >> m;

    int result {tryCalculateAmmountOfBreaks(n, m)};
    std::cout << result << std::endl;
}