// Kth ANCESTOR OF A NODE 

#include<iostream>
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
bool kthAncestor1(Node* root, int &k, int p ){
    // base case 
    if( root == NULL )
        return false;

    if( root->data == p ){
        return true;
    }    

    bool leftAns = kthAncestor1(root->left, k, p);
    bool rightAns = kthAncestor1(root->right,k,p);

    // wapas aate time
    // check ki left ya right mein ans mila ke nhin
    if( leftAns || rightAns )
        k--;
    
    if( k == 0 ){
        cout << " Answer : " << root->data << endl;
        k = -1;
    }
        
    return leftAns || rightAns; 
    
}
// Returns pointer to ancestor if found, else NULL
Node* kthAncestor(Node* root, int &k, int p) {
    if (!root) return NULL;

    if (root->data == p) return root;

    Node* left = kthAncestor(root->left, k, p);
    Node* right = kthAncestor(root->right, k, p);

    if (left || right) {
        k--;
        if (k == 0) {
            cout << "Answer: " << root->data << endl;
            return NULL; // Stop further backtracking
        }
        return left ? left : right;
    }

    return NULL;
}
int main(){
    Node* root = buildTree();
    int k = 2;
    int p = 5;
    bool ans1 = kthAncestor1(root,k,p);
    cout << ans1 << endl;
    Node* ans = kthAncestor(root, k, p);
    if (!ans && k != 0)
        cout << "No ancestor found or k is larger than the height from node to root" << endl;
    return 0;
}