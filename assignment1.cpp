#include <iostream>
#include <string> 
int main() {
    std::string name;
    std::cout << "Enter your first name: ";
    std::cin >> name;
    std::cout << "Hello, " << name << "! Welcome to C++!" << std::endl; 
    
    std::string answer;
    std::cout << "Do you like to go snowboarding? ";
    std::cin >> answer;
    if (answer == "yes") {
    std::cout << "We should go snowboarding together!" << std::endl;
} else if (answer == "no"){
    std::cout << "I don't blame you. Snowboarding is dangerous." << std::endl;
} else {
    std::cout << "Please answer with a 'yes' or 'no'." << std::endl;

    std::string answer2;
    std::cin >> answer2;
    if (answer2 == "yes") {
    std::cout << "We should go snowboarding together!" << std::endl;
} else if (answer2 == "no"){
    std::cout << "I don't blame you. Snowboarding is dangerous." << std::endl;
} else {
    std::cout << "Alright. I'm done asking you." << std::endl;
}
    }
    return 0;
}