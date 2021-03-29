#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool chk[31];
bool los[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    sort(reserve.begin(),reserve.end());
    for(int i=0;i<lost.size();i++){
        int now = lost[i];
        chk[now] = true;
        los[now] = true;
    }
    for(int i=0;i<reserve.size();i++){
        int now = reserve[i];
        if(los[now]==true){
            chk[now] = false;
            continue;
        }
        if(chk[now-1]==true){
            chk[now-1] = false;
            continue;
        }
        if(chk[now+1]==true){
            chk[now+1]=false;
        }
    }
    for(int i=1;i<=n;i++){
        if(chk[i]==false)
            answer++;
    }
    return answer;
}