#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int arr1[5] = {1,2,3,4,5};
int arr2[8] = {2,1,2,3,2,4,2,5};
int arr3[10] = {3,3,1,1,2,2,4,4,5,5};
int cnt[3];
int idx[3];
int maxx;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int l = answers.size();
    for(int i=0;i<l;i++){
        if(answers[i]==arr1[idx[0]%5]){
            cnt[0]++;
        }
        if(answers[i]==arr2[idx[1]%8]){
            cnt[1]++;
        }
        if(answers[i]==arr3[idx[2]%10]){
            cnt[2]++;
        }
        idx[0]++;
        idx[1]++;
        idx[2]++;
        for(int i=0;i<3;i++){
            maxx = max(maxx,cnt[i]);
        }        
    }
    for(int i=0;i<3;i++){
        if(cnt[i]==maxx){
            answer.push_back(i+1);
        }
    }    
    return answer;
}