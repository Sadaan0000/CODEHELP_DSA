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

Node* buildTree(){
    int data;
    cout << "Enter the data: " << endl;
    cin >> data;

    if( data == -1 ){
        return NULL;
    }
    // Step A B C
    Node* root = new Node(data);

    cout << "Enter data for left part of " << data << " node " << endl;
    root->left = buildTree();
    cout << "Enter data for right part of " << data << " node " << endl;
    root->right = buildTree();
    return root;
};

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

void inorderTraversal( Node* root ){
    // base case 
    if( root == NULL ){
        return;
    }
    // Left
    inorderTraversal(root->left);
    // Node
    cout << root->data << " ";
    // Right
    inorderTraversal(root->right);
}

void preorderTraversal( Node* root ){
    // base case 
    if( root == NULL ){
        return;
    }
    // Node
    cout << root->data << " ";
    // Left
    preorderTraversal(root->left);
    // Right
    preorderTraversal(root->right); 
}

void postorderTraversal( Node* root ){
    // base case 
    if( root == NULL ){
        return;
    }
    // Left
    postorderTraversal(root->left);
    // Right
    postorderTraversal(root->right);
    // Node
    cout << root->data << " ";     
}

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int ans = max(leftHeight, rightHeight) + 1;
    return ans;
} 



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

int main(){
    Node* root = NULL;

    root = buildTree();

    cout << "Level Order Traversal: " << endl;
    levelOrderTraversal(root);
    cout << endl;

    cout << " Height of tree : " << height(root) << endl;
    cout << endl;

    cout << "Inorder Traversal: " << endl;
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal: " << endl;
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal: " << endl;
    postorderTraversal(root);
    cout << endl;

    cout << "\n\nTree structure (sideways): \n";
    printTree(root);

    return 0;
}