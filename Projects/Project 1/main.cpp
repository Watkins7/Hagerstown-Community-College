#include <iostream>

using namespace std;

//Name: Project 1
//Created by: Wiliiam Atkins
//Date: 9/13/2018



//This is a program made to count cards in the game of Black Jack
int main() {


//Start of declaring variables
bool in_game = true;
int runningCount = 0;
int cards_dealt = 0;
string card;


// This starts the ingame while loop
while (in_game){

cout << "The card count is: " << runningCount << endl;
cout << "The number of cards dealt is: " << cards_dealt << endl;
cout << "" << endl;

//Asks user what card they want to input or to Quit
cout << "(Type QUIT or quit to end program)" << endl;
cout << "What card would you like to add to the count?: ";
cin >> card;

if (card == "2" || card == "two" || card == "3" || card == "three" || card == "4" || card == "four" || card == "5" || card == "five" || card == "6" || card == "six") {
    runningCount += 1;
    cards_dealt += 1;

}

else if ("7" == card || card == "seven" || card == "8" || card == "eight" || card == "9" || card == "9") {
    runningCount += 0;
    cards_dealt += 1;

}

else if (card == "10" || card == "ten" || card == "K" || card == "king" || card == "Q" || card == "queen" || card == "A" || card == "ace") {
    runningCount -= 1;
    cards_dealt += 1;

}

//These cases allow the while loop to close
else if (card == "quit" || card == "QUIT") {
    in_game = false;
}

else {
    cout << "Invalid Response...Please try again." << endl;
}


//This is the end of the ingame while loop
}


//This is final message to the user
cout << "The running count was " << runningCount << " and the cards dealt were " << cards_dealt << endl;


//End of int main
}

return 0;