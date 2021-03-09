#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0;i<commands.size();i++){
        int st = commands[i][0];
        int ed = commands[i][1];
        int k = commands[i][2];
        vector<int> tmp;
        for(int j=st-1;j<=ed-1;j++){
            tmp.push_back(array[j]);
        }
        sort(tmp.begin(),tmp.end());
        answer.push_back(tmp[k-1]);
    }
    return answer;
}