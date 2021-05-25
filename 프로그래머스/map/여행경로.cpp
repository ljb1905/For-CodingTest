#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> v[10001];
vector<string> tmp;
vector<string> answer;
map<string, int> m;    
map<int, string> revm;
bool chk[10001];

void dfs(int now){
    if(chk[now])
        return;
    chk[now]=true;
    answer.push_back(revm.find(now)->second.c_str());
    for(int i=0;i<v[now].size();i++){
        int next = v[now][i];
        if(chk[next]) continue;
        dfs(next);
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    for(int i=0;i<tickets.size();i++){
        string now = tickets[i][0];
        if(m.find(now)==m.end()){
            m.insert(make_pair(now,m.size()));
            revm.insert(make_pair(revm.size(),now));
        }
        string next = tickets[i][1];
        if(m.find(next)==m.end()){
            m.insert(make_pair(next,m.size()));
            revm.insert(make_pair(revm.size(),next));
        }
    }
    for(auto it=m.begin();it!=m.end();it++){
        printf("%s %d\n",it->first.c_str(),it->second);
    }
    for(int i=0;i<tickets.size();i++){
        string now = tickets[i][0];
        string next = tickets[i][1];
        int nowval = m[now];
        int nextval = m[next];
        v[nowval].push_back(nextval);
    }
    int start = m["ICN"];
    dfs(start);    
    
    return answer;
}