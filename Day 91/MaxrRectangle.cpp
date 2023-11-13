#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> arr){
    stack<int> st;
    vector<int> ans(arr.size(), -1);

    for(int i = 0; i < arr.size(); i++){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i] = st.top();
        }
        st.push(i);
    }

    return ans;
}

vector<int> nextSmaller(vector<int> arr){
    stack<int> st;
    vector<int> ans(arr.size(), arr.size());

    for(int i = 0; i < arr.size(); i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            ans[st.top()] = i;
            st.pop();
        }
        if(!st.empty()){
            ans[i] = st.top();
        }
        else{
            ans[i] = arr.size();
        }
        st.push(i);
    }

    return ans;
}

int largestArea(vector<int> arr){
    vector<int> prev = prevSmaller(arr);
    vector<int> next = nextSmaller(arr);

    int maxArea = INT_MIN;

    for(int i = 0; i < arr.size(); i++){
        int width = next[i] - prev[i] - 1;
        int area = width * arr[i];
        maxArea = max(maxArea, area);
    }

    return maxArea;
}


int maxRectangle(vector<vector<int>> &matrix){
    vector<int> histogram(matrix[0].size(), 0);

    int maxArea = INT_MIN;

    for(int i = 0; i < matrix[0].size(); i++){
        for(int j = 0; j < histogram.size(); j++){
            if(matrix[i][j] == 1){
                histogram[j]++;
            }
            else{
                histogram[j] = 0;
            }
        }
        maxArea = max(maxArea, largestArea(histogram));
    }

    return maxArea;
}

int main(){

    vector<vector<int>> matrix = {
        {1, 0, 0, 1, 1, 1},
        {1, 0, 1, 1, 0, 1},
        {0, 1, 1, 1, 1, 1},
        {0, 0, 1, 1, 1, 1}
    };

    cout << maxRectangle(matrix) << endl;
    
    return 0;
}