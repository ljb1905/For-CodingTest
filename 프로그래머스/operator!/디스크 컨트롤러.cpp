#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct str{
    int st, ed;
    str(){}
    str(int st, int ed):
        st(st),ed(ed)
        {}
    bool operator <(const str &o)const{
        if(ed==o.ed){
            return st<o.st;
        }
        return ed<o.ed;
    }
};
struct compare2{
    bool operator()(str &A, str &B){
        if(A.st==B.st){
            return A.ed<B.ed;
        }
        return A.st<B.st;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    vector <str> v;
    for(int i=0;i<jobs.size();i++){
        v.push_back(str(jobs[i][0],jobs[i][1]));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<jobs.size();i++){
        printf("%d %d\n",v[i].st,v[i].ed);
    }
    return answer;
}