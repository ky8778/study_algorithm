
//! 2020.02.10
// TODO BJ13460_구슬탈출2
#include <cstdio>
#include <vector>

using namespace std;
const int MAX = 15;
const int INF = 987654321;
int N,M;
int inMap[MAX][MAX];
int remMap[MAX][MAX];
pair <int,int> R;
pair <int,int> B;
int dirInfo[MAX];

void print(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            printf("%d ",inMap[i][j]);
        }
        printf("\n");
    }
}

int move(pair<int,int>& C,int XY,int d){
    inMap[C.first][C.second] = 0;
    if(XY==1){
        int nextX = C.second+d;
        while(inMap[C.first][nextX]!=1 && inMap[C.first][nextX]!=3){
            if(inMap[C.first][nextX]==2) return 1;
            nextX+=d;
        }
        C.second = nextX-d;
        inMap[C.first][C.second] = 3;
    }else{
        int nextY = C.first+d;
        while(inMap[nextY][C.second]!=1 && inMap[nextY][C.second]!=3){
            if(inMap[nextY][C.second]==2) return 1;
            nextY+=d;
        }
        C.first = nextY-d;
        inMap[C.first][C.second] = 3;
    }
    return 0;
}

int getNext(int inDir){
    int tmp1,tmp2;
    switch(inDir){
        case 0:
            if(R.second>=B.second){
                tmp1 = move(R,1,1);
                tmp2 = move(B,1,1);
                if(tmp2==1) return -1;
                else if(tmp1==1) return 1;
            }else{
                // printf("test\n");
                if(move(B,1,1)==1) return -1;
                if(move(R,1,1)==1) return 1;
            }
            break;
        case 1:
            if(R.first>=B.first){
                tmp1 = move(R,2,1);
                tmp2 = move(B,2,1);
                if(tmp2==1) return -1;
                else if(tmp1==1) return 1;
            }else{
                if(move(B,2,1)==1) return -1;
                if(move(R,2,1)==1) return 1;
            }
            break;
        case 2:
            if(R.second<=B.second){
                tmp1 = move(R,1,-1);
                tmp2 = move(B,1,-1);
                if(tmp2==1) return -1;
                else if(tmp1==1) return 1;
            }else{
                if(move(B,1,-1)==1) return -1;
                if(move(R,1,-1)==1) return 1;
            }
            break;
        case 3:
            if(R.first<=B.first){
                tmp1 = move(R,2,-1);
                tmp2 = move(B,2,-1);
                if(tmp2==1) return -1;
                else if(tmp1==1) return 1;
            }else{
                if(move(B,2,-1)==1) return -1;
                if(move(R,2,-1)==1) return 1;
            }
            break;
    }
    return 0;
}

int getMin(){
    pair <int,int> remR = R;
    pair <int,int> remB = B;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            remMap[i][j] = inMap[i][j];
        }
    }

    int result = INF;
    for(int i=0;i<10;i++){
        int ret = getNext(dirInfo[i]);
        if(ret==1){
            result = i+1;
            break;
        }
        else if(ret==-1) break;
        // print();
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            inMap[i][j] = remMap[i][j];
        }
    }
    B = remB;
    R = remR;

    return result;
}

int getResult(int t){
    int minResult = INF;
    if(t>=10){
        return getMin();
    }
    else{
        int result = 0;
        for(int dir=0;dir<4;dir++){
            dirInfo[t] = dir;
            int tmpResult = getResult(t+1);
            if(tmpResult<minResult) minResult = tmpResult;
        }
        return minResult;
    }
}

int main(){
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        char tmp[MAX];
        scanf("%s",tmp);
        for(int j=0;j<M;j++){
            if(tmp[j]=='#') inMap[i][j] = 1;
            else if(tmp[j]=='O') inMap[i][j] = 2;
            else if(tmp[j]=='R'){
                inMap[i][j] = 3;
                R = make_pair(i,j);
            }else if(tmp[j]=='B'){
                inMap[i][j] = 3;
                B = make_pair(i,j);
            }
        }
    }

    int result = getResult(0);
    if(result<=10) printf("%d\n",result);
    else printf("-1\n");
    
    return 0;
}