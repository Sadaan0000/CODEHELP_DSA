// #include<iostream>
// #include<vector>
// using namespace std;
 
//  string calc_Sum(vector<int>& arr1, vector<int>& arr2) {
//         // Complete the function
//         int carry = 0;
//         string ans;
//         int i = arr1.size()-1;
//         int j = arr2.size()-1;
        
//         while(i>=0 && j>=0){
//             int x = arr1[i] + arr2[j] + carry;
//             int digit = x%10;
//             ans.push_back(digit + '0');
//             carry = x/10;
//             i--,j--;
//         }
//         while(i>=0){
//             int x = arr1[i] + 0 + carry;
//             int digit = x%10;
//             ans.push_back(digit + '0');
//             carry = x/10;
//             i--;
//         }
//         while(j>=0){
//             int x =  0 + arr2[j] + carry;
//             int digit = x%10;
//             ans.push_back(digit + '0');
//             carry = x/10;
//             j--;
//         }
//         if(carry){
//             ans.push_back(carry + '0');
//         }
//         while(ans[ans.size()-1] == '0'){
//             ans.pop_back();
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }

//     int main(){
//     // string v1 = "1234";
//     // string v1 = "5678";
//     calc_Sum("12654","56895");

//     for(int i =0;i<ans.size();i++){
//         cout << ans[i] << " ";
//     }
//     return 0;
// }


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string calc_Sum(vector<int>& arr1, vector<int>& arr2) {
    int carry = 0;
    string ans;
    int i = arr1.size() - 1;
    int j = arr2.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int x = carry;
        if (i >= 0) x += arr1[i--];
        if (j >= 0) x += arr2[j--];

        ans.push_back((x % 10) + '0');
        carry = x / 10;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> stringToVector(const string &s) {
    vector<int> v;
    for (char c : s) {
        v.push_back(c - '0');
    }
    return v;
}

int main() {
    string s1 = "12654";
    string s2 = "56895";

    vector<int> arr1 = stringToVector(s1);
    vector<int> arr2 = stringToVector(s2);

    string ans = calc_Sum(arr1, arr2);

    cout << "Sum: " << ans << endl;
    return 0;
}
