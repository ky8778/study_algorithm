//! 2020.03.04
// TODO AS_PI
#include<cstdio>
#include<string.h>
using namespace std;

const int MAX = 10050;
const int INF = 987654321;
char inData[MAX];
int myLv[3][MAX];            // [len-3][startIdx]
int DP[MAX];
int N,T;

int getMin(int n1,int n2){
    if(n1<n2) return n1;
    else return n2;
}

int checkArr(int startIdx,int lenData){
    bool test[4] = {true,true,true,true};
    int prev = inData[startIdx+1]-'0';
    int pprev = inData[startIdx]-'0';
    int prevDist = pprev-prev;
    if(prevDist!=0) test[0] = false;
    if(prevDist!=1 && prevDist!=-1) test[1] = false;
    
    for(int i=startIdx+2;i<startIdx+lenData;i++){
        int next = inData[i]-'0';
        int nextDist = prev-next;
        if(prev!=next) test[0] = false;
        if(prevDist*nextDist!=1) test[1] = false;
        if(prevDist!=-nextDist) test[2] = false;
        if(prevDist!=nextDist) test[3] = false;
        
        prevDist = nextDist;
        prev = next;
    }
    if(test[0]) return 1;
    else if(test[1]) return 2;
    else if(test[2]) return 4;
    else if(test[3]) return 5;
    else return 10;
}

void getLv(){
    for(int l=3;l<=5;l++){
        for(int i=0;i<=N-l;i++){
            for(int j=i;j<i+l;j++){
                myLv[l-3][i] = getMin(myLv[l-3][i],checkArr(i,l));
            }
        }
    }
}

void print(){
    for(int i=0;i<=N;i++){
        printf("DP[%d] : %d\n",i,DP[i]);
        for(int l=3;l<=5;l++){
            printf("myLv[%d][%d] : %d\n",l,i,myLv[l-3][i]);
        }
    }
}

void initTables(){
    for(int i=0;i<=N;i++){
        DP[i] = -1;
        for(int l=3;l<=5;l++){
            myLv[l-3][i] = INF;
        }
    }
}

int getResult(int idx){
    if(idx>=N){
        idx = N;
        return 0;
    }
    int& ret = DP[idx];
    if(ret!=-1) return ret;
    ret = INF;
    for(int l=3;l<=5;l++) ret = getMin(ret,myLv[l-3][idx]+getResult(idx+l));
    return ret;
}

int main(){
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        scanf("%s",inData);
        N = strlen(inData);
        initTables();
        getLv();
        printf("%d\n",getResult(0));
        // print();
    }
    return 0;
}