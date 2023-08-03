#include <bits/stdc++.h>
using namespace std;


vector<int> reverse(vector<int>arr){
    int i=0;
    int j= arr.size();
    while(i<j){
        swap(arr[i++],arr[j--]);
    }
    return arr;
}

vector<int> sumOfBoth(vector<int>arr1,vector<int>arr2){
    int carry = 0;
    int sumTotal=0;
    int m = arr1.size();
    int n = arr2.size();
    int i=m;
    int j=n;
    //to save answers;
    vector<int>ans;

    //when size of both array are equal
    while (i>=0 && j>=0)
    { 
        int sum = arr1[i]+arr2[j]+carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum); //we've learnt this in vectors.
        i--;
        j--;
    }
    //case II: When elements are left in first array;
    //ex.   2369
    //        23     
    //above 23 is left
    while(i>=0){
        int sum = arr1[i] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum); //we've learnt this in vectors.
        i--;
    }

    //case III: When elements are left in Second array;
    //ex.     69
    //      4523     
    //above 45 is left
    while(j>=0){
        int sum = arr1[j] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum); //we've learnt this in vectors.
        j--;
    }

    //case IV: When carry is left;
    //ex.   8269
    //      4523     
    //above 1 is left as carry
    while(carry!=0){
        int sum = carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum); //we've learnt this in vectors.
    }

    // answer here will be reversed
    // return ans;
    // Hence using reverse()    
    return reverse(ans);
}
 
int main() {

    vector<int>arr1={4,5,6,8};
    vector<int>arr2={1,6,3};

    sumOfBoth(arr1,arr2);

    return 0;
}