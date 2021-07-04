//! 2020.06.04
// TODO BJ16236_아기상어
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
// 아기상어 첫 크기 2
// 1초에 상하좌우로 인접한 한칸씩 이동한다.
// 한칸에 물고기는 최대 1마리
// 자신의 크기보다 작은 물고기만 먹을 수 있다.
// 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없다.
// 크기가 같은 물고기는 먹을 수 없지만, 그 물고가기 있는 칸은 지나갈 수 있다.
// 아기 상어가 움직이는 방법
// 1. 더이상 먹을 수 있는 물고기가 공간에 없으면 아기 상어는 엄마 상어에게 도움을 요청한다. 끝
// 2. 먹을 수 있는 물고기가 1마리라면, 그 물고기를 먹으러 간다.
// 3. 먹을 수 있는 물고기가 1마리보다 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.
// 아기상어 이동 : 1초
// 먹는 칸으로 이동과 동시에 물고기를 먹고 빈칸이 됨
// 자신의 크기만큼 물고기를 먹을 때마다 크기가 1 증가
// 맵은 N X N
// 9는 아기 상어의 위치
// 0은 빈칸
// 나머지는 물고기의 크기
// 아기상어 struct shark > pair <int> location, int size
// 상어부터 BFS 하면서 한턴씩 가까운 물고기중 먹을 수 있는 녀석 있는지 체크
// 한 턴에서 여러 물고기가 가능하다면 맨 위 맨 왼쪽녀석을 먹는다.
struct shark{
    int size;
    int eatCnt;
    pair <int, int> location;
};

const int MAX = 25;
const int INF = 987654321;
const int dy[4] = {0,1,0,-1};
const int dx[4] = {1,0,-1,0};

shark babyShark;
int inputMap[MAX][MAX];
bool checkMap[MAX][MAX];
int N;
queue <pair<int,int>> bfsQ;
vector <pair<int,int>> fish;

bool inRange(int y, int x){
    if(y>=0 && x>=0 && y<N && x<N) return true;
    else return false;
}

void eatFish(){
    // fish vector 비우고 먹을 물고기 찾고
    int yy = INF;
    int xx = INF;

    for(int i=0;i<fish.size();i++){
        if(fish[i].first < yy){
            yy = fish[i].first;
            xx = fish[i].second;
        }else if(fish[i].first == yy){
            if(fish[i].second <= xx) xx = fish[i].second;
        }
    }

    vector <pair<int,int>> empty;
    fish.swap(empty);
    inputMap[yy][xx] = 0;
    babyShark.location.first = yy;
    babyShark.location.second = xx;
    babyShark.eatCnt++;
    if(babyShark.eatCnt >= babyShark.size){
        babyShark.size++;
        babyShark.eatCnt = 0;
    }
}

int BFS(){
    bfsQ.push(make_pair(babyShark.location.first,babyShark.location.second));
    checkMap[babyShark.location.first][babyShark.location.second] = true;
    int dist = 0;
    while(!bfsQ.empty()){
        int sizeQ = bfsQ.size();
        bool findFish = false;
        for(int i=0;i<sizeQ;i++){
            pair <int, int> now = bfsQ.front();
            bfsQ.pop();
            for(int dir=0;dir<4;dir++){
                int nextY = now.first+dy[dir];
                int nextX = now.second+dx[dir];
                if(inRange(nextY,nextX) && !checkMap[nextY][nextX] && inputMap[nextY][nextX] <= babyShark.size){
                    checkMap[nextY][nextX] = true;
                    bfsQ.push(make_pair(nextY,nextX));
                    if(inputMap[nextY][nextX] != 0 && inputMap[nextY][nextX] != babyShark.size){
                        findFish = true;
                        fish.push_back(make_pair(nextY,nextX));
                    }
                }
            }
        }
        dist++;
        // printf("dist : %d\n",dist);
        if(findFish){
            eatFish();
            return dist;
        }
    }
    return 0;
}

void resetCheckMap(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            checkMap[i][j] = false;
        }
    }
    queue <pair<int,int>> emptyQ;
    bfsQ.swap(emptyQ);
}

int getResult(){
    int ret = 0;
    while(true){
        int time = BFS();
        resetCheckMap();
        if(time == 0) break;
        else ret += time;
        // printf("time : %d\n",ret);
    }
    return ret;
}

int main(){
    scanf("%d", &N);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d", &inputMap[i][j]);
            if(inputMap[i][j]==9){
                babyShark.location.first = i;
                babyShark.location.second = j;
                babyShark.size = 2;
                babyShark.eatCnt = 0;
                inputMap[i][j] = 0;
            }
        }
    }

    printf("%d\n", getResult());

    return 0;
}


// 2019.10.18
// 1H 30M 걸리고 질문에서 반례를 찾아서 알고리즘의 맹점을 개선시킴
// 반례를 찾고 테스트케이스를 만들어보는 연습또한 중요하다!
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct shark{
    int y;
    int x;
    int size;
};

const int MAX = 25;
int N;
int numFish[7];
int map[MAX][MAX];
bool check[MAX][MAX];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
shark babyShark;
queue <pair<int,int>> myQ;
vector <pair<int,int>> eatFish;

bool compare(pair <int,int> a,pair <int,int> b){
    if(a.first==b.first){
        return a.second<b.second;
    }else return a.first<b.first;
    // if(a.first<b.first) return true;
    // else if(a.first==b.first){
    //     if(a.second<b.second) return true;
    //     else return false;
    // }else return false;
}

int sharkBFS(){
    int TT=-1;
    check[babyShark.y][babyShark.x] = true;
    myQ.push(make_pair(babyShark.y,babyShark.x));
    
    int sizeEatFish = 0;

    while(!myQ.empty() && sizeEatFish==0){
        TT++;
        int sizeQ = myQ.size();
        for(int q=0;q<sizeQ;q++){
            pair <int,int> current = myQ.front();
            myQ.pop();
            int yy = current.first;
            int xx = current.second;
            for(int dir=0;dir<4;dir++){
                int nextY = yy+dy[dir];
                int nextX = xx+dx[dir];
                
                if(nextY>=0&&nextX>=0&&nextX<N&&nextY<N){
                    int nextValue = map[nextY][nextX];
                    if(check[nextY][nextX]==false && nextValue<=babyShark.size){
                        if(nextValue==babyShark.size || nextValue==0){
                            check[nextY][nextX] = true;
                            myQ.push(make_pair(nextY,nextX));
                        }else{
                            eatFish.push_back(make_pair(nextY,nextX));
                            sizeEatFish++;
                        }
                    }
                }
            }
        }
    }
    TT++;
    if(sizeEatFish==0) return -1;
    sort(eatFish.begin(),eatFish.end(),compare);
    //for(int i=0;i<sizeEatFish;i++) printf("(%d,%d)\t",eatFish[i].first,eatFish[i].second);
    babyShark.y = eatFish[0].first;
    babyShark.x = eatFish[0].second;
    int sizeFish = map[eatFish[0].first][eatFish[0].second];
    numFish[sizeFish]--;
    map[eatFish[0].first][eatFish[0].second] = 0;
    for(int i=0;i<sizeEatFish;i++) eatFish.pop_back();

    queue <pair<int,int>> empty;
    myQ.swap(empty);
    return TT;
}

// simulation fucntion
int getResult(){
    int T = 0;

    ///////////////////////////////
    // code for Debug
    // for(int i=1;i<=6;i++){
    //     int fish = numFish[i];
    //     printf("numFish[%d] : %d\n",i,fish);
    //     for(int j=0;j<fish;j++){
    //         printf("position : (%d,%d)\n",Fish[i][j].first,Fish[i][j].second);
    //     }
    // }
    // printf("Shark info : (%d,%d) , size %d\n",babyShark.y,babyShark.x,babyShark.size);
    ///////////////////////////////

    int numEat = 0;
    while(1){
        int cntFish = 0;
        for(int i=1;i<babyShark.size && i<=6;i++) cntFish+=numFish[i];
        //printf("baby size : %d, num of small fish : %d\n",babyShark.size,cntFish);
        if(cntFish<=0) break;
        int nextT = sharkBFS();
        if(nextT==-1) break;
        T += nextT;
        numEat++;
        if(numEat==babyShark.size){
            babyShark.size++;
            numEat = 0;
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                check[i][j] = false;
            }
        }
    }

    return T;
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&map[i][j]);
            if(map[i][j]==9){
                map[i][j] = 0;
                babyShark.x = j;
                babyShark.y = i;
                babyShark.size = 2;
            }else if(map[i][j]>0){
                int sizeFish = map[i][j];
                numFish[sizeFish]++;
            }
        }
    }
    printf("%d\n",getResult());
    return 0;
}