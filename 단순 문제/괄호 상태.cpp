//프로그래머스 괄호 회전하기

#include <string>
#include <vector>
#include <stack>

using namespace std;

bool chk(string s){
    stack<char> sta;
    for(int i=0;i<s.size();i++){
        char now = s[i];
        if(now=='[' || now=='(' || now=='{') sta.push(now);
        if(now==']'){
            if(!sta.empty() && sta.top()=='['){
                sta.pop();
                continue;
            }
            else{
                return false;
            }
        }
        else if(now==')'){
            if(!sta.empty() && sta.top()=='('){
                sta.pop();
                continue;
            }
            else{
                return false;
            }
        }
        else if(now=='}'){
            if(!sta.empty() && sta.top()=='{'){
                sta.pop();
                continue;
            }
            else{
                return false;
            }
        }        
    }
    if(!sta.empty()) return false;
    return true;
}

int solution(string s) {
    int answer = 0;
    for(int i=0;i<s.size();i++){
        string now = "";
        for(int j=0;j<s.size();j++){
            int idx = (i+j)%s.size();
            now += s[idx];
        }
        if(chk(now)) answer++;
    }
    return answer;
}