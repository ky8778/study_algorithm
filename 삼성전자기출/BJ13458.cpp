// 2019.10.17
// 17M 24S

#include <cstdio>

using namespace std;

const int MAX = 1000050;
int N;
int A[MAX];
int B,C;

int main(){
    scanf("%d",&N);

    for(int n=0;n<N;n++){
        scanf("%d",&A[n]);
    }
    scanf("%d %d",&B,&C);
    long long result = 0;
    for(int n=0;n<N;n++){
        result++;
        A[n]-=B;
        if(A[n]>0){
            int num = A[n]/C;
            int addition = A[n]%C;
            if(addition>0) num++;
            result+=num;
        }
    }
    printf("%lld\n",result);
    return 0;
}
