#include <iostream>
#include <string>
using namespace std;
class Circle;  // წინასწარი განაცხადი Circle კლასზე
class Square {
	double side;
    double area;
    double perimeter;
  public:
	Square(double side = 100.) {
        this->side = side;
        this->calculateArea();
    } 
	~Square() = default;

    void calculatePerimeter() {
        perimeter = 4 * side;
    }
	double getPerimeter()const {
		return this->perimeter;
	}
    void calculateArea() {
        area = side * side;
    }
	double getArea()const {
		return this->area;
	}
   friend int same(const Square& k, const Circle& m);
};
class Circle {
	double radius;
    double area;
    double length;
  public:
    const static double PI;
	Circle(double r = 2.) {
		this->radius = r;
        this->calculateArea();
	}
	~Circle() = default;
    void calculateLength() {
        length = 2 * PI * radius;
    }
    double getLength() const {
        return length;
    }
	void calculateArea() {
		area = PI * radius * radius;
	}
    double getArea() const {
        return area;
    }
   friend int same(const Square& k, const Circle& m);
};
const double Circle::PI = 3.14159;
// გლობალური ფუნქცია - ორივე კლასის მეგობარი
int same(const Square& sq, const Circle& c) {
	double s = sq.side,  r = c.radius;
	if (s > r) return 1;
	else if (s == r) return 0;
	else return -1;
}

// გლობალური ფუნქცია 
string sameArea(const Square& sq, const Circle& c)
{
	double sqf = sq.getArea(), cf = c.getArea();
	if (sqf > cf) {
        string result = "The square area is greater and it equals: ";
        result.append(to_string(sq.getArea()));
        return result;
    }
	else if (sqf == cf) return "The areas are equal.\n";
	     else return "The circle area is greater.\n";
}
int main()
{
    vector<pair<double, double>> vec = {{1.,1.}, {10.5,6.9}};
    for (const auto & pair: vec) {
        Square M(pair.first);  
        Circle C(pair.second);  
        switch ( same(M, C)) {
            case -1: cout << "The circle radius is greater.\n"; break;
            case 0:  cout << "The data are equal.\n";  break;
            case 1:  cout << "The square side is larger.\n"; 
        }
        cout << sameArea(M,C) << endl;
    }

	
}
