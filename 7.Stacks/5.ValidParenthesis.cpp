#include<iostream>
#include<stack>
using namespace std;

bool checkParenthesis(string str){
    
stack<char> s;
// if(str.length() == 0){ 
//     cout << " Stack is empty , Enter parenthesis...." << endl;
//     return false;
// }
    for(int i=0; i<str.length(); i++){
        char ch =str[i];

        //opening bracket
        if(ch == '(' || ch == '{' || ch == '[' ){
            s.push(ch);
        }
        else{
            //closing bracket
            if(!s.empty()){
                char topCh = s.top();
                if(ch == ')' && topCh == '(' ){
                    //matching brackets
                    s.pop();
                }
                else if(ch == '}' && topCh == '{' ){
                    //matching brackets
                    s.pop();
                }
                else if(ch == ']' && topCh == '[' ){
                    //matching brackets
                    s.pop();
                }
                else{
                    //brackets not matching
                    return false;
                }
            }
            else{
                return false;
            }
        }
    
    }
    if(s.empty()){
        //valid
        // cout << "Valid Parenthesis";
        return true;
    }
    else{
        //invalid
        // cout << " Invalid Parenthesis";
        return false;
    }
};

int main(){
    cout << endl;
    
    string str = "({}){}[()]";
   
    cout << checkParenthesis(str);

    return 0;
}