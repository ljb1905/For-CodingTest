#include <string>
#include <vector>
#include <queue>

using namespace std;
priority_queue <long long,vector<long long>,greater<long long>> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    for(int i=0;i<scoville.size();i++){
        pq.push(scoville[i]);
    }
    long long tmp = 0;
    bool flag = false;
    while(!pq.empty()){
        tmp = 0;
        if(pq.top()>=K){
            flag = true;
            break;   
        }
        if(pq.size()==1) break;
        tmp += pq.top();
        pq.pop();
        tmp += (long long)2*pq.top();
        pq.pop();
        pq.push(tmp);     
        answer++;
    }
    if(!flag) answer=-1;
    return answer;
}