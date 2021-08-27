#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const string &a, const string &b)
{
    if (a + b > b + a) return true;
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> tmp;
    for(int i=0;i<numbers.size();i++){
        tmp.push_back(to_string(numbers[i]));
    }
    sort(tmp.begin(),tmp.end(),comp);
    for(int i=0;i<tmp.size();i++){
        for(int j=0;j<tmp[i].length();j++){
            answer.push_back(tmp[i][j]);
        }
    }
    int l = answer.length();
    for(int i=0;i<l;i++){
        printf("%c",answer[0]);
        if(answer[0]!='0'){
            break;            
        } 
        answer.erase(0,1);
    }
    if(answer.length()==0)
        answer.push_back('0');
    return answer;
}