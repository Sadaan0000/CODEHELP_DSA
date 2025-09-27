#include<iostream>
#include<queue>
#include<deque>
using namespace std;

class CirQueue{
    public:
    int size;
    int *arr;
    int front;
    int rear;

    CirQueue(int size){
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }    

    void push(int data){
        // queue full
        //single element case
        //circular nature
        //normal flow        

        if(front == 0 && rear == size-1 || front == (rear + 1) % size){
            cout << " Queue is full and cannot insert item.." << endl;
        }
        else if(front == -1 ){
            front = rear = 0;
            arr[rear] = data;
        }
        else if( rear == size-1 && front != 0 ){
            rear = 0;
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
        
        if ( front == -1 ){
            cout << " Queue is empty.." << endl;
        }
        else if( front == rear ){
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if( front == size-1 ){
            front = 0;
        }
        else{
            front++;
        }
    }    
};

class DoublyEndedQueue{
    public:
    int size;
    int *arr;
    int front;
    int rear;

    DoublyEndedQueue(int size){
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void pushRear(int data){
        // queue full
        //single element case
        //circular nature
        //normal flow        

        if(front == 0 && rear == size-1 || front == (rear + 1) % size){
            cout << " Queue is full and cannot insert item.." << endl;
            return;
        }
        else if(front == -1 ){
            front = rear = 0;
        }
        else if( rear == size-1 && front != 0 ){
            rear = 0;
        }
        else{
            rear++;
        }
    }

    void pushFront(int data){
        // queue full
        //single element case
        //circular nature
        //normal flow        

        if(front == 0 && rear == size-1 || front == (rear + 1) % size){
            cout << " Queue is full and cannot insert item.." << endl;
        }
        else if(front == -1 ){
            front = rear = 0;
            
        }
        else if( front == 0 && rear != size-1 ){
            front = size -1 ;
            
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
        
        if ( front == -1 ){
            cout << " Queue is empty.." << endl;
        }
        else if( front == rear ){
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if( front == size-1 ){
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
        
        if ( front == -1 ){
            cout << " Queue is empty.." << endl;
        }
        else if( front == rear ){
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if( rear == 0 ){
            rear = size - 1;
        }
        else{
            rear--;
        }
    }    

};

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << "Size of queue : " << q.size() << endl;
    (q.empty()) ? printf( "Queue is empty.") : printf("Queue is not empty."); 
    cout << endl << "Front element : " << q.front() << endl;    
    return 0;
}