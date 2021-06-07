#include <string>
#include <queue>
#include <stdlib.h>
#include <vector>

using namespace std;

priority_queue <int> maxpq;
priority_queue <int, vector<int>, greater<int>> minpq;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int cnt = 0;
    for(int i=0;i<operations.size();i++){
        if(operations[i][0]=='I'){
            cnt++;
            int num = atoi(&operations[i][2]);
            minpq.push(num);
            maxpq.push(num);
        }
        else if(operations[i][0]=='D' && operations[i][2]=='1' && cnt){
            cnt--;
            maxpq.pop();
        }
        else if(operations[i][0]=='D' && operations[i][2]=='-' && cnt){
            cnt--;
            minpq.pop();
        }
        if(!cnt){
            while(!maxpq.empty()){
                maxpq.pop();
            }
            while(!minpq.empty()){
                minpq.pop();
            }
        }
    }
    if(!cnt){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(maxpq.top());
        answer.push_back(minpq.top());
    }
    return answer;
}