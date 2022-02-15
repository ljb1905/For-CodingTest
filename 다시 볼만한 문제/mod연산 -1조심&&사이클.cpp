//프로그래머스 빛의 경로 사이클

#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool chk[501][501][4];
vector<int> answer;
int n, m;

int nextfun(int nowdir, char now){
    if(now=='S') return nowdir;
    else if(now=='L') return (nowdir-1+4)%4;
    else return (nowdir+1)%4;
}

void dfs(int sty, int stx, int stdir, int y,int x,int dir, vector<string> &grid, int cnt){
    if(cnt!=0 && sty==y && stx==x && stdir==dir){
        answer.push_back(cnt);
        return;
    }
    chk[y][x][dir] = true;
    int nextdir = nextfun(dir,grid[y][x]);
    if(nextdir==1) x = (x+1)%m;
    else if(nextdir==2) y = (y+1)%n;
    else if(nextdir==3) x = (x-1+m)%m;
    else y = (y-1+n)%n;
    //if(chk[y][x][nextdir]) return;
    dfs(sty,stx,stdir,y,x,nextdir,grid,cnt+1);
}

vector<int> solution(vector<string> grid) {
    n = grid.size();
    m = grid[0].size();
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            for(int k=0;k<4;k++){
                if(chk[i][j][k]) continue;
                dfs(i,j,k,i,j,k,grid,0);
            }
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}