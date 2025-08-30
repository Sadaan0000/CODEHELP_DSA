#include<iostream>
#include<vector>
using namespace std;
  
  bool isPossibleSolution( vector<int>&arr, int k, int mid ){
      int pageSum = 0;
      int c = 1;
      for ( int i=0;i<arr.size();i++ ){
          if( arr[i] > mid ){
              return false;
          }
          
          if( pageSum + arr[i] > mid ){
              c++;
              pageSum = arr[i];
              if( c>k ){
                  return false;
              }
          }
          else{
              pageSum += arr[i];
          }
      }
      return true;
  }
  

int main(){
    vector<int> arr = {12,34,67,90}; 
    int k = 5;
    int ans = -1;

    if( k > arr.size() ) {
        cout << ans;
        return 0;
    } 
       
    int end = 0;
    for( int i=0;i<arr.size();i++ ){
        end += arr[i]; 
    }
    
    int start = 0;
        
        
    while( start <= end ){
        int mid = start + (end-start) / 2;
        if( isPossibleSolution(arr,k,mid) ){
            ans = mid ;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    cout << ans;
    
return 0;
}


// class Solution {
//   public:
//   bool isPossibleSolution( vector<int>&arr, int k, int mid ){
//       int pageSum = 0;
//       int c = 1;
//       for ( int i=0;i<arr.size();i++ ){
//           if( arr[i] > mid ){
//               return false;
//           }
//           if( pageSum + arr[i] > mid ){
//               c++;
//               pageSum = arr[i];
//               if( c>k ){
//                   return false;
//               }
//           }
//           else{
//               pageSum += arr[i];
//           }
//       }
//       return true;
//   }
//     int findPages(vector<int> &arr, int k) {
//         // code here
//         if( k > arr.size() ) return -1; 
//        int end = 0;
//         for( int i=0;i<arr.size();i++ ){
//             end += arr[i]; 
//         }
//         int ans = -1;
//         int start = 0;
//         while( start <= end ){
//             int mid = start + (end-start) / 2;
//             if( isPossibleSolution(arr,k,mid) ){
//                 ans = mid ;
//                 end = mid - 1;
//             }
//             else{
//                 start = mid + 1;
//             }
//         }
//         return ans;
//     }
// };