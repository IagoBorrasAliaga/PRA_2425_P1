#include "Square.h"

using namespace std;

bool Square::check(Point2D* vertices) {
    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);
    
    return (d01 == d12) && (d12 == d23) && (d23 == d30);
}

Square::Square() : Rectangle() {
    vs[0] = Point2D(-1, 1);
    vs[1] = Point2D(1, 1);
    vs[2] = Point2D(1, -1);
    vs[3] = Point2D(-1, -1);
}

Square::Square(string color, Point2D* vertices) : Rectangle(color, vertices) {
    if (!check(vertices)) {
        throw invalid_argument("Los vertices son encorrectos!");
    }
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}

void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw invalid_argument("Los vertices son incorrectos!");
    }
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}

void Square::print() {
    cout << *this;
}

ostream& operator<<(ostream &out, const Square &square) {
    out << "Square: color = " << square.get_color() << "; v0 = " << square.vs[0] 
        << "; v1 = " << square.vs[1] << "; v2 = " << square.vs[2] 
        << "; v3 = " << square.vs[3];
    return out;
}
