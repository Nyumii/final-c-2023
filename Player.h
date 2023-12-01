#pragma once

#include <string> 
using namespace std;

// Player class 
class Player
{

private: 
    string name;
    int marbles;
    int wager;

public:
    Player(std::string playerName = " "); // Constructor. 
    virtual ~Player();  // Destructor. 

    int getMarbles() const;
    int getWager() const;
    std::string getName() const;

    virtual void makeWager() = 0; 
    virtual int guessEvenOdd() = 0; // 0 even, 1 odd.
    virtual int lost() = 0; // Subtracts and returns wager. 
    virtual void won( int winnings) = 0; // adds to marbles. 
    virtual void printInfo() const = 0; // Prints name, marbles, and wager. 
};

// Person subclass. 
class Person : public Player
{

public:
    Person(string personName = " ");
    ~Person();

    void makeWager() override;  
    int guessEvenOdd() override; // 0 even, 1 odd. 
    int lost() override; // Subtract and returns wager. 
    void won( int winnings) override; // Adds to marbles.
    void printInfo() const override; // Prints name, marbles, and wager. 
};

// Computer subclass. 
class Computer : public Player
{

public:
    Computer(std::string computerName = " ");
    ~Computer();

    void makeWager() override;  
    int guessEvenOdd() override; // 0 even, 1 odd. 
    int lost() override; // Subtract and returns wager. 
    void won( int winnings) override; // Adds to marbles.
    void printInfo() const override; // Prints name, marbles, and wager. 
};
