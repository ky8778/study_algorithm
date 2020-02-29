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
bool checkDist[7];
int number;
int myDist[7][7];
queue <pair<int,int>> myQ;
vector <int> myV;

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
                    int tmpDist = j-prevIdx-1;
                    if(tmpDist >= 2) myDist[prev][next] = min(myDist[prev][next],tmpDist);
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
        for(int i=0;i<N;i++){
            if(inMap[i][j]!=0){
                if(inMap[i][j]!=prev){
                    int next = inMap[i][j];
                    int tmpDist = i-prevIdx-1;
                    if(tmpDist>=2) myDist[prev][next] = min(myDist[prev][next],tmpDist);
                    myDist[next][prev] = myDist[prev][next];
                    // printf("prev : %d, next : %d, dist : %d\n",prev,next,myDist[prev][next]);
                    prev = next;
                }
                prevIdx = i;
            }
        }
    }
}

void init(){
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            myDist[i][j] = INF;
        }
    }
}

int getMinDist(){
    myV.push_back(1);
    checkDist[1] = true;
    int totalDist = 0;
    while(myV.size()<number){
        int minIdx = -1;
        int minVal = INF;
        for(int i=0;i<myV.size();i++){
            for(int end=1;end<=number;end++){
                int start = myV[i];
                if(!checkDist[end]){
                    if(myDist[start][end]<minVal){
                        minVal = myDist[start][end];
                        minIdx = end;
                    }
                }
            }
        }
        if(minIdx<0) return -1;
        myV.push_back(minIdx);
        checkDist[minIdx] = true;
        totalDist+=minVal;
        // printf("minIdx : %d, minVal : %d, total : %d\n",minIdx,minVal,totalDist);
    }
    return totalDist;
}

int getResult(){
    init();
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!checkMap[i][j] && inMap[i][j]==1){
                checkMap[i][j] = true;
                BFS(i,j);
            }
        }
    }
    getDistance();
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