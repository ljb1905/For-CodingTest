#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[46];
int rankk[8] = {6,6,5,4,3,2,1};

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zcnt = 0;
    for(int i=0;i<lottos.size();i++){
        arr[lottos[i]]++;
        if(lottos[i]==0)
            zcnt++;
    }
    int cnt = 0;
    for(int i=0;i<win_nums.size();i++){
        if(arr[win_nums[i]]) cnt++;
    }    
    answer.push_back(rankk[cnt+zcnt]);
    answer.push_back(rankk[cnt]);    
    return answer;
}