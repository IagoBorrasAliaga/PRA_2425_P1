#ifndef SQUARE_H
#define SQUARE_H

#include <ostream>
#include "Rectangle.h"

using namespace std;

class Square : public Rectangle {
private:
    static bool check(Point2D* vertices);

public:
    Square();
    Square(string color, Point2D* vertices);
    
    void set_vertices(Point2D* vertices) override;
    void print() override;
    
    friend ostream& operator<<(ostream &out, const Square &square);
};

#endif
