#include <iostream>
#include <string>
#include "Six.h"
#include "SixBuilder.h"

using namespace std;

int main() {
    unsigned char text[] = "123"; 
    Six b{Six("10000")};
    Six a{Six("100")};
    // cout << "Enter a:" << endl;
    // cin >> a;
    // cout << "Enter b:" << endl;
    // cin >> b;
    cout << a << " " << a.getSize() << endl;
    cout << b << " " << b.getSize() << endl;
    cout << (a < b) << (a > b) << (a == b) << endl;
    Six c{a + b};
    cout << c << " " << c.getSize() << endl;
}