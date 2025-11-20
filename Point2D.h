#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>  

class Point2D {
public:
   
    double x, y;

    Point2D(double x = 0, double y = 0);

    // Método estático para calcular la distancia entre dos puntos
    static double distance(const Point2D &a, const Point2D &b);

    // Sobrecarga del operador == (igualdad)
    friend bool operator==(const Point2D &a, const Point2D &b);

    // Sobrecarga del operador != (desigualdad)
    friend bool operator!=(const Point2D &a, const Point2D &b);

    // Sobrecarga del operador << (salida de flujo)
    friend std::ostream& operator<<(std::ostream &out, const Point2D &p);
};

#endif
