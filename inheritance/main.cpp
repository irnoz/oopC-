#include <iostream>

using namespace std;

class Shape {
private:
    static int object_count;
    float width_;
    float height_;

public:
    static int blo;
    Shape() : width_(0), height_(0) { 
        increase_object_count(); 
    }
    
    Shape(float width, float height = 0) : width_(width), height_(height) { 
        increase_object_count(); 
    }

    float get_width() const { return width_; }

    void set_width(float width) { width_ = width; }

    float get_height() const { return height_; }

    void set_height(float height) { height_ = height; }

    static int get_object_count() { return object_count; }

private:
    void increase_object_count() { object_count++; }
};

int Shape::object_count = 0;
int Shape::blo = 15;

class Rectangle : public Shape {
public:
    Rectangle() : Shape() {}

    Rectangle(float width, float height) : Shape(width, height) {}

    float get_area() const {
        return get_height() * get_width();
    }
};

class Circle : public Shape {
    static const float PI;
public:
    Circle() : Shape() { }
    Circle(float width) : Shape(width) { }

    float get_area() const {
        float r = get_width() / 2;
        return PI * r * r;
    }

};

const float Circle::PI = 3.14;

class Triangle : public Shape {
public:
    Triangle() : Shape() {}

    Triangle(float width, float height) : Shape(width, height) {}

    float get_area() const {
        return get_width() * get_height() / 2;
    }
};

int main() {
    Rectangle rectangle(4, 6);
    Triangle triangle(4, 6);
    Circle circle(6);


    cout << Shape::get_object_count() << " objects created" << endl;
    cout << "Area of rectangle is: " << rectangle.get_area() << endl;
    cout << "Area of triangle is: " << triangle.get_area() << endl;
    cout << "Area of circle is: " << circle.get_area() << endl;
    return 0;
}
