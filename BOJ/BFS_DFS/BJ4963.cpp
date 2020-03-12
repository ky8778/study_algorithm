
//! 2020.02.04
// TODO BJ4963 : https://www.acmicpc.net/problem/4963

#include<cstdio>

using namespace std;

const int MAX = 55;
const int dx[8] = {1,1,0,-1,-1,-1,0,1};
const int dy[8] = {0,1,1,1,0,-1,-1,-1};
int inMap[MAX][MAX];
bool checkMap[MAX][MAX];
int W,H;

bool inRange(int y,int x){
    if(y>=0 && y<H && x>=0 && x<W) return true;
    else return false;
}

void DFS(int y, int x){
    // printf("y : %d, x : %d\n",y,x);
    for(int dir=0;dir<8;dir++){
        int nextY = y+dy[dir];
        int nextX = x+dx[dir];
        if(inRange(nextY,nextX)){
            if(!checkMap[nextY][nextX] && inMap[nextY][nextX]==1){
                checkMap[nextY][nextX] = true;
                DFS(nextY,nextX);
            }
        }
    }
}

int getResult(){
    int ret = 0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(!checkMap[i][j] && inMap[i][j]==1){
                checkMap[i][j] = true;
                DFS(i,j);
                ret++;
            }
        }
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            checkMap[i][j] = false;
            inMap[i][j] = 0;
        }
    }
    return ret;
}

int main(){
    while(true){
        scanf("%d %d",&W,&H);
        if(W==0) break;
        else{
            for(int i=0;i<H;i++){
                for(int j=0;j<W;j++){
                    scanf("%d",&inMap[i][j]);
                }
            }
            printf("%d\n",getResult());
        }
    }

    return 0;
}
