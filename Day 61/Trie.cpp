#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26]; // 26 alphabets
        bool isTerminal;

        TrieNode(char data){
            this->data = data;
            for(int i=0;i<26;i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie{
    public:
        TrieNode* root;

        Trie(){
            root = new TrieNode('\0');
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
                root->children[index] = child;
            }

            //recursive call
            insertUtil(child, word.substr(1));
        }

        void insertVoid(string word){
            insertUtil(root, word);
        }

        void searchUtil(TrieNode* root, string word){
            //base
            if(word.size() == 0){
                if(root->isTerminal){
                    cout<<"Word is present"<<endl;
                }
                else{
                    cout<<"Word is not present"<<endl;
                }
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
                cout<<"Word is not present"<<endl;
                return;
            }

            //recursive call
            searchUtil(child, word.substr(1));
        } // O(length of word)

        void search(string word){
            return searchUtil(root, word);
        }

};



int main(){

    Trie *t = new Trie();
    t->insertVoid("hello");

    t->search("hello");
    t->search("hell");

    
    return 0;
}