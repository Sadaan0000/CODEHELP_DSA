#include<iostream>
using namespace std;

class animal{
   //state or properties

private:
int weight;

public: //access modifier
int age;
string name;

//behaviour
void eat(){ //member functions
    cout << " ramesh is eating " << endl;
}
void sleep(){
    cout << " ramesh is sleeping " << endl;
}

int getWeight(){
    return weight;
}
void setWeight(int w){
    weight = w;
}

// default constructor
animal(){
   
    this->weight = 0;
    this->age = 0;
    this->name = "";
    cout << " constructor called" << endl;
    
}

//paramaterized constructor
animal(int age){
    this->age = age;
    cout << " paramaterized constructor called" << endl;
}

};

int main(){
    
    //object creation
    //static
    // animal ramesh;
    // ramesh.age = 12;       
    // ramesh.name = "lion";
    // cout << " age of ramesh is: " << ramesh.age << endl;
    // cout << " name of ramesh is: " << ramesh.name << endl;
    // ramesh.eat();
    // ramesh.sleep();

    // ramesh.setWeight(101);
    // cout << " ramesh weight: " << ramesh.getWeight() << endl;

// dynamic memory 

// animal* suresh = new animal;
// (*suresh).age = 15;
// (*suresh).name = " billi ";

// //alternate dynamic memory
// suresh->age = 15;
// suresh->name = " billi ";

animal a(10);
animal* b = new animal(10);

    return 0;
}