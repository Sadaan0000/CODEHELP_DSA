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

Node* insertIntoBST(Node* root, int data){
    if( root == NULL ){
        // this is the first node we have to create
        root = new Node(data);
        return root;
    }

    // no the first node

    if( root->data > data ){
        // insert in left
        root->left = insertIntoBST(root->left, data);
    }
    else{
        // insert into right
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cout << " Enter data for Node : " << endl;
    cin >> data;

    while(data != -1 ){
        root = insertIntoBST(root,data);
        cin >> data;
    }
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

int main(){
    // Node* root = NULL;
    // takeInput(root);
    // // 10 20 5 11 17 2 4 8 6 25 15 -1

    int inorder[] = {1,2,3,4,5,6,7,8,9};
    int s = 0;
    int e = 8;

    Node* root = bstUsingInorder(inorder,s,e);
    
    cout << "\n\nTree structure (sideways): \n";
    printTree(root);

    return 0;
}