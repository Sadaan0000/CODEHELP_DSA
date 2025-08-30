#include <iostream>
#include <unordered_map>
using namespace std;

int main(){

    //creation
    unordered_map<string, int> map;

    //insertion
    pair<string,int> p1=make_pair("harrier",100);
    map.insert(p1);

    pair<string,int> p2("curvv",10);
    map.insert(p2);

    map["safari"] = 20;

    //access
    cout << map.at("curvv") << endl;
    cout << map["safari"] << endl;

    //searching
    cout << map.count("harrier") << endl;

    if(map.find("safarui") != map.end()){
        cout << "found" << endl;
    }
    else{
        cout << "not found" << endl;
    }

    cout << map.size() << endl;

    //counting frequency of each letter in a string
    string str = "jfbdhbchbcywbHOEUYFBHBCHEBCYEBYhb chbewkhjb";
    unordered_map<char,int> freq;
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        freq[ch]++;
    }
    for(auto i:freq){
        cout << i.first << " " << i.second << endl;
    }


    return 0;
}
