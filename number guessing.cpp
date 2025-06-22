#include <iostream>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()

using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int userGuess;
    int attempts = 0;

    cout << "?? Welcome to the Number Guessing Game!" << endl;
    cout << "I have picked a number between 1 and 100." << endl;
    cout << "Can you guess what it is?" << endl;

    // Game loop
    do {
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempts++;

        if (userGuess < secretNumber) {
            cout << "?? Too low! Try a higher number." << endl;
        } else if (userGuess > secretNumber) {
            cout << "?? Too high! Try a lower number." << endl;
        } else {
            cout << "?? Congratulations! You guessed the number in " << attempts << " attempts." << endl;
        }
    } while (userGuess != secretNumber);

    return 0;
}

