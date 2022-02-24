//프로그래머스 예상 대진표

#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    while(1){
        if(a%2==1) a++;
        if(b%2==1) b++;
        if(a==b) break;
        answer++;
        a/=2;
        b/=2;
    }
    return answer;
}