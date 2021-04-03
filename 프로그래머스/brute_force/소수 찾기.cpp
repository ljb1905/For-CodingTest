#include <string>
#include <vector>
#include <math.h>

using namespace std;
const int maxnum = 87654321;
bool not_prime[maxnum];
int l;
int arr[8];
bool chk[8];

void dfs(int now){
    if(now==l){
        for(int i=0;i<l)
    }
}

int solution(string numbers) {
    int l = numbers.size();
    int rootnum = (int)sqrt(maxnum);
    for(int i=2;i<rootnum;i++){
        if(not_prime[i]==true){
            continue;
        }
        for(int j=i*2;j<maxnum;j+=i){
            not_prime[j] = true;
        }
    }    
    int answer = 0;
    return answer;
}