#include "Circle.h"
#include <cmath>

using namespace std;

const double PI = 3.141592;

Circle::Circle() : Shape(), center(Point2D(0, 0)), radius(1) {
}

Circle::Circle(string color, Point2D center, double radius) : Shape(color), center(center), radius(radius) {
}

Point2D Circle::get_center() const {
    return center;
}

void Circle::set_center(Point2D p) {
    center = p;
}

double Circle::get_radius() const {
    return radius;
}

void Circle::set_radius(double r) {
    radius = r;
}

double Circle::area() const {
    return PI * pow(radius, 2);
}

double Circle::perimeter() const {
    return 2 * PI * radius;
}

void Circle::translate(double incX, double incY) {
    center = Point2D(center.x + incX, center.y + incY);
}

void Circle::print() {
    cout << "[Circle: color = " << get_color() << "; center = " << center << "; radius = " << radius << "]";
}

ostream& operator<<(ostream &out, const Circle &c) {
    out << "[Circle: color = " << c.get_color() << "; center = " << c.center << "; radius = " << c.radius << "]";
    return out;
}
