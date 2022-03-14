#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    map<string,int> mapp;
    map<string,int> nowmapp;
    int cnt = 1;
    for(int i=0;i<gems.size();i++){
        if(mapp.find(gems[i])==mapp.end()){
            mapp.insert(make_pair(gems[i],cnt++));
        }
    }
    cnt--;
    int l = 0;
    int r = 0;
    int ansl = 0;
    int ansr = gems.size()-1;
    int ansmin = 987654321;
    int nowcnt = 1;
    nowmapp[gems[l]]++;
    int n = gems.size();
    while(1){
        if(l==n) break;
        if(nowcnt<cnt){
            r++;
            if(r==n) break;
            if(nowmapp[gems[r]]==0){
                nowcnt++;
            }
            nowmapp[gems[r]]++;
        }
        else{
            if(nowmapp[gems[l]]<=1){
                if(ansmin > r-l){
                    ansl = l;
                    ansr = r;
                    ansmin = r-l;
                }
                nowcnt--;
            }
            nowmapp[gems[l]]--;
            l++;        
        }
    }
    answer.push_back(ansl+1);
    answer.push_back(ansr+1);
    return answer;
}