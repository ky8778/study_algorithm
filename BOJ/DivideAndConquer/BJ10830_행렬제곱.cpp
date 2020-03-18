//! 2020.03.18
// TODO BJ10830_행렬제곱
#include<cstdio>
using namespace std;
const int MAX = 50;
const int SIZEMAX = 7;
const int MOD = 1000;
int A[MAX][SIZEMAX][SIZEMAX];
int result[SIZEMAX][SIZEMAX];
bool check[MAX];

long long B;
int N;

void print(){
    for(int k=0;k<MAX;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                printf("%d ",A[k][i][j]);
            }
            printf("\n");
        }
    }
}

void multArray(int n){
    // printf("mult!\n");
    int next[SIZEMAX][SIZEMAX]={0,};

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                next[i][j] += result[i][k] * A[n][k][j];
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            result[i][j] = next[i][j]%MOD;
        }
    }
}

void initA(){
    long long number = 1;
    int cnt = 0;
    while(number<=B){
        number*=2;
        cnt++;
    }
    number/=2;
    cnt--;
    // printf("number : %d, cnt : %d\n",number,cnt);
    for(int k=1;k<=cnt;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                for(int m=0;m<N;m++){
                    A[k][i][j] += A[k-1][i][m] * A[k-1][m][j];
                }
                A[k][i][j] %= MOD;
            }
        }
    }
}

void getResult(){
    initA();
    while(B>0){
        long long number = 1;
        int cnt = 0;
        while(number<=B){
            number*=2;
            cnt++;
        }
        number/=2;
        cnt--;
        // printf("number : %d, cnt : %d\n",number,cnt);
        B-=number;
        // printf("B : %lld\n",B);
        multArray(cnt);
    }
}

void initArray(){
    for(int i=0;i<N;i++) result[i][i] = 1;
    for(int k=1;k<MAX;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                A[k][i][j] = 0;
            }
        }
    }
}

int main(){
    // freopen("input.txt","r",stdin);
    scanf("%d %lld",&N,&B);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&A[0][i][j]);
        }
    }
    initArray();
    
    getResult();

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }

    return 0;
}