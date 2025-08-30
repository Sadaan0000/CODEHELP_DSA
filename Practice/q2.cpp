#include<iostream>
using namespace std;
int setKthBit(int N, int k){
    int mask = 1 << k;
    int ans = N|mask;
    return ans;
}
int main(){
    int x,y;
    cin >> x >> y;
    int ans = setKthBit(x,y);
    cout << ans;
    return 0;
}