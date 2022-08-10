#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <sstream>

//WILLIAM ATKINS
//10/30/2018
//DECIPHER PROGRAM
//ROT13 ROT6 AND CUSTOM


using namespace std;

//VARIABLES USED IN MAIN LOOP
//THIS VARIABLE IS FOR WHICH DECODER
int input;

//THIS VARIABLE IS USED FOR THE CRYPTIC TEXT
string answer;





//ROT13 DECODER FUNCTION
void ROT13(string cipher_text_string) {

    //ESTABLISHES BLANK CHAR ARRAY
    int size_of_array = cipher_text_string.size();
    char cipher_text_ARRAY[answer.size()];

    //THIS FOR LOOP SETS UP THE CIPHER ARRAY FROM THE CIPHER STRING
    for (int i=0; i < size_of_array; i++)
        cipher_text_ARRAY[i] = cipher_text_string[i];

    //THE SET UP FOR ROTATION_13 MAP
    map<char, char> rotation_map_ROT13;
    map<char, char>::iterator it;

    //EVERY MAPPING NEEDED FOR ROTATION CYPHER
    rotation_map_ROT13['a'] = 'n';
    rotation_map_ROT13['A'] = 'N';
    rotation_map_ROT13['b'] = 'o';
    rotation_map_ROT13['B'] = 'O';
    rotation_map_ROT13['c'] = 'p';
    rotation_map_ROT13['C'] = 'p';
    rotation_map_ROT13['d'] = 'q';
    rotation_map_ROT13['D'] = 'Q';
    rotation_map_ROT13['e'] = 'r';
    rotation_map_ROT13['E'] = 'R';
    rotation_map_ROT13['f'] = 's';
    rotation_map_ROT13['F'] = 'S';
    rotation_map_ROT13['g'] = 't';
    rotation_map_ROT13['G'] = 'T';
    rotation_map_ROT13['h'] = 'u';
    rotation_map_ROT13['H'] = 'U';
    rotation_map_ROT13['i'] = 'v';
    rotation_map_ROT13['I'] = 'V';
    rotation_map_ROT13['j'] = 'w';
    rotation_map_ROT13['J'] = 'W';
    rotation_map_ROT13['k'] = 'x';
    rotation_map_ROT13['K'] = 'X';
    rotation_map_ROT13['l'] = 'y';
    rotation_map_ROT13['L'] = 'Y';
    rotation_map_ROT13['m'] = 'z';
    rotation_map_ROT13['M'] = 'Z';
    rotation_map_ROT13['n'] = 'a';
    rotation_map_ROT13['N'] = 'A';
    rotation_map_ROT13['o'] = 'b';
    rotation_map_ROT13['O'] = 'B';
    rotation_map_ROT13['p'] = 'c';
    rotation_map_ROT13['P'] = 'O';
    rotation_map_ROT13['q'] = 'd';
    rotation_map_ROT13['Q'] = 'D';
    rotation_map_ROT13['r'] = 'e';
    rotation_map_ROT13['R'] = 'E';
    rotation_map_ROT13['s'] = 'f';
    rotation_map_ROT13['S'] = 'F';
    rotation_map_ROT13['t'] = 'g';
    rotation_map_ROT13['T'] = 'G';
    rotation_map_ROT13['u'] = 'h';
    rotation_map_ROT13['U'] = 'H';
    rotation_map_ROT13['v'] = 'i';
    rotation_map_ROT13['V'] = 'I';
    rotation_map_ROT13['w'] = 'j';
    rotation_map_ROT13['W'] = 'J';
    rotation_map_ROT13['x'] = 'k';
    rotation_map_ROT13['X'] = 'K';
    rotation_map_ROT13['y'] = 'l';
    rotation_map_ROT13['Y'] = 'L';
    rotation_map_ROT13['z'] = 'm';
    rotation_map_ROT13['Z'] = 'M';
    rotation_map_ROT13[' '] = ' ';
    rotation_map_ROT13['.'] = '.';
    rotation_map_ROT13['!'] = '!';
    rotation_map_ROT13[','] = ',';


    //MAKES PLAIN TEXT CHAR ARRAY
    char plain_text_array [size_of_array];

    //THIS VARIABLE IS USED AS A PLACE HOLDER IN THE DECRYPTION CIPHER
    char zard;

    //THIS FOR LOOP MAPS EVERY CHARACTER IN THE CIPHER ARRAY
    //MAPPED CHARACTERS ARE SENT INTO PLAIN TEXT ARRAY
    for (int i = 0; i < size_of_array+1; i++) {
           zard = cipher_text_ARRAY[i];
           plain_text_array[i] = rotation_map_ROT13.find(zard)->second;
    }

    //THIS OUTPUTS PLAIN TEXT ARRAY
    cout << '\n' << '\n' << "Your plain text is: " << plain_text_array << '\n' << '\n' << '\n';


}





//ROT6 DECODER FUNCTION
void ROT6(string cipher_text_string)
{
    //ESTABLISHES BLANK CHAR ARRAY
    int size_of_array = cipher_text_string.size();
    char cipher_text_ARRAY[answer.size()];

    //THIS FOR LOOP SETS UP THE CIPHER ARRAY FROM THE CIPHER STRING
    for (int i=0; i < size_of_array; i++)
        cipher_text_ARRAY[i] = cipher_text_string[i];

    //THE SET UP FOR ROTATION_6 MAP
    map<char, char> rotation_map_ROT6;
    map<char, char>::iterator it;

    //EVERY MAPPING NEEDED FOR ROTATION CYPHER
    rotation_map_ROT6['a'] = 'u';
    rotation_map_ROT6['A'] = 'U';
    rotation_map_ROT6['b'] = 'v';
    rotation_map_ROT6['B'] = 'V';
    rotation_map_ROT6['c'] = 'w';
    rotation_map_ROT6['C'] = 'W';
    rotation_map_ROT6['d'] = 'x';
    rotation_map_ROT6['D'] = 'X';
    rotation_map_ROT6['e'] = 'y';
    rotation_map_ROT6['E'] = 'Y';
    rotation_map_ROT6['f'] = 'z';
    rotation_map_ROT6['F'] = 'Z';
    rotation_map_ROT6['g'] = 'a';
    rotation_map_ROT6['G'] = 'A';
    rotation_map_ROT6['h'] = 'b';
    rotation_map_ROT6['H'] = 'B';
    rotation_map_ROT6['i'] = 'c';
    rotation_map_ROT6['I'] = 'C';
    rotation_map_ROT6['j'] = 'd';
    rotation_map_ROT6['J'] = 'D';
    rotation_map_ROT6['k'] = 'e';
    rotation_map_ROT6['K'] = 'E';
    rotation_map_ROT6['l'] = 'f';
    rotation_map_ROT6['L'] = 'F';
    rotation_map_ROT6['m'] = 'g';
    rotation_map_ROT6['M'] = 'G';
    rotation_map_ROT6['n'] = 'h';
    rotation_map_ROT6['N'] = 'H';
    rotation_map_ROT6['o'] = 'i';
    rotation_map_ROT6['O'] = 'I';
    rotation_map_ROT6['p'] = 'j';
    rotation_map_ROT6['P'] = 'J';
    rotation_map_ROT6['q'] = 'k';
    rotation_map_ROT6['Q'] = 'K';
    rotation_map_ROT6['r'] = 'l';
    rotation_map_ROT6['R'] = 'L';
    rotation_map_ROT6['s'] = 'm';
    rotation_map_ROT6['S'] = 'M';
    rotation_map_ROT6['t'] = 'n';
    rotation_map_ROT6['T'] = 'N';
    rotation_map_ROT6['u'] = 'o';
    rotation_map_ROT6['U'] = 'O';
    rotation_map_ROT6['v'] = 'p';
    rotation_map_ROT6['V'] - 'P';
    rotation_map_ROT6['w'] = 'q';
    rotation_map_ROT6['W'] = 'Q';
    rotation_map_ROT6['x'] = 'r';
    rotation_map_ROT6['X'] = 'R';
    rotation_map_ROT6['y'] = 's';
    rotation_map_ROT6['Y'] = 'S';
    rotation_map_ROT6['z'] = 't';
    rotation_map_ROT6['Z'] = 'T';
    rotation_map_ROT6[' '] = ' ';
    rotation_map_ROT6['.'] = '.';
    rotation_map_ROT6['!'] = '!';
    rotation_map_ROT6[','] = ',';



    //MAKES PLAIN TEXT CHAR ARRAY
    char plain_text_array [size_of_array];

    //THIS VARIABLE IS USED AS A PLACE HOLDER IN THE DECRYPTION CIPHER
    char zard;

    //THIS FOR LOOP MAPS EVERY CHARACTER IN THE CIPHER ARRAY
    //MAPPED CHARACTERS ARE SENT INTO PLAIN TEXT ARRAY
    for (int i = 0; i < size_of_array+1; i++) {
        zard = cipher_text_ARRAY[i];
        plain_text_array[i] = rotation_map_ROT6.find(zard)->second;
    }

    //THIS OUTPUTS PLAIN TEXT ARRAY
    cout << '\n' << '\n' << "Your plain text is: " << plain_text_array << '\n' << '\n' << '\n';
}






//CUSTOM DECODER FUNCTION
void CUSTOM(string cipher_text) {
    //TEMP STRING VARIABLE
    string temp;

    //CREATES A BLANK CIPHER ARRAY
    vector<string> cipher_vector;

    //CONVERTS STRING INTO STRINGSTREAM
    stringstream stream_1(cipher_text);

    //GETLINE WHILE LOOP THAT MAKES A CIPHER VECTOR AND USES "," AS A DELIMITER
    while (getline(stream_1, temp, ','))
        cipher_vector.push_back(temp);

    //SIZE OF CIPHER_VECTOR
    int Tattle_Tale = cipher_vector.size();


    //TESTING CODE
    //for (string &s : cipher_vector)
        //cout << s;

    //MAKES BLANK ARRAY
    string cipher_array[Tattle_Tale];

    //CHANGING VECTOR INTO CIPHER_ARRAY
    for (int i = 0; i < Tattle_Tale; i++) {
        cipher_array[i] = cipher_vector[i];
    }


    //TESTING CODE
    //cout << "this is j: ";
    //for (string j: cipher_array)
        //cout << j;


    //CREATES MAP FOR CUSTOM DECIPHER
    map<string, string> CUSTOM_map;
    map<string, string>::iterator it;
    CUSTOM_map["1"] = "A";
    CUSTOM_map["1.5"] = "B";
    CUSTOM_map["2"] = "C";
    CUSTOM_map["2.5"] = "D";
    CUSTOM_map["3"] = "E";
    CUSTOM_map["3.5"] = "F";
    CUSTOM_map["4"] = "G";
    CUSTOM_map["4.5"] = "H";
    CUSTOM_map["5"] = "I";
    CUSTOM_map["5.5"] = "J";
    CUSTOM_map["6"] = "K";
    CUSTOM_map["6.5"] = "L";
    CUSTOM_map["7"] = "M";
    CUSTOM_map["7.5"] = "N";
    CUSTOM_map["8"] = "O";
    CUSTOM_map["8.5"] = "P";
    CUSTOM_map["9"] = "Q";
    CUSTOM_map["9.5"] = "R";
    CUSTOM_map["10"] = "S";
    CUSTOM_map["10.5"] = "T";
    CUSTOM_map["11"] = "U";
    CUSTOM_map["11.5"] = "V";
    CUSTOM_map["12"] = "W";
    CUSTOM_map["12.5"] = "X";
    CUSTOM_map["13"] = "Y";
    CUSTOM_map["13.5"] = "Z";
    CUSTOM_map["!"] = "!";
    CUSTOM_map[" "] = " ";
    CUSTOM_map["."] = ".";

    //TEMP STRING FOR THE FOR LOOP BELOW
    string temp_agency;
    int array_size = sizeof(cipher_array)/sizeof(*cipher_array);


    //TESTING CODE
    //cout << "array size is : " << array_size << endl;


    //CREATION OF A PLAIN TEXT ARRAY
    string plain_text_array[array_size];


    //TESTING CODE
    //cout << "test 001" << endl;


    //THIS IS HERE BECAUSE WITHOUT IT, IT WILL KEEPS BREAKING
    //I SUSPECT IT HAS TO DO WITH THE LAST STRING IN THE ARRAY BEING A "!" AND SOMETHING TO DO WITH GETLINE
        //if (cipher_array[array_size] == "!" || cipher_array[array_size] == "." || cipher_array[array_size] == " ")
           // cipher_array[array_size] = ",";


    //THIS IS THE DECIPHER PROCESS IN WHICH EVERY ELEMENT IN THE ARRAY IS MAPPED
    for (int z = 0; z < array_size; z++) {
        temp_agency = cipher_array[z];
        plain_text_array[z] = CUSTOM_map.find(temp_agency)->second;
        }


        //COUTS PLAIN TEXT ARRAY (THIS WORKS)
        cout << '\n' << '\n' << "Your plain text is: ";
        for (string p: plain_text_array)
            cout << p;

        cout << "!" <<'\n' << '\n' << endl;

    }



//MAIN MENU FOR THE USER
    int main() {

    bool lightswitch = true;

        while (lightswitch) {



            //MENU


            cout << "This is a decoder." << endl;
            cout << "Press 1 for ROT13 decoder." << endl;
            cout << "Press 2 for ROT6 decoder." << endl;
            cout << "Press 3 for custom decoder." << endl;
            cout << "Press 4 to quit." << endl;
            cout << '\n' << "My option: ";


            //USER INPUTS RESPONSE FOR DECODER
            cin >> input;


            //CHECKS USER'S ANSWERS
            if (input == 1) {
                cout << "This is the ROT13 decoder...please enter your text to decipher:";

                //CLEARS BUFFER AND GRABS ANSWER
                cin.ignore();
                getline(cin, answer);

                //START OF APPROPRIATE DECIPHER COMMAND
                ROT13(answer);

            } else if (input == 2) {
                cout << "This is the ROT6 decoder...please enter your text to decipher:";

                //CLEARS BUFFER AND GRABS ANSWER
                cin.ignore();
                getline(cin, answer);

                //START OF APPROPRIATE DECIPHER COMMAND
                ROT6(answer);

            } else if (input == 3) {
                cout << "This is the CUSTOM decoder...please enter your text to decipher:";

                //CLEARS BUFFER AND GRABS ANSWER
                cin.ignore();
                getline(cin, answer);

                //SETS UP VARIABLES NEEDED FOR LAST CHAR, TO SEE IF WE NEED TO REMOVE IT
                int length = answer.length() -1;
                char last = *answer.rbegin();

                //CHECKS LAST CHAR AND REMOVES IT IF NEEDED
                if (last == '!' || last == '.' || last == ',')
                answer = answer.erase(length);

                //START OF APPROPRIATE DECIPHER COMMAND
                CUSTOM(answer);
            }

            //QUIT OPTION
            else if (input == 4)
            {
                cout << '\n' << "You have chosen to exit the program...goodbye";
                lightswitch = false;
            }

            //FOR INVALID OPTIONS
            else
            {
                cout << '\n' << '\n' << "Sorry, the option you selected was invalid..." << '\n' << '\n';
                break;


            }


            //START OF APPROPRIATE DECIPHER COMMAND


            //ENDS WHILE LOOP
        }

        //END OF MAIN
    }