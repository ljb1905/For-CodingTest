//[1차] 프렌즈 4블록

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<string> erasef(vector<string> &board, int n, int m){
    vector<string> ret;
    bool chkarr[31][31] = {false,};
    for(int i=0;i<board.size();i++){
        if(i==m-1) continue;
        for(int j=0;j<board[i].size();j++){
            if(j==n-1) continue;
            if(board[i][j]==board[i+1][j] && board[i][j]==board[i][j+1] && board[i][j]==board[i+1][j+1]){
                chkarr[i][j] = true;
                chkarr[i+1][j] = true;
                chkarr[i][j+1] = true;
                chkarr[i+1][j+1] = true;
            }
        }
    }
    stack<char> sta[31];
    for(int j=0;j<n;j++){
        for(int i=m-1;i>=0;i--){
            if(chkarr[i][j]) continue;
            sta[j].push(board[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        string tmp = "";
        for(int j=0;j<n;j++){
            if(sta[j].size()>=m-i){
                tmp+=sta[j].top();
                sta[j].pop();
            }
            else{
                tmp+=' ';
            }
        }
        ret.push_back(tmp);
    }
    return ret;
}
bool endchk(vector<string> &board){
    for(int i=0;i<board.size()-1;i++){
        for(int j=0;j<board[i].size()-1;j++){
            if(board[i][j]==board[i+1][j] && board[i][j]==board[i][j+1] && board[i][j]==board[i+1][j+1] &&board[i][j]!=' '){
                return true;
            }
        }
    }
    return false;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while(endchk(board)){
        board = erasef(board,n,m);
    }
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(board[i][j]==' ') answer++;
        }
    }
    return answer;
}