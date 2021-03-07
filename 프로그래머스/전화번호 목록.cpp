#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(),phone_book.end());
    for(int i=0;i<phone_book.size()-1;i++){
        string now = phone_book[i];
        string next = phone_book[i+1];
        if(now==next.substr(0,now.size())){
            answer = false;
        }
    }
    return answer;
}