#include <iostream>
#include <cmath>

using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w);

    double getLength() const;
    double getWidth() const;

    double area() const;              
    void area(double& result) const; 
    Rectangle& resize(double newLength, double newWidth); 

    void display() const; 
};

Rectangle::Rectangle(double l, double w) : length(l), width(w) {}

double Rectangle::getLength() const { return length; }
double Rectangle::getWidth() const { return width; }

double Rectangle::area() const {
    return length * width;
}

void Rectangle::area(double& result) const {
    result = length * width;
}

Rectangle& Rectangle::resize(double newLength, double newWidth) {
    this->length = newLength;
    this->width = newWidth;
    return *this;
}

void Rectangle::display() const {
    cout << "Rectangle - Length: " << length << ", Width: " << width << endl;
}

class Circle {
private:
    double radius;

public:
    Circle(double r); 

    double area() const;           
    double circumference() const; 

    void print() const;               
    void print(bool detailed) const; 
};

Circle::Circle(double r) : radius(r) {}

double Circle::area() const {
    return M_PI * radius * radius;
}

double Circle::circumference() const {
    return 2 * M_PI * radius;
}

void Circle::print() const {
    cout << "Circle with radius: " << radius << endl;
}

void Circle::print(bool detailed) const {
    if (detailed) {
        cout << "Circle Details:\n";
        cout << "Radius: " << radius << endl;
        cout << "Area: " << area() << endl;
        cout << "Circumference: " << circumference() << endl;
    } else {
        print(); 
    }
}

int main() {
    double length, width, radius;

    cout << "Enter rectangle length: ";
    cin >> length;
    cout << "Enter rectangle width: ";
    cin >> width;

    cout << "Enter circle radius: ";
    cin >> radius;

    Rectangle rect(length, width);
    Circle circ(radius);

    cout << "\n--- Rectangle Info ---\n";
    rect.display();
    cout << "Area (return): " << rect.area() << endl;
    double rectArea;
    rect.area(rectArea);
    cout << "Area (reference): " << rectArea << endl;

    cout << "\nResizing rectangle using method chaining...\n";
    rect.resize(8.0, 4.0).display();

    cout << "\n--- Circle Info ---\n";
    circ.print();           
    circ.print(true);       
    circ.print(false);      

    const Circle constCirc(3.0);
    cout << "\n--- Const Circle Info ---\n";
    cout << "Area: " << constCirc.area() << endl;
    cout << "Circumference: " << constCirc.circumference() << endl;
    constCirc.print(true);

    return 0;
}
