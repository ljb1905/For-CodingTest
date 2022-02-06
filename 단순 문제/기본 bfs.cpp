//프로그래머스 게임 맵 최단거리

#include<vector>
#include <stdio.h>
#include <queue>
using namespace std;

struct s{
    int y,x,cnt;
    s(){}
    s(int y, int x, int cnt)
        :y(y),x(x),cnt(cnt)
    {}
};
int dy[4] = {-1,0,1,0};
int dx[4] = {0,-1,0,1};

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    int n = maps.size();
    int m = maps[0].size();
    queue<s> que;
    que.push(s(0,0,1));
    maps[0][0] = 0;
    while(!que.empty()){
        s now = que.front();
        que.pop();
        if(now.y==n-1 && now.x==m-1){
            answer = now.cnt;
            break;
        }
        for(int i=0;i<4;i++){
            int nexty = now.y + dy[i];
            int nextx = now.x + dx[i];
            if(nextx<0 || nexty<0 || nexty>=n || nextx>=m) continue;
            //printf("%d %d %d\n",nexty,nextx,now.cnt);
            if(maps[nexty][nextx]==0) continue;
            que.push(s(nexty,nextx,now.cnt+1));
            maps[nexty][nextx] = 0;
        }
    }
    return answer;
}