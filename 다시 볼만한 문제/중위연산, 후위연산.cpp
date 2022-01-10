#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

map<char, int> mapp;

string trans(string s){
    string ret = "";
    stack<char> sta;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9') ret += s[i];
        else{
            ret+=' ';
            while(!sta.empty() && mapp[sta.top()]>=mapp[s[i]]){
                ret += sta.top();
                ret +=' ';
                sta.pop();
            }
            sta.push(s[i]);
        }
    }
    while(!sta.empty()){
        ret +=' ';
        ret += sta.top();
        sta.pop();
    }
    ret += ' ';
    return ret;
}
long long val(string s){
    long long ret = 0;
    long long n = 1;
    for(int i=s.size()-1;i>=0;i--){
        ret += (s[i]-'0')*n;
        n*=10;
    }
    return ret;
}
int findnext(string s, int st){
    for(int i=st;i<s.size();i++){
        if(s[i]==' ') return i;
    }
    return s.size()-1;
}
long long func(string s){
    long long ret = 0;
    stack<long long> sta;
    for(int i=0;i<s.size();i++){
        if(s[i]==' ') continue;
        if(s[i]>='0' && s[i]<='9'){
            int nexti = findnext(s,i);
            int cha = nexti - i;
            sta.push(val(s.substr(i,cha)));
            i+=cha-1;
        }
        else{
            long long now2 = sta.top();
            sta.pop();
            long long now1 = sta.top();
            sta.pop();
            if(s[i]=='*'){
                sta.push(now1*now2);
            }
            else if(s[i]=='+'){
                sta.push(now1+now2);
            }
            else{
                sta.push(now1-now2);
            }
        }
    }
    ret = sta.top();
    return abs(ret);
}

long long solution(string expression) {
    long long answer = 0;
    mapp['*'] = 3, mapp['+'] = 2, mapp['-'] = 1;
    string tmp = trans(expression);
    answer = max(answer,func(tmp));
    mapp['*'] = 3, mapp['+'] = 1, mapp['-'] = 2;
    tmp = trans(expression);
    answer = max(answer,func(tmp));
    mapp['*'] = 2, mapp['+'] = 3, mapp['-'] = 1;
    tmp = trans(expression);
    answer = max(answer,func(tmp));
    mapp['*'] = 2, mapp['+'] = 1, mapp['-'] = 3;
    tmp = trans(expression);
    answer = max(answer,func(tmp));
    mapp['*'] = 1, mapp['+'] = 3, mapp['-'] = 2;
    tmp = trans(expression);
    answer = max(answer,func(tmp));
    mapp['*'] = 1, mapp['+'] = 2, mapp['-'] = 3;
    tmp = trans(expression);
    answer = max(answer,func(tmp));
    
    return answer;
}