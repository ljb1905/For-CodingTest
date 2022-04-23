#include <string>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <map>

using namespace std;

queue <pair<string,int>> q;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    map <string, int> m;
    //m.insert(make_pair(begin,1));
    q.push(make_pair(begin,0));
    while(!q.empty()){
        string tmp = q.front().first;
        int num = q.front().second;
        int l = tmp.length();
        q.pop();
        //존재하지 않으면 end 반환
        if(m.count(tmp)){//이미 존재
            continue;
        }
        // for(auto it = m.begin();it!=m.end();it++){
        //     printf("%s\n",it->first.c_str());
        // }
        m.insert(make_pair(tmp,1));
        int anschk = 0;
        for(int i=0;i<l;i++){
            if(tmp[i]==target[i])
                anschk++;
        }
        if(anschk==l){
            answer = num;
            break;
        }
        for(int i=0;i<words.size();i++){
            int cnt = 0;
            for(int j=0;j<l;j++){
                if(tmp[j]==words[i][j]){
                    cnt++;
                }
            }
            if(cnt==l-1){
                q.push(make_pair(words[i],num+1));
            }
        }
    }
    return answer;
}