#include <iostream>
#include <string>
using namespace std;
int main(){
    string answer;
    float temp;
    double fahrenheit = (temp * 9.0 / 5.0);
    double Fahrenheit = (fahrenheit + 32.0);
    double celsius = (temp - 32.0); 
    double Celsius = (celsius * 5.0 / 9.0);
    cout << "Enter a tempreture. " << endl;
    cin >> temp;
    cout << "Enter 'c' for Celsius or 'f' for Fahrenheit. " << endl;
    cin >> answer;
    if (answer == "c")
    {
    cout << "\n" << "Your tempreture of " << temp << " degrees Celsius is equivilent to " << Fahrenheit << " degrees Fahrenhiet." << endl;
    } else if (answer == "f"){
        cout << "\n" << "Your tempreture of " << temp << " degrees Fahrenhiet is equivalent to " << Celsius << " degrees Celsius."<< endl;
    } else {
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return 0;
    
}