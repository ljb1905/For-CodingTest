#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string parss(string inp){
    string ret = "";
    for(int i=0;i<inp.size();i++){
        if(inp[i]==' ') break;
        ret += inp[i];
    }
    return ret;    
}
string parss2(string inp){
    string ret = "";
    int idx = 0;
    for(int i=0;i<inp.size();i++){
        if(inp[i]==' '){
            idx = i+1;
            break;
        }
    }
    for(int i=idx;i<inp.size();i++){
        ret += inp[i];
    }
    return ret;  
}

bool arr[1001][1001];
int cnt[1001];

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string ,int> mapp;
    sort(report.begin(),report.end());
    int n = 0;
    for(int i=0;i<report.size();i++){
        string st = parss(report[i]);
        string ed = parss2(report[i]);
        if(!mapp.count(st)) mapp.insert(make_pair(st,++n));
        if(!mapp.count(ed)) mapp.insert(make_pair(ed,++n));
        int now = mapp[st];
        int next = mapp[ed];
        if(arr[now][next]) continue;
        arr[now][next] = 1;        
        cnt[next]++;
    }
    for(int i=0;i<id_list.size();i++){
        int now = mapp[id_list[i]];
        int inpp = 0;
        for(int j=1;j<=n;j++){
            if(!arr[now][j]) continue;
            if(cnt[j]>=k){
                inpp++;
            }
        }
        answer.push_back(inpp);
    }
    return answer;
}