#include <string>
#include <vector>
#include <queue>

using namespace std;
queue <int> q;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int cnt = 0;
    int now_weight = 0;
    for(int i=0;i<truck_weights.size();){
        int now = truck_weights[i];
        answer++;
        if(q.size()==bridge_length){
            now_weight-=q.front();
            q.pop();
        }
        if(now_weight+now<=weight){
            if(i==truck_weights.size()-1){
                answer+=bridge_length;
                break;
            }
            q.push(now);
            now_weight += now;
            i++;
        }
        else{
            q.push(0);
        }
    }
    return answer;
}