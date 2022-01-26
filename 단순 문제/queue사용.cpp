#include <string>
#include <vector>
#include <queue>

using namespace std;

int ori_ind[30];

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    queue<char> ori_que;
    for(int i=0;i<skill.size();i++){
        char now = skill[i];
        ori_ind[now-'A']=1;
        ori_que.push(now);
    }
    for(int i=0;i<skill_trees.size();i++){
        int ind[30];
        bool flag = false;
        queue<char> que = ori_que;
        for(int i=0;i<26;i++){
            ind[i] = ori_ind[i];
        }
        for(int j=0;j<skill_trees[i].size();j++){
            char now = skill_trees[i][j];
            if(!que.empty() && que.front()==now){
                que.pop();
                ind[now-'A'] = 0;
            }
            if(ind[now-'A']){
                flag = true;
                break;
            }
        }
        if(flag==false) answer++;
    }
    return answer;
}