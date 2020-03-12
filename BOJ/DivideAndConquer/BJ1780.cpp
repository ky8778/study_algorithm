
//! 20200129
// TODO Divide & Conquer
// BJ1780 : https://www.acmicpc.net/problem/1780
#include<cstdio>

using namespace std;

const int INF = 987654321;
const int MAX = 2500;
int N;
int inputMap[MAX][MAX];
int result[3];                  // 0 : -1, 1 : 0, 2 : 1

int checkMap(int rS,int cS, int size){
    int start = inputMap[rS][cS];
    for(int r=rS ; r<rS+size ; r++){
        for(int c=cS ; c<cS+size ; c++){
            if(start!=inputMap[r][c]) return INF;
        }
    }  
    return start;
}

void getResult(int rowStart, int colStart, int size){
    int tmpResult = checkMap(rowStart,colStart,size);
    if(tmpResult==1) result[2]++;
    else if(tmpResult==0) result[1]++;
    else if(tmpResult==-1) result[0]++;
    else{
        size /= 3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                getResult(rowStart + i*size,colStart + j*size,size);
            }
        }
    }
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&inputMap[i][j]);
        }
    }
    getResult(0,0,N);
    for(int i=0;i<3;i++)
        printf("%d\n",result[i]);
    return 0;
}
