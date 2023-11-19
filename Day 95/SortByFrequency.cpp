#include <bits/stdc++.h>
using namespace std;

string sortByFreq(string s){
    unordered_map<char, int> m;
    for(int i = 0; i<s.length(); i++){
        m[s[i]]++;
    }

    priority_queue<pair<int, char>> maxHeap;
    for(auto it = m.begin(); it != m.end(); it++){
        maxHeap.push({it->second, it->first});
    }

    string ans = "";
    while(maxHeap.size() > 0){
        int freq = maxHeap.top().first;
        char ch = maxHeap.top().second;
        maxHeap.pop();
        while(freq--){
            ans += ch;
        }
    }
    return ans;
}

int main(){

    string s = "aaabbcc";

    cout << sortByFreq(s) << endl;
    
    return 0;
}