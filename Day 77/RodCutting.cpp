#include <bits/stdc++.h>
using namespace std;

/*RECURSIVE SOLUTION*/
int solve(int n, int x, int y, int z){
    if(n == 0){
        return 0;
    }
    if(n < 0){
        return 0;
    }

    //note: only single variable is changing --> hence scope of using memoisation
    int includeX = solve(n-x, x, y, z) + 1;
    int includeY = solve(n-y, x, y, z) + 1;
    int includeZ = solve(n-z, x, y, z) + 1;

    return max(includeX, max(includeY, includeZ));
}

/*MEMOISATION*/
int solve2(int n, int x, int y, int z, vector<int> &dp){
    if(n == 0){
        return 0;
    }
    if(n < 0){
        return 0;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int includeX = solve2(n-x, x, y, z, dp) + 1;
    int includeY = solve2(n-y, x, y, z, dp) + 1;
    int includeZ = solve2(n-z, x, y, z, dp) + 1;

    return dp[n] = max(includeX, max(includeY, includeZ));
}

/*TABULATION*/
int solve3(int n , int x, int y, int z){
    vector<int> dp(n+1, INT_MIN);
    dp[0] = 0;

    for(int i=1; i<=n; i++){
        if(i-x >= 0){
            dp[i] = max(dp[i], dp[i-x] + 1);
        }
        if(i-y >= 0){
            dp[i] = max(dp[i], dp[i-y] + 1);
        }
        if(i-z >= 0){
            dp[i] = max(dp[i], dp[i-z] + 1);
        }
    }

    if(dp[n] < 0){
        return 0;
    }
    return dp[n];

}

int cutSegments(int n, int x, int y, int z){

    /*Recursive Solution --> TLE*/
    // int ans = solve(n,x,y,z);
    // if(ans < 0){
    //     return 0;
    // }
    // return ans;

    /*MEMOISATION*/
    // vector<int> dp(n+1, -1);
    // int ans = solve2(n, x, y, z, dp);
    // if(ans < 0){
    //     return 0;
    // }
    // return ans;

    /*TABULATION*/
    int ans = solve3(n, x, y, z);
    return ans;
}

int main(){

    cout<<cutSegments(5, 1, 2, 3)<<endl;
    
    return 0;
}