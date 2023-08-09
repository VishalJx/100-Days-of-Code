//Sliding Window Approach:-

#include <bits/stdc++.h>
using namespace std;

bool checkEqual(int count1[], int count2[]){
    for(int i=0; i<26; i++){
        if(count1[i] != count2[i]){
            return 0;//count of every index MUST be equal
        }
    }
        return 1;
}

bool isExists(string s2, string s1){

    //maintaining count of characters
    int count1[26] = {0}; //empty array
    for(int i=0; i<s1.length();i++){
        int index = s1[i] - 'a';
        count1[index]++;
    }

    //traversing s2 string using window of size string s2
    int count2[26] = {0};
    int window = s1.length();
    int i = 0;

    //processing for first window(placing our window at very start of string s2)
    while(i<window && i<s2.length()){ //checking if size exceeds or not
        int index = s2[i] - 'a'; //storing index corresponding to character;
        count2[index]++;//increasing 0 by 1 at those indices above we calculated
        i++;
    }

    //checking if character count in arr-1 is equal to arr-2; means our substring
    //or its permutation exists, hence return true
    if (checkEqual(count1, count2))
        return 1;

    //moving window forward
    while(i<s2.length()){
        char newChar = s2[i];//here 'i' will be in the window(last element in window)
        int index = newChar - 'a';// same as above, storing index corresponding to character;
        count2[index]++; //increasing index of next element to window from 0 to 1

        char oldChar = s2[i - window];//very first element in the window that we need to ignore once we checked it.
        index = oldChar - 'a';
        count2[index]--;

        i++;

        //checking if character count in arr-1 is equal to arr-2; means our substring
        //or its permutation exists, hence return true
        if (checkEqual(count1, count2))
            return 1;
    }

    return 0;

}
 
int main() {

    string s2 = "nnnannbb";
    string s1 = "ab";

    cout<<isExists(s2,s1);

    return 0;
}