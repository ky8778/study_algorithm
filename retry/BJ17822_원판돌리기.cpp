//! 2020.02.06
// TODO BJ17822_원판돌리기 : https://www.acmicpc.net/problem/17822
#include<cstdio>
#include<queue>
#include<deque>
#include<vector>

using namespace std;

const int MAX = 55;
const int CLKW = 0;
const int REVCLKW = 1;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
deque <int> inMap[MAX];
vector <int> rotInfo[MAX];
queue <pair<int,int>> myQ;
int T,N,M;
bool checkMap[MAX][MAX];

void calculating(){
    int sum = 0.;
    int cnt = 0;
    for(int n=0;n<N;n++){
        for(int m=0;m<M;m++){
            if(inMap[n][m]>0){
                sum+=inMap[n][m];
                cnt++;
            }
        }
    }
    for(int n=0;n<N;n++){
        for(int m=0;m<M;m++){
            if(inMap[n][m]!=0){
                int current = inMap[n][m];
                current *= cnt;
                if(current>sum){
                    inMap[n][m]--;
                }else if(current<sum){
                    inMap[n][m]++;
                }
            }
        }
    }
}

void rotating(int xx,int dd,int kk){
    for(int idx = xx;idx<=N;idx+=xx){
        if(dd==CLKW){
            for(int ik=0;ik<kk;ik++){
                int tmp = inMap[idx-1].back();
                inMap[idx-1].pop_back();
                inMap[idx-1].push_front(tmp);
            }
        }else if(dd==REVCLKW){
            for(int ik=0;ik<kk;ik++){
                int tmp = inMap[idx-1].front();
                inMap[idx-1].pop_front();
                inMap[idx-1].push_back(tmp);
            }
        }
    }
}

bool inRange(int y){
    if(y>=0 && y<N) return true;
    else return false;
}

bool BFS(int yy,int xx){
    int value = inMap[yy][xx];
    checkMap[yy][xx] = true;
    myQ.push(make_pair(yy,xx));
    int cnt = 0;
    while(!myQ.empty()){
        pair <int,int> current = myQ.front();
        myQ.pop();
        inMap[current.first][current.second] = 0;
        cnt++;
        for(int dir=0;dir<4;dir++){
            int nextY = current.first+dy[dir];
            int nextX = current.second+dx[dir];
            if(nextX<0) nextX += M;
            else nextX %= M;
            if(inRange(nextY)){
                if(!checkMap[nextY][nextX] && inMap[nextY][nextX]==value){
                    checkMap[nextY][nextX] = true;
                    myQ.push(make_pair(nextY,nextX));
                }
            }
        }
    }
    if(cnt==1){
        inMap[yy][xx] = value;
        return false;
    }else return true;
}

bool deleting(){
    bool ret = false;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!checkMap[i][j] && inMap[i][j]!=0){
                if(BFS(i,j)) ret = true;
            }
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            checkMap[i][j] = false;
        }
    }

    return ret;
}

int getResult(){
    int sum = 0;
    for(int t=0;t<T;t++){
        int x = rotInfo[t][0];
        int d = rotInfo[t][1];
        int k = rotInfo[t][2];
        rotating(x,d,k);
        if(!deleting()) calculating();
    }
    for(int n=0;n<N;n++){
        for(int m=0;m<M;m++){
            sum += inMap[n][m];
        }
    }

    return sum;
}

int main(){
    scanf("%d %d %d",&N,&M,&T);
    for(int n=0;n<N;n++){
        for(int m=0;m<M;m++){
            int tmp;
            scanf("%d",&tmp);
            inMap[n].push_back(tmp);
        }
    }
    for(int t=0;t<T;t++){
        int x,d,k;
        scanf("%d %d %d",&x,&d,&k);
        rotInfo[t].push_back(x);
        rotInfo[t].push_back(d);
        rotInfo[t].push_back(k);
    }

    printf("%d\n",getResult());
    return 0;
}