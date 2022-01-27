//프로그래머스 압축

#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> mapp;
    int idx = 1;
    for(idx = 1;idx<=26;idx++){
        string tmp = "";
        tmp += 'A'+idx-1;
        mapp.insert(make_pair(tmp,idx));
    }
    for(int i=0;i<msg.size();){
        int j=1;
        int inp = 0;
        for(j=1;j<=msg.size();j++){
            if(i+j>msg.size()){
                break;
            }
            string now = msg.substr(i,j);
            if(!mapp.count(now)){
                mapp.insert(make_pair(now,idx++));
                break;
            }
            else{
                inp = mapp[now];
            }
        }
        answer.push_back(inp);
        if(j==1) i++;
        else i+=j-1;
    }
    return answer;
}