#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> split(string s, char c){
    vector<string> v;
    string inp = "";
    for(int i=0;i<s.size();i++){
        if(s[i]==c){
            v.push_back(inp);
            inp = "";
            continue;
        }
        else{
            inp += s[i];
        }
    }
    if(inp!="") v.push_back(inp);
    return v;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    for(int i=0;i<record.size();i++){
        if(record[i][0]=='E'){
            vector<string> tmp = split(record[i], ' ');
            m[tmp[1]] = tmp[2];
        }
        else if(record[i][0]=='C'){
            vector<string> tmp = split(record[i], ' ');
            m[tmp[1]] = tmp[2];
        }
    }
    for(int i=0;i<record.size();i++){
        string inp="";
        if(record[i][0]=='E'){
            vector<string> tmp = split(record[i], ' ');
            inp += m[tmp[1]].c_str();
            inp += "님이 들어왔습니다.";
            answer.push_back(inp);
        }
        else if(record[i][0]=='L'){
            vector<string> tmp = split(record[i], ' ');
            inp += m[tmp[1]].c_str();
            inp += "님이 나갔습니다.";
            answer.push_back(inp);
        }
    }
    return answer;
}