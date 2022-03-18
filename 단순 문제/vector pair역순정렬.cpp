#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int chal[501];
int noty[501];
bool comp(pair<int,double> a, pair<int,double> b) {
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second>b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    for(int i=1;i<=N;i++){
        for(int j=0;j<stages.size();j++){
            if(stages[j]>=i){
                chal[i]++;
            }
            if(stages[j]==i){
                noty[i]++;
            }
        }
    }
    vector<pair<int,double>> arr;
    for(int i=1;i<=N;i++){
        double inp = 0;
        if(chal[i]!=0) inp = (double)noty[i]/(double)chal[i];
        arr.push_back(make_pair(i,inp));
    }
    sort(arr.begin(),arr.end(), comp);
    for(int i=0;i<arr.size();i++){
        answer.push_back(arr[i].first);
    }
    return answer;
}