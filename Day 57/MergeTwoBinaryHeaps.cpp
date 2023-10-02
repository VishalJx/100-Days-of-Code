#include <bits/stdc++.h>
using namespace std;

/*Algorithm:
    1. Create an empty array of size n+m.
    2. Merge both the arrays into the empty array.(simply merge; nothing else)
    3. Heapify the merged array.
*/

//Heapify the array
void heapify(vector<int> &arr, int n, int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l<n && arr[l]>arr[largest])
        largest = l;
    if(r<n && arr[r]>arr[largest])
        largest = r;
    
    if(largest!=i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}


vector<int> mergeHeaps( vector<int> &a, vector<int> &b, int n, int m){
    //Step 1
    vector<int> ans;

    //Step 2 : Merge both the arrays
    for(int i=0; i<n; i++)
        ans.push_back(a[i]);
    for(int i=0; i<m; i++)
        ans.push_back(b[i]);

    //Step 3 : Heapify the merged array
    for(int i=(n+m)/2-1; i>=0; i--)
        heapify(ans, n+m, i);
    
    return ans;

}

int main(){
    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};
    int n = a.size();
    int m = b.size();

    vector<int> ans = mergeHeaps(a, b, n, m);
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
    cout<<endl;

    
    return 0;
}