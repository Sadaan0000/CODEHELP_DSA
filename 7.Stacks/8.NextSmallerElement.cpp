#include<iostream>
#include<stack>
#include<vector>
#include<limits.h>
using namespace std;

vector<int> prevSmallerElement(vector<int> &input){
    stack<int> s;
    s.push(-1);
    vector<int> ans(input.size());

    for(int i=0;i<input.size();i++){
        int curr = input[i];
        while( s.top() != -1 && input[s.top()] >= curr){
            s.pop();
        }
        //chota element mil chuka hai to ans store 
        ans[i] = s.top();

        //push krdo current element ko 
        s.push(i);
    }
    return ans;
}

vector<int> nextSmaller(vector<int> &input){
    stack<int> s;
    
    s.push(-1);
    vector<int> ans(input.size());
    for(int i=input.size()-1; i >= 0; i--){
        int curr = input[i];
        while(s.top() != -1 && input[s.top()] >= curr){
            s.pop();
        }
        //chota element mil chuka hai to ans store 
        ans[i] = s.top();

        //push krdo current element ko 
        s.push(i);
    }
    return ans;
}

int getrectangularAreaHistogram(vector<int> &height){

    //step1: prev smaller input
    vector<int> prev = prevSmallerElement(height);

    //step2: next smaller call
    vector<int> next = nextSmaller(height);

    int maxArea = INT_MIN;
    int size = height.size();

    for(int i=0; i<height.size(); i++){
        int length = height[i];
        if(next[i] == -1){
            next[i] = size;
        }

        int width = next[i] - prev[i] -1;

        int area = length * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main(){
cout << endl;

    vector <int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    v.push_back(6);
    v.push_back(2);
    v.push_back(3);


    // vector<int> ans1 = nextSmaller(v);
    // cout << "Printing ans1..." << endl;
    
    // for( int i=0; i < v.size(); i++){
    //     cout << ans1[i] << " ";
    // }
    // cout << endl;

    // vector<int> ans2 = prevSmallerElement(v);
    // cout << "Printing ans2..." << endl;
    
    // for( int i=0; i < v.size(); i++){
    //     cout << ans2[i] << " ";
    // }
    // cout << endl;

    cout << getrectangularAreaHistogram(v) << endl;

    cout << endl;
    return 0;
}