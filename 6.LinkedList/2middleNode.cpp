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

Node* getMiddle(Node* &head){
    //check if LL is empty
    if(head == NULL){
        cout << "LL is empty" << endl;
        return head;
    }
    //check if LL has only 1 node
    if(head -> next == NULL){
        return head;
    }
    // when LL has > 1 node
    Node* slow = head;
    Node* fast = head->next;   //for getting 40 as an answer 
    // Node* fast = head;      //for getting 30 as an answer

    while(slow != NULL && fast != NULL){
        fast = fast-> next;
        if(fast != NULL){
            fast = fast -> next;
            slow = slow -> next;
        }
    }
    return slow;

}


int main(){

    // Node* head = new Node(10);
    // Node* second = new Node(20);
    // Node* third = new Node(30);
    // Node* fourth = new Node(40);
    // Node* fifth = new Node(50);
   
    // head -> next = second;
    // second -> next = third;
    // third -> next = fourth;
    // fourth ->next = fifth;
    // fifth -> next = NULL;
    

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

    cout << "Middle Node is " << getMiddle(head) ->data <<endl;


    return 0;
}