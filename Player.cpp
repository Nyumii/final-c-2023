#include "Player.h"
#include <cstdlib>
#include <string> 
#include <iostream>
using namespace std; 

// Player class
Player::Player(string playerName)
    : name(playerName), marbles(10), wager(0)
{

}

Player::~Player()
{

}

int Player::getMarbles() const
{
    return marbles;
}

int Player::getWager() const
{
    return wager;
}

string Player::getName() const
{
    return name;
}

void Player::makeWager()
{
    // Input validation for wager
    while (true) {
        cout << name << ", enter the number of marbles to wager (0 to " << marbles << "): ";
        cin >> wager;

        if (cin.fail() || wager < 0 || wager > marbles) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a valid wager.\n";
        }
        else {
            break; // Valid input
        }
    }
}

int Player::guessEvenOdd() // 0 even, 1 odd.
{
    int guess;
    // Input validation for guess
    while (true) {
        cout << name << ", enter your guess (0 for even, 1 for odd): ";
        cin >> guess;

        if (cin.fail() || (guess != 0 && guess != 1)) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a valid guess.\n";
        }
        else {
            break; // Valid input
        }
    }
    return guess;
}

int Player::lost() // Subtracts and returns wager. 
{
    cout << getName() << " lost " << wager << " marbles." << endl;
    marbles -= wager;
    wager = 0; // Reset wager. 
    return wager;
}

void Player::won(int winnings) // adds to marbles. 
{
    marbles += winnings;
    cout << getName() << " won " << winnings << " marbles" << endl;
}

void Player::printInfo() const // Prints name, marbles, and wager. 
{
    cout << "Name: " << name << ", Marbles: " << marbles << ", Wager: " << wager << endl;
}



// Person subclass
Person::Person(string personName)
    : Player(personName)
{

}


Person::~Person()
{

}

void Person::makeWager()
{
    Player::makeWager();
}

int Person::guessEvenOdd() // 0 even, 1 odd.
{
    return Player::guessEvenOdd();
}

int Person::lost() // Subtracts and returns wager. 
{
    Player::lost();
}

void Person::won(int winnings) // adds to marbles. 
{
    Player::won(winnings);

}

void Person::printInfo() const // Prints name, marbles, and wager.
{
    Player::printInfo();
}

// Computer subclass
Computer::Computer(std::string computerName)
    : Player(computerName)
{

}

Computer::~Computer()
{

}

void Computer::makeWager()
{
    int wager = rand() % (getMarbles() + 1);
    cout << getName() << " wagers " << getWager() << " marbles." << endl;

}

int Computer::guessEvenOdd() // 0 even, 1 odd.
{
    return rand() % 2;
}

int Computer::lost() // Subtracts and returns wager. 
{
    Player::lost();
}

void Computer::won(int winnings) // adds to marbles. 
{
    Player::won(winnings);

}

void Computer::printInfo() const // Prints name, marbles, and wager.
{
    Player::printInfo();
}