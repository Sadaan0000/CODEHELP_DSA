#include<iostream>
#include<vector>
using namespace std;

//Runtime PolyMorphism

class Animal{
        public:
        Animal(){
            cout << " i am animal constructor" << endl;
        }
        //use virtual keyword for using parent class constructor 
        virtual void speak() {
            cout << "speaking " << endl;
        }
};

class dog:public Animal{
        public:
        dog(){
            cout << " i am dog constructor" << endl;
        }
        //override 
        void speak(){
            cout << "barking " << endl;
        }
};



int main(){

    //2d array using vector using dynamically created array  
    vector<vector<int> >arr(5,vector<int>(6,0));

    for(int i=0;i<5;i++){
        for(int j=0;j<6;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    //upcasting and downcasting
    // Animal * a=new dog();
    // cout << endl;
    // dog * b=new dog();
    //   cout << endl;
    // Animal * c=new Animal();
    //   cout << endl;
    // dog * d=(dog*)new Animal(); //typecasting
    //   cout << endl;

    // Animal* a= new dog();
    // a->speak();
    // dog d1;
    // d1.speak();

    //printing 2d array using heap memory
    // int row = 5;
    // int col = 3;
     
    // int** arr = new int*[5];

    // for(int i=0;i<row;i++){
    //     arr[i] = new int[col];
    // }

    // //printing
    // for (int i=0;i<row;i++){
    //         for(int j=0;j<col;j++){
    //             cout << arr[i][j] << " ";
    //         }
    //         cout << endl;
    // }



    return 0;
}