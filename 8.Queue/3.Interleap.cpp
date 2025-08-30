#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void InterleapQueue(queue<int> &q){
    //stpe 1: seperate into two halves
    int n = q.size();
    if(q.empty()){
        return;
    }

    int k = n/2;
    int count = 0;
    queue<int> q2;

    while(!q.empty()){
        int temp = q.front();
        q.pop();
        q2.push(temp);
        count++;

        if(count == k){
            break;
        }
    }
    //start interleap

    while(!q.empty() && !q2.empty()){
        int first = q2.front();
        q2.pop();

        q.push(first);

        int second = q.front();
        q.pop();

        q.push(second);
    }
        // odd wala case
        if(n&1){
            int element = q.front();
            q.pop();
            q.push(element); 
        }            

    

}

int main(){
    cout << endl;

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);

    InterleapQueue(q);

    cout << "Printing queue: " << endl;
while(!q.empty()){
    cout << q.front() << " ";
    q.pop();
}

    cout << endl;
    return 0;
}