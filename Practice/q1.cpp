// #include<iostream>
// using namespace std;

// int main(){
//    return 0;
// }

// #include<iostream>
// using namespace std;

// int main(){
//     int a,b,c;
//     cin>>a>>b>>c;
//     if((a>b)&&(a>c)){
//         cout << a;
//     }
//     else if((a<b)&&(b>c)){
//         cout << b;
//     }
//     else{
//         cout << c;
//     }
//     return 0;
// }

//REVERSE INTEGER
#include<iostream>
using namespace std;

int reverseInt(int x){
   int ans=0, rem=0;
   bool isNeg = false;
   if(x <= INT_MIN){
      return 0;
   }
   if(x < 0){
      isNeg = true;
      x = -x;
   }
   while( x>0 ){
      if(ans > INT_MAX / 10){
         return 0;
      }
      int digit = x%10;
      ans = ans*10 + digit;
      x = x/10;
   }
   return isNeg ? -ans : ans; 
}
int main(){
   int x; 
   cin >> x;
   
   cout << reverseInt(x) << endl;

   return 0;
}