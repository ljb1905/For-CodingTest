#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int n;
map <string, vector<string>> m;
map <pair<string,string>,int> visit;
vector<string> answer;

void dfs(string now){
    answer.push_back(now);
    if(n+1==answer.size())
        return;
    for(int i=0;i<m[now].size();i++){
        string next = m[now][i];
        if(visit[{now,next}]==0)
            continue;
        visit[{now,next}]--;
        dfs(next);
        if(n+1==answer.size())
            return;
        visit[{now,next}]++;        
    }
    answer.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    n = tickets.size();
    sort(tickets.begin(),tickets.end());
    for(int i=0;i<n;i++){
        string now = tickets[i][0];
        string next = tickets[i][1];
        vector<string> tmp;
        if(m.find(now)!=m.end()){
            m.insert(make_pair(now,tmp));
        }
        m[now].push_back(next);
        visit[{now,next}]++;
        
        dfs("ICN");
    }
    return answer;
}