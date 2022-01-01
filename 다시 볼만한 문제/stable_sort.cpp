#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string headd(string s){
    string ret = "";
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9') break;
        if(s[i]>='A' && s[i]<='Z') ret += s[i]-'A'+'a';
        else ret += s[i];
    }
    return ret;
}
int vall(string s){
    int ret = 0;
    string tmp = "";
    bool sw = false;
    for(int i=0;i<s.size();i++){
        if(sw && !(s[i]>='0' && s[i]<='9')){
            break;
        }
        if(!sw && !(s[i]>='0' && s[i]<='9')){
            continue;
        }
        if(s[i]>='0' && s[i]<='9'){
            sw = true;
            tmp += s[i];
        }
    }
    int num = 1;
    for(int i=tmp.size()-1;i>=0;i--){
        ret += num*(tmp[i]-'0');
        num*=10;
    }
    return ret;
}
bool comp(string a, string b){
    if(headd(a)==headd(b))
        return vall(a)<vall(b);
    return headd(a)<headd(b);
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    stable_sort(files.begin(),files.end(),comp);
    answer = files;
    return answer;
}