//프로그래머스 방금그곡

#include <string>
#include <vector>

using namespace std;
vector<string> tolist(string s){
    vector<string>ret;
    int cnt = 0;
    int idx = 0;
    while(cnt<3){
        if(s[idx]==',') cnt++;
        idx++;
    }
    for(int i=idx;i<s.size();i++){
        string tmp = "";
        tmp+=s[i];
        if(i!=s.size()-1 && s[i+1]=='#'){
            tmp+=s[i+1];
            i++;
        }
        ret.push_back(tmp);
    }
    return ret;
}
int toval(string s){
    int n = 1;
    int ret = 0;
    for(int i=s.size()-1;i>=0;i--){
        ret += (s[i]-'0')*n;
        n*=10;
    }
    return ret;
}
int calctime(string s){
    int aft = toval(s.substr(6,2))*60+toval(s.substr(9,2));
    int bef = toval(s.substr(0,2))*60+toval(s.substr(3,2));
    return aft-bef;
}
string calctitle(string s){
    int cnt = 0;
    string ret = "";
    int idx = 0;
    while(cnt<2){
        if(s[idx]==',') cnt++;
        idx++;
    }
    while(s[idx]!=','){
        ret += s[idx++];
    }
    return ret;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    int anstime = 0;
    for(int i=0;i<musicinfos.size();i++){
        int timee = calctime(musicinfos[i]);
        string titlee = calctitle(musicinfos[i]);
        vector<string> listt = tolist(musicinfos[i]);
        //printf("%d %s\n",timee,titlee.c_str());
        string reall = "";
        for(int j=0;j<timee;j++){
            reall+=listt[j%listt.size()];
        }
        int tmp = reall.size()-m.size();
        for(int j=0;j<=tmp;j++){
            bool sw = true;
            for(int k=0;k<m.size();k++){
                if(m[k]!=reall[k+j]){
                    sw = false;
                    break;
                }
            }
            if(m.size()+j!=reall.size()-1 && reall[m.size()+j]=='#') sw = false;
            if(sw && anstime < timee){
                anstime = timee;
                answer = titlee;
            }
        }
    }
    if(answer =="") answer = "(None)";
    return answer;
}