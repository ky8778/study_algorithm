
//! 2020.02.04
// TODO BJ14502 : https://www.acmicpc.net/problem/14502
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

const int MAX = 10;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
int N,M;
int inMap[MAX][MAX];
bool checkMap[MAX][MAX];
vector <pair<int,int>> myV[2];      // 0 : virus, 1 : 빈칸
queue <pair<int,int>> myQ;
int numB;

bool inRange(int y,int x){
    if(y>=0 && y<N && x>=0 && x<M) return true;
    else return false;
}

int BFS(int y,int x){
    checkMap[y][x] = true;
    myQ.push(make_pair(y,x));
    int cnt = 0;
    while(!myQ.empty()){
        int sizeQ = myQ.size();
        for(int i=0;i<sizeQ;i++){
            pair <int,int> current = myQ.front();
            myQ.pop();
            inMap[current.first][current.second] = 2;
            cnt++;

            for(int dir=0;dir<4;dir++){
                int nextY = current.first + dy[dir];
                int nextX = current.second + dx[dir];
                if(inRange(nextY,nextX)){
                    if(!checkMap[nextY][nextX]){
                        checkMap[nextY][nextX] = true;
                        myQ.push(make_pair(nextY,nextX));
                    }
                }
            }
        }
    }
    return cnt;
}

void resetMap(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(inMap[i][j]==1) checkMap[i][j] = true;
            else{
                inMap[i][j] = 0;
                checkMap[i][j] = false;
            }
        }
    }
}

int getResult(){
    int maxResult = -1;
    int sizeV1 = myV[1].size();
    int maxSize = N*M-numB;

    for(int i=0;i<sizeV1-2;i++){
        pair <int,int> B1 = myV[1][i];
        inMap[B1.first][B1.second] = 1;
        checkMap[B1.first][B1.second] = true;

        for(int j=i+1;j<sizeV1-1;j++){
            pair <int,int> B2 = myV[1][j];
            inMap[B2.first][B2.second] = 1;
            checkMap[B2.first][B2.second] = true;

            for(int k=j+1;k<sizeV1;k++){
                pair <int,int> B3 = myV[1][k];
                inMap[B3.first][B3.second] = 1;
                checkMap[B3.first][B3.second] = true;

                int sizeV2 = myV[0].size();
                int viSize = 0;
                for(int vi=0;vi<sizeV2;vi++){
                    pair <int,int> now = myV[0][vi];
                    if(!checkMap[now.first][now.second]){
                        viSize += BFS(now.first,now.second);
                    }
                }

                viSize = maxSize-viSize;
                if(viSize > maxResult) maxResult = viSize;

                inMap[B3.first][B3.second] = 0;
                checkMap[B3.first][B3.second] = false;
                resetMap();
            }

            inMap[B2.first][B2.second] = 0;
            checkMap[B2.first][B2.second] = false;
        }
        inMap[B1.first][B1.second] = 0;
        checkMap[B1.first][B1.second] = false;
    }
    return maxResult;
}

int main(){
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d",&inMap[i][j]);
            if(inMap[i][j]==2) myV[0].push_back(make_pair(i,j));
            else if(inMap[i][j]==0) myV[1].push_back(make_pair(i,j));
            else{
                checkMap[i][j] = true;
                numB++;
            }
        }
    }
    numB+=3;
    printf("%d\n",getResult());

    return 0;
}