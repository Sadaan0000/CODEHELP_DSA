#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom2(stack<int> &s, int target){
    //base case
    if(s.empty()){
        s.push(target);
        return;
    }
    int topElement = s.top();
    s.pop();
    //recursive call
    insertAtBottom2(s,target);
    //BackTracking
    s.push(topElement);
}

void reverse(stack<int> &s){
    //base case
    if(s.empty()){
        return;
    }

    //finding target
    int target = s.top();
    s.pop();

    //reverse stack 
    reverse(s);

    //insert at bottom target ko
    insertAtBottom2(s,target);
}

int main(){
cout << endl;

    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    reverse(s);

    cout << "Printing Stack..." << endl;
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
    

    return 0;
}