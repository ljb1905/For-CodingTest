//프로그래머스 추석 트래픽

#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(const pair<int,int>&a, const pair<int,int>&b){
    return a.second < b.second;
}

int toval(string s){
    int ret = 0;
    int n = 1;
    for(int i=s.size()-1;i>=0;i--){
        ret += (s[i]-'0')*n;
        n*=10;
    }
    return ret;
}

pair<int,int> val(string s){
    int ed = 0;
    ed = toval(s.substr(0,2))*3600000 + toval(s.substr(3,2))*60000 + toval(s.substr(6,2)) * 1000 + toval(s.substr(9,3));
    int st = ed;
    int timee = 0;
    bool sw = false;
    string inp = "";
    for(int i=13;i<s.size()-1;i++){
        if(s[i]=='.'){
            sw = true;
            timee += toval(inp)*1000;
            inp = "";
            continue;
        }
        inp+=s[i];
    }
    if(sw==false) inp+="000";
    else{
        while(inp.size()<3){
            inp+='0';
        }
    }    
    timee += toval(inp);
    //
    st-=timee;
    return make_pair(st+1, ed);
}

int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<int,int>> v;
    for(int i=0;i<lines.size();i++){
        string now = "";
        for(int j=11;j<lines[i].size();j++){
            now += lines[i][j];
        }
        pair<int,int> tmp = val(now); 
        v.push_back(tmp);
    }
    sort(v.begin(),v.end(),comp);
    for(int i=0;i<v.size();i++){
        int cnt = 1;
        int st = v[i].first;
        int ed = v[i].second;
        for(int j=i+1;j<v.size();j++){
            if(st+999>=v[j].first || ed+999>=v[j].first){
                cnt++;
            }
        }
        answer = max(cnt,answer);
    }
    return answer;
}