#include<iostream>
using namespace std;

bool checkKey(string str, int n, int i,char key){
    //base case
    if( i>=n ){
        //key not found
        return false;
    }

    //solve 1 case 
    if( str[i] == key ){
        return true;
    }

    //baaki recursion sambhaal lega 
    bool ans = checkKey( str, n, i+1, key );
    return ans;
}


int main(){
    string str = "sadaanakhter";
    int n = str.length();

    char key = 'z';

    int i = 0;

    bool ans = checkKey(str,n,i,key);
    cout << ans;

    return 0;
}