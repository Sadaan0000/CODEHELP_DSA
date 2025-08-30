#include<iostream>
using namespace std;

//DOUBLY LINKED LIST
class Node{
        public:
        int data;
        Node* prev;
        Node* next;
    Node(){
        this-> data =0;
        this-> prev = NULL;
        this-> next = NULL;    
    }
    Node(int data){
        this-> data = data;
        this-> prev = NULL;
        this-> next = NULL; 
    }
    ~Node(){
       
    }
};

void print(Node* &head){

    Node* temp = head;

    while(temp != NULL ){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

int getLength(Node* &head){
    int len = 0;
    Node* temp = head;
    while( temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtHead( Node* &head, Node* &tail, int data ){

    if(head == NULL ){
        Node* newnode = new Node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    else{

        Node* newnode = new Node(data);
        newnode ->next = head;
        head->prev = newnode;
        head = newnode;

    }
    return;
}

void insertAtTail( Node* &head, Node* &tail, int data ){

    if(head == NULL ){
        Node* newnode = new Node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    else{

        Node* newnode = new Node(data);
        tail ->next = newnode;
        newnode->prev = tail;
        tail = newnode;

    }
    return;
}

void insertAtPosition( Node* &head, Node* &tail, int data , int pos){

    if(head == NULL ){
        Node* newnode = new Node(data);
        head = newnode;
        tail = newnode;
        return;
    }
   
    if (pos == 1 ){
        insertAtHead(head,tail,data);
        return;
    }    

    int len = getLength(head);

    if(pos > len){
        insertAtTail(head,tail,data);
        return;
    }

    //insertion in middle
    int i=1;
    Node* prevNode = head;
    while( i< pos-1){
        prevNode = prevNode-> next;
        i++;
    }
    Node* curr = prevNode->next;

    Node* newnode = new Node(data);
    prevNode->next = newnode;
    newnode -> prev = prevNode;
    curr -> prev  = newnode;
    newnode -> next = curr;

    // Node* newnode = new Node(data);
    // prevNode-> next->prev = newnode;
    // newnode-> next = prevNode-> next;
    // prevNode->next = newnode;
    // newnode -> prev = prevNode;
}

void deleteFromPosition(Node* &head, Node* tail, int position){

    if(head == NULL ){
        cout << "Linked list is empty"<<endl;
        return;
    }
    if(head->next == NULL ){
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }
    int len = getLength(head);
    if(position > len){
        cout << " Please enter a valid length " << endl;
        return;
    }
    if( position == 1 ){

        Node* temp = head;
        head = head -> next;
        head -> prev = NULL;
        temp -> next = NULL;
        delete temp;
        return;
    }
    // int len = getLength(head);

    if(position == len){
        //delete last node

        Node* temp = tail;
        tail = tail -> prev;
        temp -> prev = NULL;
        tail -> next = NULL;
        delete temp;
        return;
    }

    //delete in middle position
    int i=1;
    Node* left = head; 
    while(i < position-1){
            left = left -> next;
            i++;
    }
    Node* curr = left -> next;
    Node* right = curr -> next;
    
    left -> next = right;
    right -> prev = left;
    curr -> next = NULL;
    curr -> prev = NULL;
    delete curr;
    return ;

}

int main(){
   
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* head = first;
    Node* tail = third;

    first -> next= second;
    second -> prev = first;

    second -> next = third;
    third -> prev = second;

    insertAtHead(head,tail,100);
    // print(head);
    
    // cout << endl;

    insertAtTail(head,tail,101);
    // print(head);

    // cout << endl;

    insertAtPosition(head,tail,150,5);
    print(head);
    cout << endl;

    deleteFromPosition(head,tail,7);
    print(head);

    return 0;
}