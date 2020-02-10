
// TODO BJ15683_감시
//! 2019.10.16
/*
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
*/

//! 2020.02.10
#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 15;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,-1,0,1};
int N,M;
int inMap[MAX][MAX];
int detectMap[MAX][MAX];
vector <pair<int,int>> CCTV;
vector <int> dirCCTV;

void detecting(int y,int x,int dir){
    while(inMap[y][x]!=6){
        detectMap[y][x] = 1;
        y+=dy[dir];
        x+=dx[dir];
    }
}

int getSize(){
    int cnt = 0;
    
    for(int i=0;i<dirCCTV.size();i++){
        int y = CCTV[i].first;
        int x = CCTV[i].second;
        int numCCTV = inMap[y][x];
        
        switch(numCCTV){
            case 1:
                detecting(y,x,dirCCTV[i]);
                break;
            case 2:
                detecting(y,x,dirCCTV[i]);
                detecting(y,x,dirCCTV[i]+2);
                break;
            case 3:
                for(int dir=0;dir<2;dir++){
                    int nextDir = (dir+dirCCTV[i])%4;
                    detecting(y,x,nextDir);
                }
                break;
            case 4:
                for(int dir=0;dir<4;dir++){
                    if(dir==dirCCTV[i]) continue;
                    detecting(y,x,dir);
                }
                break;
            case 5:
                for(int dir=0;dir<4;dir++) detecting(y,x,dir);
                break;
        }
    }
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(inMap[i][j]!=6 && detectMap[i][j]==0) cnt++;
            detectMap[i][j] = 0;
        }
    }
    return cnt;
}

int getResult(int idx){
    if(idx>=dirCCTV.size()){
        return getSize();
    }
    else{
        int y = CCTV[idx].first;
        int x = CCTV[idx].second;
        int numCCTV = inMap[y][x];
        int minResult = 987654321;
        if(numCCTV==2){
            for(int i=0;i<2;i++){
                dirCCTV[idx] = i;
                int tmp = getResult(idx+1);
                if(tmp<minResult) minResult = tmp;
            }
        }else if(numCCTV==5){
            int tmp = getResult(idx+1);
            if(tmp<minResult) minResult = tmp;
        }else{
            for(int i=0;i<4;i++){
                dirCCTV[idx] = i;
                int tmp = getResult(idx+1);
                if(tmp<minResult) minResult = tmp;
            }
        }
        return minResult;
    }
}

int main(){
    scanf("%d %d",&N,&M);
    for(int i=0;i<=N+1;i++){
        inMap[i][0] = 6;
        inMap[i][M+1] = 6;
    }
    for(int j=0;j<=M+1;j++){
        inMap[0][j] = 6;
        inMap[N+1][j] = 6;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            scanf("%d",&inMap[i][j]);
            if(inMap[i][j]!=0 && inMap[i][j]!=6){
                CCTV.push_back(make_pair(i,j));
                dirCCTV.push_back(0);
            }
        }
    }
    printf("%d\n",getResult(0));
    return 0;
}