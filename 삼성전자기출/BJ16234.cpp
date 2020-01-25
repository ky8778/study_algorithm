// 2019.10.19
// Simulation & BFS
// 1H 정도.
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

const int MAX = 55;
int map[MAX][MAX][2];
bool check[MAX][MAX];
pair <int,int> rememMap[MAX*MAX];
int N,L,R;
queue <pair<int,int>> myQ;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int BFS(int y,int x,int nowIdx,int nextIdx){
    int count = 0;
    int sumMap = map[y][x][nowIdx];
    check[y][x]=true;
    myQ.push(make_pair(y,x));
    rememMap[count++] = make_pair(y,x);

    while(!myQ.empty()){
        int Qsize = myQ.size();
        for(int i=0;i<Qsize;i++){
            pair <int,int> current = myQ.front();
            myQ.pop();
            int currentValue = map[current.first][current.second][nowIdx];
            for(int dir=0;dir<4;dir++){
                int yy = current.first+dy[dir];
                int xx = current.second+dx[dir];
                if(yy>=0&&xx>=0&&yy<N&&xx<N){
                    int adjValue = map[yy][xx][nowIdx];
                    int dist = currentValue-adjValue;
                    if(dist<0) dist = -dist;
                    if(check[yy][xx]==false && dist>=L && dist<=R){
                        check[yy][xx] = true;
                        sumMap += adjValue;
                        rememMap[count++] = make_pair(yy,xx);
                        myQ.push(make_pair(yy,xx));
                    }
                }
            }
        }
    }

    int nextValue = sumMap/count;
    for(int i=0;i<count;i++){
        int yy = rememMap[i].first;
        int xx = rememMap[i].second;
        map[yy][xx][nextIdx] = nextValue;
    }

    if(count==1) return 0;
    else return 1;
}

int getResult(){
    int result = 0;

    while(1){
        result++;
        int now = (result+1)%2;
        int next = result%2;
        int move = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(check[i][j]==false){
                    move += BFS(i,j,now,next);
                }
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                check[i][j] = false;
            }
        }
        if(move==0){
            result--;
            break;
        }
    }

    return result;
}

int main(){
    scanf("%d %d %d",&N,&L,&R);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&map[i][j][0]);
        }
    }
    printf("%d\n",getResult());

    return 0;
}