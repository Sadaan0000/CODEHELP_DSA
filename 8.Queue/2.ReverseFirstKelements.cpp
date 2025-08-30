#include<iostream>
#include<queue>
#include<stack>
using namespace std;

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

void reverseK(queue<int> &q, int k){
    
    // 1: queue ->k elements -> stack 
    stack<int> s;
    int count =0;
    int n = q.size();

    if( k <= 0 || k > n){
        return;
    }

    while(!q.empty()){
        int temp = q.front();
        q.pop();
        s.push(temp);
        count++;

        if(count == k){
            break;
        }
    }
    //step 2 : stack se q mein wapas 
    while(!s.empty()){
        int temp = s.top();
        s.pop();
        q.push(temp);
    }

    // step 3: push n-k elements from q front to back 
    count = 0;
    while(!q.empty() && n-k != 0){
        int temp = q.front();
        q.pop();
        q.push(temp);
        count++;
        if(count == n - k){
            break;
        }
    }
}

int main(){
    cout << endl;

    queue<int> q;

    q.push(3);
    q.push(4);
    q.push(1);
    q.push(8);
    q.push(9);

    reverseK(q , 2);

cout << "Printing queue: " << endl;
while(!q.empty()){
    cout << q.front() << " ";
    q.pop();
}

    cout << endl;
    return 0;
}