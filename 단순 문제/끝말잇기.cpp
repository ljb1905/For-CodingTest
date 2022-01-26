//프로그래머스 영어 끝말잇기

#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, int> mapp;
    mapp.insert(make_pair(words[0],1));
    for(int i=1;i<words.size();i++){
        string now = words[i];
        string bef = words[i-1];
        if(mapp[now] || bef[bef.size()-1] != now[0]){
            int num = i%n + 1;
            int cnt = i/n + 1;
            answer.push_back(num);
            answer.push_back(cnt);
            break;
        }
        mapp[now]++;
    }
    if(answer.size()==0){
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}