//프로그래머스 전력망을 둘로 나누기

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int par[101];
int find(int n){
    if(par[n]==n) return n;
    return par[n] = find(par[n]);
}
void uni(int a,int b){
    a = find(a);
    b = find(b);
    par[b] = a;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    int minn = 987654321;
    for(int k=0;k<n-1;k++){
        for(int i=1;i<=n;i++){
            par[i] = i;
        }
        for(int i=0;i<wires.size();i++){
            if(i==k) continue;
            uni(wires[i][0],wires[i][1]);
        }
        for(int i=1;i<=n;i++){
            par[i] = find(i);
        }
        int bef = par[1];
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i=1;i<=n;i++){
            if(par[i]==bef) cnt1++;
            else cnt2++;
        }
        minn = min(abs(cnt1-cnt2),minn);
    }
    answer = minn;
    return answer;
}