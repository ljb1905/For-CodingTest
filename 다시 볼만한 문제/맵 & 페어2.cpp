#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;
    for(int i=0;i<clothes.size();i++){
        m[clothes[i][1]]++;
    }
    //map<string,int>::iterator it;
    for(auto it=m.begin();it!=m.end();it++){
        answer *= it->second+1;
    }
    answer--;
    return answer;
}