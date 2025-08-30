#include<iostream>
#include<stack>
using namespace std;

int main(){
    cout << endl;
   
    string str = "sadaan";
    
    stack<char> s;
    for(int i=0; i<str.length(); i++){
        s.push(str[i]);
        cout << s.top() << " ";
    }
    cout << endl;

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

   
    return 0;
}