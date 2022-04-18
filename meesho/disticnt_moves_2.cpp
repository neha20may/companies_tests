//
// Created by neha2 on 19-04-2022.
//
#include <bits/stdc++.h>

using namespace std;
static int MOD = 1000000007;

int solve(string s, int n, int x, int y) {
    vector<int> prevSame = vector<int>(s.length(), 0);
    int idxL = -1;
    int idxR = -1;
    for (int i = 0; i < prevSame.size(); i++) {
        if (s[i] == 'l') {
            prevSame[i] = idxL;
            idxL = i;
        } else {
            prevSame[i] = idxR;
            idxR = i;
        }
    }

    // dp[i][j] is number of distinct subsequnces of length i to end up at j
//    long[][] dp = new long[s.length+1][n+1];
    vector<vector<long>> dp = vector<vector<long>>(s.size() + 1, vector<long>(n + 1, 0));
    dp[0][x] = 1;
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = dp[i - 1][j];
            if (s[i - 1] == 'l') {
                if (j + 1 <= n) dp[i][j] += dp[i - 1][j + 1];
                if (j + 1 <= n && prevSame[i - 1] >= 0) dp[i][j] -= dp[prevSame[i - 1] + 1 - 1][j + 1];
            } else {
                if (j - 1 >= 0) dp[i][j] += dp[i - 1][j - 1];
                if (j - 1 >= 0 && prevSame[i - 1] >= 0) dp[i][j] -= dp[prevSame[i - 1] + 1 - 1][j - 1];
            }
            dp[i][j] = (dp[i][j] + MOD) % MOD;
        }
    }
    return (int) dp[s.size()][y];
}

int main(){
    int x = 1, y = 4;
    string s="rrlrlr";
    int n=6;
    int res = solve(s, n, x, y);
    cout << res << endl;
}