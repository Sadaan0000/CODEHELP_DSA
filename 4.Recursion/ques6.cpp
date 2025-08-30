#include<iostream>
#include<vector>
#include<string>
using namespace std;

void subsequenceString(string str, string output, vector<string>& v, int i){
    
    //base case
    if( i>=str.length() ){
        // cout << output << " ";
        v.push_back(output);
        return;
    }

    //exclude
    subsequenceString(str, output,v,i+1);

    //include
    output.push_back(str[i]);
    subsequenceString(str,output,v,i+1);

}
int main(){
    string str = "abc";
    string output = "";
    vector<string> v;
    int i=0;

    subsequenceString(str,output,v,i );

    for( string i:v ){
        cout << i << " ";
    }

    return 0;
}