#include <string>
#include <vector>
#include <stack>

using namespace std;

string fun(int n, int num){
    string ret = "";
    stack<char> s;
    while(num){
        int now = num%n;
        if(now>=0 && now<=9) s.push(now+'0');
        else{
            s.push(now-10+'A');
        }
        num/=n;
    }
    while(!s.empty()){
        ret += s.top();
        s.pop();
    }
    if(ret=="") ret+='0';
    return ret;   
    
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int x = 0;
    int now = 0;
    int l = 0;
    int step = p;
    while(x!=t){
        string tmp = fun(n,now);
        //
        //printf("%s\n",tmp.c_str());
        l+=tmp.size();
        if(step<=l){
            int cha = l-step;
            answer += tmp[tmp.size()-1-cha];
            step += m;
            x++;
        }
        now++;
    }
    return answer;
}