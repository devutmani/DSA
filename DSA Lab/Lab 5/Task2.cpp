#include <iostream>
#include <random>
using namespace std;

int randomNumber;

void guessNumber(int player) {
    int guess;
    cout << "Player " << player << ", enter your guess (1-100): ";
    cin >> guess;

    if (guess == randomNumber) {
        cout << "Player " << player << " guessed the correct number " << randomNumber << "! You win!\n";
        return;
    } 
    else if (guess < randomNumber) {
        cout << "Too low!\n";
    } 
    else {
        cout << "Too high!\n";
    }

    if (player == 1)
        guessNumber(2);
    else
        guessNumber(1);
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);
    randomNumber = dist(gen);

    cout << "Welcome to the Guessing Game!\n";
    cout << "Guess a number between 1 and 100.\n";
    guessNumber(1);

    return 0;
}