#include <iostream>
#include <string>
int main(){
    std::string answer;
    float temp;
    double Fahrenheit = (temp * 9.0/5.0) + 32.0;
    double Celsius = (temp - 32.0) * 5.0/9.0;
    std::cout << "Enter a tempreture. " << std::endl;
    std::cin >> temp;
    std::cout << "Enter 'c' for Celsius or 'f' for Fahrenheit. ";
    std::cin >> answer;
    if (answer == "c")
    {
    std::cout << "Your tempreture of " << temp << " degrees Celsius is equivilent to " << Fahrenheit << " degrees Fahrenhiet.";
    } else if (answer == "f"){
        std::cout << "Your tempreture of " << temp << " degrees Fahrenhiet is equivalent to " << Celsius << " degrees Celsius.";
    }
    return 0;
    
}