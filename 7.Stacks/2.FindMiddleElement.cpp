#include<iostream>
#include<stack>
using namespace std;

void printMiddle(stack<int> &s, int &totalsize){
    if(s.size() == 0){
        cout << "there is no element to find middle ..." << endl;
        return;
        
    }
    //base case
    if(s.size() == totalsize/2 +1){
        cout << "Middle element is: " << s.top() << endl;
        return;
    }
    
    int temp = s.top();
    s.pop();
    
    //recursive call
    printMiddle(s, totalsize);

    //backtrack
    s.push(temp);

}

int main(){
    cout << endl;

    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
   

    int totalsize = s.size();
    printMiddle(s, totalsize);





    return 0;
}