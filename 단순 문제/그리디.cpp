#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end());
    int l = 0;
    int r = people.size()-1;
    while(l<r){
        int now = people[l] + people[r];
        if(now > limit){
            r--;
        }
        else{
            l++;
            r--;
        }
        answer++;
        if(l==r) answer++;
    }
    return answer;
}