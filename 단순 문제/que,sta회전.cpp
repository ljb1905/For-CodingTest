#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int tmp = n;
    int cnt = 0;
    for(int i=1;i<=n;i++){
        cnt += i;
    }
    queue<int> que[1001];
    stack<int> sta[1001];
    int i=0;
    bool sw = false;
    int now = 1;
    while(now <= cnt){
        if(i==n && !sw){
            while(que[i].size()+sta[i].size()<n){
                que[i].push(now++);
            }
            sw = !sw;
            n--;
        }
        else if(sw && que[i].size()+sta[i].size()==i && i<n){
            sw = !sw;
        }
        else if(sw){
            sta[--i].push(now++);
        }
        else if(!sw){
            que[++i].push(now++);
        }
    }
    for(int i=1;i<=tmp;i++){
        while(!que[i].empty()){
            answer.push_back(que[i].front());
            que[i].pop();
        }
        while(!sta[i].empty()){
            answer.push_back(sta[i].top());
            sta[i].pop();
        }
    }
    return answer;
}