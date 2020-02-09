
//! 2020.02.09
// TODO BJ17837_새로운게임2
#include<cstdio>
#include<vector>

using namespace std;

const int MAX = 20;
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,-1,1};
const int B = 2;
const int R = 1;
const int W = 0;
int inMap[MAX][MAX];

int N,K;

vector <pair<int,int>> horseInfo[MAX][MAX];
vector <pair<int,int>> horse;

int move(int k){
    // printf("k : %d\n",k);
    int y = horse[k].first;
    int x = horse[k].second;

    int idx = 0;
    while(horseInfo[y][x][idx].first != k) idx++;

    int dir = horseInfo[y][x][idx].second;
    int nextY = y+dy[dir];
    int nextX = x+dx[dir];
    
    if(inMap[nextY][nextX]==B){
        if(dir==1) dir = 0;
        else if(dir==0) dir = 1;
        else if(dir==2) dir = 3;
        else if(dir==3) dir = 2;
        nextY = y+dy[dir];
        nextX = x+dx[dir];
        horseInfo[y][x][idx].second = dir;
    }
    // printf("%d %d %d",nextY,nextX,dir);
    if(inMap[nextY][nextX]==B) return horseInfo[y][x].size();
    
    int sizeH = horseInfo[y][x].size();
    if(inMap[nextY][nextX]==W){
        for(int i=idx;i<sizeH;i++){
            horseInfo[nextY][nextX].push_back(horseInfo[y][x][i]);
            horse[horseInfo[y][x][i].first].first = nextY;
            horse[horseInfo[y][x][i].first].second = nextX;
        }
    }else{
        for(int i=sizeH-1;i>=idx;i--){
            // printf("%d %d\n",y,x);
            horseInfo[nextY][nextX].push_back(horseInfo[y][x][i]);
            horse[horseInfo[y][x][i].first].first = nextY;
            horse[horseInfo[y][x][i].first].second = nextX;
        }
    }
    for(int i=idx;i<sizeH;i++){
        horseInfo[y][x].pop_back();
    }

    return horseInfo[nextY][nextX].size();
}

int getResult(){
    for(int t=1;t<=1000;t++){
        for(int k=0;k<K;k++){
            if(move(k)>=4) return t;
        }
    }
    return -1;
}

int main(){
    scanf("%d %d",&N,&K);
    for(int i=0;i<=N+1;i++){
        inMap[i][0] = 2;
        inMap[i][N+1] = 2;
        inMap[0][i] = 2;
        inMap[N+1][i] = 2;
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            scanf("%d",&inMap[i][j]);
        }
    }

    for(int k=0;k<K;k++){
        int r,c,dir;
        scanf("%d %d %d",&r,&c,&dir);
        horseInfo[r][c].push_back(make_pair(k,dir-1));
        horse.push_back(make_pair(r,c));
    }

    printf("%d\n",getResult());
    return 0;
}