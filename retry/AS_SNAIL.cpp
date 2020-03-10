//! 2020.03.10
// TODO AS_SNAIL
#include<cstdio>
using namespace std;

const int MAX = 1050;
double DP[MAX][MAX*2+1];
int N,M,T;

double getResult(int days,int height){
    if(days>=M) return height >= N ? 1 : 0;
    double& ret = DP[days][height];
    if(ret!=-1) return ret;
    ret = 0.75*getResult(days+1,height+2)+0.25*getResult(days+1,height+1);
    return ret;
}

void initDP(){
    for(int i=0;i<M;i++){
        for(int j=0;j<M*2+1;j++){
            DP[i][j] = -1;
        }
    }
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        scanf("%d %d",&N,&M);
        initDP();
        printf("%.10lf\n",getResult(0,0));
    }
    return 0;
}