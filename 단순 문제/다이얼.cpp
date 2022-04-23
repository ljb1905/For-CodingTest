#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int nowl = 10, nowr = 12;
    for(int i=0;i<numbers.size();i++){
        int val = numbers[i];
        if(val==0) val=11;
        if(val==1 || val==4 || val==7){
            answer+="L";
            nowl = val;
        }
        else if(val==3 || val==6 || val==9){
            answer+="R";
            nowr = val;
        }
        else{
            int disl = (max(nowl,val)-min(nowl,val))/3 + (max(nowl,val)-min(nowl,val))%3;
            int disr = (max(nowr,val)-min(nowr,val))/3 + (max(nowr,val)-min(nowr,val))%3;
            if(disl<disr || ((disl==disr)&&hand[0]=='l')){
                answer+="L";
                nowl = val;                
            }
            else{
                answer+="R";
                nowr = val;                
            }
        }
    }
    return answer;
}