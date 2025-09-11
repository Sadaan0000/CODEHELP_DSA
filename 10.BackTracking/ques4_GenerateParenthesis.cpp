#include<iostream>
#include<vector>
using namespace std;

void solve(vector<string> &ans, int n, int open, int close, string &output){
    //base case
    if( open==0 && close==0 ){
        ans.push_back(output);
        return;
    }

    //include krlo open waale bracket ko 
    if( open>0 ){
        output.push_back('(');
        solve(ans, n, open-1, close, output);

        //backtrack
        output.pop_back();
    }

    //include krlo close wale bracket ko 
    if( close>open ){
        output.push_back(')');
        solve(ans,n,open,close-1,output);

        //backtrack
        output.pop_back();
    }

}

int main(){
    int n;
    cout << "Enter n: ";
    cin>>n;

    vector<string> ans;
    int open = n;
    int close = n;
    string output = "";

    solve(ans,n,open,close,output);

    cout << "Total no of valid combinations are : " << ans.size() << endl;
    for( string c:ans ){
        cout << c << endl;
    }

    return 0;
}