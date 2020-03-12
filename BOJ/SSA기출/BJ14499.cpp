// 2019.10.16
#include<cstdio>

using namespace std;
const int MAX = 25;
int map[MAX][MAX];
int N,M,R,C,K;
int status[6];
int changeIndex[4][6] = {{4,1,2,0,5,3},{3,1,2,5,0,4},{1,5,0,3,4,2},{2,0,5,3,4,1}};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

int getResult(int dir){
    int tmpR = R;
    int tmpC = C;
    R+=dy[dir];
    C+=dx[dir];
    //printf("x : %d, y : %d\n",C,R);
    if(R<0||C<0||R>=N||C>=M){
        R = tmpR;
        C = tmpC;
        return -1;
    }

    int tmp[6];
    for(int i=0;i<6;i++){
        int index = changeIndex[dir][i];
        tmp[index] = status[i];
    }
    for(int i=0;i<6;i++) status[i] = tmp[i];
    if(map[R][C]==0) map[R][C] = status[5];
    else{
        status[5] = map[R][C];
        map[R][C] = 0;
    }
    return status[0];
}

int main(){
    scanf("%d %d %d %d %d",&N,&M,&R,&C,&K);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d",&map[i][j]);
        }
    }

    for(int k=0;k<K;k++){
        int direction;
        scanf("%d",&direction);
        int result = getResult(direction-1);
        if(result>=0) printf("%d\n",result);
    }
    return 0;
}