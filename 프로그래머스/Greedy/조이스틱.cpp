#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int calc(char a){
    int ret = min('Z'-a+1,a-'A');
    return ret;
}
bool chk[21];
int l;

int solution(string name) {
    int answer = 0;
    int idx = 0;
    int cnt = 0;
    l = name.length();
    for(int i=0;i<l;i++){
        if(name[i]!='A'){
            chk[i] = true;
            cnt++;
        } 
    }
    while(cnt){
        if(cnt==0) break;
        int tmp[2] = {0,};
        int tmpidx[2] = {idx,idx};
        while(!chk[tmpidx[0]]){
            tmpidx[0]++;
            tmp[0]++;
            if(tmpidx[0]==l)
                tmpidx[0] = 0;
        }
        while(!chk[tmpidx[1]]){
            tmpidx[1]--;
            tmp[1]++;
            if(tmpidx[1]==-1)
                tmpidx[1] = l-1;
        }
        int ans = min(tmp[0],tmp[1]);
        if(ans==tmp[0]){
            answer+=tmp[0];
            idx = tmpidx[0];
        }
        else{
            answer+=tmp[1];
            idx = tmpidx[1];
        }
        answer+=calc(name[idx]);
        chk[idx] = false;
        cnt--;
    }    
    return answer;
}