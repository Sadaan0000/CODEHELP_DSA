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

void print( Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

//1st Approach function using count of 0 1 2 
void sort012(Node* &head){
    // find count of zeroes ones nad twos
    int zero = 0, one = 0, two = 0;
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == 0)
            zero++;
        else if(temp->data == 1)
            one++;
        else if(temp->data == 2)
            two++;
        temp = temp->next;            
    }
    // fill 0 1 2 in the original LL
    temp = head;
    
        //fill zeroes
        while(zero--){
            temp->data = 0;
            temp = temp -> next;
        }
        //fill one
        while(one--){
            temp->data = 1;
            temp = temp->next;
        }
        //fill two 
        while(two--){
            temp->data = 2;
            temp = temp->next;
        }
    
}

//2nd Approach function using Pyaari 
Node* sort2Sadaan(Node* &head){
    if(head == NULL) {
        cout << "LL is empty " << endl;
        return NULL;
    }
    if(head -> next == NULL) {
        //sngle node in LL
        return head;
    }
    
    //create dummy nodes
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    // traverse the origianl LL
    Node* curr = head;
    while( curr != NULL){
        if(curr->data == 0){
            //takes out the zero wali node
                Node* temp = curr;
                curr = curr->next;
                temp->next = NULL;

            //append the zero node in zeroHead LL
                zeroTail->next = temp ;
                zeroTail = temp;
        }
        else if(curr->data == 1){
            //takes out the zero wali node
                Node* temp = curr;
                curr = curr->next;
                temp->next = NULL;

            //append the zero node in zeroHead LL
                oneTail->next = temp ;
                oneTail = temp;
        }
        else if(curr->data == 2){
            //takes out the zero wali node
                Node* temp = curr;
                curr = curr->next;
                temp->next = NULL;

            //append the zero node in zeroHead LL
                twoTail->next = temp ;
                twoTail = temp;

        }
    }
    // now all three linked list are ready
    // join them
    //remove the dummy nodes
    //modify one wali list
    Node* temp = oneHead;
    oneHead = oneHead->next;
    temp->next = NULL;
    delete temp;
    
    //modify two wali list
    temp = twoHead;
    twoHead = twoHead->next;
    temp->next = NULL;
    delete temp;

    //join list
    if(oneHead != NULL){
        //one wali list is non-empty
        zeroTail->next = oneHead;
        if(twoHead != NULL){
            oneTail->next = twoHead;
        }
    }
    else{
        //one list is empty
        if(twoHead != NULL){
            zeroTail->next = twoHead;
        }
    }

    //remove zeroHead dummy node
    temp = zeroHead;
    zeroHead = zeroHead->next;
    temp->next = NULL;
    delete temp;

    //return head of modified linked list
    return zeroHead;

}

//Love babbar code 
Node* sort2(Node* &head) {
    if(head == NULL) {
            cout << "LL is empty " << endl;
            return NULL;
    }
    if(head -> next == NULL) {
            //sngle node in LL
            return head;
    }

    //create dummy nodes
    Node* zeroHead = new Node(-101);
    Node* zeroTail = zeroHead; 

    Node* oneHead = new Node(-101);
    Node* oneTail = oneHead; 

    Node* twoHead = new Node(-101);
    Node* twoTail = twoHead; 

    //traverse the original LL
    Node* curr = head;
    while(curr != NULL) {

            if(curr -> data == 0) {
                    //take out the zero wali node
                    Node* temp = curr;
                    curr = curr -> next;
                    temp -> next = NULL;

                    //append the zero node in zeroHead LL
                    zeroTail -> next = temp;
                    zeroTail = temp;

            }
            else if(curr -> data == 1) {
                    //take out the one wali node
                    Node* temp = curr;
                    curr = curr -> next;
                    temp -> next = NULL;

                    //append the zero node in zeroHead LL
                    oneTail -> next = temp;
                    oneTail = temp;

            }
            else if(curr -> data == 2) {
                    //take out the zero wali node
                    Node* temp = curr;
                    curr = curr -> next;
                    temp -> next = NULL;

                    //append the zero node in zeroHead LL
                    twoTail -> next = temp;
                    twoTail = temp;

            }
    }

    //ab yha pr, zero , one, two, teeno LL readyv h 

    // join them 
    //remove dummmy nodes

    //modify one wali list
    Node* temp = oneHead;
    oneHead = oneHead -> next;
    temp -> next = NULL;
    delete temp;

    //modify two wali list
    temp = twoHead;
    twoHead = twoHead -> next;
    temp -> next = NULL;
    delete temp;

    //join list
    if(oneHead != NULL) {
            // one wali list is non empty
            //zero wali list ko one wali list se attach krdia 
            zeroTail -> next = oneHead;
            
            if(twoHead != NULL)
                    oneTail -> next = twoHead;
    }
    else{
            //one wali list is empty
            if(twoHead != NULL)
                    zeroTail -> next = twoHead;
    }

    //remove zerohead dummy Node
    temp = zeroHead;
    zeroHead = zeroHead -> next;
    temp -> next = NULL;
    delete temp;
    
    //return head of the modified linked list
    return zeroHead;

}

int main(){
    cout << endl;

    Node* head = new Node(2);
    Node* second = new Node(2);
    Node* third = new Node(2);
    Node* fourth = new Node(2);    
    Node* fifth = new Node(0);
    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth ->next = fifth;
    
    print(head);
    cout << endl;

    cout << "printing the sorted list: " << endl;
    Node* temp = NULL;

    // head = sort012(head);
    // head = sort2Sadaan(head);
    // head = sort2(head);

    print(head);
    
    cout << endl;
    return 0;
}