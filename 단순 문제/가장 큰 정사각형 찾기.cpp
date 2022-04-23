//프로그래머스 가장 큰 정사각형 찾기

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int solution(vector<vector<int>> board)
{
    int answer = 0;
    if(board[0][0]==1) answer = 1;
    for(int i=0;i<board.size();i++){
        dp[i][0] = board[i][0];
    }
    for(int j=0;j<board[0].size();j++){
        dp[0][j] = board[0][j];
    }
    for(int i=1;i<board.size();i++){
        for(int j=1;j<board[0].size();j++){
            if(board[i][j]==0) dp[i][j] = 0;
            else{
                int minn = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                dp[i][j] = minn+1;
            }
            answer = max(answer,dp[i][j]);
        }
    } 
    answer *= answer;
    return answer;
}