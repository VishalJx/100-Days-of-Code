#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n, -1); // -1 if no smaller element found
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            //above condition is true, 
            //means we have found the next smaller element
            ans[st.top()] = arr[i]; //hence update the ans
            st.pop(); //pop the element because we have found the next smaller element
                    // and element at st.top() is larger than arr[i]
        }
        st.push(i); //push the index of the element
                    //because we have not found the next smaller element
    }
    return ans;
}
 
int main() {
    vector<int> arr = {4, 8, 5, 2, 25};
    vector<int> ans = nextSmallerElement(arr);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}

/*Working*/
/*
    1. We will use a stack to store the index of the elements
    2. We will traverse the array from right to left instead of left to right
    3. Because as we move from right to left, we will find the next smaller element
        for the elements on the left side
    4. for each element, we will check if the element at the top of the stack is greater than the current element
    5. if it is greater, then we have found the next smaller element
    6. if it is not greater, then we will push the index of the current element in the stack
    7. we will repeat the above steps until we reach the end of the array
    8. if we reach the end of the array, then we will pop the elements from the stack
    9. if the stack is empty, then we have found the next smaller element for all the elements
*/