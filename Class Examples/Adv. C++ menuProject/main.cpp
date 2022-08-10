#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

ifstream openFile;
ofstream writeToFile;
float tax = 0.05;
string userInput = "";




//Variable used for getline
string x;
string a;
int n = 3;
double z;


//Struct is designed to identify menu item name & price
struct menuItemType {

    string name;
    double price;

};


//Function sets a double to return 2 decimal places
double round(double d) {
    return floor(d + 0.5);
}


//Prints vector to reciept
void vectorToFile(vector<menuItemType> currentVector){

    cout << '\n' << "I have printed a reciept to your file." << '\n';

    writeToFile.open("Bob's Burgers Recipt.txt");

    for (int i =0; i < currentVector.size(); i++)
    {
        cout.width(15);
        writeToFile << currentVector[i].name << left << "  $" << currentVector[i].price << '\n';
    }

    cout << '\n' << '\n';

    double y = 0;
    double calc;
    for (int i=0; i < currentVector.size(); i++)
    {
        y = y + currentVector[i].price;
    }

    calc = y *0.07;

    writeToFile << setprecision(2) << fixed <<'\n' << "---------------------------" << '\n' << "Sales Tax:" << right << "   $" << calc << '\n' << "Total Bill is:" <<  right << "   $" << y + calc << endl << "---------------------------";
    writeToFile.close();

}


//Prints the menu to the screen and also to a vector in main
vector<menuItemType> menuToScreen() {
    vector<menuItemType> totalMenuItems;
    menuItemType menuItem;
    int n = 3;


    //Couts welcome sign to the screen
    cout << "---------------------------" << endl;
    cout << "Welcome to Bob's Burgers" << endl;
    cout << "---------------------------" << endl;

    openFile.open("menu.txt");


    cin.clear();

    //Goes through the whole menu.txt file
    //After every two line it makes a new Struct
    //New Struct is added to a vector
    while (getline(openFile, x)) {

        if (n % 2 == 1) {
            a = x;
            n++;

        } else if (n % 2 == 0) {

            z = stod(x);

            menuItem = {a, z};
            totalMenuItems.push_back(menuItem);
            n++;
        }



    }

    //Couts menu
    for (int i = 0; i < totalMenuItems.size(); i++) {
        cout.width(15);
        cout << totalMenuItems[i].name << left << "$" << totalMenuItems[i].price << '\n';
    }

    cout << "---------------------------" << endl << '\n';

    //Closes the opened file
    openFile.close();

    cout << "Please type the menu item would you like to order." << endl << "Or press Q to quit." << endl
         << "Or press R for current reciept:";

    return totalMenuItems;

}


//Adds item to reciept vector
vector<menuItemType> returnRecieptVector(string userInput, vector<menuItemType>menu, vector<menuItemType>currentReciept) {
    vector<menuItemType> newReciept = currentReciept;

    //Adds item to reciept
    for (int i = 0; i < menu.size(); i++)
    {
        if (userInput == menu[i].name)
            newReciept.push_back(menu[i]);
    }

    return newReciept;
}


//Search menu and add item to bill
bool searchMenu(string userInput) {
    //Set up variables
    menuItemType menuItem;
    vector<menuItemType> totalMenuItems;


    openFile.open("menu.txt");


    cin.clear();

    //Goes through the whole menu.txt file
    //After every two line it makes a new Struct
    //New Struct is added to a vector
    while (getline(openFile, x)) {

        if (n % 2 == 1) {
            a = x;
            n++;

        } else if (n % 2 == 0) {

            z = stod(x);

            menuItem = {a, z};
            totalMenuItems.push_back(menuItem);
            n++;
        }

    }

        openFile.close();


        for (int i = 0; i < totalMenuItems.size(); i++) {
            if (totalMenuItems[i].name == userInput) {
                cout << '\n' << totalMenuItems[i].name << " Was added to your bill" << '\n' << '\n' << endl;
                //The code below I have is so clever, I came up with it and im so proud
                //menuItem = {totalMenuItems[i].name,
                //totalMenuItems[i].price}; //Yo please read this and tell me if I am saving memory.
                //Please for the love of god read the above message

                return true;

            }

        }

        return false;
    }



//Main Program
int main() {

    //Creates an empty menuItemType Struct;
    menuItemType menuItem;

    //Creates a vector of menuItemsTypes
    vector<menuItemType> totalMenuItems;

    //Vector that contains the running bill items
    vector<menuItemType> reciept;



    //Main menu screen while loop
    while (true) {

        //Function will not only print menu to screen, but also sets up a vector for menu
        totalMenuItems = menuToScreen();

        //gets user input
        cin.clear();
        getline(cin, userInput);

        //Q response, makes reciept and quits
        if (userInput == "Q" || userInput == "q" || userInput == "quit" || userInput == "QUIT") {
            vectorToFile(reciept);
            cout << '\n' << "You have exited the program...goodbye.";
            exit(0);
        }

        //R response, makes reciept
        if (userInput == "R" || userInput == "r" || userInput == "RECIEPT" || userInput == "recipt") {
            //Sends a vector to a function that will print a file
            vectorToFile(reciept);
            }

        //Function will search menu for user's response
        bool truth = searchMenu(userInput);

        //If menu search is true, functions below will add menu item to reciept
        if (truth == true)
            {
                reciept = returnRecieptVector(userInput, totalMenuItems, reciept);
            }

        //If menu search cannot find item, couts approriate response
        else
            {
            cout << '\n' << "Sorry, unable to find your item. Please check your spelling." << '\n' << endl;
            }

        }




        }
