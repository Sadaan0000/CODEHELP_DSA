#include<iostream>
#include<stack>
using namespace std;

//single stack in one array
class Stack{
public:
    int top;
    int size;
    int *arr;

    // constructor of stack 
    Stack(int size){
        arr = new int[size];
        this -> size = size;
        top = -1;
    }

    //functions
    void push(int data){

        if(size - top > 1){
            //space available
            //insert
            top++;
            arr[top] = data;
        }
        else{
            //space not available
            cout << " Stack Overflow. " << endl;
        }

    }

    void pop(){

        if(top == -1){
            //stack is empty
            cout << " Stack Undeflow. " << endl;
        }
        else{
            //stack is not empty
            top--;
        }
    }

    int getSize(){
        return top + 1;
    }

    int getTop(){
        if(top == -1){
            //stack is empty
            cout << " Stack Undeflow. " << endl;
            return top;
        }
        else{
            //stack is not empty
            return arr[top];
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }

};

//double stack in one array
class Stack2{
    public:
    int top1;
    int top2;
    int size;
    int *arr;

    // constructor of stack 
    Stack2(int size){
        arr = new int[size];
        this -> size = size;
        top1 = -1;
        top2 = size;
    }

    void push1(int data){
        if(top2 -top1 == 1){
            cout << "Stack1 Overflow ..." <<endl;
        }
        else{
            //space available
            top1++;
            arr[top1] = data;
        }
    }

    void push2(int data){
        if(top2 - top1 == 1){
            cout << "Stack2 Overflow ..." <<endl;
        }
        else{
            //space available
            top2--;
            arr[top2] = data;
        }
    }

    void pop1(){
        if(top1 == -1){
            cout << "Stack Underflow ..." << endl;
        }
        else{
            top1--;
        }
    }

    void pop2(){
        if(top2 == size){
            cout << "Stack Underflow ..." << endl;
        }
        else{
            top2--;
        }
    }


};

int main(){
    cout << endl;
    
    // //creation
    // stack<int> st;
    // //insertion
    // st.push(10);
    // st.push(20);
    // st.push(30);
    // st.push(40);
    // st.pop();
    // cout << "elemnet on top " << st.top() << endl;
    // //size
    // cout << st.size() << endl;
    // if(st.empty())
    //     cout << "stack is empty" << endl;
    // else
    //     cout << "stack is not empty " << endl;    
    
    // Stack s(4);
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // s.push(40);
    // // s.push(60);
    // while(! s.isEmpty()){
    //     cout << s.getTop() << endl;
    //     s.pop();
    // }
    // cout << s.getSize() << endl;
    
    return 0;
}