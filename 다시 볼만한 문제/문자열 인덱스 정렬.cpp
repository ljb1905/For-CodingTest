//프로그래머스 문자열 내 마음대로 정렬하기

#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N;
bool comp(string a,string b){
    if(a[N] == b[N]){
        return a<b;
    }
    return a[N] < b[N];
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    N = n;
    sort(strings.begin(),strings.end(),comp);
    answer = strings;
    return answer;
}