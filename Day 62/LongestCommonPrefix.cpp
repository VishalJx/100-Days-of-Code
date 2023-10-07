#include <bits/stdc++.h>
using namespace std;
/*Approach using loops*/

// string longestCommonPrefix(vector<string>&arr, int n){
//     string ans = "";

//     //traverse all characters of the first string
//     for(int i=0; i<arr[0].length(); i++){
//         char curr = arr[0][i];
//         bool match = true;

//         //for comparing curr with other strings
//         for(int j=1; j<n; j++){
//             if(i>=arr[j].length() || arr[j][i] != curr){
//                 match = false;
//                 break;
//             }
//         }
//         if(match){
//             ans.push_back(curr);
//         }
//         else{
//             break;
//         }
//     }
//     return ans;
// }

/*Approach using Trie*/

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        int childCount;
        bool isTerminal;

        TrieNode(char data){
            this->data = data;
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
            childCount = 0;
            isTerminal = false;
        }
};

class Trie{
    public:
        TrieNode* root;

        Trie(char ch){
            root = new TrieNode(ch);
        }

        void insertUtil(TrieNode* root, string word){
            //base
            if(word.size() == 0){
                root->isTerminal = true;
                return;
            }
            
            int index = word[0] - 'a';
            TrieNode* child;

            //present
            if(root->children[index] != NULL){
                child = root->children[index];
            }
            //not present
            else{
                child = new TrieNode(word[0]);
                root->childCount++;
                root->children[index] = child;
            }

            //recursive call
            insertUtil(child, word.substr(1));
        }

        void insertVoid(string word){
            insertUtil(root, word);
        }

        void lcp(string str, string &ans){
            for(int i = 0; i < str.length(); i++){
                if(root->childCount == 1){
                    ans.push_back(str[i]);
                    int index = str[i] - 'a';
                    root = root->children[index];
                }
                else{
                    break;
                }
                if(root->isTerminal){
                    break;
                }
            }
        }
};

string longestCommonPrefix(vector<string> &arr, int n){
    Trie*t = new Trie('\0');

    //insert all words of arr in trie
    for(int i=0; i<n; i++){
        t->insertVoid(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    t->lcp(first, ans);

    return ans;

}


int main(){

    vector<string> arr = {"geeksforgeeks", "geeks", "geek", "geeker"};
    int n = arr.size();

    cout<<longestCommonPrefix(arr, n)<<endl;
    
    return 0;
}