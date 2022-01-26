//프로그래머스 쿼드압축 후 개수 세기

#include <string>
#include <vector>

using namespace std;
int cnt1 = 0;
int cnt2 = 0;

void func(vector<vector<int>> &arr, int y, int x, int n){
    if(n<=1) return;
    int one_cnt = 0;
    for(int i=y;i<y+n;i++){
        for(int j=x;j<x+n;j++){
            if(arr[i][j]) one_cnt++;
        }
    }
    if(one_cnt==n*n){
        cnt1 -= n*n-1;
        return;
    }
    else if(one_cnt==0){
        cnt2 -= n*n-1;
        return;
    }
    func(arr,y+0,x+0,n/2);
    func(arr,y+0,x+n/2,n/2);
    func(arr,y+n/2,x+0,n/2);
    func(arr,y+n/2,x+n/2,n/2);
    return;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    int n = arr.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]) cnt1++;
            else cnt2++;
        }
    }
    func(arr,0,0,n);
    answer.push_back(cnt2);
    answer.push_back(cnt1);
    return answer;
}