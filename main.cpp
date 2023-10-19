#include <iostream>
#include "Point.h"
#include "Figure.h"
#include "Triangle.h"

using namespace std;

int main() {
    Point points[3] = {Point(0, 0), Point(1, 0), Point(0, 1)};
    Figure *fig = new Triangle(points);
    cout << (double)*fig;
}