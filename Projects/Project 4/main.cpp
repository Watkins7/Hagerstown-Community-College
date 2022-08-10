#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <istream>
#include <chrono>
#include <algorithm>
#include <sstream>

using namespace std;



//CREATED BY: William Atkins
//DATE LAST MODIFIED: 12/11/2019
//PURPOSE: MP3 Player





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
    int songsCreated = 0;
    int endNumberOfSongs = 0;
    int songsOnMixtape = 0;



    //FUNCTRION MEANT TO CREATE A FILE
    void printInfo() {

        //THIS WILL WRITE INFO INTO A FILE CALLED "debuggerFile"
        ofstream debuggerWriteFile;
        debuggerWriteFile.open("debugger.txt");
        debuggerWriteFile << "The number of songs created were: " << songsCreated << '\n';
        debuggerWriteFile << "The end numbers of songs were: " << endNumberOfSongs << '\n';
        debuggerWriteFile << "Number of songs added to mixtape: " << songsOnMixtape << '\n' << '\n';
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



//SONG CLASS HOLDS INFO ABOUT SONGS AND CONTATINS FUNCTIONS NEEDED TO COUT INFO
class song{

//PRIVATE ATTRIBUTES FOR SONG
private:

string name , genre, artist, duration, yearReleased;


//FUNCTIONS FOR SONGS
public:


    //RETURNS NAME OF THE SONG
    string returnSongName(){

        return this->name;
    }





    //RETURNS SONG STATISTICS, COUTS INFO TO SCREEN
    void playSong(){

        cout << '\n';
        cout << "Song name: " << this->name << '\n';
        cout << "Song genre: " << this->genre << '\n';
        cout << "Song artist: " << this->artist << '\n';
        cout << "Song duration: " << this->duration << '\n';
        cout << "Year released: " << this->yearReleased << '\n' << '\n';

    }


    //SETS SONG ATTRIBUTES
    void addSong(string name, string genre, string artist, string duration, string yearReleased){
        this->name = name;
        this->genre = genre;
        this->artist = artist;
        this->duration = duration;
        this->yearReleased = yearReleased;

    }


};





class casettePlayer {

private:

    vector<song> playlist;
    vector<song> musicLibary;

//FUNCTIONS OF cassettePlayer CLASS
public:

    //SONG OBJECT IS ADDED TO PLAYLIST FROM MUSIC LIBARY
    void addPlaylistSong(string addToPlaylist) {

        for (int y =0; y < musicLibary.size(); y++)
        {
            if (musicLibary[y].returnSongName() == addToPlaylist) {
                playlist.push_back(musicLibary[y]);
                cout << '\n' << '\n' << "You have added a song to the playlist" << '\n';
            }
        }


    }


    //SONG OBJECT IS ADDED TO MUSIC LIBARY VECTOR
    void addMusicLibarySong(song addToMusicLibary) {
        cout << '\n' << '\n' << "You have added a song to the music libary." << '\n';
        musicLibary.push_back(addToMusicLibary);
    };


    //SEARCHES THROUGH MUSIC LIBARY AND REMOVES ALL SONGS WITH THAT NAME
    void removePlayListSong(string answer) {

        for (int i = 0; i < playlist.size(); i++) {
            if (playlist[i].returnSongName() == answer) {
                cout << '\n' << "We have located and removed your searched song." << '\n';
                playlist.erase(playlist.begin() + i);
                i--;
            }
        }
    }


    //REMOVES SONG FROM LIBARY
    void removeSongLibary(string name) {

        for (int i = 0; i < musicLibary.size(); i++) {
            if (musicLibary[i].returnSongName() == name) {
                cout << '\n' << "We have located and removed your searched song." << '\n';
                musicLibary.erase(musicLibary.begin() + i);
                i--;
            }
        }
    }



    //SEARCHES THROUGH LIBARY AND PLAYS THE SELECTED SONG
    void playSelectSong(string answer){

        for (int i = 0; i < musicLibary.size(); i++) {
            if (musicLibary[i].returnSongName() == answer)
                musicLibary[i].playSong();

        }
    }


    //GOES THROUGH VECTOR PLAYLIST AND COUTS SONGS
    void playPlaylist() {

        for (int i =0; i < playlist.size(); i++)
        {
            playlist[i].playSong();
        }
    }


    //GOES THROUGH VECTOR MUSIC LIBARY AND COUTS SONGS
    void playAllSongs(){

        for (int i =0; i < musicLibary.size(); i++)
        {
            musicLibary[i].playSong();
        }
    }

};


    int main() {

        //CREATE DEBUGGER OBJECT AND SET STOPWATCH
        Dead_Bug_Debugger gribble;
        gribble.resetStopWatch();


        string answer, songName, songGenre, songArtist, songDuration, songYearReleased;
        int i = 0;
        int y =0;

        casettePlayer CassettePlayer;

        //CREATES BASIC PREMADE SONG OBJECTS
        song Hooked_On_A_Feeling, Go_All_The_Way, Spirit_In_The_Sky, I_Want_You_Back, Come_And_Get_Your_Love, Moonage_Daydream, Fooled_Around_And_Fell_In_Love, Im_Not_In_Love, customSong;

        //SET INFO TO OBJECTS
        Hooked_On_A_Feeling.addSong("Hooked_on_a_Feeling", "Rock/Pop Rock", "Blue Swede", "2.48", "1974");
        Go_All_The_Way.addSong("Go_All_the_Way", "Classic Rock", "Raspberries", "3.18", "1972");
        Spirit_In_The_Sky.addSong("Spirit_in_the_Sky", "Rock", "Norman Greenbaum", "3.59", "1969");
        I_Want_You_Back.addSong("I_Want_You_Back", "Pop/Soul", "Jackson 5", "2.59", "1969");
        Come_And_Get_Your_Love.addSong("Come_and_Get_Your_Love", "Rock", "Redbone", "3.30", "1974");
        Moonage_Daydream.addSong("Moonage_Daydream", "Art Rock", "David Bowie", "4.38", "1972");
        Fooled_Around_And_Fell_In_Love.addSong("Fooled_Around_and_Fell_in_Love", "Rock", "Elvin Bishop", "4.35", "1975");
        Im_Not_In_Love.addSong("I'm_Not_in_Love", "Soft Rock", "10cc", "6.07", "1975");


        //PUTS ALL SONGS IN MUSIC LIBARY VECTOR WHICH IS LOCATED IN THE CLASS
        CassettePlayer.addMusicLibarySong(Hooked_On_A_Feeling);
        CassettePlayer.addMusicLibarySong(Go_All_The_Way);
        CassettePlayer.addMusicLibarySong(Spirit_In_The_Sky);
        CassettePlayer.addMusicLibarySong(I_Want_You_Back);
        CassettePlayer.addMusicLibarySong(Come_And_Get_Your_Love);
        CassettePlayer.addMusicLibarySong(Moonage_Daydream);
        CassettePlayer.addMusicLibarySong(Fooled_Around_And_Fell_In_Love);
        CassettePlayer.addMusicLibarySong(Im_Not_In_Love);


        //WHILE LOOP HOLDS MENU
        while (true) {


            cout << "--------------------------------" << '\n';
            cout << "|                              |" << '\n';
            cout << "| ( ) CASSETTE TAPE PLAYER ( ) |" << '\n';
            cout << "|                              |" << '\n';
            cout << "--------------------------------" << '\n' << '\n';
            cout << "1.)  Create a song." << '\n';
            cout << "2.)  Add song to mixtape" << '\n';
            cout << "3.)  Remove song from mixtape." << '\n';
            cout << "4.)  Play mixtape." << '\n';
            cout << "5.)  Play all songs/tracks." << '\n';
            cout << "6.)  Remove song from Music Libary." << '\n';
            cout << "7.)  Play a certain song." << '\n';
            cout << "8.)  Exit Program." << '\n' << '\n';
            cout << "What would you like to do?: ";


            //SANITIZE INPUT, GETS ANSWER, AND SETS NEW LINES
            cin.clear();

            cin >> answer;



            //IF STATEMENTS BASED ON STATEMENTS
            if (answer == "1" || answer == "one" || answer == "One" || answer == "ONE") {

                cout << '\n'
                     << "Enter song name, genre, artist, duration, and year released.  Separate each answer with a space."
                     << '\n';
                cout << "Answer: ";




                cin >> songName >> songGenre >> songArtist >> songDuration >> songYearReleased;

                //ADDS CUSTOM SONG TO A VECTOR
                customSong.addSong(songName, songGenre, songArtist, songDuration, songYearReleased);
                CassettePlayer.addMusicLibarySong(customSong);


                //UPS SONGS CREATED TALLY
                gribble.songsCreated++;

            }


            //ADD SONGS TO MIXTAPE
            if (answer == "2" || answer == "two" || answer == "TWO" || answer == "Two") {
                cout << '\n' << "Name of song to be added to mixtape: ";
                cin >> answer;

                CassettePlayer.addPlaylistSong(answer);

                gribble.songsOnMixtape++;

            }


            //REMOVE SONG FROM PLAYLIST
            if (answer == "3" || answer == "three" || answer == "THREE" || answer == "Three") {
                cout << '\n' << "Please type the name of the song you would like to remove from the playlist: ";
                cin >> answer;

                CassettePlayer.removePlayListSong(answer);

                gribble.songsOnMixtape--;

            }


            //PLAY PLAYLIST/MIXTAPE
            if (answer == "4" || answer == "four" || answer == "FOUR" || answer == "Four") {

                CassettePlayer.playPlaylist();

            }


            //PLAY ALL SONGS IN MUSIC LIBARY
            if (answer == "5" || answer == "five" || answer == "FIVE" || answer == "Five") {

                CassettePlayer.playAllSongs();

            }


            //REMOVE SONG FROM SONG LIBARY
            if (answer == "6" || answer == "six" || answer == "SIX" || answer == "Six") {

                cout << '\n' << "Please type the name of the song you would like to remove from the Music Libary: ";
                cin >> answer;

                CassettePlayer.removeSongLibary(answer);

                gribble.songsCreated--;

            }


            //PLAYS A SELECT SONG
            if (answer == "7" || answer == "seven" || answer == "SEVEN" || answer == "Seven") {

                cout << '\n' << "Please type the name of the song you want to play: ";
                cin >> answer;

                CassettePlayer.playSelectSong(answer);

            }


            //QUITS PROGRAM AND WRITES INFO TO DEBUGGER
            if (answer == "8" || answer == "eight" || answer == "EIGHT" || answer == "Eight") {

                    cout << "You are exiting the program...goodbye" << '\n';

                //CALLS THE FUNCTION THAT WILL OUTOUT FUNCTION INFO INTO A FILE
                gribble.printInfo();

                //CALLS THE FUNCTION THAT WILL COUT FILE
                gribble.callFile();

                break;

            }


            cout << '\n' << '\n';

        }
}

