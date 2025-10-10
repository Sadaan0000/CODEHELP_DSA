// BINARY SEARCH TREE QUESTIONS

#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void printTree(Node* root, int space = 0, int gap = 5) {
    if (root == NULL) return;

    // increase distance between levels
    space += gap;

    // process right child first
    printTree(root->right, space);

    cout << endl;
    for (int i = gap; i < space; i++)
        cout << " ";
    cout << root->data << "\n";

    // process left child
    printTree(root->left, space);
}

Node* bstUsingInorder(int inorder[], int s, int e){
    // base case
    if( s > e ){
        return NULL;
    }

    int mid = (s+e)/2;
    int element = inorder[mid];
    Node* root = new Node(element);

    root->left = bstUsingInorder(inorder,s,mid-1);
    root->right = bstUsingInorder(inorder,mid+1,e);

    return root;
}

void convertIntoSortedDLL(Node* root, Node*&head){
    // base case
    if( root == NULL ){
        return;
    }

    // right subtree into LL 
    convertIntoSortedDLL(root->right, head);

    // attach root node
    root->right = head;

    if( head != NULL ){
        head->left = root;
    }

    // update head
    head = root;

    // left subtree linked list 
    convertIntoSortedDLL(root->left,head);
}

void printLinkedList(Node* head){
    Node* temp = head;
    cout << endl;
    while( temp != NULL ){
        cout << temp->data << " ";
        temp = temp->right;
    }
}

Node* sortedLLintoBST(Node* &head, int n){
    // base case
    if( n <= 0 || head == NULL ){
        return NULL;
    }

    Node* leftSubtree = sortedLLintoBST(head,n/2);

    Node* root = head;
    root->left = leftSubtree;
    head = head->right;

    // right part solve krna hai 
    root->right = sortedLLintoBST(head,n-1-n/2);
    return root;
}

class NodeData {
    public:
    int size;
    int minVal;
    int maxVal;
    bool validBST;

    NodeData(){

    }

    NodeData(int size, int max, int min, bool valid){
        this->size = size;
        this->minVal = min;
        this->maxVal = max;
        validBST = valid;
    }
};

NodeData findLargestBST(Node* root, int &ans ) {
    // base case
    if( root == NULL ){
        NodeData temp (0,INT_MIN,INT_MAX,true);
        return temp;
    }

    NodeData left = findLargestBST(root->left, ans);
    NodeData right = findLargestBST(root->right, ans);

    // checking wala kaam krna hai 
    NodeData currNode;

    currNode.size = left.size + right.size + 1;
    currNode.maxVal = max( root->data, right.maxVal);
    currNode.minVal = min(root->data, left.minVal);

    if( left.validBST && right.validBST && (root->data > left.maxVal && root->data < right.minVal ) ){
        currNode.validBST = true;
    }
    else{
        currNode.validBST = false;
    }

    if( currNode.validBST ){
        ans = max( ans, currNode.size);
    }

    return currNode;

}


int main(){
    // int inorder[] = {1,2,3,4,5,6,7,8};
    // int s = 0;
    // int e = 7;
    // Node* root = bstUsingInorder(inorder,s,e);

    // // cout << "\n\nTree structure (sideways): \n";
    // // printTree(root);

    // Node* head = NULL;
    // convertIntoSortedDLL(root,head);
    // printLinkedList(head);

    // Node* root1 = NULL;
    // root1 = sortedLLintoBST(head, 8);

    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(60);

    root->left->left = new Node(5);
    root->left->right = new Node(20);
    root->left->left->left = new Node(1);
    root->left->left->right = new Node(10);
    root->left->left->right->right = new Node(15);
    root->left->right->right = new Node(25);

    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(55);
    root->right->right->right = new Node(80);
    root->right->right->left->right = new Node(58);
    root->right->right->left->right->left = new Node(57);
    root->right->right->left->right->right = new Node(59);

    int ans = 0;
    findLargestBST(root, ans);
    cout << "Size of Largest BST is: " << ans << endl;

    cout << "\n\nTree structure (sideways): \n";
    printTree(root);

    return 0;
}