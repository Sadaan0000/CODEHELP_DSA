#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

class DoublyLinkedList {

private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Destructor: frees memory for all nodes
    ~DoublyLinkedList() {
        Node* temp = head;
        while (temp != NULL) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        cout << "Doubly linked list destroyed\n";
    }

    // Get length of the list
    int getLength() {
        int len = 0;
        Node* temp = head;
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    // Print the list
    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Insert at head
    void insertAtHead(int data) {
        Node* newnode = new Node(data);
        if (head == NULL) {
            head = tail = newnode;
        } else {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }

    // Insert at tail
    void insertAtTail(int data) {
        Node* newnode = new Node(data);
        if (head == NULL) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }

    // Insert at a given position
    void insertAtPosition(int position, int data) {
        if (position <= 1) {
            insertAtHead(data);
            return;
        }

        int len = getLength();
        if (position > len) {
            insertAtTail(data);
            return;
        }

        Node* temp = head;
        int count = 1;
        while (count < position - 1) {
            temp = temp->next;
            count++;
        }

        Node* newnode = new Node(data);
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next->prev = newnode;
        temp->next = newnode;
    }

    // Delete from a position
    int deleteFromPosition(int position) {
        if (head == NULL) {
            cout << "Linked list is empty" << endl;
            return -1; // sentinel value
        }

        int len = getLength();
        if (position < 1 || position > len) {
            cout << "Invalid position" << endl;
            return -1; // sentinel value
        }

        int deletedValue;

        // Case 1: only one node
        if (head->next == NULL) {
            deletedValue = head->data;
            delete head;
            head = tail = NULL;
            return deletedValue;
        }

        // Case 2: delete head
        if (position == 1) {
            Node* temp = head;
            deletedValue = temp->data;
            head = head->next;
            head->prev = NULL;
            temp->next = NULL;
            delete temp;
            return deletedValue;
        }

        // Case 3: delete tail
        if (position == len) {
            Node* temp = tail;
            deletedValue = temp->data;
            tail = tail->prev;
            tail->next = NULL;
            temp->prev = NULL;
            delete temp;
            return deletedValue;
        }

        // Case 4: delete in middle
        int i = 1;
        Node* left = head;
        while (i < position - 1) {
            left = left->next;
            i++;
        }
        Node* curr = left->next;
        Node* right = curr->next;

        deletedValue = curr->data;
        left->next = right;
        right->prev = left;
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;

        return deletedValue;
    }
    
    //Reversing a linked list 
    void reverse(){
        Node* curr = head;
        Node* temp = NULL;

        // Swap prev and next for every node
        while (curr != NULL) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev; // move to "next" node (was prev before swap)
        }

        // Update head and tail
        if (temp != NULL) {
            tail = head;
            head = temp->prev;
        }
    }



};

int main() {
    DoublyLinkedList dll;

    dll.insertAtHead(10);
    dll.insertAtTail(20);
    dll.insertAtTail(30);

    
    dll.print();

    dll.insertAtHead(5);
    dll.print();

    dll.insertAtTail(40);
    dll.print();

    dll.insertAtPosition(3, 15);
    dll.print();

    // cout << "Length of list = " << dll.getLength() << endl;

    dll.reverse();
    cout << "Reversed List: " << endl;
    dll.print();

    int deleted = dll.deleteFromPosition(2);
    cout << "Deleted Value: " << deleted << endl;
    dll.print();

    cout << "Length of list = " << dll.getLength() << endl;

   

    return 0;
}
