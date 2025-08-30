#include <iostream>
#include<vector>
using namespace std;


int binarySearch(int arr[],int size,int target){
    int start=0;int end=size-1;
    
    while(start<=end){
        int mid=start+(end-start)/2;
        int element=arr[mid];
        if(element==target){
            return mid;
        }
        else if(target<element){
                end=mid-1;
        }
        else{
            start=mid+1;
        }
      
    }
    return -1;
}


int firstoccurence(vector<int> arr,int target){
  int s=0;int e=arr.size()-1;
  int mid=(s+e)/2;
  int ans=-1;
  while(s<=e){
    int mid=(s+e)/2;
    if(arr[mid]==target){
      //ans store and then left
      ans=mid;
      e=mid-1;
    }
    else if (target<arr[mid])
    {
      e=mid-1;
    }
    else if (target>arr[mid])
    {
      s=mid+1;
    }
  }
  return ans;
}

int main() {
  
  // int arr[]={2,4,6,8,10,12,16};
  // int size=7;
  // int target=16;
  // int indexoftarget=binarySearch(arr,size,target);
  // if(indexoftarget==-1){
  //   cout<<"element not found"<<endl;
  // }
  // else{
  //   cout<<"target found "<< indexoftarget<<endl; 
  // }

  vector<int> arr{1,3,4,4,4,6,7};
  int target=4;
  int indexoffirstocc=firstoccurence(arr,target);
  cout<<"ans is "<<indexoffirstocc<<endl;

  return 0;
}
