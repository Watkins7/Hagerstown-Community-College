#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include <string>
using namespace std;


//CREATED BY: William Atkins
//DATE LAST MODIFIED: 12/5/2019
//PURPOSE: Debugger Program


//START OF DEBUGGER CLASS
class Dead_Bug_Debugger
{
private:
    //CODE NEEDED FOR STOP WATCH VARIABLE
    typedef chrono::high_resolution_clock stopWatch;
    stopWatch::time_point startTime;


public:
    //FUCTION THAT WILL SET INTIAL TIME
    void resetStopWatch() {
        startTime = stopWatch::now();
    }


    //FUNCTION WILL RETURN TIME ELAPSED SINCE LAST START TIME
    stopWatch::duration timeElapsedFunction() {
        return stopWatch::now() - startTime;

    }

    //INT COUNTERS FOR LOOP COUNTING
    int counter_1 = 0;
    int counter_2 = 0;
    int counter_3 = 0;



    //FUNCTRION MEANT TO CREATE A FILE
    void printInfo() {

        //THIS WILL WRITE INFO INTO A FILE CALLED "debuggerFile"
        ofstream debuggerWriteFile;
        debuggerWriteFile.open("debugger.txt");
        debuggerWriteFile << "Loop counter 1 (\"if\") is: " << counter_1 << '\n';
        debuggerWriteFile << "Loop counter 2 (\"for\" is: " << counter_2 << '\n';
        debuggerWriteFile << "Loop counter 3 (\"single loop counter\") is: " << counter_3 << '\n' << '\n';
        debuggerWriteFile << "The program took this amount of time: ";

        //WILL RECORD TIME IN BOTH NANOSECONDS AND SECONDS
        debuggerWriteFile << chrono::duration_cast<chrono::nanoseconds>(this->timeElapsedFunction()).count() << " nanoseconds" << " or ";
        debuggerWriteFile << chrono::duration_cast<chrono::seconds>(this->timeElapsedFunction()).count() << " seconds" << '\n';


        debuggerWriteFile.close();

    }


    //THIS WILL CALL FROM A FILE AND COUT IT'S CONTENTS
    void callFile() {

        //CREATES VARIABLES AND RUNS APPROPRIATE FUNCTIONS
        string file;
        ifstream file_("debugger.txt");

        //WHILE LOOP THAT WILL COUT EVERYTHING INTO THE FILE
        while (file_)
        {
            getline(file_, file);
            cout << file << endl;

        }

        //CLOSES FILE
        file_.close();

    }




    //END OF CLASS
};






//START OF MAIN FUNCTION LOOP
int main()
{


    //CREATES A Dead_Bug_Debugger CLASS, AND SETS UP VARIABLES
    Dead_Bug_Debugger gribble;
    string answer;
    int answer_2;


    //AT THE BEGINNING OF THE MAIN FUNCTION THIS PROGRAM WILL START A STOP WATCH
    gribble.resetStopWatch();


    //WHILE STATEMENT THAT WILL MAKE A MAIN MENU LOOP
    while (true)
    {

        cout << "________________________________________" << endl;
        cout << "|   CLASS CODE FOR DEAD BUG DEBUGGER   |" << endl;
        cout << "|    By: William Atkins                |" << endl;
        cout << "|    Date: 11/28/2018                  |" << endl;
        cout << "----------------------------------------" << endl;
        cout << '\n' << '\n';


        cout << "This is an example menu...what would you like to do?: " << '\n';
        cout << "  1) Run an \"if\" statement X amount of times." << '\n';
        cout << "  2) Run a \"for\" statement X amount of times." << '\n';
        cout << "  3) Run a \"single loop counter\" 1 time." << '\n';
        cout << "  4) Print debugger info to a file, then display counters and time." << '\n';
        cout << "  5) Exit Script." << '\n';
        cout << '\n';
        cout << "What option would you like to do?:";

        //GETS ANSWER FROM USER
        getline(cin, answer);

        //SANTIZES INPUT AFTER ANSWER
        cin.clear();


        //IF STATEMENTS TRIGGERED FROM MAIN MENU CHOICES
        if (answer == "one" || answer == "1" || answer == "ONE" || answer == "One") {
            cout << "How many times would you like to run the \"if\" statement?: " << endl;
            cin >> answer_2;

            gribble.counter_1 += answer_2;
        }


        if (answer == "two" || answer == "2" || answer == "TWO" || answer == "Two") {
            cout << "How many times would you like to run the \"for\" loop?: " << endl;
            cin >> answer_2;

            gribble.counter_2 += answer_2;
        }


        if (answer == "three" || answer == "3" || answer == "THREE" || answer == "Three") {
            cout << "You have upped the Single Loop counter 1 time..." << endl;

            gribble.counter_3++;
        }


        if (answer == "four" || answer == "4" || answer == "FOUR" || answer == "Four") {



            //CALLS THE FUNCTION THAT WILL OUTOUT FUNCTION INFO INTO A FILE
            gribble.printInfo();

            //CALLS THE FUNCTION THAT WILL COUT FILE
            gribble.callFile();

            //RESETS THE STOPWATCH APPLICATION
            gribble.resetStopWatch();


        }


        if (answer == "five" || answer == "5" || answer == "FIVE" || answer == "Five") {
            cout << "You have exited the program...goodbye";
            break;
        }

        //END OF WHILE LOOP
    }

    //END OF MAIN MENU FUNCTION
}