//프로그래머스 배달

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int dis[51];
struct s{
    int ed, cost;
    s(){}
    s(int ed, int cost):
        ed(ed),cost(cost)
        {}
    bool operator < (const s &o)const{
        return cost > o.cost;
    }
};

bool chk[51];

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    for(int i=2;i<=N;i++){
        dis[i] = 987654321;
    }
    priority_queue<s> pq;
    vector<s> v[51];
    for(int i=0;i<road.size();i++){
        v[road[i][0]].push_back(s(road[i][1],road[i][2]));
        v[road[i][1]].push_back(s(road[i][0],road[i][2]));
    }
    pq.push(s(1,0));
    while(!pq.empty()){
        s now = pq.top();
        pq.pop();
        if(chk[now.ed]) continue;
        chk[now.ed] = true;
        for(int i=0;i<v[now.ed].size();i++){
            s next = v[now.ed][i];
            if(dis[now.ed]+next.cost < dis[next.ed]){
                dis[next.ed] = dis[now.ed]+next.cost;
                pq.push(s(next.ed,dis[next.ed]));
            }
        }
    }
    for(int i=1;i<=N;i++){
        if(dis[i]<=K){
            answer++;
        }
    } 
    return answer;
}