// 2019.10.16
#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 10;
int map[MAX][MAX];
bool check[MAX][MAX];
pair <int,int> CCTV[MAX];
int dirCCTV[5][4] = {{1,0,0,0},{1,0,1,0},{1,0,0,1},{1,0,1,1},{1,1,1,1}};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int numCCTV;
int N,M;
bool tmpCheck[MAX][MAX][MAX];

int actCCTV(int yy,int xx,int _dir){
    int see = 0;
    while(1){
        yy+=dy[_dir];
        xx+=dx[_dir];
        if(xx>=0&&yy>=0&&xx<M&&yy<N&&map[yy][xx]!=6){
            if(check[yy][xx] == false){
                check[yy][xx] = true;
                see++;
            }
        }else break;
    }
    return see;
}

int getResult(int n,int blank){
    if(n>=numCCTV) return blank;

    pair <int,int> currentPoint = CCTV[n];
    int x = currentPoint.second;
    int y = currentPoint.first;
    int idxCCTV = map[y][x]-1;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            tmpCheck[n][i][j] = check[i][j];
        }
    }

    int min = 987987987;
    for(int rotation=0 ; rotation<4 ; rotation++){
        int tmpBlank = blank;
        for(int dir=0 ; dir<4 ; dir++){
            if(dirCCTV[idxCCTV][dir]==1){
                //printf("n : %d, dx : %d, dir : %d\n",n,idxCCTV,dir);
                int go = (rotation+dir)%4;
                tmpBlank -= actCCTV(y,x,go);
            }
        }
        tmpBlank = getResult(n+1,tmpBlank);
        if(tmpBlank < min) min = tmpBlank;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                check[i][j] = tmpCheck[n][i][j];
            }
        }
    }
    return min;
}

int main(){
    scanf("%d %d",&N,&M);
    int blankMap=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d",&map[i][j]);
            if(map[i][j]>=6) check[i][j] = true;
            else if(map[i][j]>0){
                check[i][j] = true;
                CCTV[numCCTV++] = make_pair(i,j);
            }else{
                blankMap++;
            }
        }
    }
    printf("%d\n",getResult(0,blankMap));
    return 0;
}