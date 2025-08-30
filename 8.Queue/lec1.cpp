#include<iostream>
#include<queue>
#include<deque>
using namespace std;

class Queue{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size){
        this->size = size;
        arr = new int(size);
        front = 0;
        rear = 0;
    }

    void push(int data){
        if(rear == size){
            cout << " Q is full" << endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }

    }

    void pop(){
        if (front == rear){
            cout << " Q is empty." << endl;
        }
        else{
            arr[front] = -1;
            front++;
            if(front == rear){
                front = 0;
                rear = 0;
            }
        }
    }

    int getFront(){
        if(front == rear){
            cout << " Q is empty." << endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }
 
    bool isEmpty(){
        if(front == rear){
            return true;
        }
        else{
            return false;
        }
    }

    int getSize(){
        return rear-front;
    }
};

class CirQueue{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    CirQueue(int size){
        this->size = size;
        arr = new int(size);
        front = -1;
        rear = -1;
    }

    void push(int data){
        //Quieue full
        //single element case
        //circular nature
        //normal flow

        if(front == 0 && rear == size-1){
            cout << " Q is full ..." << endl;
        }
        else if(front == -1){
            front = rear = 0;
            arr[rear] = data;
        }
        else if( rear == size-1 && front != 0){
            rear =0;
            arr[rear] = data;
        }
        else{
            rear++;
            arr[rear] = data;
        }
    }

    void pop(){
        //empty check
        //single element
        //circular nature
        //normal flow

        if( front == -1){
            cout << " Q is empty..." << endl;
        }
        else if(front == rear){
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if( front == size - 1){
            front = 0;
        }
        else{
            front++;
        }
    }

};

class DbenQueue{
    public:
    int size;
    int *arr;
    int front;
    int rear;

    DbenQueue(int size){
        this->size = size;
        arr = new int(size);
        front = -1;
        rear = -1;
    }

    void pushRear(int data){
        //Quieue full
        //single element case
        //circular nature
        //normal flow

        if(front == 0 && rear == size-1){
            cout << " Q is full ..." << endl;
            return;
        }
        else if(front == -1){
            front = rear = 0;
           
        }
        else if( rear == size-1 && front != 0){
            rear =0;
            
        }
        else{
            rear++;
            
        }
        arr[rear] = data;
    }

    void pushFront(int data){
        //Quieue full
        //single element case
        //circular nature
        //normal flow

        if(front == 0 && rear == size-1){
            cout << " Q is full ..." << endl;
            return;
        }
        else if(front == -1){
            front = rear = 0;
        }
        else if( front == 0 && rear != size-1 ){
            front = size - 1;
        }
        else{
            front--;
        }
        arr[front] = data;
    }

    void popFront(){
        //empty check
        //single element
        //circular nature
        //normal flow

        if( front == -1){
            cout << " Q is empty..." << endl;
        }
        else if(front == rear){
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if( front == size - 1){
            front = 0;
        }
        else{
            front++;
        }
    }

    void popRear(){
        //empty check
        //single element
        //circular nature
        //normal flow

        if( front == -1){
            cout << " Q is empty..." << endl;
        }
        else if(front == rear){
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if( rear == 0 ){
            rear = size-1;
        }
        else{
            rear--;
        }
    }

};

int main(){
cout << endl;
// queue<int> q;
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(4);
    // cout << "Size of queue : " << q.size() << endl;
    // q.pop();
    // cout << "Size of queue : " << q.size() << endl;
    // (q.empty()) ? printf( "Queue is empty.") : printf("Queue is not empty."); 
    // cout << endl << "Front element : " << q.front() << endl;

    // Queue q(10);

    // q.push(5);
    // q.push(23);
    // q.push(30);
    // q.push(45);

    // cout << "Front Element: " <<q.getFront() << endl;
    // cout << "Size of Queue is: " << q.getSize() << endl;
    // cout << endl;

    // q.pop();
    // cout << "Front Element: "<< q.getFront() << endl;
    // cout << "Size of Queue is: " << q.getSize() << endl;
    // cout << endl;
    
    // q.pop();
    // cout << "Front Element: "<< q.getFront() << endl;
    // cout << "Size of Queue is: " << q.getSize() << endl; 


    deque<int> dq;

    dq.push_back(5);
    dq.push_back(6);
    dq.push_back(7);
    dq.push_back(7);
    dq.push_back(8);
    dq.push_back(9);

    cout << "Front Element: " <<dq.front() << endl;
    cout << "Size of Queue is: " << dq.size() << endl;
    cout << endl;

    dq.pop_front();
    cout << "Front Element: " <<dq.front() << endl;
    cout << "Size of Queue is: " << dq.size() << endl;
    cout << endl;
    
    dq.pop_front();
    cout << "Front Element: " <<dq.front() << endl;
    cout << "Size of Queue is: " << dq.size() << endl;
    cout << endl;

    



cout << endl;
return 0;
}