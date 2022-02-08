//프로그래머스 모음사전

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> v;
string inp = "";

void dfs(int idx){
    if(idx==5) return;
    inp += 'A';
    v.push_back(inp);
    dfs(idx+1);
    inp.erase(idx,1);
    
    inp += 'E';
    v.push_back(inp);
    dfs(idx+1);
    inp.erase(idx,1);
    
    inp += 'I';
    v.push_back(inp);
    dfs(idx+1);
    inp.erase(idx,1);
    
    inp += 'O';
    v.push_back(inp);
    dfs(idx+1);
    inp.erase(idx,1);
    
    inp += 'U';
    v.push_back(inp);
    dfs(idx+1);
    inp.erase(idx,1);    
}

int solution(string word) {
    int answer = 0;
    dfs(0);
    for(int i=0;i<v.size();i++){
        if(v[i]==word){
            answer = i+1;
            break;
        }
    }
    return answer;
}