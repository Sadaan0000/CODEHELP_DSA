#include<iostream>
#include<vector>
using namespace std;

int bs(vector<int>a, int l, int h, int x){
    while(l<=h){
        int mid = l + (h-l)/2;
        if(a[mid] == x){
            return mid;
        }
        else if(a[mid] > x){
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return -1;
}

int expSearch(vector<int> &a, int n, int x){
    if(a[0] == x){
        return 0;
    }
    int i=1;
    while(i<n && a[i] <= x){
        i = i*2;
    }
    return bs(a, i/2, min(i, n-1), x);
}

int main()
{
    vector<int> a{3,4,5,6,11,13,14,15,56,70};
    int n = a.size();
    int x = 70;
    int ans = expSearch(a,n,x);
    cout << n << endl;
    cout << "Found at " << ans << endl;
    return 0;
}