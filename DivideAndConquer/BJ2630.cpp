
//! 20200128
// TODO Dynamic Programming
// BJ2630 : https://www.acmicpc.net/problem/2630
#include<cstdio>

using namespace std;

const int MAX = 150;
int N;
int map[MAX][MAX];
int result[2];                  // 0 : white, blue : 1

int checkMap(int r,int c,int l){
    int start = map[r][c];
    for(int i=r;i<r+l;i++){
        for(int j=c;j<c+l;j++){
            if(start != map[i][j]) return -1;
        }
    }
    return start;
}

void getResult(int rowIdx,int colIdx,int lenMap){
    if(lenMap==1){
        result[map[rowIdx][colIdx]]++;
    }else{
        int checkResult = checkMap(rowIdx,colIdx,lenMap);
        if(checkResult==-1){
            lenMap /= 2;
            getResult(rowIdx,colIdx,lenMap);
            getResult(rowIdx+lenMap,colIdx,lenMap);
            getResult(rowIdx,colIdx+lenMap,lenMap);
            getResult(rowIdx+lenMap,colIdx+lenMap,lenMap);
        }else{
            result[checkResult]++;
            return;
        }
    }
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&map[i][j]);
        }
    }
    getResult(0,0,N);
    printf("%d\n%d\n",result[0],result[1]);
    return 0;
}
