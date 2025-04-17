#include <iostream>
#include <cstdlib>  // For rand() function
#include <ctime>    // For time() function
using namespace std;

//sets the range from 0-1
bool flipCoin() {
    return rand() % 2;
    }
int main() {

    srand(time(0));
// vars
    int flips;
    int heads = 0;
    int tails = 0;
//intro
    cout << "Coin Flip Simulator" << endl;
    cout << "How many flips would you like to simulate? ";
    cin >> flips;
    cout << "Simulating " << flips << " coin flips... \n\nResults:\n";
//where the coin actually flips
    for (int i = 0; i < flips; i++){
        if (flipCoin()) {
            ++heads;
        } else {
            ++tails;
        }
        
    }
//calculators
    double hPer = (static_cast <double> (heads) / flips) * 100;
    double tPer = (static_cast <double> (tails) / flips) * 100;    
    cout << "Coin landed on Heads " << heads << " times (" << hPer << "%)." << endl;
    cout << "Coin landed on Tails " << tails << " times (" << tPer << "%)." << endl;
    return 0;
}