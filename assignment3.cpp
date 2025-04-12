#include <iostream>
#include <string>
int main(){
    std::string answer;
    double temp;
    double Fahrenhiet = ((temp * (9/5)) + 32);
    double Celsius = ((5/9) * (temp - 32));
    std::cout << "Enter a tempreture. " << std::endl;
    std::cin >> temp;
    std::cout << "Enter 'c' for Celsius or 'f' for Fahrenheit. ";
    std::cin >> answer;
    if (answer == "c")
    {
    std::cout << "Your tempreture of " << temp << " degrees Celsius is equivilent to " << Fahrenhiet << " degrees Fahrenhiet.";
    } else if (answer == "f"){
        std::cout << "Your tempreture of " << temp << " degrees Fahrenhiet is equivalent to " << Celsius << " degrees Celsius.";
    }
    return 0;
    
}