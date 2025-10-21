#include<iostream>
using namespace std;

class Animal{
        public:
            int age;
            int weight;

            
};

//Inheritance syntax
class dog:private Animal {

        public: 
        void print(){
            cout << this->age;
        }
};

class Car{

    public:
    string name;
    int weight;
    int age;

    void speedUp(){
        cout << " speeding up" << endl;
    }
    void breakMaaro(){
        cout << " break apply" << endl;
    }
};

class Safari:public Car{

};

class A{
        public:
        int chemistry;
        A(){
            chemistry = 111;
        }
};

class B{
        public:
        int chemistry;
        B(){
            chemistry = 222;
        }
};

class C:public A,public B{
    public:
    int maths;
};

class  Maths{
        public:

        int sum(int a,int b){
            return a+b;
        }
        int sum(int a,float b){
            return a+b+10;
        }
         int sum(int a,int b,int c){
            return a+b+c;
        }
};

class Parameter{
        public:
        int val;

        void operator+(Parameter& obj2){
                int value1 = this->val;
                int value2 = obj2.val;
                cout << (value2-value1) << endl;
        }
};

int main(){

    Parameter obj1,obj2;
    obj1.val = 7;
    obj2.val = 2;

    //this shold print the difference between them 
    obj1 + obj2;

    // Maths obj;
    // cout << obj.sum(10,12.01);   
                  
    // C obj;
    // cout << " " << obj.A::chemistry << " " << obj.maths << endl;
    // cout << " " << obj.B::chemistry << " " << obj.maths << endl;

    // Safari future;
    // future.speedUp();  
    // future.breakMaaro();

    // dog d1;
    // d1.print();
    // d1.print();


    return 0;
}