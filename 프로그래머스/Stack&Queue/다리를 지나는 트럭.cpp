#include <string>
#include <queue>
#include <vector>

using namespace std;
queue <int> q;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int cnt = 0;
    int idx = 0;
    int now_weight = 0;
    while(idx < truck_weights.size()){
        int now = truck_weights[idx];
        if(q.size()<bridge_length && weight>=now+now_weight){
            now_weight += now;
            q.push(now);
            if(idx==0){
                answer++;
            }
            idx++;
        }
        else{
            if(q.size()>1){
                answer++;
                cnt++;
                now_weight -= q.front();
                q.pop();
            }
            else{
                answer += bridge_length - cnt;
                cnt=0;
                idx++;
            }
        }
        printf("%d\n",answer);
    }
    return answer;
}