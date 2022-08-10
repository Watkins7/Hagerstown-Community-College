#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

//Created by: William Atkins
//Last Modified: 2/11/2019
//Purpose: Yahtzee Game


//This function will "roll" the dice 5 times
void roll5Dice(vector<int>& runningNumberCount,vector<int>& currentRolledNumbers, int &seedValue){

    int randomNumber;
    srand(seedValue);
    currentRolledNumbers.clear();

    //For 5 times this will generate a random number, and push it into the appropriate vector
    for (int i = 0; i < 5; i++) {
        randomNumber = (rand() % 6 + 1);

        //cout << randomNumber << endl;

        currentRolledNumbers.push_back(randomNumber);

        //End of for loop
    }

}

//This will up each number in the vector runningNumberCount
void upRunningCount(vector<int> &runningNumberCount, vector<int> &currentRolledNumbers){

    //For loop will run through the whole vector of the rolledNumbers and up the appriporiate count in the runningNumberCount variable.
    for (int i = 0; i < currentRolledNumbers.size(); i++) {

        //Look at this code below...it looks so beautiful
        //Basically it ups the running count vector by one at the appropriate spot
        runningNumberCount.at(currentRolledNumbers.at(i)-1)++;

        //End of for loop
    }

}

//Function will check the roll of the dice and determine what was the score
void checkRoll(vector<int> &currentRolledNumbers){

    vector<int> checker = {0,0,0,0,0,0};

    //Eveb though I passed currentRolledNumbers as a refrence, I want the same vector I can work with
    for (int i = 0; i < currentRolledNumbers.size(); i++) {
        checker.at(currentRolledNumbers.at(i) - 1)++;

        //End of for loop
    }

    vector<int> newChecker;

    //Creates a new vector that elimates "0"'s
    for (int y = 0; y < checker.size(); y++) {
        if (checker.at(y) != 0)
            newChecker.push_back(checker.at(y));
    }

    //Freaking super complicated code to see if it is straight
    //Basically a small straight can occur three different way
    //The first for loop takes care of the three possiblities
    //The second for loop will check to see if there are numbers in the vector
    for (int u = 0; u < 2; u++){

        int straightCheck = 0;

        for (int t = 0 + u; t < 4 + u; t++) {

            if (checker.at(t) >= 1) {
                straightCheck++;
            }

            if (straightCheck == 4) {
                cout << "Straight" << endl;
            }
        }
    }

    //All the if statements below will check to see what the user rolled
    if (newChecker.size() == 1) {
        cout << "Five of a kind" << endl;
    }

    else if (newChecker.at(0) == 4 || newChecker.at(1) == 4){
        cout << "Four of a kind" << endl;
    }

    else if (newChecker.size() == 2){
        cout << "Full House" << endl;
    }

    else if (newChecker.at(0) == 3 || newChecker.at(1) == 3 || newChecker.at(2) == 3){
        cout << "Three of a kind" << endl;
    }

    else if (newChecker.at(0) + newChecker.at(1) == 4 || newChecker.at(0) + newChecker.at(2) == 4 || newChecker.at(1) + newChecker.at(2) == 4){
        cout << "Two pair" << endl;
    }

    else if (newChecker.at(0) == 2 || newChecker.at(1) == 2 || newChecker.at(2) == 2 || newChecker.at(3) == 2){
        cout << "Two of a kind" << endl;
    }

    else if (checker.at(0) == 1 && checker.at(1) == 1 && checker.at(2) == 1 && checker.at(3) == 1 && checker.at(4) == 1){
        cout << "Long Straight" << endl;
    }

    else if (checker.at(5) == 1 && checker.at(1) == 1 && checker.at(2) == 1 && checker.at(3) == 1 && checker.at(4) == 1){
        cout << "Long Straight" << endl;
    }

    else
        cout << "Nothing good" << endl;

}

//This function will cout winning numbers
void winningNumbers (vector<int> &currentRolledNumber) {

    vector<int> diceCount = {0, 0, 0, 0, 0, 0};

    for (int i = 0; i < currentRolledNumber.size(); i++) {

        //Look at this code below...it looks so beautiful
        //Basically it ups the running count vector by one at the appropriate spot
        diceCount.at(currentRolledNumber.at(i) - 1)++;

    }


        for (int i = 0; i < diceCount.size(); i++) {
            if (diceCount.at(i) >= 2)
                cout << i + 1 << "'s ";
        }

}

//Gets the user to get a new seed value
void getSeedValue(int &seedValue){

    cout << "Enter seed (1 - 10,000): ";

    cin >> seedValue;

    cout << endl << "Using seed of " << seedValue << endl;

    //Seed value has to be within 1 - 10,000
    while (seedValue < 1 || seedValue > 10000){
        cout << '\n' << "Error...please insert a seed value from 1 - 10,000: ";

        cin >> seedValue;
    }

}

int main(){

    int seedValue;
    string answer;

    vector<int> runningCountOfNumbers = {0,0,0,0,0,0};
    vector<int> currentRolledNumbers;


    //While loop will continuely run the program until otherwise
    while (true) {

        cout << '\n' << "Welcome to the Yahtzee Menu" << '\n' << "Press \"R\" to roll or \"Q\" to quit" << '\n' << "Response: ";
        cin >> answer;

        //Answer for roll
        if (answer == "R" || answer == "r") {

            //Gets user seed's value
            getSeedValue(seedValue);

            //Rolls the dice 5 times
            roll5Dice(runningCountOfNumbers, currentRolledNumbers, seedValue);

            //Ups the current running count for each number
            upRunningCount(runningCountOfNumbers, currentRolledNumbers);


            cout << "The numbers you have rolled are: ";

            //COUTS the current numbers that were rolled
            for (int i = 0; i < currentRolledNumbers.size(); i++) {
                cout << currentRolledNumbers.at(i) << " ";
            }

            cout << endl << "The number frequency is: ";

            //COUTS the running number count
            for (int i = 0; i < runningCountOfNumbers.size(); i++) {
                cout << i + 1 << "'s -> " << "[" << runningCountOfNumbers.at(i) << "]" << " ";
            }

            cout << endl;

            //Calculates the total of all the dice
            int total = 0;
            for (int j = 0; j < currentRolledNumbers.size(); j++) {
                total += currentRolledNumbers.at(j);
            }

            cout << "The dice total is: " << total << endl;

            //Uses function to output what the user scored
            cout << "You have rolled: ";
            checkRoll(currentRolledNumbers);

            cout << "Numbers that won: ";
            winningNumbers(currentRolledNumbers);

            cout << '\n' << '\n';
        }

        if (answer == "Q" || answer == "q")
        {
            break;
        }

    }

}