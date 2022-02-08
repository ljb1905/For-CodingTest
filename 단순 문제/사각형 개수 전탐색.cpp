//프로그래머스 카펫

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    bool sw = false;
    for(int i=3;i<=2000;i++){//가로
        for(int j=3;j<=i;j++){
            int b = 2*i + 2*j - 4;
            int y = (i-2)*(j-2);
            if(b==brown && y==yellow){
                answer.push_back(i);
                answer.push_back(j);
                sw = true;
                break;
            }
        }
        if(sw) break;
    }
    return answer;
}