#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int chk(double n){
    if(n==(int)n/1){
        return (int)n;
    }
    else{
        return (int)n+1;
    }
}

int func(int n, int s){
    int rem = 100 - n;
    int ret = chk(rem/(double)s);
    return ret;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    for(int i=0;i<progresses.size();i++){
        int cnt = 1;
        int now = func(progresses[i],speeds[i]);
        for(int j=i+1;j<progresses.size();j++){
            int next = func(progresses[j],speeds[j]);
            if(now>=next){
                cnt++;
                i++;
            }
            else{
                break;
            }
        }
        answer.push_back(cnt);
    }
    return answer;
}