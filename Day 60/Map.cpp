#include <bits/stdc++.h> 
//#include <map>
//#include <unordered_map>
using namespace std;

int main(){

    //creation
    unordered_map<string, int> m;

    //insertion
    pair<string, int> p1 = make_pair("abc", 1); //1
    m.insert(p1);
    pair<string, int> p2("def", 2); //2
    m.insert(p2);
    m["ghi"] = 3; //3
    m["ghi"] = 4; //this will update the value of ghi to 4
    //for every key, there is a unique value

    //searching
    cout<<m["abc"]<<endl; //1
    //if the key is not present, it will insert the key with value 0
    cout<<m.at("def")<<endl; //2
    //if the key is not present, it will throw an error

    //size
    cout<<m.size()<<endl; //output: 3

    //to check presence
    cout<<m.count("ghi")<<endl; //output: 1
    return 0;

    //erase
    m.erase("ghi");
    cout<<m.count("ghi")<<endl; //output: 0

    //traversal
    for(auto it=m.begin(); it!=m.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
        //OR
        cout<<it.first<<" "<<it.second<<endl;
    }

    //traversal using iterator
    unordered_map<string, int>::iterator it;
    while(it!=m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
}