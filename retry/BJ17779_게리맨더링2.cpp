
//! 2020.02.07
// TODO BJ17779_게리맨더링2
#include<cstdio>
#include<queue>

using namespace std;

const int MAX = 25;
const int dx[8] = {1,1,-1,-1,1,0,-1,0};
const int dy[8] = {-1,1,1,-1,0,1,0,-1};
queue <pair<int,int>> myQ;  
bool checkMap[MAX][MAX];
int inMap[MAX][MAX];
int myMap[MAX][MAX];
int N;

int counting(){
    int cnt[5] = {0,0,0,0,0};
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cnt[myMap[i][j]-1] += inMap[i][j];
            myMap[i][j] = 0;
            checkMap[i][j] = false;
        }
    }
    int maxVal = -1;
    int minVal = 987654321;
    for(int idx=0;idx<5;idx++){
        if(cnt[idx]>maxVal) maxVal = cnt[idx];
        if(cnt[idx]<minVal) minVal = cnt[idx];
    }
    return maxVal-minVal;
}


void dividing(int y,int x,int d1,int d2){
    myMap[y][x] = 5;
    for(int d=0;d<d1;d++){
        y+=dy[0];
        x+=dx[0];
        myMap[y][x] = 5;
        for(int j=0;j<x;j++) myMap[y][j] = 1;
    }
    for(int i=0;i<y;i++){
        for(int j=0;j<=x;j++){
            myMap[i][j] = 1;
        }
    }

    for(int i=0;i<=y;i++){
        for(int j=x+1;j<N;j++){
            myMap[i][j] = 2;
        }
    }
    for(int d=0;d<d2;d++){
        y+=dy[1];
        x+=dx[1];
        myMap[y][x] = 5;
        for(int j=x+1;j<N;j++) myMap[y][j] = 2;
    }

    for(int d=0;d<d1;d++){
        y+=dy[2];
        x+=dx[2];
        myMap[y][x] = 5;
        for(int j=x+1;j<N;j++) myMap[y][j] = 4;
    }
    for(int i=y+1;i<N;i++){
        for(int j=x;j<N;j++){
            myMap[i][j] = 4;
        }
    }

    for(int i=y;i<N;i++){
        for(int j=0;j<x;j++){
            myMap[i][j] = 3;
        }
    }
    for(int d=0;d<d2;d++){
        y+=dy[3];
        x+=dx[3];
        myMap[y][x] = 5;
        for(int j=0;j<x;j++) myMap[y][j] = 3;
    }

    for(int i=y-d1+1;i<y+d2;i++){
        for(int j=x+1;j<x+d2+d1;j++){
            if(myMap[i][j]==0) myMap[i][j] = 5;
        }
    }
}

int getResult(){
    int minRet = 987654321;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int d2 = 1 ; d2 < N-i ; d2++){
                for(int d1 = 1 ; d1 <= i ; d1++){
                    if(d1+d2 < N-j){
                        dividing(i,j,d1,d2);
                        int curVal = counting();
                        if(curVal<minRet) minRet = curVal;
                    }
                }
            }
        }
    }
    return minRet;
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&inMap[i][j]);
        }
    }
    printf("%d\n",getResult());
    return 0;
}