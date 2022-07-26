#include <iostream>
#include <cmath>

class Shape{
    protected :
    std::string shape_name;

    public :
    Shape(std::string input) : shape_name(input) {}
    Shape(const Shape &input) : shape_name(input.shape_name) {}
    virtual ~Shape(){}

    virtual double get_area() = 0;
    std::string print_shape(){
        return shape_name;
    }
};

class Rect : public Shape{
    private :
    double height;
    double base;

    public :
    Rect(double height, double base) : height(height), base(base), Shape("Rectangle") {}
    Rect(const Rect &input) : height(input.height), base(input.base), Shape(input.shape_name) {}
    ~Rect(){}

    double get_area() override {
        return height * base;
    }

};

class Circle : public Shape{
    private :
    double radius;
    
    public :
    Circle(double radius) : radius(radius), Shape("Circle") {}
    Circle(const Circle &input) : radius(input.radius), Shape(input.shape_name) {}
    ~Circle(){}

    double get_area() override {
        return radius * radius * M_PI;
    }
};

class Triangle : public Shape{
    private :
    double height;
    double base;

    public :
    Triangle(double height, double base) : height(height), base(base), Shape("Triangle") {}
    Triangle(const Triangle &input) : height(input.height), base(input.base), Shape(input.shape_name) {}
    ~Triangle(){}

    double get_area() override{
        return height * base / 2;
    }
};





int main(){
    std::cout << "\ncode_start\n\n" << std::endl;
    
    Triangle a_1(1,2);
    Triangle a_4(2,4);

    Circle b_1(1.0);
    Circle b_2(2.0);

    Rect c_2(1,2);
    Rect c_4(2,2);


    Shape *array[6];

    array[0] = &a_1;
    array[1] = &a_4;
    array[2] = &b_1;
    array[3] = &b_2;
    array[4] = &c_2;
    array[5] = &c_4;

    for (int i = 0; i < 6; i++){
        std::cout << i + 1 << ". " << array[i]->print_shape() << " : " << array[i]->get_area() << std::endl;
    }
    
    for (int i = 0; i < 6; i++){
        delete array[i];
    }
    

    std::cout << "\n\ncode_end\n" << std::endl;
    return 0;
}
