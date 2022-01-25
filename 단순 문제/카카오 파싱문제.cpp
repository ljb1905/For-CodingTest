#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int inval[10001];
int summin[10001];

int toint(string s){
    int ret = 0;
    int n = 1;
    for(int i=s.size()-1;i>=0;i--){
        ret += (s[i] - '0') * n;
        n *= 10;
    }
    return ret;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<int> listt;
    for(int i=1;i<=9999;i++){
        inval[i]=-1;
    }
    for(int i=0;i<records.size();i++){
        string now = records[i];
        int nowh = toint(now.substr(0,2));
        int nowm = toint(now.substr(3,2));
        int timee = nowh*60+nowm;
        int nownum = toint(now.substr(6,4));
        if(now[11]=='I'){
            if(summin[nownum]==0) listt.push_back(nownum);
            inval[nownum] = timee;
        }
        else{
            summin[nownum]+=timee - inval[nownum];
            inval[nownum] = -1;
        }
    }
    for(int i=0;i<listt.size();i++){
        int now = listt[i];
        if(inval[now]==-1) continue;
        summin[now]+=1439-inval[now];
        inval[now] = 0;
    }
    sort(listt.begin(),listt.end());
    for(int i=0;i<listt.size();i++){
        int now = listt[i];
        int timee = summin[now];
        //
        printf("%d\n",timee);
        int ret = 0;
        ret += fees[1];
        timee = max(0,timee - fees[0]);
        int rem = 0;
        if(timee % fees[2] >= 1){
            rem++;
        }
        ret += (timee/fees[2] + rem)*fees[3];
        answer.push_back(ret);
    }
    
    return answer;
}