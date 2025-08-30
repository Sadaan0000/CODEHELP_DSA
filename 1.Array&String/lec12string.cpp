#include<iostream>
#include<string.h>
using namespace std;
  
//length of a string 
int getlength(char ch[]){
    int length=0;
    int i=0;
    while(ch[i]!='\0'){
        length++;
        i++;
    }
 return length;
}

//reverse of a string
void reversechararray(char ch[]){
    int i=0;
    int n=getlength(ch);
    int j=n-1;
    while(i<=j){
        swap(ch[i],ch[j]);
        i++;
        j--;
    }
}

//replace with @
void replacechararray(char ch[]){
    int i=0;
    int n=getlength(ch);
    for (i = 0; i < n; i++)
    {
        if(ch[i]==' '){
              ch[i]='@';  
        }
    }
}

//palindrome we can check a palindrome by a two pointer approach
bool palindrome(char ch[]){
    int i=0;
    int n=getlength(ch);
    int j=n-1;
    while(i<=j){
        if(ch[i]!=ch[j]){
            return false;
        }
        else{
        i++;
        j--;
    }
}
return true;
}

//convert into upper case
void convertIntoUpperCase(char ch[]){
    int n=getlength(ch);
    for(int i=0;i<n;i++){
        if(ch[i]>='a'&& ch[i]<='z'){
        ch[i]=ch[i]-'a'+'A';
    }
    }
}

//convert into lowercase
void convertIntoLowerCase(char ch[]){
    int n=getlength(ch);
    for(int i=0;i<n;i++){
        if(ch[i]>='A'&& ch[i]<='Z'){
        ch[i]=ch[i]-'A'+'a';
    }
}
}

int main() {  

      // 1st
    // cout<<"enter your name :"<<endl;
    // cin>>name;
    // cout<<"name : "<<name<<endl;

    //2nd
    // cout<<"enter your name :";
    // cin>>name;
    // for(int i=0;i<7;i++){
    //     cout<<"index: "<<i<<" value: "<<name[i]<<endl;
    // }
    // int value=(int)name[6];
    // cout<<"value :"<<value;

    //3rd
    // cin.getline(ch,50);
    // cout<<ch<<endl;

    //  char ch[100];
    //  cout<<"enter a string : ";
    //  cin.getline(ch,100);
   
    //  cout<<"length is : "<<getlength(ch)<<endl;
    //  cout<<"length is -> "<<strlen(ch)<<endl;
    
    // cout<<"initially : "<<ch<<endl;
    
    // replacechararray(ch);
    // cout<<" after inserting @ : "<<ch<<endl;
    //  reversechararray(ch);
    //  cout<<"after reversing : "<<ch<<endl;
    
    // cout<<"palindrome check : "<< palindrome(ch);

    // convertIntoUpperCase(ch);
    // cout<<"after converting : "<<ch<<endl;
    // convertIntoLowerCase(ch);
    // cout<<"after converting : "<<ch;

    // string str;
    // getline(cin, str); //take input with spaces for a string
    // cout<<str<<endl;
    
    // cout<<"length : "<<str.length()<<endl; // find the length of the string
    // cout<<"is empty : "<<str.empty()<<endl; // returns if the string is empty or not
    // str.push_back('a'); //push a character into the string at the last position
    // cout<<str<<endl;
    // str.pop_back(); // pop the last character from the string given
    // cout<<str<<endl;
    // cout<<str.substr(0,4)<<endl;; //most important function of string gives a substring from index till the length given
 
    // string str1,str2;
    // cout<<"enter a string : ";
    // getline(cin,str1);
    // cout<<"enter a string : ";
    // getline(cin,str2);
    // cout<<str1.compare(str2)<<endl;// o==0 strings are exactly same !=0 different strings

    // str1.replace(0,4,str2);
    // cout<<str1<<endl;

    // str1.erase(4,5);
    // cout<<str1<<endl;

    

 return 0;
}

