// 2019.10.19
// greedy algorithm
// 1H 40M
// brute force로도 되는지 확인해보자.
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 550;
int N,M;
int map[MAX][MAX];
queue <pair<int,int>> myQ;
bool check[MAX][MAX];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void init_check(int y,int x){
    for(int i=y-4;i<y+4;i++){
        for(int j=x-4;j<x+4;j++){
            if(i>=0&&j>=0&&i<N&&j<M)
                check[i][j] = false;
        }
    }
}

int BFS(int y,int x){
    int resultBFS = 0;
    check[y][x] = true;
    myQ.push(make_pair(y,x));
    resultBFS+=map[y][x];
    for(int n=0;n<3;n++){
        int sizeQ = myQ.size();
        int max = -987987987;
        pair <int,int> maxIdx;
        for(int i=0;i<sizeQ;i++){
            pair <int,int> current = myQ.front();
            myQ.pop();
            for(int dir=0;dir<4;dir++){
                int yy = current.first+dy[dir];
                int xx = current.second+dx[dir];
                if(xx>=0&&yy>=0&&xx<M&&yy<N&&check[yy][xx]==false){
                    if(max<map[yy][xx]){
                        max = map[yy][xx];
                        maxIdx.first = yy;
                        maxIdx.second = xx;
                    }
                }
            }
            myQ.push(current);
        }
        //printf("maxIdx : %d,%d\n",maxIdx.first,maxIdx.second);
        myQ.push(maxIdx);
        check[maxIdx.first][maxIdx.second] = true;
        resultBFS+=max;
    }

    queue <pair<int,int>> empty;
    myQ.swap(empty);
    return resultBFS;
}

int getResult(){
    int result = -987987987;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int tmp = BFS(i,j);
            if(tmp>result) result = tmp;
            //printf("i : %d, j : %d, tmp : %d\n",i,j,tmp);
            init_check(i,j);
        }
    }
    return result;
}

int main(){
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d",&map[i][j]);
        }
    }
    printf("%d\n",getResult());

    return 0;
}

/* brute force
#include <cstdio>
using namespace std;
const int MAX = 550;
int N,M;
int map[MAX][MAX];
int sumMap[MAX][MAX];
int barMap[MAX][MAX][2];            // 0 : | 1: -
int squareMap[MAX][MAX];

int makeBarMap(){
    int max = -987987987;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(j>=4) barMap[i][j][1] = sumMap[i][j]-sumMap[i][j-4]-sumMap[i-1][j]+sumMap[i-1][j-4];
            if(i>=4) barMap[i][j][0] = sumMap[i][j]-sumMap[i-4][j]-sumMap[i][j-1]+sumMap[i-4][j-1];
            if(i>=2&&j>=2) squareMap[i][j] = sumMap[i][j]-sumMap[i-2][j]-sumMap[i][j-2]+sumMap[i-2][j-2];
            if(max<barMap[i][j][1]) max = barMap[i][j][1];
            if(max<barMap[i][j][0]) max = barMap[i][j][0];
            if(max<squareMap[i][j]) max = squareMap[i][j];
        }
    }

    ////////////////////////////////////////
    // code for Debugging
    for(int n=0;n<2;n++){
        printf("%d-th barMap print!!\n",n);
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                printf("%d ",barMap[i][j][n]);
            }
            printf("\n");
        }
    }
    printf("squareMap print!!\n");
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            printf("%d ",squareMap[i][j]);
        }
        printf("\n");
    }
    ////////////////////////////////////////

    return max;
}

int makeTMap(){
    int max = -987987987;
    return max;
}

int getResult(){
    int result = 0;
    result = makeBarMap();
    return result;
}

int main(){
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            scanf("%d",&map[i][j]);
            sumMap[i][j] = map[i][j]+sumMap[i-1][j]+sumMap[i][j-1]-sumMap[i-1][j-1];
        }
    }

    printf("%d\n",getResult());
    //////////////////////////////
    // code for Debugging
    printf("\nprint sumMap!\n");
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            printf("%d ",sumMap[i][j]);
        }
        printf("\n");
    }
    //////////////////////////////
    return 0;
}
*/

/* TC
5 5
1 2 3 4 5
5 4 3 2 1
2 3 4 5 6
6 5 4 3 2
1 2 1 2 1
*/