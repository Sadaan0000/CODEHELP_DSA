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
};

void print( Node* &head){
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

Node* reverse(Node* &prev, Node* &curr){
    //base case
    if(curr==NULL){
        //LL reversed ho chuki hai 
        return prev;
    }
    //1 case solve then recursion will take care
    Node* forward = curr -> next;
    curr -> next = prev;

    return reverse(curr, forward);
}

Node* reverseUsingLoop(Node* &head){
    Node* prev = NULL;
    Node* curr = head;    
    Node* temp = curr-> next;
    while(curr != NULL){
        curr ->next = prev;
        prev = curr;
        curr = temp; 
    }
    return prev;
}

Node* reverseUsingRecursion(Node* prev, Node* curr){
    if(curr== NULL)
        return prev;
    
    Node* temp = curr-> next;
    curr ->next = prev;
    prev = curr;
    curr = temp; 

    return reverseUsingRecursion(prev, curr);
}

int main(){

    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head,tail,20);
    insertAtTail(head,tail,60);
    insertAtTail(head,tail,70);
    insertAtTail(head,tail,80);
    insertAtTail(head,tail,90);

    print(head);
    cout << endl;
    
    Node* prev = NULL;
    Node* curr = head;
    head = reverse(prev, curr);
    print(head);

    cout << endl;

    head = reverseUsingLoop(head);
    print(head);

    cout << endl;

    head = reverseUsingRecursion(prev, curr);
    print(head);
    
    return 0;
}