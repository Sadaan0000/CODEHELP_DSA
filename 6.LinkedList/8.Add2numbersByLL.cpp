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

Node* solve(Node* &head1, Node* &head2){
    
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }

    //step1 : reverse both LL
    head1 = reverse(head1);
    head2 = reverse(head2);

    //step2 : add both linked list
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    int carry = 0;

    while( head1 != NULL && head2 != NULL){

        // calculate sum
        int sum = carry + head1->data + head2->data;
        //find digit to create node 
        int digit = sum % 10;
        //calculate carry 
        carry = sum / 10;

        //create a new node for the digit
        Node* newNode = new Node(digit);
        //attach the new node to the answer wali ll
        if( ansHead == NULL ){
            //first node insert krrhe ho 
            ansHead = newNode;
            ansTail = newNode;
        }
        else{
            ansTail -> next = newNode;
            ansTail = newNode;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    //jab head1 list ki length head2 list ki length se zyada hoga 
    while( head1 != NULL){
        int sum = carry +head1->data;
        int digit = sum % 10;
        carry = sum / 10; 

        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
        head1 = head1->next;
    }

    //jab head2 list ki length head1 list ki length se zyada hoga 
    while( head2 != NULL){
        int sum = carry + head2->data;
        int digit = sum % 10;
        carry = sum / 10; 

        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
        head2 = head2->next;
    }

    //handle carry alag se 
    while(carry != 0){
        int sum = carry;
        int digit = sum % 10;
        carry = sum / 10;

        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
    }

    //step3 : reverse both linked list
    ansHead = reverse(ansHead);
    return ansHead;

}

int main(){
cout << endl;

    Node* head1 = new Node(9);
    Node* second1 = new Node(9);
    Node* third1 = new Node(9);
    head1->next = second1;
    second1->next = third1;

    Node* head2 = new Node();
    Node* second2 = new Node();
    Node* third2 = new Node();
    head2->next = second2;
    second2->next = third2;

    Node* answer = solve(head1, head2);
    print(answer);

cout << endl;
return 0;
}