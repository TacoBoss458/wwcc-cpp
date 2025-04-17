#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main (){
    int integerValue = 42;
    float floatValue = 3.14159265f;
    double doubleValue = 3.14159265;
    char charValue = 'x';
    const char* stringValue = "Hello, World!";
    printf("Format Specifier Practice\n");
    printf("------------------------\n\n");
    printf("Integer formats: \n");
    printf("Decimal: %d\n",integerValue);
    printf("Hexadecimal: %#x\n", integerValue);
    printf("Octal: %o\n", integerValue);
    printf("With width (5): [%5d]\n",integerValue);
    printf("Left-aligned: [%-5d]\n\n", integerValue);
    printf("Float formats:\n\n");
    printf("Default: %f\n", floatValue);
    printf("With precision (2): %.2f\n", floatValue);
    printf("Scientific: %e\n", floatValue);
    printf("Fixed with percision: %.4f\n\n", floatValue);
    printf("Character and String formats:\n");
    printf("Character: %c\n", charValue);
    printf("String: %s\n"), stringValue;
    printf("String with width (20): [%20s]\n"), stringValue;

    return 0;
}