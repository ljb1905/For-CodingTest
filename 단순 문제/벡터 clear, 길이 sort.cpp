//프로그래머스 튜플

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> func(string s){
    vector<vector<int>> ret;
    vector<int> inp;
    vector<int> tmp;
    bool sw = false;
    for(int i=1;i<s.size()-1;i++){
        if(s[i]=='{'){
            sw = true;
            if(inp.size()==0) continue;
            ret.push_back(inp);
            inp.clear();
            continue;            
        } 
        if(s[i]=='}'){
            int n = 1;
            int val = 0;
            for(int j=tmp.size()-1;j>=0;j--){
                val += tmp[j]*n;
                n*=10;
            }
            inp.push_back(val);
            sw = false;
            tmp.clear();
            continue;
        }
        if(sw==false && s[i]==',') continue;
        if(sw==true && s[i]==','){
            int n = 1;
            int val = 0;
            for(int j=tmp.size()-1;j>=0;j--){
                val += tmp[j]*n;
                n*=10;
            }
            inp.push_back(val);
            tmp.clear();
            continue;
        }
        tmp.push_back(s[i]-'0');
    }
    if(inp.size()>0){
        ret.push_back(inp);
    }
    return ret;
}
bool compare(vector<int> a, vector<int> b)
{
    return a.size() < b.size();
}

bool chk[100001];
vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> tmp = func(s);
    sort(tmp.begin(),tmp.end(),compare);
    for(int i=0;i<tmp.size();i++){
        for(int j=0;j<tmp[i].size();j++){
            int now = tmp[i][j];
            if(chk[now]) continue;
            chk[now] = true;
            answer.push_back(now);
            break;
        }
    }
    return answer;
}