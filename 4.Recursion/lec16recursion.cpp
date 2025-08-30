#include<iostream>
using namespace std;

int fib(int n){
    
    int ans;

    //base case    
    if(n == 0){
        return 1;
    }
    // cout << " function is called for n : " << n << endl;
    if( n == 2){
        return 1;
    }
    
    return ans = fib(n-1) + fib(n-2);
}

int factorial(int n){

    cout << " function is called for n : " << n << endl;

    //base case
    if(n == 1)
        return 1;

    int chotiproblem = factorial( n-1 );
    int badiproblem = n * chotiproblem;

    return badiproblem;
}

void printcounting(int n){

    //base case
    if(n==0) {
        return ;
    }

    //processing part
    cout << n << endl;

    //recursive relation
    printcounting(n-1);

 }

int main(){

    // when a function calls itself it is called as recursion 
    // when a bigger problems solution depends on small and same type of problem  

    int n;
    cout << " enter the value of n :  " << endl;
    cin >> n;
    
    int ans = factorial(n);
    cout << " the ans is: " << ans << endl;

    // printcounting(n);

    // int ans = fib(n);
    // cout << ans << endl;

    return 0;
}