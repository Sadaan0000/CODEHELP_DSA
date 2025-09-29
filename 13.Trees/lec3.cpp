// BUILD TREE FROM INORDER PREORDER POSTORDER TRAVERSAL
// TOPVIEW TRAVERSAL

#include<iostream>
#include<unordered_map>
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

int findPosition(int arr[], int n, int element){
    for( int i=0; i<n; i++ ){
        if(arr[i] == element){
            return i;
        }
    }
    return -1;
}

Node* buildTree(int inorder[], int preorder[], int size, int &preIndex, int inorderStart, int inorderEnd){
    // base case 
    if( preIndex >= size || inorderStart > inorderEnd){
        return NULL;
    }

    // step A
    int element = preorder[preIndex++];
    Node* root = new Node(element);
    int pos = findPosition(inorder, size, element);

    // step b root-> left solve
    root->left = buildTree( inorder, preorder, size, preIndex, inorderStart, pos-1);

    // step c root->right solve
    root->right = buildTree( inorder, preorder, size, preIndex, pos+1, inorderEnd);

    return root;
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

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    //initially 
    q.push(root);
    q.push(NULL);

    while (!q.empty()){
        //A
        Node* temp = q.front();

        //B
        q.pop();

        if( temp == NULL ){
            cout << endl;
            if( !q.empty() ){
                q.push(NULL);
            }
        }
        else{
        //C
        cout << temp->data << " ";

        //D
        if( temp->left ){
            q.push(temp->left);
        }
        if( temp->right ){
            q.push(temp->right);
        }
        }
    }
}

Node* buildTreeFromPostorderInorder(int inorder[], int postorder[], int size, int &postIndex, int inorderStart, int inorderEnd){
    // base case 
    if( postIndex < 0 || inorderStart > inorderEnd ){
        return NULL;
    }

    // A
    int element = postorder[postIndex];
    postIndex--;
    Node* root = new Node(element);

    int pos = findPosition(inorder,size,element);

    // root-> right solve
    root->right = buildTreeFromPostorderInorder( inorder, postorder, size, postIndex, pos+1, inorderEnd);

    // root -> left solve 
    root->left = buildTreeFromPostorderInorder( inorder, postorder, size, postIndex, inorderStart, pos-1);

    return root;
}

void printTopView(Node* root){
    if( root == NULL ){
        return;
    }

    //create a map for storing HD -> Topnode -> Data
    unordered_map<int,int> topNode;

    // level order
    // we will store a pair consisting of node and horizontal diatance

    queue<pair<Node*, int>> q;
    q.push(make_pair(root,0));

    while (!q.empty())
    {
        pair<Node* , int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        // jo bhi horizontal dostance aaya hai check if answer for that hd already exist or not 

        if( topNode.find(hd) == topNode.end() ){
            // create entry
            topNode[hd] = frontNode->data;
        }

        if( frontNode -> left ){
            q.push(make_pair(frontNode->left, hd-1));
        }

        if( frontNode -> right ){
            q.push(make_pair( frontNode->right, hd+1));
        }
    }

    // ab answer map mein store ho gaya hoga 
    cout << " Printing the answer : " << endl;

    for( auto i: topNode ){
        cout << i.first << " -> " << i.second << endl;
    }
    

}

void printBottomView(Node* root){
if( root == NULL ){
        return;
    }

    //create a map for storing HD -> Topnode -> Data
    unordered_map<int,int> topNode;

    // level order
    // we will store a pair consisting of node and horizontal diatance

    queue<pair<Node*, int>> q;
    q.push(make_pair(root,0));

    while (!q.empty())
    {
        pair<Node* , int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        // create entry

        topNode[hd] = frontNode->data;

        if( frontNode -> left ){
            q.push(make_pair(frontNode->left, hd-1));
        }

        if( frontNode -> right ){
            q.push(make_pair( frontNode->right, hd+1));
        }
    }

    // ab answer map mein store ho gaya hoga 
    cout << " Printing the answer : " << endl;

    for( auto i: topNode ){
        cout << i.first << " -> " << i.second << endl;
    }    
}

void printLeftView(Node* root, vector<int> &ans, int level){
    // base case
    if( root == NULL ){
        return;
    }

    if( level == ans.size()){
        ans.push_back(root->data);
    }

    //left 
    printLeftView(root->left, ans, level+1);

    //right
    printLeftView(root->right, ans, level+1);
}

void printRightView( Node* root, vector<int> &ans, int level){
    // base case
    if( root == NULL ){
        return;
    }

    if( level == ans.size()){
        ans.push_back(root->data);
    }

    //left 
    printRightView(root->right, ans, level+1);

    //right
    printRightView(root->left, ans, level+1);
}

int main(){
    // int inorder[] = {40,20,50,10,60,30,70};
    // int preorder[] = {10,20,40,50,30,60,70};
    // int size = 7;
    // int preIndex = 0;
    // int inorderStart = 0;
    // int inorderEnd = size-1;
    // Node* root = buildTree(inorder, preorder, size, preIndex, inorderStart, inorderEnd);

    int inorder[] = {40,20,50,10,60,30,70};
    int postorder[] = {40,50,20,60,70,30,10};
    int size = 7;
    int postIndex = size-1;
    int inorderStart = 0;
    int inorderEnd = size-1;
    Node* root = buildTreeFromPostorderInorder( inorder, postorder, size, postIndex, inorderStart, inorderEnd );

    // cout << "TopView Traversal: " << endl;
    // printTopView(root);
    // cout << endl;

    // cout << "BottomView Traversal: " << endl;
    // printBottomView(root);
    // cout << endl;

    // vector<int> ans;
    // int level = 0;
    // cout << "Left Tree View : " << endl;
    // printLeftTree(root,ans,level);
    // for( auto i:ans){
    //     cout << i << " ";
    // }

    // vector<int> ans;
    // int level = 0;
    // cout << "Right Tree View : " << endl;
    // printRightView(root,ans,level);
    // for( auto i:ans){
    //     cout << i << " ";
    // }

    // cout << "Level Order Traversal: " << endl;
    // levelOrderTraversal(root);
    // cout << endl;

    cout << "\n\nTree structure (sideways): \n";
    printTree(root);

    return 0;
}