#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverse(queue<int> &q){
    stack<int> s;
    
    // push elements of q into stack 
    while(!q.empty()){    
        int element = q.front();
        q.pop();

        s.push(element);
    }
    // push elements form stack into queue
    while (!s.empty()){
        int element = s.top();
        s.pop();

        q.push(element);
    }
    
}

void revrseQueueRecursion(queue<int> &q){
    //base case
    if(q.empty()){
        return;
    }
    // step 1
    int temp =q.front();
    q.pop();

    // step 2
    revrseQueueRecursion(q);

    // step 3
    q.push(temp);
}


int main(){
// cout << endl;

queue<int> q;

q.push(3);
q.push(4);
q.push(1);
q.push(8);
q.push(9);

// cout << "Printing queue: " << endl;
// while(!q.empty()){
//     cout << q.front() << " ";
//     // q.pop();
// }
// cout << endl;

reverse(q);

cout << "Printing queue: " << endl;
while(!q.empty()){
    cout << q.front() << " ";
    q.pop();
}
cout << endl;
    return 0;
}