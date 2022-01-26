// 프로그래머스 방문 길이

#include <string>
#include <algorithm>
using namespace std;

bool chk[11][11][2];

int solution(string dirs) {
    int answer = 0;
    int i = 5, j = 5;
    for(int x=0;x<dirs.size();x++){
        char now = dirs[x];
        if(now=='U'){
            if(i==0) continue;
            if(!chk[i-1][j][1]) answer++;
            chk[i-1][j][1] = true;
            i--;
        }
        else if(now=='D'){
            if(i==10) continue;
            if(!chk[i][j][1]) answer++;
            chk[i][j][1] = true;
            i++;
        }
        else if(now=='R'){
            if(j==10) continue;
            if(!chk[i][j][0]) answer++;
            chk[i][j][0] = true;
            j++;
        }
        else{
            if(j==0) continue;
            if(!chk[i][j-1][0]) answer++;
            chk[i][j-1][0] = true;
            j--;
        }
    }
    return answer;
}