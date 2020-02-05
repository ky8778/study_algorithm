
//! 2020.02.05
// TODO BJ14890 경사로 : acmicpc.net/problem/14890
#include<cstdio>

using namespace std;

const int MAX = 105;
const int ROW = 0;
const int COL = 1;
int inMap[MAX][MAX];
int numbers[MAX];
int N,L;
bool checkMap[MAX];

void reset(){
    for(int i=0;i<N;i++){
        checkMap[i] = false;
    }
}

bool checking(int startIdx,int RC){
    if(RC==ROW){
        for(int j=0;j<N;j++){
            numbers[j] = inMap[startIdx][j];
        }
    }else{
        for(int i=0;i<N;i++){
            numbers[i] = inMap[i][startIdx];
        }
    }
    int prev = numbers[0];
    for(int n=1;n<N;n++){
        int next = numbers[n];
        int cnt = 0;
        
        if(prev>next){
            if(prev-next>1) return false;
            n--;
            while(cnt<L){
                n++;
                if(n>=N) return false;
                if(next==numbers[n]) cnt++;
                else return false;
                checkMap[n] = true;
            }
        }
        else if(prev<next){
            if(next-prev>1) return false;
            int tmpIdx = n;
            while(cnt<L){
                n--;
                if(n<0) return false;
                if(!checkMap[n] && prev == numbers[n]) cnt++;
                else return false;
                checkMap[n] = true;
            }
            n = tmpIdx;
        }
        prev = numbers[n];
    }
    return true;
}

int getResult(){
    int ret = 0;

    for(int i=0;i<N;i++){
        if(checking(i,ROW)) ret++;
        reset();
        if(checking(i,COL)) ret++;
        reset();
    }

    return ret;
}

int main(){
    scanf("%d %d",&N,&L);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&inMap[i][j]);
        }
    }

    printf("%d\n",getResult());

    return 0;
}