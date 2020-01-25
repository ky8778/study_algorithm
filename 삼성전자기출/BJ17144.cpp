// 2019.10.15
#include<cstdio>
#include<queue>

using namespace std;

const int MAX = 55;
int R,C,T;
int map[MAX][MAX][2];
queue <pair<int,int>> myQ;
int cleaner[2];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool check[MAX][MAX];

void clean(int _next){
    int y1 = cleaner[0];
    int y2 = cleaner[1];
    for(int i=y1-1;i>0;i--) map[i][0][_next] = map[i-1][0][_next];
    for(int j=0;j<C-1;j++) map[0][j][_next] = map[0][j+1][_next];
    for(int i=0;i<y1;i++) map[i][C-1][_next] = map[i+1][C-1][_next];
    for(int j=C-1;j>1;j--) map[y1][j][_next] = map[y1][j-1][_next];
    map[y1][1][_next] = 0;

    for(int i=y2+1;i<R-1;i++) map[i][0][_next] = map[i+1][0][_next];
    for(int j=0;j<C-1;j++) map[R-1][j][_next] = map[R-1][j+1][_next];
    for(int i=R-1;i>y2;i--) map[i][C-1][_next] = map[i-1][C-1][_next];
    for(int j=C-1;j>1;j--) map[y2][j][_next] = map[y2][j-1][_next];
    map[y2][1][_next] = 0;
}

void BFS(int _current,int _next){
    int Qsize = myQ.size();
    for(int q=0;q<Qsize;q++){
        pair <int,int> now = myQ.front();
        myQ.pop();
        int y = now.first;
        int x = now.second;
        int A = map[y][x][_current];
        int AA = A/5;
        if(AA==0){
            map[y][x][_next] += A;
            continue;
        }

        int cnt = 0;
        for(int d=0;d<4;d++){
            int yy = y+dy[d];
            int xx = x+dx[d];
            if(xx>=0 && yy>=0 && xx<C && yy<R && map[yy][xx][_current]!=-1){
                map[yy][xx][_next]+=AA;
                cnt++;
            }
        }
        AA*=cnt;
        map[y][x][_next] += A-AA;
    }
    queue <pair<int,int>> empty;
    myQ.swap(empty);
}

int getResult(){
    int result = 0;

    for(int t=1;t<=T;t++){
        int current = (t+1)%2;
        int next = t%2;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                check[i][j] = false;
                if(map[i][j][current]!=-1) map[i][j][next] = 0;
                
                if(map[i][j][current]>0) myQ.push(make_pair(i,j));
            }
        }
        BFS(current,next);
        clean(next);
    }

    int index = T%2;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(map[i][j][index]!=-1) result+=map[i][j][index];
            //printf("%d ",map[i][j][index]);
        }
        //printf("\n");
    }
    
    return result;
}

int main(){
    scanf("%d %d %d",&R,&C,&T);
    int index = 0;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            scanf("%d",&map[i][j][0]);
            if(map[i][j][0]==-1){
                cleaner[index] = i;
                map[i][j][1] = -1;
                index++;
            }
        }
    }
    printf("%d\n",getResult());
    return 0;
}