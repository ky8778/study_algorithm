//! 2020.02.28
// TODO SWEA4008_숫자만들기
#include<cstdio>
using namespace std;

const int MAX = 15;
const int INF = 987654321;
int T,N;
int calIdx[MAX];
int calSet[4];              // 0 : +, 1 : -, 2 : *, 3 : /
int numbers[MAX];
int maxRet,minRet;

int calculate(){
    int ret = numbers[0];
    for(int i=1;i<N;i++){
        switch(calIdx[i-1]){
        case 0:
            ret += numbers[i];
            break;
        case 1:
            ret -= numbers[i];
            break;
        case 2:
            ret *= numbers[i];
            break;
        case 3:
            ret /= numbers[i];
            break;
        }
    }
    return ret;
}

void getResult(int now){
    if(now>=N-1){
        int tmpRet = calculate();
        if(tmpRet<minRet) minRet = tmpRet;
        if(tmpRet>maxRet) maxRet = tmpRet;
        return;
    }
    for(int i=0;i<4;i++){
        if(calSet[i]!=0){
            calSet[i]--;
            calIdx[now] = i;
            getResult(now+1);
            calSet[i]++;
        }
    }
}

int main(){
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        maxRet = -INF;
        minRet = INF;
        scanf("%d",&N);
        for(int i=0;i<4;i++) scanf("%d",&calSet[i]);
        for(int n=0;n<N;n++) scanf("%d",&numbers[n]);
        getResult(0);
        printf("#%d %d\n",t,maxRet-minRet);
    }
    return 0;
}