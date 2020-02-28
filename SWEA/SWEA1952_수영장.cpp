//! 2020.02.28
// TODO SWEA1952_수영장
/* DP */
#include <cstdio>
using namespace std;
const int INF = 987654321;
int T;
int price[4];           // 0 : 1day, 1 : 1month, 2: 3months, 3:1year
int inData[12];
int DP[12];

int min(int n1,int n2){
    if(n1<n2) return n1;
    else return n2;
}

int getResult(int idx){
    if(idx>=12) return 0;
    int& ret = DP[idx];

    if(DP[idx]!=-1) return DP[idx];
    ret = INF;
    int tmpRet = inData[idx]*price[0];
    ret = min(ret,tmpRet+getResult(idx+1));
    
    tmpRet = price[1];
    ret = min(ret,tmpRet+getResult(idx+1));

    tmpRet = price[2];
    ret = min(ret,tmpRet+getResult(idx+3));

    tmpRet = price[3];
    ret = min(ret,tmpRet+getResult(idx+12));
    return ret;
}

int main(){
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        for(int i=0;i<4;i++) scanf("%d",&price[i]);
        for(int i=0;i<12;i++) scanf("%d",&inData[i]);
        for(int i=0;i<12;i++) DP[i] = -1;
        printf("#%d %d\n",t,getResult(0));
    }
    return 0;
}

/* BruteForce
#include <cstdio>
using namespace std;
const int INF = 987654321;
int T;
int price[4];           // 0 : 1day, 1 : 1month, 2: 3months, 3:1year
int tickets[4];
int inData[12];
int DP[12];
 
int min(int n1,int n2){
    if(n1<n2) return n1;
    else return n2;
}
 
int getResult(int idx){
    if(idx>=12){
        int tmpRet = 0;
        for(int i=0;i<4;i++) tmpRet += (tickets[i]*price[i]);
        return tmpRet;
    }
    else if(inData[idx]==0) return getResult(idx+1);
    else{
        int tmpRet = INF;
         
        tickets[0] += inData[idx];
        tmpRet = min(tmpRet,getResult(idx+1));
        tickets[0] -= inData[idx];
         
        tickets[1]++;
        tmpRet = min(tmpRet,getResult(idx+1));
        tickets[1]--;
 
        tickets[2]++;
        tmpRet = min(tmpRet,getResult(idx+3));
        tickets[2]--;
 
        tickets[3]++;
        tmpRet = min(tmpRet,getResult(idx+12));
        tickets[3]--;
 
         
        return tmpRet;
    }
}
 
int main(){
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        for(int i=0;i<4;i++) scanf("%d",&price[i]);
        for(int i=0;i<12;i++) scanf("%d",&inData[i]);
        printf("#%d %d\n",t,getResult(0));
        for(int i=0;i<4;i++) tickets[i] = 0;
    }
    return 0;
}
*/