//
// Created by neha2 on 19-04-2022.
//

#include<bits/stdc++.h>
using namespace std;
int dp[101][100][2];
int solve(string str, int idx, int flag, int s, int d, int n){
    if(s > n || s < 0)
        return 0;
    int len = str.length();
    if(idx >= len)
        return 0;
    int res = 0;
    if( (str[idx] == 'l' && flag == 0 ) || ( str[idx] == 'r' && flag) ){
        int f = 1;
        if(str[idx] == 'l')
            f = -1;
        res = solve(str, idx + 1, flag, s + f, d, n) + solve(str, idx + 1, 1 - flag, s + f, d, n);
        if(s + f == d)
            res++;
    }
    else{
        res = solve(str, idx + 1, flag, s, d, n);
    }
    dp[idx][s][flag] = res;
    return res;
}
int main(){
    string str;
    cin >> str;
    int len = str.length();
    int n;
    cin >> n;
    int s, d;
    cin >> s >> d;
    memset(dp, -1, sizeof(dp));
    int res = solve(str, 0 , 0, s, d, n) + solve(str, 0, 1, s, d, n);
    cout << res << endl;
}