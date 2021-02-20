#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct s{
    int st,ed;
    s(){}
    s(int st, int ed):
        st(st),ed(ed)
    {}
    bool operator < (const s &o)const{
        return ed < o.ed;
    }
};

int solution(vector<vector<int>> routes) {
    int answer = 0;
    vector<s> v;
    for(int i=0;i<routes.size();i++){
        v.push_back(s(routes[i][0],routes[i][1]));
    }
    sort(v.begin(),v.end());
    int n = v.size();
    bool chk[10001] = {0,};
    for(int i=0;i<v.size();i++){
        if(chk[i]==false){
            chk[i]=true;
            answer++;
            for(int j=i+1;j<v.size();j++){
                if(v[j].st <= v[i].ed){
                    chk[j] = true;
                }
            }
        }
    }
    return answer;
}