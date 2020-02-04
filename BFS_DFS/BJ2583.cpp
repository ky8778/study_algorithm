//! 2020.02.04
// TODO BJ2583 : https://www.acmicpc.net/problem/2583
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

const int MAX = 110;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
int inMap[MAX][MAX];
bool checkMap[MAX][MAX];
int M,N,K;
queue <pair<int,int>> myQ;
vector <int> result;

bool inRange(int y,int x){
    if(y<M && y>=0 && x<N && x>=0) return true;
    else return false;
}

int BFS(int y,int x){
    int size = 0;
    checkMap[y][x] = true;
    myQ.push(make_pair(y,x));
    while(!myQ.empty()){
        int sizeQ = myQ.size();
        for(int i=0;i<sizeQ;i++){
            pair<int,int> current = myQ.front();
            myQ.pop();
            size++;
            for(int dir=0;dir<4;dir++){
                int nextY = current.first + dy[dir];
                int nextX = current.second + dx[dir];
                if(inRange(nextY,nextX)){
                    if(!checkMap[nextY][nextX] && inMap[nextY][nextX]==0){
                        checkMap[nextY][nextX] = true;
                        myQ.push(make_pair(nextY,nextX));
                    }
                }
            }
        }
    }
    return size;
}

void coloring(int sx,int sy,int ex,int ey){
    for(int i=sy;i<ey;i++){
        for(int j=sx;j<ex;j++){
            inMap[i][j] = 1;
        }
    }
}

void getResult(){
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(!checkMap[i][j] && inMap[i][j]==0){
                result.push_back(BFS(i,j));
            }
        }
    }
}

int main(){
    scanf("%d %d %d",&M,&N,&K);
    for(int k=0;k<K;k++){
        int a1,b1,a2,b2;
        scanf("%d %d %d %d",&a1,&b1,&a2,&b2);
        coloring(a1,b1,a2,b2);
    }

    getResult();
    sort(result.begin(),result.end());
    printf("%d\n",result.size());
    for(int i=0;i<result.size();i++){
        printf("%d ",result[i]);
    }
    printf("\n");

    // for(int i=0;i<M;i++){
    //     for(int j=0;j<N;j++){
    //         printf("%d ",inMap[i][j]);
    //     }
    //     printf("\n");
    // }
    
    return 0;
}