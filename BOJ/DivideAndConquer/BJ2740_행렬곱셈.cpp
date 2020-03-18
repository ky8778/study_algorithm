//! 2020.03.18
// TODO BJ2740_행렬곱셈
#include <cstdio>
using namespace std;

const int MAX = 105;
int N,M,K;
int A[MAX][MAX],B[MAX][MAX],result[MAX][MAX];

void getResult(){
    for(int n=0;n<N;n++){
        for(int k=0;k<K;k++){
            for(int m=0;m<M;m++){
                result[n][k]+=A[n][m]*B[m][k];
            }
        }
    }
}

int main(){
    // freopen("input.txt","r",stdin);
    scanf("%d %d",&N,&M);
    for(int n=0;n<N;n++){
        for(int m=0;m<M;m++){
            scanf("%d",&A[n][m]);
        }
    }
    scanf("%d %d",&M,&K);
    for(int m=0;m<M;m++){
        for(int k=0;k<K;k++){
            scanf("%d",&B[m][k]);
        }
    }

    getResult();
    for(int n=0;n<N;n++){
        for(int k=0;k<K;k++){
            printf("%d ",result[n][k]);
        }
        printf("\n");
    }

    return 0;
}