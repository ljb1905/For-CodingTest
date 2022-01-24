//프로그래머스 k진수에서 소수개수 구하기

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<long long> func(int n, int k){
    vector<long long> ret;
    queue<int> que;
    while(n>=k){
        int tmp = n%k;
        n/=k;
        if(tmp==0){
            long long ja = 1;
            long long now = 0;
            while(!que.empty()){
                now += que.front()*ja;
                que.pop();
                ja*=10;
            }
            ret.push_back(now);
        }
        else{
            que.push(tmp);
        }
    }
    que.push(n);
    long long ja = 1;
    long long now = 0;
    while(!que.empty()){
        now += que.front()*ja;
        que.pop();
        ja*=10;
    }
    ret.push_back(now);
    return ret;
}
bool prime_chk(long long n){
    if(n < 2) return false;        
    for(long long i=2; i*i<=n; i++) {
        if(n % i == 0) return false;
    }    
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    vector<long long> tmp = func(n,k);
    for(int i=0;i<tmp.size();i++){
        if(prime_chk(tmp[i])) answer++;
    }
    return answer;
}