#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

//Created by: William Atkins
//Last Modified: 2/11/2019
//Purpose: Yahtzee Game


//This function will "roll" the dice 5 times
//It will
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


void checkRoll(vector<int> &currentRolledNumbers){

    vector<int> checker = {0,0,0,0,0,0};

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

    if (newChecker.size() == 1) {
        cout << "Five of a kind" << endl;
        exit(0);
    }

    else if (newChecker.at(0) == 4 || newChecker.at(1) == 4){
        cout << "Four of a kind" << endl;
        exit(0);
    }

    else if (newChecker.at(0) + newChecker.at(1) == 5){
        cout << "Full House" << endl;
        exit(0);
    }

    else if (newChecker.at(0) == 3 || newChecker.at(1) == 3 || newChecker.at(2) == 3){
        cout << "Three of a kind" << endl;
        exit(0);
    }

    else if (newChecker.at(0) + newChecker.at(1) == 4 || newChecker.at(0) + newChecker.at(2) == 4 || newChecker.at(1) + newChecker.at(2) == 4){
        cout << "Two pair" << endl;
        exit(0);
    }

    else if (newChecker.at(0) == 2 || newChecker.at(1) == 2 || newChecker.at(2) == 2 || newChecker.at(3) == 2){
        cout << "Two of a kind" << endl;
        exit(0);
    }

    else if (checker.at(0) == 1 && checker.at(1) == 1 && checker.at(2) == 1 && checker.at(3) == 1 && checker.at(4) == 1){
        cout << "Long Straight" << endl;
        exit (0);
    }

    else if (checker.at(5) == 1 && checker.at(1) == 1 && checker.at(2) == 1 && checker.at(3) == 1 && checker.at(4) == 1){
        cout << "Long Straight" << endl;
        exit (0);
    }


}


void getSeedValue(int &seedValue){

    cout << "Please insert a seed value between 1 - 10,000: ";

    cin >> seedValue;

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

    getSeedValue(seedValue);

    while (true) {

        cout << '\n' << "Welcome to the Yahtzee Menu" << '\n' << "Press R to roll or Q to quit" << '\n' << "Response: ";
        cin >> answer;

        if (answer == "R" || answer == "r") {

            roll5Dice(runningCountOfNumbers, currentRolledNumbers, seedValue);

            upRunningCount(runningCountOfNumbers, currentRolledNumbers);


            cout << "The numbers you have rolled are: ";

            //For testing
            for (int i = 0; i < currentRolledNumbers.size(); i++) {
                cout << currentRolledNumbers.at(i) << " ";
            }

            cout << endl << "The number frequency is: ";

            //For testing
            for (int i = 0; i < runningCountOfNumbers.size(); i++) {
                cout << i + 1 << "'s -> " << "[" << runningCountOfNumbers.at(i) << "]" << " ";
            }

            cout << endl;

            int total = 0;
            for (int j = 0; j < currentRolledNumbers.size(); j++) {
                total += currentRolledNumbers.at(j);
            }

            cout << "The dice total is: " << total << endl;

            cout << "You have rolled: ";
            checkRoll(currentRolledNumbers);

        }

        if (answer == "Q" || answer == "q")
        {
            break;
        }

    }

}