// 2019.10.17
// 55M 27S
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

struct snake{
    queue <pair<int,int>> snakeQ;
    pair <int,int> head;
    int direction;
    void updateHead(int y,int x){
        head.first = y;
        head.second = x;
        snakeQ.push(head);
    }
};

int const MAX = 115;
int map[MAX][MAX];      // 0 : blank 1 : apple 2: snake 3: wall
int N,K,L;
int changeDir[10050];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int getResult(){
    int T=0;
    snake S;
    S.head = make_pair(1,1);
    S.snakeQ.push(S.head);
    S.direction = 0;
    map[1][1] = 2;

    while(1){
        T++;
        int d = S.direction;
        pair <int,int> current = S.head;
        int xx = current.second + dx[d];
        int yy = current.first + dy[d];
        //printf("T : %d, yy : %d, xx : %d\n",T,yy,xx);
        if(map[yy][xx]==3||map[yy][xx]==2) break;

        S.updateHead(yy,xx);
        if(map[yy][xx]==0){
            pair <int,int> end = S.snakeQ.front();
            S.snakeQ.pop();
            map[end.first][end.second] = 0;
        }
        map[yy][xx] = 2;

        if(changeDir[T]==1){
            d--;
            if(d<0) d+=4;
        }
        else if(changeDir[T]==2) d = (d+1)%4;
        S.direction = d;
    }
    return T;
}

int main(){
    scanf("%d",&N);
    scanf("%d",&K);

    // make walls
    for(int i=0;i<=N+1;i++){
        map[i][0] = 3;
        map[i][N+1] = 3;
    }
    for(int j=0;j<=N+1;j++){
        map[0][j] = 3;
        map[N+1][j] = 3;
    }
    
    for(int k=0;k<K;k++){
        int x,y;
        scanf("%d %d",&y,&x);
        map[y][x] = 1;
    }

    scanf("%d",&L);
    for(int l=0;l<L;l++){
        int X;
        char C;
        int dir = 0;
        scanf("%d %c",&X,&C);
        if(C=='D') dir=2;
        else if(C=='L') dir = 1;
        else dir = 0;
        changeDir[X] = dir;
        //printf("X : %d, C : %c, dir : %d\t",X,C,dir);
    }
    
    printf("%d\n",getResult());
    
    return 0;
}