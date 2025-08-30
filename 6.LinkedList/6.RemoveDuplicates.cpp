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
        
    }
};

void print( Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* removeDuplicates(Node* &head){
    if( head == NULL){
        cout <<" ll is empty" << endl;
        return NULL;
    }
    if(head->next == NULL){
        cout << " single ll " << endl;
        return NULL;
    }
    // gretaer than 1 node

    Node* curr = head;
    while(curr != NULL){
        if(( curr -> next != NULL ) && ( curr -> data == curr -> next -> data )){
            //equal
            Node* temp = curr ->next;
            curr -> next = curr -> next -> next;
            //deleting standalone node
            temp->next = NULL;
            delete temp;
        }
        else{
            //not equal
            curr = curr->next; 
        }
    }
    
}

int main(){
    cout << endl;

    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(20);
    Node* fourth = new Node(30);    
    Node* fifth = new Node(40);
    Node* sixth = new Node(40);
    // Node* seventh = new Node(70);
    // Node* eighth = new Node(80);
    // Node* ninth = new Node(90);

    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth ->next = fifth;
    fifth -> next = sixth;
    // sixth ->next = seventh;
    // seventh -> next = eighth;
    // eighth-> next = ninth;
    // ninth-> next = fifth;

    print(head);
    cout << endl;

    removeDuplicates(head);
    print(head);
    cout << endl;

return 0;
}