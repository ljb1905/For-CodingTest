#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int l = s.size();
    int answer = l;
    for(int i=1;i<=l/2;i++){
        int cnt = 1;
        string compp = s.substr(0,i);
        string val = "";
        
        for(int j=i;j<l;j+=i){
            string tmp = s.substr(j,i);
            if(tmp==compp) cnt++;
            else {
                if(cnt==1){
                    val += compp;
                }
                else{
                    val += to_string(cnt);
                    val += compp;
                }
                cnt = 1;
                compp = tmp;
            }
        } 
        if(cnt>1) val += to_string(cnt);
        val += compp;
        int n = val.size();
        answer = min(answer,n);        
    }
    return answer;
}