#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerArea(vector<int> &heights){
    int size = heights.size();
    vector<int> right(size);
    stack<int> st;

    for(int i = size - 1; i >= 0; i--){
        while(!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
        if(st.empty())
            right[i] = -1;
        else
            right[i] = st.top();
        st.push(i);
    }
    return right;
}

vector<int> prevSmallerArea(vector<int> &heights){
    int size = heights.size();
    vector<int> left(size);
    stack<int> st;

    for(int i = 0; i < size; i++){
        while(!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
        if(st.empty())
            left[i] = -1;
        else
            left[i] = st.top();
        st.push(i);
    }
    return left;
}

int largestArea(vector<int> &heights){
    int size = heights.size();
    vector<int> left(size), right(size);

    right = nextSmallerArea(heights);
    left = prevSmallerArea(heights);

    int maxArea = 0;
    for(int i = 0; i < size; i++){
        int length = heights[i];
        if(right[i] == -1)
            right[i] = size;
        int width = right[i] - left[i] - 1;
        maxArea = max(maxArea, length * width);
    }
    return maxArea;
}
 
int main() {
    vector<int> arr = {2,1,5,6,2,3};
    cout<<largestArea(arr);

    return 0;
}