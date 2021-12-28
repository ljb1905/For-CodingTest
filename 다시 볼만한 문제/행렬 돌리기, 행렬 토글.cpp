#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[101][101][2];
bool sw = false;
void init(int rows, int columns){
    for(int i=1;i<=rows;i++){
        for(int j=1;j<=columns;j++){
            arr[i][j][sw] = (i-1)*columns + j;
        }
    }
    return;
}
int func(int y1,int x1,int y2, int x2, int rows, int columns){
    int ret = 987654321;
    sw = !sw;
    for(int j=x2;j>=x1+1;j--){
        arr[y1][j][sw] = arr[y1][j-1][!sw];
        ret = min(ret, arr[y1][j][sw]);
    }
    for(int i=y2;i>=y1+1;i--){
        arr[i][x2][sw] = arr[i-1][x2][!sw];
        ret = min(ret, arr[i][x2][sw]);
    }
    for(int j=x1;j<=x2-1;j++){
        arr[y2][j][sw] = arr[y2][j+1][!sw];
        ret = min(ret, arr[y2][j][sw]);
    }
    for(int i=y1;i<=y2-1;i++){
        arr[i][x1][sw] = arr[i+1][x1][!sw];
        ret = min(ret, arr[i][x1][sw]);
    }
    for(int i=1;i<=rows;i++){
        for(int j=1;j<=columns;j++){
            if((i==y1 && j>=x1 && j<=x2) || (i==y2 && j>=x1 && j<=x2) || (j==x1 && i>=y1 && i<=y2) || (j==x2 && i>=y1 && i<=y2)) continue;
            arr[i][j][sw] = arr[i][j][!sw];
        }
    }
    return ret;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    init(rows,columns);
    for(int i=0;i<queries.size();i++){
        answer.push_back(func(queries[i][0],queries[i][1],queries[i][2],queries[i][3], rows, columns));
        
    }
    return answer;
}