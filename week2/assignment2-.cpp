#include <iostream>
#include <cstdlib>  // For rand() function
#include <ctime>    // For time() function
using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "Number Guessing Game" << endl;
    cout << "I'm thinking of a number between 1 and 100." << endl << endl;
    while (guess !=secretNumber){
        cout << "Take a guess..." << endl;
        cin >> guess;
        if (guess < secretNumber){
            cout << "Too low. Try again." << endl << endl;
            ++attempts;
            continue;
        }
        else if (guess > secretNumber){
            cout << "Too high. Try again." << endl << endl;
            ++attempts;
            continue;
        }
        else{
            ++attempts;
            cout << "Congratulations! You guessed the number!" << endl;
            cout << "It only took you " << attempts << " guesses!" << endl;
        }
    }
    //what needs to happen is it needs to guess a number,
    //then add one to the Y var (y++),
    //then it needs to state higher or lower (x>__),
    //then repeat the loopafter (continue functoin),
    //then break once you get the right number.

    return 0;
}