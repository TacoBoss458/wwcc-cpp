#include <iostream> 
#include <cmath>
using namespace std;


double calculateDistance(double X1_param, double X2_param, double Y1_param, double Y2_param) {
    return sqrt(pow(X2_param - X1_param, 2) + pow(Y2_param - Y1_param, 2));
}
int main () {
    double x1;
    double x2;
    double y1;
    double y2;
    cout << "\nEnter two points on a 2D Cartesian coordinate plane. \n\nPoint one\nX1: " ;
    cin >> x1;
    cout << "Y1: ";
    cin >> y1;
    cout << "Point two\nX2: ";
    cin >> x2;
    cout << "Y2: ";
    cin >> y2;
    double result = calculateDistance(x1, x2, y1, y2);
    cout << "The distance between (" << x1 << "," << y1 << ") and (" 
    << x2 << "," << y2 << ") is " << result << "!" << endl;
    return 0;

}