// 프로그래머스 자물쇠와 열쇠

#include <string>
#include <vector>

using namespace std;
bool arr[21][21][4];
vector<pair<int,int>>v[4];

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int sum = 0;
    for(int i=0;i<lock.size();i++){
        for(int j=0;j<lock[i].size();j++){
            if(lock[i][j]) sum++;
        }
    }
    for(int x=0;x<4;x++){
        for(int i=0;i<key.size();i++){
            for(int j=0;j<key[i].size();j++){
                if(x==0){
                    arr[i][j][0] = key[i][j];
                    if(arr[i][j][0])
                        v[0].push_back(make_pair(i,j));
                }
                else {
                    int nexty = j;
                    int nextx = key[i].size()-1-i;
                    arr[nexty][nextx][x] = arr[i][j][x-1];
                    if(arr[nexty][nextx][x])
                        v[x].push_back(make_pair(nexty,nextx));
                }
            }
        }
    }
    int tmp = 1-key.size();
    int n = lock.size();
    for(int i=tmp;i<n;i++){
        for(int j=tmp;j<n;j++){
            for(int x=0;x<4;x++){
                int cnt = 0;
                for(int k=0;k<v[x].size();k++){
                    int nowy = i+v[x][k].first;
                    int nowx = j+v[x][k].second;
                    if(nowy<0 || nowy>=lock.size() || nowx<0 || nowx>=lock.size()) continue;
                    if(lock[nowy][nowx]==0) cnt++;
                    else cnt--;
                }
                if(sum+cnt>=lock.size()*lock.size()){
                    answer = true;
                }
            }
        }
    }
    return answer;
}