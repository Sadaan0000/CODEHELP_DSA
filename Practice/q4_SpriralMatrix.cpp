#include<iostream>
#include<vector>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int te = m*n;

        int startrow = 0;
        int endcol = n-1;
        int endrow = m-1;
        int startcol = 0;

        int count =0;
        while(count < te){
            // print starting row
            for(int i=startcol;i<=endcol && count < te;i++){
                ans.push_back(matrix[startrow][i]);
                count++;
            }
            startrow++;

            // print ending col
            for(int i=startrow;i<=endrow && count < te;i++){
                ans.push_back(matrix[i][endcol]);
                count++;
            }
            endcol--;

            // print ending row
            for(int i=endcol;i>=startcol && count < te;i--){
                ans.push_back(matrix[endrow][i]);
                count++;
            }
            endrow--;

            // print starting col
            for(int i=endrow;i>=startrow && count < te;i--){
                ans.push_back(matrix[i][startcol]);
                count++;
            }
            startcol++;
        }
        return ans;
    }

int main(){
    vector<vector<int>> v{
        {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}
    };
    vector<int>ans = spiralOrder(v);

    for(int i =0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}