#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
map<string ,int> mapp;
int cnt[11];
void dfs(string ori, int idx, string s, int maxlen){
    if(idx >= ori.size() || s.size()>=maxlen){
        if(s.size()==maxlen){
            mapp[s]++;
            //else mapp.insert(make_pair(s,1));
            if(mapp[s] > cnt[maxlen]){
                cnt[maxlen] = mapp[s];
            }
        }
        return;
    }
    dfs(ori,idx+1,s,maxlen);
    dfs(ori,idx+1,s+ori[idx],maxlen);
    return;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int i=0;i<orders.size();i++){
        sort(orders[i].begin(), orders[i].end());
        for(int j=0;j<course.size();j++){
            dfs(orders[i],0,"",course[j]);
        }
    }
    for(int i=0;i<course.size();i++){
        for(auto it=mapp.begin();it!=mapp.end();it++){
            int now = course[i];
            int nowl = it->first.size();
            if(it->second == cnt[now] && nowl == now && cnt[now]>=2){
                //
                //printf("%s %d\n",it->first.c_str(),cnt[now]);
                answer.push_back(it->first);
            }
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}