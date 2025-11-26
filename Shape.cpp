#include "Shape.h"
#include "Point2D.h"
using namespace std;

Shape::Shape() : color("red") {
}

Shape::Shape(string color) {
    if (color != "red" && color != "green" && color != "blue") {
        throw invalid_argument("Color no válido. Debe ser 'red', 'green' o 'blue'.");
    }
    this->color = color;
}

string Shape::get_color() const {
    return color;
}

void Shape::set_color(string c) {
    if (c != "red" && c != "green" && c != "blue") {
        throw invalid_argument("Color no válido. Debe ser 'red', 'green' o 'blue'.");
    }
    color = c;
}
