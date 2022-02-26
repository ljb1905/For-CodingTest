//프로그래머스 교점에 별 만들기

#include <string>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

bool comp(const pair<long long,long long> &a, const pair<long long,long long> &b){
    if(a.first == b.first){
        if(a.second < b.second) return true;
    }
    if(a.first > b.first) return true;
    else return false;    
}

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<pair<long long,long long>> tmp;
    long long maxx=LLONG_MIN;
    long long maxy=LLONG_MIN;
    long long minx=LLONG_MAX;
    long long miny=LLONG_MAX;
    for(int i=0;i<line.size();i++){
        for(int j=i+1;j<line.size();j++){
            long long xx = (long long)line[i][1]*line[j][2] - (long long
                                                               )line[i][2]*line[j][1];
            long long div = (long long)line[i][0]*line[j][1] - (long long)line[i][1]*line[j][0];
            if(div==0) continue;
            if(xx%div!=0) continue;
            xx /= div;
            long long yy = (long long)line[i][2]*line[j][0] - (long long)line[i][0]*line[j][2];
            if(yy%div!=0) continue;
            yy /= div;
            maxx = max(maxx,xx);
            minx = min(minx,xx);
            maxy = max(maxy,yy);
            miny = min(miny,yy);
            tmp.push_back(make_pair(yy,xx));
        }
    }
    sort(tmp.begin(),tmp.end(),comp);
    // for(int i=0;i<tmp.size();i++){
    //     printf("%d %d\n",tmp[i].first,tmp[i].second);
    //     printf("%d %d\n",tmp[i].first-miny,tmp[i].second-minx);
    // }
    for(int i=maxy-miny;i>=0;i--){
        string inp = "";
        for(int j=0;j<=maxx-minx;j++){
            inp+='.';
        }
        answer.push_back(inp);
    }
    for(int i=0;i<tmp.size();i++){
        answer[maxy-tmp[i].first][tmp[i].second-minx] = '*';
    }
    return answer;
}