#include <bits/stdc++.h>
using namespace std;

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

        void printSuggestions(TrieNode* root, string prefix, vector<string> &ans){
            //base
            if(root->isTerminal){
                ans.push_back(prefix);
            }

            //recursive call
            for(int i=0; i<26; i++){
                if(root->children[i] != NULL){
                    printSuggestions(root->children[i], prefix + root->children[i]->data, ans);
                }
            }
        }

        vector<vector<string>> getSuggestion(string str){
            vector<vector<string>> output;
            TrieNode* prev = root;
            string prefix = "";

            for(int i=0; i<str.size(); i++){
                char lastch = str[i];
                prefix.push_back(lastch);;

                //find last character node
                TrieNode* node = prev->children[lastch - 'a'];

                //if last character node is not present
                if(node == NULL){
                    break;
                }
                //if last character node is present
                vector<string> ans;
                printSuggestions(node, prefix, ans);

                output.push_back(ans);
                ans.clear();
                prev = node;

            }
            return output;
        }

};

vector<vector<string>> phoneDirectory(vector<string>& contactList, string &queryStr){
    //create trie
    Trie *t = new Trie('\0');

    //insert all contact in trie
    for(int i=0; i<contactList.size(); i++){
        string str = contactList[i];
        t->insertVoid(contactList[i]);
    }

    //get suggestions
    return t->getSuggestion(queryStr);
}

int main(){

    vector<string> contactList = {"cod", "coding", "codding", "code", "coly"};
    string queryStr = "coding";

    vector<vector<string>> ans = phoneDirectory(contactList, queryStr);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}