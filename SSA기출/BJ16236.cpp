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