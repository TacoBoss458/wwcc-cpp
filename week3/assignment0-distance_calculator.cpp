#include <iostream> 
#include <cmath>
using namespace std;
double x1;
double x2;
double y1;
double y2;

int calculateDistance(double x1, double x2, double y1, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
int main () {
    cout << "Enter two points on a 2D Cartesian coordinate plane. \n\nPoint one\nX1: " ;
    cin >> x1;
    cout << "Y1: ";
    cin >> y1;
    cout << "Point two\nX2: ";
    cin >> x2;
    cout << "Y2: ";
    cin >> y2;
    double result = calculateDistance(x1, y1, x2, y2);
    cout << "The distance between (" << x1 << "," << y1 << ") and (" 
    << x2 << "," << y2 << ") is " << result << "!";

}