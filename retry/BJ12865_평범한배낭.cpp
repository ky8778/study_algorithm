//! 2020.03.17
// TODO BJ12865_평범한배낭
#include<cstdio>
#include<vector>
using namespace std;

const int MAX = 100050;
int N,K;
int DP[MAX];
pair <int,int> inData[105];

int getMax(int n1,int n2){
    if(n1>n2) return n1;
    else return n2;
}

int getResult(){
    for(int i=0;i<N;i++){
        int w = inData[i].first;
        int v = inData[i].second;
        for(int k=K;k>=0;k--){
            if(DP[k]!=-1){
                int nextW = k+w;
                int nextV = DP[k]+v;
                if(nextW<=K) DP[nextW] = getMax(DP[nextW],nextV);
            }
        }
    }
    int ret = 0;
    for(int i=0;i<=K;i++) ret = getMax(ret,DP[i]);
    return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d %d",&N,&K);
    for(int n=0;n<N;n++){
        int W,V;
        scanf("%d %d",&W,&V);
        inData[n] = make_pair(W,V);
    }

    for(int i=1;i<=K;i++) DP[i] = -1;
    DP[0] = 0;

    printf("%d\n",getResult());
    return 0;
}