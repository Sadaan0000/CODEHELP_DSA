#include<iostream>
#include<stack>
using namespace std;

// class Stack{
//     public:

//     int *arr;
//     int size;
//     int top;

//     Stack(int size){
//         arr = new int[size];
//         this->size = size;
//         top = -1;
//     }

// }

class Stack {
    public:
    int top1;
    int top2;
    int size;
    int *arr;

    Stack(int size){
        arr = new int[size];
        this->size = size;
        this->top1 = -1;
        this->top2 = size;
    }

    void push1(int data){
        if( top2 - top1 == 1 ){
            //space not available
            cout << " stack Overflow" << endl;
        }
        else{
            // space available
            top1++;
            arr[top1] = data;
        }
    }

    void pop1(){
        // stack empty
        if( top1 == -1 ){
            cout << " Stack Underflow.." << endl;
        }
        else{
            top1--;
        }
    }
    
    void push2( int data ){
        if( top2 - top1 == 1 ){
            cout << " stack Overflow " << endl;
        }
        else{
            // space available 
            top2--;
            arr[top2] = data;
        } 
    }

    void pop2(){
        //stack empty 
        if ( top2 == size ){
            cout << " Stack Underflow.. " << endl;
        } 
        else{
            //stack not empty
            top2++;
        }
    }
};

int main(){

    Stack s(10);

    s.push1(1);
    s.push2(2);
    s.push1(3);
    s.push2(4);

    // while(top1 != -1){
    //     cout << s.top1() << endl;
    //     s.pop1();
    // }

    return 0;
}