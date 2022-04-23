//프로그래머스 GPS

#include <stdio.h>
#include <vector>

using namespace std;

int dp[111][211] = {0,};


int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = 0;
    vector<int> v[211];
    for(int i=0;i<edge_list.size();i++){
        v[edge_list[i][0]].push_back(edge_list[i][1]);
        v[edge_list[i][1]].push_back(edge_list[i][0]);
    }
    for(int i=0;i<=k;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = 987654321;
        }
    }
    dp[0][gps_log[0]] = 0;
    for(int i=1;i<k;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = min(dp[i][j],dp[i-1][j]);
            for(int l=0;l<v[j].size();l++){
                int tmp = v[j][l];
                dp[i][j] = min(dp[i-1][tmp],dp[i][j]);
            }
            if(gps_log[i]!=j) dp[i][j]++;
        }
    }
    if(dp[k-1][gps_log[k-1]]>=987654321) dp[k-1][gps_log[k-1]] = -1;
    answer = dp[k-1][gps_log[k-1]];
    return answer;
}