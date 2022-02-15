#include <string>
#include <vector>
#include <stack>

using namespace std;

pair<string, string> sepfun(string s){
    string ret1 = "";
    string ret2 = "";
    int cnt1 = 0;
    int cnt2 = 0;
    int idx = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') cnt1++;
        else cnt2++;
        if(cnt1==cnt2){
            idx = i;
            break;
        }
    }
    for(int i=0;i<=idx;i++){
        ret1 += s[i];
    }
    for(int i=idx+1;i<s.size();i++){
        ret2 += s[i];
    }
    return make_pair(ret1,ret2);
}

bool ollchk(string s){
    stack<char> sta;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') sta.push('(');
        else if(!sta.empty() && sta.top()=='(') sta.pop();
        else return false;
    }
    if(!sta.empty()) return false;
    return true;
}

string solution(string p) {
    string answer = "";
    if(p=="") return "";
    pair<string, string> ret = sepfun(p);
    if(ollchk(ret.first)) return ret.first + solution(ret.second);
    string newret = "(" + solution(ret.second) + ")";
    for(int i=1;i<ret.first.size()-1;i++){
        if(ret.first[i]=='(') newret += ')';
        else newret += '(';
    }
    return newret;
}