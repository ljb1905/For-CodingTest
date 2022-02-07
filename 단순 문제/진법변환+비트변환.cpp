//프로그래머스 2개 이하로 다른 비트

#include <string>
#include <vector>
#include <stack>

using namespace std;

string func(long long n){
    string ret = "";
    stack<char> sta;
    while(n){
        if(n%2) sta.push('1');
        else sta.push('0');
        n/=2;
    }
    while(!sta.empty()){
        ret += sta.top();
        sta.pop();
    }
    return ret;
}
long long valf(string s){
    long long ret = 0;
    long long n = 1;
    for(int i=s.size()-1;i>=0;i--){
        ret += (s[i]-'0')*n;
        n*=2;
    }
    return ret;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(int i=0;i<numbers.size();i++){
        long long now = numbers[i];
        string tmp = "0";
        tmp += func(now);
        int idx = 0;
        for(int j=tmp.size()-1;j>=0;j--){
            if(tmp[j]=='0'){
                tmp[j]='1';
                idx = j;
                break;
            }
        }
        for(int j=idx+1;j<tmp.size();j++){
            if(tmp[j]=='1'){
                tmp[j] = '0';
                break;
            }
        }
        answer.push_back(valf(tmp));
    }
    return answer;
}