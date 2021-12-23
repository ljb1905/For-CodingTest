#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string fir_fun(string s){
    int l = s.size();
    for(int i=0;i<l;i++){
        if(s[i]<='Z' && s[i]>='A'){
            s[i] = s[i] - 'A' + 'a';
        }
    }
    return s;
}
string sec_fun(string s){
    int l = s.size();
    string ret = "";
    for(int i=0;i<l;i++){
        if(s[i]<='z' && s[i]>='a') ret.push_back(s[i]);
        else if(s[i]<='9' && s[i]>='0') ret.push_back(s[i]);
        else if(s[i]=='-' || s[i]=='_' || s[i]=='.') ret.push_back(s[i]);
    }
    return ret;
}
string thi_fun(string s){
    int l = s.size();
    string ret = "";
    for(int i=0;i<l;i++){
        if(i!=l-1 && s[i]=='.' && s[i+1]=='.') continue;        
        ret.push_back(s[i]);
    }
    return ret;
}
string fou_fun(string s){
    if(s[0]=='.') s.erase(0,1);
    if(s[s.size()-1]=='.') s.erase(s.size()-1,1);
    return s;
}
string fif_fun(string s){
    if(s.size()==0) s.push_back('a');
    return s;
}
string six_fun(string s){
    string ret = "";
    int l = 15;
    int tmp = s.size();
    l = min(tmp,l);    
    for(int i=0;i<l;i++){
        ret.push_back(s[i]);
    }
    if(ret[ret.size()-1]=='.') ret.erase(ret.size()-1,1);
    return ret;
}
string sev_fun(string s){
    if(s.size()<=2){
        while(s.size()<3){
            s.push_back(s[s.size()-1]);
        }
    }
    return s;
}

string solution(string new_id) {
    string answer = "";
    new_id = fir_fun(new_id);
    new_id = sec_fun(new_id);
    new_id = thi_fun(new_id);
    new_id = fou_fun(new_id);
    new_id = fif_fun(new_id);
    new_id = six_fun(new_id);
    new_id = sev_fun(new_id);
    answer = new_id;
    return answer;
}