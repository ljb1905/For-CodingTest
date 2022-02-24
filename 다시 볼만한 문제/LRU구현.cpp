//프로그래머스 캐시

#include <string>
#include <map>
#include <vector>
#include <queue>

using namespace std;

queue<string> que;
map<string,int> mapp;

void tofirst(string s){
    queue<string> tmp;
    while(que.front()!=s){
        tmp.push(que.front());
        que.pop();
    }
    que.pop();
    while(!que.empty()){
        tmp.push(que.front());
        que.pop();
    }
    tmp.push(s);
    que = tmp;
    return;
}
string tosmall(string s){
    string ret = "";
    for(int i=0;i<s.size();i++){
        if(s[i]>='A' && s[i]<='Z'){
            ret += s[i]-'A'+'a';
        }
        else ret += s[i];
    }
    return ret;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int nowidx = 0;
    for(int i=0;i<cities.size();i++){
        string now = cities[i];
        now = tosmall(now);
        if(mapp[now]==0){
            answer+=5;
            mapp[now]++;
            que.push(now);
            if(que.size()>cacheSize){
                mapp[que.front()]--;
                que.pop();
            }
        }
        else{
            answer+=1;
            tofirst(now);
        }
    }
    return answer;
}