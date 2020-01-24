// 2019.10.11
#include<cstdio>

using namespace std;

const int MAX = 100050;
int N;
int A[MAX];
int DP[MAX];

int getDP(int x){
    if(x == 1) return DP[x] = A[x];
    if(DP[x]!=0) return DP[x];
    
    int prev = getDP(x-1);
    return DP[x] = A[x] + (prev < 0 ? 0 : prev);
}

int main(){
    scanf("%d",&N);
    for(int n=1;n<=N;n++) scanf("%d",&A[n]);
    int result = -987987987;
    for(int n=1;n<=N;n++){
        int value = getDP(n);
        result = (result<value?value:result);
    }
    printf("%d\n",result);
    return 0;
}