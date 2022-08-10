#include <iostream>
#include <string>
#include <vector>
#include <boost/math/special_functions/factorials.hpp>

using namespace std;

//Start of base class which is food item
class Food_Item {

protected:
    string name;
    int calories;
    double fat;
    double protein;
    double carbs;

public:
    Food_Item() {}

    Food_Item(string n, int c, double f, double p, double cb) {
        name = n;
        calories = c;
        carbs = cb;
        protein = p;
        fat = f;
    };

    void coutFoodItem() {

        cout << '\n';
        cout << "Name is: " << name << '\n';
        cout << "Calories are: " << calories << '\n';
        cout << "Carbs are: " << carbs << '\n';
        cout << "Protein is: " << protein << '\n';
        cout << "Fat is: " << fat << '\n';
    }
};


class Reciepe : public Food_Item {

private:
    double servingsize;
    double amountPerServing;
    double caloriesPerServing;

public:
    Reciepe();
    Reciepe(string n, int c, double f, double p, double carbs){
        this->name=n;
        this->calories=c;
        this->carbs=carbs;
        this->protein=p;
        this->fat=f;

        string answer;

        cout << '\n' << "Do you know amount per serving? Y or N: ";
        cin >> answer;
        if (answer == "y" || answer == "Y") {
            cin.clear();
            cout << '\n' << "Amount per serving: ";
            cin >> amountPerServing;
        }

        cout << '\n' << "Do you know the serving size? Y or N: ";
        cin >> answer;
        if (answer == "y" || answer == "Y") {
            cin.clear();
            cout << '\n' << "Serving size: ";
            cin >> servingsize;
        }

    };

    //Calcs calories per serving
    double calculateCaloriePerServing(double totalCalories, double amountPerServing){
        caloriesPerServing = totalCalories/amountPerServing;
        return caloriesPerServing;
    }

    //sets all variables
    void setVariables(string n, int c, double f, double p, double carbs){
        this->name=n;
        this->calories=c;
        this->carbs=carbs;
        this->protein=p;
        this->fat=f;
    }

    void coutReciepe(){

            cout << '\n';
            cout << "Name is: " << name << '\n';
            cout << "Calories are: " << calories << '\n';
            cout << "Carbs are: " << carbs << '\n';
            cout << "Protein is: " << protein << '\n';
            cout << "Fat is: " << fat << '\n';
            cout << "Serving Size is: " << servingsize << '\n';
            cout << "Amount per serving is: " << amountPerServing << '\n';

    }

};

Food_Item ingredient;
vector<Food_Item> Food_List;
vector<Reciepe> Reciepe_List;


//Main cpp file
int main() {

    //The required exeternal libary function
    cout << "External Libary used 7!! , " << tgamma(7) << '\n';

    //Varables needed for responses
    int response, y;
    string x;
    double z, w, k;

    cout << "Hello welcome to the food calculator!" << endl;
    cout << "What would you like to do?" << '\n' << "1) Add food item" << '\n' << "2) Display food item" << '\n' <<"3) Make recipe" << '\n' << "4) Display Recipe" << '\n' <<'\n' << "ANSWER::";

    cin >> response;

    if (response == 1){
        cout << '\n' << '\n' << "What is the name of the Food Item?";
        cin >> x;
        cin.clear();
        cout << '\n' << '\n' << "What are the calories for the Food Item?:";
        cin >> y;
        cin.clear();
        cout << '\n' << '\n' << "What is the carbs for the Food Item?:";
        cin >> z;
        cin.clear();
        cout << '\n' << '\n' << "What is the protein for the Food Item?:";
        cin >> w;
        cin.clear();
        cout << '\n' << '\n' << "What is the fat for the Food Item?:";
        cin >> k;
        cin.clear();

        Food_Item tempFI(x,y,z,w,k);
        Food_List.push_back(tempFI);

        cout << '\n' << "Current Food Items";
        for (int i = 0; i < Food_List.size(); i++)
        {
            Food_List[i].coutFoodItem();
        }
    }

    if (response == 3){
        cout << '\n' << '\n' << "What is the name of the Recipe?";
        cin >> x;
        cin.clear();
        cout << '\n' << '\n' << "What are the calories for the Recipe?";
        cin >> y;
        cin.clear();
        cout << '\n' << '\n' << "What is the carbs for the Recipe?";
        cin >> z;
        cin.clear();
        cout << '\n' << '\n' << "What is the protein for the Recipe?";
        cin >> w;
        cin.clear();
        cout << '\n' << '\n' << "What is the fat for the Recipe?";
        cin >> k;
        cin.clear();

        Reciepe temp(x,y,z,w,k);
        Reciepe_List.push_back(temp);

        cout << '\n' << "Current Reciepes";
        for (int i = 0; i < Reciepe_List.size(); i++)
        {
            Reciepe_List[i].coutReciepe();
        }
    }
    return 0;
}