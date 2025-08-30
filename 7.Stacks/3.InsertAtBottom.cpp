#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &s, int target){
    //base case
    if(s.empty()){
        s.push(target);
        return;
    }
    int topElement = s.top();
    s.pop();
    //recursive call
    solve(s,target);
    //BackTracking
    s.push(topElement);
}

void insertAtBottom(stack<int> &s){
    if(s.empty()){
        cout << " Stack is empty .." << endl;
        return;
    }
    int target = s.top();
    s.pop();
    solve(s,target);
}

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

int main(){
cout << endl;

    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    
    if(s.empty()){
        cout << " Stack is empty .." << endl;
    }
    int target = s.top();
    s.pop();
    

    // insertAtBottom(s);
    insertAtBottom2(s,target);

    cout << "Printing Stack..." << endl;
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}