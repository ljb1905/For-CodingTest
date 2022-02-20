//프로그래머스 순위검색

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> infov[3][2][2][2];

int val(string s){
    int ret = 0;
    int n = 1;
    for(int i=s.size()-1;i>=0;i--){
        ret += (s[i]-'0')*n;
        n*=10;
    }
    return ret;
}

vector<int> func(string s){
    string inp = "";
    vector<int> ret;
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            if(inp=="cpp") ret.push_back(0);
            else if(inp=="java") ret.push_back(1);
            else if(inp=="python") ret.push_back(2);
            else if(inp=="backend") ret.push_back(0);
            else if(inp=="frontend") ret.push_back(1);
            else if(inp=="junior") ret.push_back(0);
            else if(inp=="senior") ret.push_back(1);
            else if(inp=="chicken") ret.push_back(0);
            else if(inp=="pizza") ret.push_back(1);
            else if(inp=="-") ret.push_back(5);
            inp = "";
        }
        else inp+=s[i];
    }
    ret.push_back(val(inp));
    return ret;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for(int i=0;i<info.size();i++){
        string inp = info[i];
        vector<int> tmp = func(inp);
        infov[tmp[0]][tmp[1]][tmp[2]][tmp[3]].push_back(tmp[4]);
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                for(int l=0;l<2;l++){
                    sort(infov[i][j][k][l].begin(),infov[i][j][k][l].end());
                }
            }
        }
    }
    for(int i=0;i<query.size();i++){
        vector<int> now = func(query[i]);
        vector<int> tmp[4];
        if(now[0]==5){
            tmp[0].push_back(0);
            tmp[0].push_back(1);
            tmp[0].push_back(2);
        } 
        else if(now[0]==0) tmp[0].push_back(0);
        else if(now[0]==1) tmp[0].push_back(1);
        else if(now[0]==2) tmp[0].push_back(2);
        
        if(now[1]==5){
            tmp[1].push_back(0);
            tmp[1].push_back(1);
        }
        else if(now[1]==0) tmp[1].push_back(0);
        else if(now[1]==1) tmp[1].push_back(1);
        
        if(now[2]==5){
            tmp[2].push_back(0);
            tmp[2].push_back(1);
        }
        else if(now[2]==0) tmp[2].push_back(0);
        else if(now[2]==1) tmp[2].push_back(1);
        
        if(now[3]==5){
            tmp[3].push_back(0);
            tmp[3].push_back(1);
        }
        else if(now[3]==0) tmp[3].push_back(0);
        else if(now[3]==1) tmp[3].push_back(1);
        
        int cnt = 0;
        for(int j=0;j<tmp[0].size();j++){
            for(int k=0;k<tmp[1].size();k++){
                for(int l=0;l<tmp[2].size();l++){
                    for(int m=0;m<tmp[3].size();m++){
                        int inp = lower_bound(infov[tmp[0][j]][tmp[1][k]][tmp[2][l]][tmp[3][m]].begin(),infov[tmp[0][j]][tmp[1][k]][tmp[2][l]][tmp[3][m]].end(),now[4])-infov[tmp[0][j]][tmp[1][k]][tmp[2][l]][tmp[3][m]].begin();
                        cnt += infov[tmp[0][j]][tmp[1][k]][tmp[2][l]][tmp[3][m]].size()-inp;
                    }
                }
            }
        }
        answer.push_back(cnt);
    }
    return answer;
}