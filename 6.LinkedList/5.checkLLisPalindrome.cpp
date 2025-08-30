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

Node* reverse(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* temp = curr->next;
    while(curr != NULL){
        temp = curr->next;
        curr->next=prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

bool checkPalindrome(Node* &head){
    if(head == NULL ){
        cout << " " << endl;
        return false;
    }
    if(head ->next == NULL){
        return true;
    }
    // find the middle node
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    // slow pointer is now pointing to middle node
    // reverse LL after the middle node
    Node* reverseLLkaHead = reverse(slow->next);

    slow->next = reverseLLkaHead;

    // start comaprison
    Node* temp1 = head;
    Node* temp2 = reverseLLkaHead;
    while(temp2 != NULL){
        if(temp1->data != temp2->data){
            return false;
        }
        else{
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    return true;
}

int main(){
    cout << endl;

    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(30);    
    Node* fifth = new Node(20);
    Node* sixth = new Node(10);
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

    bool isPalindrome = checkPalindrome(head);

    if(isPalindrome){
        cout << " LL is a Valid Paindrome." << endl;
    }
    else{
        cout << " LL is not a valid Palindrome" << endl;
    }

    return 0;
}
