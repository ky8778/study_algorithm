//! 2020.02.29
// TODO BJ17472_다리만들기2
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int MAX =  12;
const int INF = 987654321;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
int N,M;
int inMap[MAX][MAX];
bool checkMap[MAX][MAX];
int number;
int myDist[7][7];
queue <pair<int,int>> myQ;

void print(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            printf("%d ",inMap[i][j]);
        }
        printf("\n");
    }
}

bool inRange(int y,int x){
    if(y>=0&&x>=0&&y<N&&x<M) return true;
    else return false;
}

int min(int n1,int n2){
    if(n1<n2) return n1;
    else return n2;
}

void BFS(int y,int x){
    number++;
    myQ.push(make_pair(y,x));
    while(!myQ.empty()){
        pair<int,int> current = myQ.front();
        inMap[current.first][current.second] = number;
        myQ.pop();
        for(int dir=0;dir<4;dir++){
            int nextY = current.first + dy[dir];
            int nextX = current.second + dx[dir];
            if(inRange(nextY,nextX) && !checkMap[nextY][nextX] && inMap[nextY][nextX]==1){
                checkMap[nextY][nextX] = true;
                myQ.push(make_pair(nextY,nextX));
            }
        }
    }
}

void getDistance(){
    for(int i=0;i<N;i++){
        int prev = 0;
        int prevIdx = -1;
        for(int j=0;j<M;j++){
            if(inMap[i][j]!=0){
                if(inMap[i][j]!=prev){
                    int next = inMap[i][j];
                    myDist[prev][next] = j-prevIdx-1;
                    myDist[next][prev] = myDist[prev][next];
                    // printf("prev : %d, next : %d, dist : %d\n",prev,next,myDist[prev][next]);
                    prev = next;
                }
                prevIdx = j;
            }
        }
    }
    for(int j=0;j<M;j++){
        int prev = 0;
        int prevIdx = -1;
        for(int i=0;i<N;j++){
            if(inMap[i][j]!=0){
                if(inMap[i][j]!=prev){
                    int next = inMap[i][j];
                    myDist[prev][next] = i-prevIdx-1;
                    myDist[next][prev] = myDist[prev][next];
                    // printf("prev : %d, next : %d, dist : %d\n",prev,next,myDist[prev][next]);
                    prev = next;
                }
                prevIdx = i;
            }
        }
    }
}

int getMinDist(){
    for(int i=1;i<=number;i++){
        int minDist
    }
}

int getResult(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!checkMap[i][j] && inMap[i][j]==1){
                checkMap[i][j] = true;
                BFS(i,j);
            }
        }
    }
    getDistance();

    // print();
    // printf("number : %d\n",number);
    return getMinDist();
}

int main(){
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d",&inMap[i][j]);
        }
    }
    printf("%d\n",getResult());

    return 0;
}