#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>


//William Atkins
//Last Modified: 2/4/2019

//This program inputs raw data from a puzzle.txt file and makes a crossword



using namespace std;

ofstream outPutFile;

//Struct class made so that we can pass multidimensional arrays
//Directions say it is a max of 22
struct matrix {
    char multiArray [22][22];
};


//Creates a vector from a puzzle.txt
vector<string> lookAtPuzzleFile() {
    vector <string> allWords;
    string currentWord;

    ifstream fin("puzzle.txt");

    //Every word from the puzzle file is put is a vector
    while (fin >> currentWord)
    {
        allWords.push_back(currentWord);

    }

    fin.close();

    return allWords;
}


//Checks row and column lengths, exits program if there is a problem
void checkPuzzleText(int &row, int &column, vector<string> &allWords){


    //If rows or columns exceed size limit then the program quits
    if (row >= 19 || column >= 19)
    {
        cout << "Your rows or column exceed size limits, please change your file.  The program will now exit, goodbye." << endl;

        exit(0);
    }


    //Checks word lenght im puzzle.txt
    for (int r = 0; r < allWords.size(); r++)
    {
        if (allWords.at(r).length() != column) {

            cout << "In your puzzle.txt, please check all the words in your row, the row number and words in the row length do not match." << endl;
            cout << "The program will now quit, goodbye.";

            exit(0);
        }
    }


    //Checks how many words are in the column
    if (allWords.size() != row)
    {
        cout << "In your puzzle.txt, please the number of columns.  The number of columns and the amount of words that you have do not match." << endl;
        cout << "The program will now quit, goodbye.";


        exit(0);
    }

}


//Creates a blank multi array filling all sections with "="
matrix createBlankMultiArray(int &row, int &column, vector<string> &allWords){



    //Sets new struct which will be returned
    matrix neo;

    //sets blanks for every item in the multi array, which is inside the struct
    for (int i = 0; i < row + 2; i++)
        for (int j = 0; j < column + 2; ++j)
        {
            neo.multiArray[i][j] = '=';
        }

        return neo;
}


//Actual creates a crossword, fills each spot with a character
matrix createActualCrossword(matrix &multiArrayOutline,int &row, int &column, vector<string> allWords){

    string alpha;
    int red =0;


    //This will set every character in the multiarray
    for (int k = 1; k < row + 1; ++k) {
        alpha = allWords.at(red);
        for (int p = 1; p < column + 1; p++){
            multiArrayOutline.multiArray[k][p] = alpha.at(p-1);
        }
        red++;
    }



    return multiArrayOutline;

}


//Prints crossword to screen and to a file
void printCrossword(matrix &crossword, int &row, int &column, vector<string> &allWords){


    //This will cout the whole array to the screen
    for (int l = 0; l < row+2; ++l) {

        for (int i = 0; i < column+2; ++i) {
            cout << crossword.multiArray[l][i];
        }

        cout << '\n';
    }


    //This will output the crossword to a file
    outPutFile.open("crossword.txt");
    for (int l = 0; l < row+2; ++l) {

        for (int i = 0; i < column+2; ++i) {
            outPutFile << crossword.multiArray[l][i];
        }

        outPutFile << '\n';
    }

    outPutFile.close();

}



//Main function
int main() {

    //Creates a vector by calling the approriate function
    vector<string> allWords = lookAtPuzzleFile();


    //Records the row and columns length
    int row = stoi(allWords.at(0));
    int column = stoi(allWords.at(1));

    //erase the front two vector items, which are numbers for size paramters
    allWords.erase(allWords.begin());
    allWords.erase(allWords.begin());


    //This function will check to make sure that columns and rows are within parameters
    checkPuzzleText(row, column, allWords);


    //Creates a "matrix" (which is a struct) by using the approripate function and passing the allWords vector
    matrix crossword = createBlankMultiArray(row, column, allWords);


    //Creates actual crossword using the appropriate function, matrix struct and vector are passed
    crossword = createActualCrossword(crossword, row, column, allWords);


    //Prints crossword to screen and to a file
    printCrossword(crossword, row, column, allWords);


    cout << '\n' << "We have located the puzzle.txt file, and have outputted the contents to crossword.txt";


    return 0;
}