#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    stack<char> sta;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9') sta.push(s[i]);
        else{
            if(s[i]=='z'){
                sta.push('0');
                i+=3;
            }
            else if(s[i]=='o'){
                sta.push('1');
                i+=2;
            }
            else if(s[i]=='t' && s[i+1]=='w'){
                sta.push('2');
                i+=2;
            }
            else if(s[i]=='t' && s[i+1]=='h'){
                sta.push('3');
                i+=4;
            }
            else if(s[i]=='f' && s[i+1]=='o'){
                sta.push('4');
                i+=3;
            }
            else if(s[i]=='f' && s[i+1]=='i'){
                sta.push('5');
                i+=3;
            }
            else if(s[i]=='s' && s[i+1]=='i'){
                sta.push('6');
                i+=2;
            }
            else if(s[i]=='s' && s[i+1]=='e'){
                sta.push('7');
                i+=4;
            }
            else if(s[i]=='e'){
                sta.push('8');
                i+=4;
            }
            else{
                sta.push('9');
                i+=3;
            }
        }
    }
    int num = 1;
    while(!sta.empty()){
        answer+=num*(sta.top()-'0');
        sta.pop();
        num*=10;
    }
    return answer;
}