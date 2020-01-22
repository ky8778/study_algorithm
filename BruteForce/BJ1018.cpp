//! 20200122
// TODO BruteForce
// BJ1018 : https://www.acmicpc.net/problem/1018

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int white = 0;
const int black = 1;

int dataMap[60][60];
int N,M;

int checkMap(int row,int col){
    // result[0] : 백으로 시작 result[1] : 흑으로 시작
    int result[2] = {0,};
    for(int i = row ; i < row + 8 ;i++){
        for(int j = col ; j < col + 8 ; j++){
            if(i%2 == j%2){
                if(dataMap[i][j] == white) result[1]++;
                else result[0]++;
            }else{
                if(dataMap[i][j] == black) result[1]++;
                else result[0]++;
            }
        }
    }

    return result[0] > result[1] ? result[1] : result[0];
}

int getResult(){
    int min = 987987987;
    
    for(int i=0;i<=N-8;i++){
        for(int j=0;j<=M-8;j++){
            int tmp = checkMap(i,j);
            if(tmp < min) min = tmp;
        }
    }

    return min;
}

int main(){
    scanf("%d %d",&N,&M);
    for(int n=0;n<N;n++){
        char tmpRow[60];
        scanf("%s",tmpRow);
        for(int m=0;m<M;m++){
            if(tmpRow[m]=='W') dataMap[n][m] = 0;
            else dataMap[n][m] = 1;
        }
    }

    // printf("====================================\n");
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<M;j++){
    //         printf("%d ",dataMap[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("%d\n",getResult());
    
    return 0;
}