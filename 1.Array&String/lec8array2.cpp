#include<iostream>
#include<vector>
using namespace std;

// int findunique(vector<int> arr){
//     int ans=0;

//     for(int i=0;i<arr.size();i++){
//         ans=ans^arr[i];
//     }
//     return ans;
// }


int main()
{
//     // create vector
//     vector<int> arr;

//     // int ans=(sizeof(arr)/sizeof(int));
//     // cout<<ans<<endl;



//     // cout<<arr.size()<<endl;
//     // cout<<arr.capacity()<<endl;

//     // insert
//     arr.push_back(5);
//     arr.push_back(20);
//     for (int i = 0; i < arr.size(); i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     // remove
//     arr.pop_back();

// for (int i = 0; i < arr.size(); i++)
//     {
//         cout<<arr[i]<<endl;
//     }

//     int n;
//     cout<<"enter the value of n:"<<endl;
//     cin>>n;

//     vector<int> brr(n,-1000);
//     cout<<"size of b "<<brr.size()<<endl;
//     cout<<"capacity of b "<<brr.capacity()<<endl;

//  for (int i = 0; i < brr.size(); i++)
//     {
//         cout<<brr[i]<<endl;
//     }
//     cout<<endl;

//     cout<<"vector brr is empty or not."<<brr.empty()<<endl;

//     vector<int> crr;
//     cout<<"vector brr is empty or not."<<crr.empty()<<endl;

//UNIQUE ELEMENT

    // int n;
    // cout<<"enter the size of the array: ";
    // cin>>n;

    // vector<int> arr(n);
    // cout<<"enter the elements: "<<endl;

    // for (int i = 0; i <arr.size(); i++)
    // {
    //     cin>>arr[i];
    // }
    // int uniqueelement=findunique(arr);
    // cout<<"unique element is "<<findunique(arr)<<endl;
    

    //UNION
//     int arr[]={1,2,3,4,5,6,7};
//     int sizea=7;
//     int brr[]={9,8,10,11,12,13};
//     int sizeb=6;

//     vector<int> ans;
//     for(int i=0;i<sizea;i++)
//     {
//         ans.push_back(arr[i]);
//     }

//     for(int i=0;i<sizeb;i++){
//         ans.push_back(brr[i]);
//     }

// for (int i = 0; i < ans.size(); i++)
// {
//     cout<<ans[i]<<" ";
// }


//INTERSECTION OF ARRAYS 

// int arr[]={1,2,3,4,5,6,7};
// int sizea=7;
// int brr[]={15,12,13,14,90,13,7,8,9,11,1,2,3,4,5};
// int sizeb=15;

// vector<int> ans;

// //outerloop
// for(int i=0;i<sizea;i++){
//     int element =arr[i];
//     //for every elemnt run loop on brr
//     for(int j=0;j<sizeb;j++){
//         if(element==brr[j]){
//             ans.push_back(element);
//         }
//     }
// }

//     for (int i = 0; i < ans.size(); i++)
// {
//     cout<<ans[i]<<" ";
// }

// cout<<endl;
// for(auto value: ans){
//     cout<<value<<" ";
// }

//UNION WITH DUPLICATES

// vector<int> ans{1,2,3,4,5,6,7};
// vector<int> ans{1,2,3,4,5,6,7,15,12,13,14,90,13,7,8,9,11,1,2,3,4,5};







//PAIR SUM


// int sum,n;
// cout<<"enter the array length: "<<endl;
// cin>>n;
// vector<int> arr(n);


// cout<<"enter the array elements:"<<endl;
// for(int i=0;i<arr.size();i++){
//     cin>>arr[i];
// }

// //print all pairs
// //outer loop will traverse for ech pair
// for(int i=0;i<arr.size();i++){
//     int element1=arr[i];

//     //for every elemnt making of pairs
//     for(int j=0;j<arr.size();j++){
//         int element2=arr[j];
//         cout<<element1<<","<<element2<<endl;
//     }
// }
// cout<<"enter the sum : "<<endl;
// cin>>sum;


//SORT 0's AND 1's

// vector<int> arr{ 0,1,0,0,0,0,1,0,0,1,1,1,1 };

// int start=0;
// int end=arr.size()-1;
// int i=0;

// while(start<=end){
//     if(arr[i]==0){
//         //swap from left
//         swap(arr[start],arr[i]);
//         i++;
//         start++;
//     }
//     else{
//         //swap from right
//         swap(arr[i],arr[end]);
//         end--;
//         i++;
//     }
// }

 vector<int> vectr{9,8,7,6,5,4,3,2,1,0};   
  for (int i = 0; i < vectr.size(); i++)  
  {  
    cout << vectr[i] << " \n";   
  }  








return 0;

}