#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct str{
    int st, ed;
    str(){}
    str(int st, int ed):
        st(st),ed(ed)
        {}
    bool operator <(const str &o)const{
        if(st==o.st){
            return ed<o.ed;
        }
        return st<o.st;
    }
};
struct compare{
    bool operator()(str &A, str &B){
        if(A.ed==B.ed){
            return A.st>B.st;
        }
        return A.ed>B.ed;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    vector <str> v;
    priority_queue <str,vector<str>,compare> pq;
    for(int i=0;i<jobs.size();i++){
        v.push_back(str(jobs[i][0],jobs[i][1]));
    }
    sort(v.begin(),v.end());
    int cnt = 0;
    int now = 0;
    int n = v.size();
    int idx = 0;
    while(cnt < n){
        bool flag = false;
        for(;idx<n;idx++){
            if(now >= v[idx].st){
                pq.push(v[idx]);
            }
            else break;
        }
        if(!pq.empty()){
            answer += now - pq.top().st + pq.top().ed;
            now += pq.top().ed;
            pq.pop();
            cnt++;
            flag = true;
        }
        if(!flag) now++;
    }
    answer = answer/n;
    return answer;
}