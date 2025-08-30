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

Node* reverseKNodes(Node* &head,int k){

    if(head==NULL){
        cout << " LL is empty ." << endl;

        
        return NULL;
    }
    int len = findLength(head);
    if(k > len){
        // cout << " Enter correct value of k . " << endl;
        return head;
    }
    // no of nodes in LL is >= k

    //step 1: reverse first k nodes of ll

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr -> next;
    int count = 0;

    while(count < k){
        forward = curr->next;
        curr->next=prev;
        prev = curr;
        curr =forward;
        count++;
    }
    //recursive call
    if(forward != NULL){ //we still have nodes left to reverse
        head -> next = reverseKNodes(forward ,k);
    }
    //return head of previous LL
    return prev;
}


int main(){

Node* head = new Node(10);
Node* second = new Node(20);
Node* third = new Node(30);
Node* fourth = new Node(40);
Node* fifth = new Node(50);
Node* sixth = new Node(60);

head -> next = second;
second -> next = third;
third -> next = fourth;
fourth ->next = fifth;
fifth -> next = sixth;
sixth ->next= NULL;

print(head);
cout << endl;

head = reverseKNodes(head,4);
print(head);

return 0;
}