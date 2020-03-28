// TODO AS_CHRISTMAS
//! 2020.03.27
/* 오답(시간초과)
#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 100050;
const int MOD = 20091101;
int T,N,K;
int D[MAX];
int mySum[MAX];
vector <int> count[MAX];
int DP[MAX];
int result;

int getSum(){
    mySum[0] = 0;
    for(int i=1;i<=N;i++){
        mySum[i] = (mySum[i-1] + D[i]) % K;
    }

    for(int i=1;i<=N;i++){
        count[mySum[i]].push_back(i);
    }
    
    for(int i=0;i<MAX;i++){
        DP[i] = -1;
    }
    
    int sum = 0;
    for(int i=0;i<K;i++){
        int c = count[i].size();
        sum += (((c*(c-1))/2) % MOD);
    }

    return sum % MOD;
}

int getMax(int n1,int n2){
    if(n1>n2) return n1;
    else return n2;
}

int getResult(int prev){
    int& ret = DP[prev];
    if(ret!=-1) return ret;
    else if(prev+1>N) return 0;
    else{
        ret = 0;
        for(int i=prev+1;i<=N;i++){
            int idx = mySum[i];
            if(idx==0) ret = getMax(ret, 1+getResult(i+1));
            for(int next=0;next<count[idx].size();next++){
                if(count[idx][next] > i){
                    ret = getMax(ret,1+getResult(count[idx][next]));
                }
            }
        }
        return ret;
    }
}

int main(){
    // freopen("input.txt","r",stdin);
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        scanf("%d %d",&N,&K);
        for(int n=1;n<=N;n++){
            scanf("%d",&D[n]);
        }
        printf("%d ",getSum());
        printf("%d\n",getResult(0));
    }

    return 0;
}
*/