#include "Player.h"
#include <cstdlib>
#include <string> 
#include <iostream>
#include <vector>
using namespace std;

// Function to get player names. 
string getPlayerName(const string& playerType) {
    string playerName;
    cout << "Enter the name for the " << playerType << " player: ";
    cin >> playerName; 
    return playerName;
}

// Function to simulate a single turn of a player
void playTurn(Player* currentPlayer, Player* otherPlayer) {
    // Display whose turn it is
    cout << "\nIt's " << currentPlayer->getName() << "'s turn.\n";

    // Make the player take a turn
    currentPlayer->makeWager();
    int guess = currentPlayer->guessEvenOdd();
    int totalWager = currentPlayer->getWager() + otherPlayer->getWager();

    cout << currentPlayer->getName() << " guessed " << (guess == 0 ? "even" : "odd") << ".\n";
    cout << "Total marbles wagered: " << totalWager << ".\n";

    if (totalWager % 2 == guess) {
        // Guessed correctly
        cout << currentPlayer->getName() << " guessed correctly! Won " << totalWager << " marbles.\n";
        currentPlayer->won(totalWager);
        otherPlayer->lost();
    }
    else {
        // Guessed incorrectly
        cout << currentPlayer->getName() << " guessed incorrectly. Nothing happens.\n";
    }

    // Display player information after the turn
    currentPlayer->printInfo();
}

int main() {
    // Get player names
    string personName = getPlayerName("person");
    string computerName = getPlayerName("computer");

    // Create instances of Person and Computer with user-provided names
    Person person(personName);
    Computer computer(computerName);

    // Place them in a vector
    vector<Player*> players;
    players.push_back(&person);
    players.push_back(&computer);

    // Game loop
    size_t currentPlayerIndex = 0; // Start with the first player

    while (true) {
        // Get the current player
        Player* currentPlayer = players[currentPlayerIndex];

        // Play a turn for the current player
        playTurn(currentPlayer, players[(currentPlayerIndex + 1) % players.size()]);

        // Check if the player has all the marbles
        if (currentPlayer->getMarbles() == 20) {
            cout << currentPlayer->getName() << " has all the marbles! Game Over.\n";
            return 0; // End the game
        }

        // Switch to the next player
        currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
    }

    return 0;
}

