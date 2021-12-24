#include <stdio.h>
#include <algorithm>

using namespace std;
long long GCD(long long a,long long b){ return (a%b==0 ? b:GCD(b,a%b));}

long long solution(int w,int h) {
    long long answer = 1;
    long long ww = max(w,h);
    long long hh = min(w,h);
    answer = hh*(ww-1) - (ww/GCD(ww,hh) - 1)*GCD(ww,hh);
    // answer = hh*(ww-1) - (ww - GCD(ww,hh));
    
    return answer;
}