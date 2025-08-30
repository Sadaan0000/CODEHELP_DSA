#include<iostream>
#include<stack>
using namespace std;

void insertSorted(stack<int> &s, int target){
    //base case
    if(s.empty()){
        s.push(target);
        return ;
    }

    if(s.top() >= target){
        s.push(target);
        return;
    }

    int topElement = s.top();
    s.pop();
    insertSorted(s, target);

    s.push(topElement);
}

void sortStack(stack<int> &s){
    //base case
    if(s.empty()){
        return;
    }
    int topElement = s.top();
    s.pop();

    sortStack(s);

    insertSorted(s, topElement);
}

int main(){
    cout << endl;
  
    stack<int> s;
    s.push(3);
    s.push(26);
    s.push(4);
    s.push(39);
    s.push(16);
    s.push(73);
    

    sortStack(s);
    cout << "Printing Stack..." << endl;
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    

    return 0;
}    