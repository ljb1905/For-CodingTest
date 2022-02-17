#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end());
    int n = citations.size();
    for(int i=0;i<=n;i++){
        int cnt = 0;
        for(int j=0;j<citations.size();j++){
            if(i<=citations[j]){
                cnt++;
            }
        }
        if(i<=cnt){
            answer = i;
        }
    }
    return answer;
}