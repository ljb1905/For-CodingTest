#include <string>
#include <vector>
#include <stack>

using namespace std;

int cnt = 0;

string remv(string s){
    string ret = "";
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            cnt++;
            continue;
        }
        ret += s[i];
    }
    return ret;
}
string to_bin(int n){
    stack<char> sta;
    string ret = "";
    while(n>1){
        if(n%2) sta.push('1');
        else sta.push('0');
        n/=2;
    }
    if(n==0) sta.push('0');
    if(n==1) sta.push('1');
    while(!sta.empty()){
        ret += sta.top();
        sta.pop();
    }
    return ret;    
}

vector<int> solution(string s) {
    vector<int> answer;
    int stepp=0;
    while(s!="1"){
        stepp++;
        s = remv(s);
        int l = s.size();
        s = to_bin(l);
    }
    answer.push_back(stepp);
    answer.push_back(cnt);
    return answer;
}