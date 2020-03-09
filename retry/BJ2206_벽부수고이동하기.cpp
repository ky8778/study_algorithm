//! 2020.03.09
// TODO BJ2206_벽부수고이동하기
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

struct myPoint{
    int y;
    int x;
    int isBroken;
};

const int MAX = 1050;
const int INF = 987654321;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
int N,M;
int inMap[MAX][MAX];
queue <myPoint> myQ;
int DP[MAX][MAX][2];

int getMin(int n1,int n2){
    if(n1<n2) return n1;
    else return n2;
}

bool inRange(int y,int x){
    if(y>=0 && y<N && x>=0 && x<M) return true;
    else return false;
}

bool isEnd(int y,int x){
    if(y==N-1 && x==M-1) return true;
    else return false;
}

void initDP(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            for(int k=0;k<2;k++) DP[i][j][k] = INF;
        }
    }
}

void print(int k){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            printf("%d ",DP[i][j][k]);
        }
        printf("\n");
    }
}

int getResult(){
    int cnt = 1;
    myPoint current;
    current.y = 0;
    current.x = 0;
    current.isBroken = 0;
    myQ.push(current);
    DP[current.y][current.x][current.isBroken] = cnt;

    while(!myQ.empty()){
        int qSize = myQ.size();
        cnt++;
        for(int s=0;s<qSize;s++){
            current = myQ.front();
            myQ.pop();
            if(isEnd(current.y,current.x)) return DP[current.y][current.x][current.isBroken];
            for(int dir=0;dir<4;dir++){
                myPoint next;
                next.y = current.y+dy[dir];
                next.x = current.x+dx[dir];
                if(inRange(next.y,next.x)){
                    if(DP[next.y][next.x][current.isBroken]>cnt){
                        if(inMap[next.y][next.x]==0){
                            next.isBroken = current.isBroken;
                            myQ.push(next);
                            DP[next.y][next.x][current.isBroken] = cnt;
                        }else{
                            if(current.isBroken==0){
                                next.isBroken = 1;
                                myQ.push(next);
                                DP[next.y][next.x][current.isBroken] = cnt;
                            }
                        }
                    }
                }
            }
        }
    }
    return INF;
}

int main(){
    // freopen("input.txt", "r", stdin);
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        char tmp[MAX];
        scanf("%s",tmp);
        for(int j=0;j<M;j++){
            inMap[i][j] = tmp[j]-'0';
        }
    }
    initDP();
    int result = getResult();
    if(result>=INF) result = -1;
    printf("%d\n",result);
    return 0;
}
