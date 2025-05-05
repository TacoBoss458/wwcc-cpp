#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;

bool isEmoji(const string& word) {
    static vector<string> emojis = {":)", ":(", ":D"}; //This is storing the Emojis just from the assignment
    return find(emojis.begin(), emojis.end(), word) != emojis.end();
}

string capitalizeSentences(const string& text) { // Takes a constant refference of the sentence and captializes the first letters
    string result = text; // Copy
    bool capitalize = true;
    for (size_t i = 0; i < result.length(); ++i) {
        if (capitalize && isalpha(result[i])) {
            result[i] = toupper(result[i]);
            capitalize = false;
        }
        if (result[i] == '.' || result[i] == '!' || result[i] == '?') {
            capitalize = true;
        }
    }
    return result;
}

int main() {
    string message;
    cout << "Enter a text message: ";
    getline(cin, message);

    int charCount = message.length();
    int wordCount = 0, sentenceCount = 0;
    int totalWordLength = 0;
    bool containsEmoji = false;
    vector<string> longWords; // # of 5+ letter words

    istringstream stream(message); // Takes every word and makes them into variables-ish
    string word;
    while (stream >> word) {
        ++wordCount;
        totalWordLength += word.length();
        if (word.length() > 5) {
            longWords.push_back(word);
        }
        if (isEmoji(word)) {
            containsEmoji = true;
        }
    }

    for (char ch : message) {
        if (ch == '.' || ch == '!' || ch == '?') {
            ++sentenceCount;
        }
    }

    double averageWordLength = wordCount > 0 ? static_cast<double>(totalWordLength) / wordCount : 0.0;

    cout << "\nAnalysis:\n";
    cout << "Total characters: " << charCount << "\n";
    cout << "Total words: " << wordCount << "\n";
    cout << "Total sentences: " << sentenceCount << "\n";
    cout << "Average word length: " << averageWordLength << "\n";
    cout << "Contains emoji: " << (containsEmoji ? "Yes" : "No") << "\n";
    cout << "Words longer than 5 characters: ";
    for (const auto& lw : longWords) {
        cout << lw << " ";
    }
    cout << "\n";

    string capitalized = capitalizeSentences(message);
    cout << "Capitalized message: " << capitalized << "\n";

    return 0;
}
