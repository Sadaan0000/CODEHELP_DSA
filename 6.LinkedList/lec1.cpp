#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->data = 0;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;    
    }
    ~Node(){
       delete next;
    }
};

void printll( Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }

}

int findLength(Node* &head){

    int len=0;
    Node* temp = head;
    while(temp != NULL){
        temp= temp-> next;
        len++;
    }
    return len;
}

void insertAtHead(Node* &head, Node* &tail, int data){
    //check for Empty Linked List
    if(head == NULL){  
        Node* newNode = new Node(data);
        head = newNode;             
        tail = newNode;
        return;
    }
    //cretae a new node
    Node* newNode = new Node(data); 
    //newnode linked to head
    newNode->next= head;  
    //inser newnode at head          
    head = newNode;                 
}

void insertAtTail(Node* &head, Node* &tail, int data){
        //check for Empty Linked List
    if(head == NULL){  
        Node* newNode = new Node(data);
        head = newNode;             
        tail = newNode;
        return;

    }
    //cretae a new node
    Node* newNode = new Node(data); 
    //connect with tail node
    tail->next= newNode;           
    //update tail
    tail = newNode;                 
}

void insertAtPosition(Node* &head, Node* &tail, int data, int pos){
    //check for Empty Linked List
    if(head == NULL){  
        Node* newNode = new Node(data);
        head = newNode;             
        tail = newNode;
        return;
    }
    //find the position: prev and curr
    if(pos == 0){
        insertAtHead(head,tail,data);
        return;
    }

    int len = findLength(head);
    if(pos >= len){
        insertAtTail(head,tail,data);
        return;
    }

    int i=1;
    Node* prev = head;
    while(i<pos){
        prev = prev-> next;
        i++;
    }
    Node* curr = prev -> next;

    //cretae a node
    Node* newNode = new Node(data);
    // connecting curr to newnode
    newNode -> next = curr;
    // connecting previous to newNode
    prev -> next = newNode; 
}

void deleteNode(int pos, Node* &head, Node* &tail){
    if(head == NULL ){
        cout << " Cannot delete LL is empty ";
        return;
    }

    if(pos == 1){
        Node* temp = head;
        head = head -> next;
        temp-> next = NULL;
        delete temp;
        return;
    }

    int len = findLength(head);
    
    //deleting last node
    if ( pos == len ){
        //find prev
        int i = 1;
        Node* prev = head;
        while(i < pos-1 ){
            prev = prev->next;
            i++;
        }
        // prev ke next ko null krdo 
        prev -> next = NULL;
        
        Node* temp = tail;
        
        tail = prev;

        delete temp;
        return;
    }
    
    int i=1;
    Node* prev = head;
    while( i< pos-1){
        prev = prev-> next;
        i++;

    }
    Node* curr = prev -> next;

    prev -> next =curr;

    curr -> next = NULL;

    delete curr;

    return;

}

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head,tail,20);
    insertAtTail(head,tail,60);
    insertAtTail(head,tail,90);

    printll(head);
    cout << endl;
    // cout << "head : "<< head -> data <<endl;
    // cout << "tail: "<< tail -> data <<endl;
    // cout << endl;

    // insertAtPosition(head,tail,101,0);
    // cout << "Printing after insert at position "<< endl;
    // printll(head);
    // cout << endl;
    // cout << "head : "<< head -> data << endl;
    // cout << "tail : "<< tail -> data << endl;
    // cout << endl;

    // insertAtPosition(head,tail,102,4);
    // cout << "Printing after insert at position "<< endl;
    // printll(head);
    // cout << endl;
    // cout << "head : "<< head -> data << endl;
    // cout << "tail : "<< tail -> data << endl;

    deleteNode(1,head,tail);
    // cout << endl;
    printll(head);
    return 0;
}