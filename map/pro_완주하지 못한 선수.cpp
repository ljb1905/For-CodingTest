#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;
    for(auto c:completion){
        m[c]++; // 동명이인 존재
    }
    for(auto p:participant){
        m[p]--;
        if(m[p]<0){
            answer = p;
        }
    }
    return answer;
}