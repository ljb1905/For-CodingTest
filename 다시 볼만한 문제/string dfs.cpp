#include <string>
#include <vector>

using namespace std;
bool notPrime[10000000];
void initt(){
    notPrime[0] = true;
    notPrime[1] = true;
    for(int i=2;i*i<10000000;i++){
        if(notPrime[i]) continue;
        for(int j=i*2;j<10000000;j+=i){
            notPrime[j] = true;
        }
    }
    return;
}

bool chk[8];
int answer = 0;

int val(string s){
    int ret = 0;
    int n = 1;
    for(int i=s.size()-1;i>=0;i--){
        ret += n*(s[i]-'0');
        n*=10;
    }
    return ret;
}

void dfs(string ori, string s){
    if(!notPrime[val(s)])
    {
        notPrime[val(s)] = true;//
        answer++;
    }
    if(s.size()==ori.size()){
        return;
    }
    for(int i=0;i<ori.size();i++){
        if(chk[i]) continue;
        chk[i] = true;
        char tmp = ori[i];
        s += tmp;
        dfs(ori,s);
        s.erase(s.size()-1,1);
        chk[i] = false;
    }
    return;    
}


int solution(string numbers) {
    initt();
    dfs(numbers,"");
    return answer;
}