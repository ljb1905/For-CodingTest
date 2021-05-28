#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    queue <int> q;
    priority_queue<int> pq;
    for(int i=0;i<priorities.size();i++){
        q.push(i);
        pq.push(priorities[i]);
    }
    int now = 101;
    while(now!=location){
        int nowidx = q.front();
        if(pq.top()==priorities[nowidx]){
            if(location == nowidx) break;
            pq.pop();
            q.pop();
            answer++;
        }
        else{
            q.push(q.front());
            q.pop();   
        }             
    }
    return answer;
}