#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[12];
int tmpans[12];
int comp = -987654321;
pair<int,int> calc(vector<int> &info){
    int asum = 0;
    int lsum = 0;
    for(int i=0;i<10;i++){
        if(arr[i]>info[i]) lsum += 10-i;
        else if(info[i]>=1) asum += 10-i;
    }
    return make_pair(asum,lsum);
}

void dfs(int n, vector<int> &info, int now){
    if(now==n){
        int asum = calc(info).first;
        int lsum = calc(info).second;
        if(asum < lsum){
            if(comp <= lsum-asum){
                comp = lsum-asum;
                for(int i=0;i<11;i++){
                    tmpans[i] = arr[i];
                }
            }
        }
        return;
    }
    for(int i=0;i<11 && arr[i] <= info[i];i++){
        arr[i]++;
        dfs(n,info,now+1);
        arr[i]--;
    }
    return;
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    dfs(n,info,0);
    if(comp==-987654321) answer.push_back(-1);
    else{
        for(int i=0;i<11;i++){
            answer.push_back(tmpans[i]);
        }
    }    
    return answer;
}