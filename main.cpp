#include "mbed.h"
#include "MMA7660.h"
#include <cmath>

#define PI 3.14159265358979323846

class Shape {

    enum Shape_is{square, triangle, circle};
public:
//constructor
    Shape(int a){
        _a = a;
        Shape_type = square;
    }

    Shape(int a, int b){
        _a = a;
        _b = b;
        if(_b == 0)
            Shape_type = circle;
        else
            Shape_type = triangle;
    }

    float area(){
        if (Shape_type == circle)
            return(PI*_a*_a);
        else if (Shape_type == triangle)
           return(_a*_b*0.5);
        else if (Shape_type == square)
            return(_a*_a);
        else
        return 0;
    }

    void print_Shape(){
        if (Shape_type == circle)
            printf("Shape is a circle\r\n");
        else if (Shape_type == triangle)
            printf("Shape is a triangle\r\n");
        else if (Shape_type == square)
            printf("Shape is a square\r\n");
    }
private:
    int _a;
    int _b;
    Shape_is Shape_type;

};


int main() {  
   //input
   Shape square(5);
   Shape triangle(3,1);
   Shape circle(6, 0);

   square.print_Shape();
            printf("area is %f\r\n", square.area());
   triangle.print_Shape();
            printf("area is %f\r\n", triangle.area());
   circle.print_Shape();
            printf("area is %f\r\n", circle.area());

}
