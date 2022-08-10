#include <iostream>
#include <vector>

using namespace std;



//Abstract classes are good if every subclass a different virtual function
//Abstract BASE class MUST NOT have the virtual function defined



//Base class
class Shape {

protected:
    double area;
    double length = 0, width = 0, height = 0;

public:
    Shape(){}
    void setDeets(double length, double width, double height){
        this->height = height;
        this->length = length;
        this->width = width;
    }

    //THIS VIRTUAL IS VERY IMPORTANT, THERE IS AN OVERRIDE FUNCTION IN THE CHILD CLASS, PLEASE RUN THE CHILD CLASS FIRST
    virtual double getArea(){
        return length * width * height;

    }

};

//SUBCLASS of shape
class Circle: public Shape{

protected:
    double radius;

public:
    void setDeets(double radius){
        this->radius = radius;
    }

    double getArea(){
        return 3.1415 * radius * radius;
    }

};


class Square: public Shape{

public:
    void getDeets(double width, double height){
        this->width = width;
        this->height = height;
        this->length = 1;
    }

    //THERE IS NO GET AREA FUNCTION, SO IT DEFAULTS TO PARENT
    //double getArea() {

    //}

};



int main() {

    Shape shape;
    Circle circle;
    Square square;

    //You might need to remove the cout
    shape.setDeets(5, 5, 5);
    cout << "Shape area: " << shape.getArea() << endl;

    //You might need to remove the cout
    circle.setDeets(5);
    cout << "Circule Area: " << circle.getArea();


    square.setDeets(1,3,7);

    //These are pointers, you need to know this probably
    Shape* sptr = &shape;
    Shape* cptr = &circle;
    Shape* sqptr = &square;

    vector<Shape*> shapelist;
    shapelist.push_back(sptr);
    shapelist.push_back(cptr);
    shapelist.push_back(sqptr);

    //For every shape in shapelist...please run this
    for (Shape* s : shapelist){
        cout << "The area of the shape in list is: " << s->getArea() << endl;
    }



}