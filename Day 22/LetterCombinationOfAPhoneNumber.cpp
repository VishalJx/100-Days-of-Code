#include <bits/stdc++.h>
using namespace std;

void solve(string &digit, string arr[], vector<string>&ans, string &output, int index){
    if(index >= digit.length()){
        ans.push_back(output);
        return;
    }
    int num = digit[index] - '0'; // as we have to find int value of string, ex: "23" -> 2,3
    string str = arr[num]; // string mapping corresponding to each number
    for(int i=0; i<str.length();i++){
        output.push_back(str[i]); // push the character in output string
        solve(digit, arr, ans, output, index+1); //making pair of each character with other character
        output.pop_back(); // initially we push_back the character, now we have to pop_back the character
                            //otherwise it will merge with other character and we will get wrong answer
    }
}

vector<int> letterCombinations(string digits) {//23
    string arr[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    string output = ""; // initially output string is empty and it will be empty for each test case
    int index = 0;
    solve(digits, arr, ans, output, index);
}
 
int main() {
    string s="23";
    vector<int> ans = letterCombinations(s);
    
    return 0;
}