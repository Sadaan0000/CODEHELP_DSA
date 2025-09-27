// REVERSE QUEUE

// #include<iostream>
// #include<queue>
// #include<stack>
// using namespace std;
// void reverseQueue(queue<int> &q){
//     stack<int> s;
//     // put all elements of queue into s 
//     while(!q.empty()){
//         int element = q.front();
//         q.pop();
//         s.push(element);
//     }
//     // put all elements of stack into queue
//     while(!s.empty()){
//         int element = s.top();
//         s.pop();
//         q.push(element);
//     }
// }
// int main(){
//     queue<int> q;
//     q.push(3);
//     q.push(6);
//     q.push(9);
//     q.push(2);
//     q.push(8);
//     q.push(4);
//     reverseQueue(q);
//     cout << " Priting Queue..." << endl;
//     while(!q.empty()){
//         cout << q.front() << " ";
//         q.pop();
//     }
//     return 0;
// }


// REVERSE FIRST K ELEMENTS

// #include<iostream>
// #include<queue>
// #include<stack>
// using namespace std;
// void reverseK( queue<int> &q, int k ){
//     // queue k elements in stack
//     stack<int> s;
//     int count = 0;
//     int n = q.size();
//     if( k<=0 || k>n ){
//         return;
//     }
//     while( !q.empty() ){
//         int temp = q.front();
//         q.pop();
//         s.push(temp);
//         count++;
//         if( count == k){
//             break;
//         }
//     }
//     // stack se queue mein wapas 
//     while( !s.empty() ){
//         int temp = s.top();
//         s.pop();
//         q.push(temp);
//     }
//     count = 0; 
//     // push n-k element from front to back
//     while( !q.empty() && n-k != 0 ){
//         int temp = q.front();
//         q.pop();
//         q.push(temp);
//         count++;
//         if( count == n-k ){
//             break;
//         }
//     }
// }
// int main(){
//     queue<int> q;
//     q.push(3);
//     q.push(6);
//     q.push(9);
//     q.push(2);
//     q.push(8);
//     q.push(4);
//     reverseK(q,4);
//     cout << " Priting Queue..." << endl;
//     while(!q.empty()){
//         cout << q.front() << " ";
//         q.pop();
//     }    
//     return 0;
// }


// INTERLEAVE FIRST AND SECOND HALF OF QUEUE

// #include<iostream>
// #include<queue>
// using namespace std;
// void interleave(queue<int> &q1){
//     if( q1.empty()){
//         return;
//     }
//     // make a new queue
//     queue<int> q2;
//     int n = q1.size();
//     int k = n/2;
//     int count = 0;
//     while( !q1.empty() ){
//         int temp = q1.front();
//         q1.pop();
//         q2.push(temp);
//         count++;
//         if(count == k ){
//             break;
//         }
//     }
//     // start interleaving
//     while( !q2.empty() ){
//         int first = q2.front();
//         q2.pop();
//         q1.push(first);
//         int second = q1.front();
//         q1.pop();
//         q1.push(second);
//     }
//     // if no of elements is odd
//     if( n&1 ){
//         int temp = q1.front();
//         q1.pop();
//         q1.push(temp);
//     }
// }
// int main(){
//     queue<int> q;
//     q.push(3);
//     q.push(6);
//     q.push(9);
//     q.push(2);
//     q.push(8);
//     q.push(4);
//     q.push(3);
//     q.push(6);
//     q.push(9);
//     q.push(2);
//     q.push(8);
//     interleave(q);
//     cout << " Priting Queue..." << endl;
//     while(!q.empty()){
//         cout << q.front() << " ";
//         q.pop();
//     }    
//     return 0;
// }


// FIRST NEGATIVE 

// #include<iostream>
// #include<queue>
// using namespace std;
// void firstNegativeInt(){
// }
// int main(){
//     int arr[] = {12,-1,-7,8,-15,30,12,56};
//     int size = 8;
//     int k =3;
//     firstNegativeInt(arr,size,k); 
//     return 0;
// }


// FIRST NON REPEATING CHARACTER OF A STRING 

// #include<iostream>
// #include<queue>
// using namespace std;
// int main(){
//     string str = "zarcaazrd";
//     int freq[26] = {0};
//     queue<char> q;
//     string ans = "";
//     for( int i=0; i<str.length(); i++ ){
//         char ch = str[i];
//         // increment frequency
//         freq[ch-'a']++;
//         //q.push
//         q.push(ch);
//         while(!q.empty()){
//             if( freq[q.front() - 'a'] > 1 ){
//                 q.pop();
//             }
//             else{
//                 ans.push_back(q.front());
//                 break;
//             }
//         }
//         if(q.empty()){
//             ans.push_back('#');
//         }
//     }
//     cout << ans << endl;
//     return 0;
// }


// 
