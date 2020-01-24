// 2019.10.10
#include<cstdio>

using namespace std;

const int MAX = 1000005;
int N;
int DP[MAX];

int getDP(int x){
    //printf("%d ",x);
    if(x==1) return 0;
    if(x==2) return 1;
    if(x==3) return 1;
    if(DP[x]!=0) return DP[x];

    int D3 = getDP(x-1)+1;
    int D = D3;
    if(x%3==0){
        int D1 = getDP(x/3)+1;
        if(D1<D) D = D1;
        if(x%2==0){
            int D2 = getDP(x/2)+1;
            if(D2<D) D = D2;
        }
        return DP[x] = D;
    }
    else if(x%2==0){
        int D2 = getDP(x/2)+1;
        if(D2<D) D = D2;
        return DP[x] = D;
    }
    else return DP[x] = D;
}

int main(){
    scanf("%d",&N);
    printf("%d\n",getDP(N));    
    return 0;
}