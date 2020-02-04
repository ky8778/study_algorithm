//! 2020.02.04
// TODO BJ2468 : https://www.acmicpc.net/problem/2468
#include<cstdio>
#include<queue>
#include<vector>

using namespace std;

const int MAX = 110;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};

int N;
int minH = 987654321,maxH = -1;
int inMap[MAX][MAX];
bool checkMap[MAX][MAX];
vector <pair<int,int>> myH[MAX];
queue <pair<int,int>> myQ;

bool inRange(int y,int x){
    if(y>=0 && y<N && x>=0 && y<N) return true;
    else return false;
}

void resetCheck(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(inMap[i][j]==0) checkMap[i][j] = true;
            else checkMap[i][j] = false;
        }
    }
}

void deleteMap(int inH){
    int sizeV = myH[inH].size();
    for(int i=0;i<sizeV;i++){
        pair <int,int> current = myH[inH][i];
        inMap[current.first][current.second] = 0;
    }
}

void BFS(int y,int x){
    checkMap[y][x] = true;
    myQ.push(make_pair(y,x));
    while(!myQ.empty()){
        int sizeQ = myQ.size();
        for(int i=0;i<sizeQ;i++){
            pair <int,int> current = myQ.front();
            myQ.pop();
            for(int dir=0;dir<4;dir++){
                int nextY = current.first + dx[dir];
                int nextX = current.second + dy[dir];
                if(inRange(nextY,nextX)){
                    if(!checkMap[nextY][nextX] && inMap[nextY][nextX]!=0){
                        checkMap[nextY][nextX] = true;
                        myQ.push(make_pair(nextY,nextX));
                    }
                }
            }
        }
    }
}

int getResult(){
    int ret = -1;
    for(int h=minH;h<=maxH;h++){
        deleteMap(h);
        resetCheck();
        // for(int i=0;i<N;i++){
        //     for(int j=0;j<N;j++){
        //         printf("%d ",inMap[i][j]);
        //     }
        //     printf("\n");
        // }
        int cnt = 0;
        for(int i=h+1;i<=maxH;i++){
            int sizeV = myH[i].size();
            for(int j=0;j<sizeV;j++){
                pair <int,int> start = myH[i][j];
                if(!checkMap[start.first][start.second] && inMap[start.first][start.second]!=0){
                    BFS(start.first,start.second);
                    cnt++;
                }
            }
        }
        if(ret<cnt) ret = cnt;
        // printf("h : %d, cnt : %d\n",h,cnt);
    }
    return ret<=0?1:ret;
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&inMap[i][j]);
            myH[inMap[i][j]].push_back(make_pair(i,j));
            if(minH>inMap[i][j]) minH = inMap[i][j];
            if(maxH<inMap[i][j]) maxH = inMap[i][j];
        }
    }
    printf("%d\n",getResult());
    return 0;
}