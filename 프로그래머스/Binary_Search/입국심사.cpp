#include <string>
#include <limits.h>
#include <algorithm>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer= 0;
    int m = times.size();
    int maxx=0;
    for(int i=0;i<m;i++){
        maxx=max(maxx,times[i]);
    }
    long long l=1,r=(long long)maxx*n,mid;
    while(l<=r){
        mid = (l+r)/(long long)2;
        long long tmp=0;
        for(int i=0;i<m;i++){
            tmp += (mid /(long long) times[i]);
        }
        if(tmp>=n){
            r = (long long)mid-1;
        }
        else{
            l = (long long)mid+1;
        }
    }
    answer = l;
    return answer;
}