#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int countVowels(string word) {
    int vowels = 0;
    for (char c : word) { 
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            vowels++;
        }
    }
    return vowels; // Returns total
}
int countConsonants(string word) {
    int consonants = 0;
    for (char c : word) { // This checks both uppercase and lowercase for consonants. ! to exclude vowels
        if ((c >= 'a' && c <= 'z' && !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')) ||
            (c >= 'A' && c <= 'Z' && !(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'))) {
            consonants++;
        }
    }
    return consonants; // Returns total
}
bool isPalindrome(const string& word) {
    string reversed = word; // Copy the word
    reverse(reversed.begin(), reversed.end()); // Reverse the word
    return word == reversed; // Sets the word equal to the reversed word
}
char firstLetter(string word) { // The initial function
    if (word.empty()) {
        return '\0'; // Deals with empty string
    }
    return word[0]; // Final output being the first letter of word since we take 0 letters from the first letter
}
string reverseWord(const string& word) { // Initial function/making the word constant
    string reversed = word; // Basically making a copy of the word
    reverse(reversed.begin(), reversed.end()); // Reverseing the copy
    return reversed;// Final output
}

int main() {
    string word;
    char exitProgram;
    while (true) {
        cout << "Enter a word: ";
        cin >> word;
        int vowels = countVowels(word);
        int consonants = countConsonants(word);
        bool palindrome = isPalindrome(word);
        char first = firstLetter(word);
        string reversed = reverseWord(word);
        cout << "Number of vowels in " << word << ": " << vowels << "\n";
        cout << "Number of consonants in " << word << ": " << consonants << "\n";
        cout << word << " is " << (palindrome ? "" : "not ") << "a palindrome.\n";
        cout << "First letter of " << word << ": " << first << "\n";

        cout << "Reversed word: " << reversed << "\n";
        cout << "Do you want to exit? (y/n): ";
        cin >> exitProgram;
        if (exitProgram == 'y' || exitProgram == 'Y') {
            break;
        } else if (word{


        }
        
    }
    cout << "Goodbye.\n";
    return 0;
}
