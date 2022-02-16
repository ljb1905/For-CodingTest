//프로그래머스 큰 수 만들기

#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<char> sta;
    for(int i=0;i<number.size();i++){
        char now = number[i];
        while(!sta.empty() && sta.top()<now && k>0){
            sta.pop();
            k--;
            if(k==0) break;
        }
        sta.push(now);
    }
    string tmp = "";
    while(!sta.empty()){
        tmp += sta.top();
        sta.pop();
    }
    int cnt = number.size()-k;
    for(int i=tmp.size()-1;i>=0 && cnt>0;i--){
        answer+=tmp[i];
        cnt--;
    }
    return answer;
}