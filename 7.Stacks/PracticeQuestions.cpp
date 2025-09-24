// REVERSE STRING

// #include<iostream>
// #include<stack>
// using namespace std;
// int main(){
//     stack<char> s;
//     string str = "sadaan";
//     for ( int i=0;i<str.length();i++ ){
//         s.push(str[i]);
//         cout << s.top() << " ";
//     }
//     cout << endl;
//     while (!s.empty())
//     {
//         cout << s.top() << " ";
//         s.pop();
//     }
//     return 0;
// }


// MIDDLE ELEMENT OF STACK

// #include<iostream>
// #include<stack>
// using namespace std;
// void printMiddle(stack<int> &s, int &totalsize ){
//     if( s.size() == 0 ){
//         cout << " Stack Underflow.." << endl;
//         return;
//     }
//     // base size 
//     if ( s.size() == totalsize/2 +1 ){
//         cout << " Middle element is " << s.top() << endl;
//         return; 
//     }
//     int temp = s.top();
//     s.pop();
//     //recursive call
//     printMiddle(s,totalsize);
//     //backtracking
//     s.push(temp);
// }
// int main(){
//     stack<int> s;
//     // s.push(1);
//     // s.push(2);
//     // s.push(3);
//     // s.push(4);
//     // s.push(5);
//     // s.push(6);
//     // s.push(7);
//     // s.push(8);
//     // s.push(9);
//     // s.push(22);
//     int totalsize = s.size();
//     printMiddle(s, totalsize);
//     return 0;
// }


// INSERT AT BOTTOM

// #include<iostream>
// #include<stack>
// using namespace std;
// void insertAtBottom(stack<int> &s, int target){
//     //base case
//     if ( s.empty()){
//         s.push(target);
//         return;
//     }
//     int topElement = s.top();
//     s.pop();
//     //recursive call
//     insertAtBottom(s,target);
//     //backtrack
//     s.push(topElement);
// }
// int main(){
//     stack<int> s;
//     s.push(11);
//     s.push(5);
//     s.push(2);
//     s.push(7);
//     s.push(54);
//     s.push(32);
//     cout << "Original stack:" << endl;
//     {
//         stack<int> temp = s;
//         while (!temp.empty()) {
//             cout << temp.top() << endl;
//             temp.pop();
//         }
//         cout << endl;
//     }
//     if( s.empty()){
//         cout << " Stack is empty.."<< endl;
//     }
//     int target = s.top();
//     s.pop();
//     insertAtBottom(s,target);
//     cout << "Printing New Stack..." << endl;
//     while(!s.empty()){
//         cout << s.top() << endl;
//         s.pop();
//     }
//     return 0;
// }


// REVERSE A STACK

// #include<iostream>
// #include<stack>
// using namespace std;
// void insertAtBottom(stack<int> &s, int target){
//     //base case
//     if (s.empty()){
//         s.push(target);
//         return;
//     }
//     int topElement = s.top();
//     s.pop();
//     //recursive call
//     insertAtBottom(s,target);
//     //backtrack
//     s.push(topElement);
// }
// void reverse(stack<int> &s){
//     //base case
//     if( s.empty()){
//         return;
//     }
//     int target = s.top();
//     s.pop();
//     //recursive call
//     reverse(s);
//     //insert at bottom
//     insertAtBottom(s,target);
// }
// int main(){
//     stack<int> s;
//     s.push(11);
//     s.push(5);
//     s.push(2);
//     s.push(7);
//     s.push(54);
//     s.push(32);
//     cout << "Original stack:" << endl;
//     {
//         stack<int> temp = s;
//         while (!temp.empty()) {
//             cout << temp.top() << endl;
//             temp.pop();
//         }
//         cout << endl;
//     }
//     if( s.empty()){
//         cout << " Stack is empty.."<< endl;
//     }
//     reverse(s);
//     cout << "Printing New Stack..." << endl;
//     while(!s.empty()){
//         cout << s.top() << endl;
//         s.pop();
//     }
//     return 0;
// }


// VALID PARENTHESIS 

// #include<iostream>
// #include<stack>
// using namespace std;
// bool checkParenthesis(string &str){
//     stack<char> s;
//     for( int i=0;i<str.length();i++ ){
//         char ch = str[i];
//         //opening bracket
//         if( ch == '(' || ch == '{' || ch == '['){
//             s.push(ch);
//         }
//         else{
//             //closing bracket
//             if( !s.empty() ){
//                 char topch = s.top();
//                 if( ch == ')' && topch == '(' ){
//                     //matching brackets
//                     s.pop();
//                 }
//                 else if( ch == '}' && topch == '{' ){
//                     //matching brackets
//                     s.pop();
//                 }
//                 else if( ch == ']' && topch == '[' ){
//                     //matching brackets
//                     s.pop();
//                 }
//                 else{
//                     //brackets not matching
//                     return false;
//                 }
//             }
//             else{
//                 return false;
//             }
//         }
//     }
//     return s.empty();
// }
// int main(){
//     cout << endl;
//     string str = "({}){}[()]";
//     cout << checkParenthesis(str);
//     return 0;
// }


// SORT STACK

// #include<iostream>
// #include<stack>
// using namespace std;
// void insertSorted(stack<int> &s, int target){
//     //base case
//     if(s.empty()){
//         s.push(target);
//         return ;
//     }
//     if(s.top() >= target){
//         s.push(target);
//         return;
//     }
//     int topElement = s.top();
//     s.pop();
//     insertSorted(s, target);
//     s.push(topElement);
// }
// void sortStack(stack<int> &s){
//     //base case
//     if(s.empty()){
//         return;
//     }
//     int topElement = s.top();
//     s.pop();
//     sortStack(s);
//     insertSorted(s, topElement);
// }
// int main(){
//     stack<int> s;
//     s.push(11);
//     s.push(5);
//     s.push(2);
//     s.push(7);
//     s.push(54);
//     s.push(32);
//     cout << "Original stack:" << endl;
//     {
//         stack<int> temp = s;
//         while (!temp.empty()) {
//             cout << temp.top() << endl;
//             temp.pop();
//         }
//         cout << endl;
//     }
//     sortStack(s);
//     cout << "Printing New Stack..." << endl;
//     while(!s.empty()){
//         cout << s.top() << endl;
//         s.pop();
//     }    
//     return 0;
// }


// REMOVE REDUNDANT BRAKETS

#include<iostream>
#include<stack>
using namespace std;
void removeRedundantBrackets(stack<int> &s){
    
}
int main(){
    stack<int> s;
    s.push(11);
    s.push(5);
    s.push(2);
    s.push(7);
    s.push(54);
    s.push(32);
    cout << "Original stack:" << endl;
    {
        stack<int> temp = s;
        while (!temp.empty()) {
            cout << temp.top() << endl;
            temp.pop();
        }
        cout << endl;
    }
    removeRedundantBrackets(s);
    cout << "Printing New Stack..." << endl;
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }    
    return 0;
}