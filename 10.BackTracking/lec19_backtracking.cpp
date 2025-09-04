#include<iostream>
#include<vector>
using namespace std;

void printPermutation(string &str, int i){
    //base case
    if( i>=str.length()){
        cout << str << endl;
        return;
    }

    //swapping
    for( int j=i;j<str.length();j++ ){
        //swap
        swap(str[i],str[j]);

        //recursive call
        printPermutation(str,i+1);
        
        //backtracking to recreate the original string
        swap(str[i],str[j]);
    }
}

int main(){
    string str = "abcd";
    int i = 0;
    printPermutation(str,i);
    return 0;
}