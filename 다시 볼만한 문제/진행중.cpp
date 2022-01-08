#include <string>
#include <map>
#include <algorithm>

using namespace std;

string initt(string s){
    string ret = "";
    for(int i=0;i<s.size();i++){
        if(s[i]<='z' && s[i]>='a'){
            ret += s[i];
        }
        else if(s[i]<='Z' && s[i]>='A'){
            ret += s[i] - 'A' + 'a';
        }
        else ret+=s[i];
    }
    return ret;
}
bool chk(char inp){
    if(inp<'a' || inp>'z') return false;
    return true;
}

int solution(string str1, string str2) {
    int answer = 0;
    str1 = initt(str1);
    str2 = initt(str2);
    map<string, int> mapp1;
    map<string, int> mapp2;
    int allcnt = 0;
    int comcnt = 0;
    for(int i=0;i<str1.size()-1;i++){
        if(!chk(str1[i]) || !chk(str1[i+1])) continue;
        string tmp = "";
        tmp += str1[i];
        tmp += str1[i+1];
        //if(mapp1[tmp]) continue;
        mapp1[tmp]++;
        allcnt++;
    }
    for(int i=0;i<str2.size()-1;i++){
        if(!chk(str2[i]) || !chk(str2[i+1])) continue;
        string tmp = "";
        tmp += str2[i];
        tmp += str2[i+1];
        //if(mapp2[tmp]) continue;
        if(mapp1.count(tmp)){
            //
            //printf("공통 %s\n",tmp.c_str());
            comcnt++;
        }
        else{
           //
            //printf("혼자 %s\n",tmp.c_str()); 
            allcnt++;
        } 
        mapp2[tmp]++;
    }
    int tmp = allcnt;
    allcnt = max(allcnt,comcnt);
    comcnt = min(tmp,comcnt);
    if(allcnt==0) answer = 65536;
    else answer = comcnt*65536 / allcnt;
    //printf("%d %d\n",comcnt,allcnt);
    return answer;
}