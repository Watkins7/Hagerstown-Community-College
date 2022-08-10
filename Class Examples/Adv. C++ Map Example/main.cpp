#include <iostream>
#include <map>
#include <vector>


using namespace std;

int main() {

    map <int, char> mappy = {
            {1, 'c'},
            {2, 'b'},
            {3, 'a'}
    };


    //THIS DOES NOT WORK!!!!!!
    //for(int i=0; i < mappy.size(); i++)
    //{
   //     cout << i.first;
   // }


string cheese = "";
vector<string> stringVEC;
stringVEC.push_back("yee");
stringVEC.push_back("yee ha");



    for (auto a : stringVEC)
    {
        cheese = a;
    }

cout << cheese << endl;






//Add an & behind string to pass by refrence
    for (string& e : stringVEC)
    {
        cheese = e;
    }

    cout << cheese << endl;



    for (pair<int, char> m : mappy)
    {
        cout << m.second << endl;
    }


   for (auto &m : mappy)
   {
       cout << m.first << endl;
   }








    //code is identicatl to the one below
    for(auto it = mappy.begin(); it != mappy.end(); it++)
    {
        cout << it->first << it->second << endl;
    }



    for(map<int, char>::iterator it = mappy.begin(); it != mappy.end(); it++)
    {
    cout << it->first << it->second << endl;
    }



    return 0;
}