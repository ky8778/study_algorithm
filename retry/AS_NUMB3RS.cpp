//! 2020.03.11
//TODO AS_NUMB3RS
#include<cstdio>
using namespace std;
const int MAX = 55;

int N,T,D,start;
int myMap[MAX][MAX];
int orderMap[MAX];
double myP[105][MAX];

void initArr(){
    for(int j=0;j<N;j++){
        for(int i=0;i<=D;i++){
            myP[i][j] = 0;
        }
        orderMap[j] = 0;
    }
}

void getResult(){
    myP[0][start] = 1;
    for(int day=1;day<=D;day++){
        for(int k=0;k<N;k++){
            for(int prev=0;prev<N;prev++){
                if(myMap[prev][k]){
                    myP[day][k] += (myP[day-1][prev]/(double)orderMap[prev]);
                }
            }
        }
    }
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        scanf("%d %d %d",&N,&D,&start);
        initArr();
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                scanf("%d",&myMap[i][j]);
                orderMap[i] += myMap[i][j];
            }
        }
        getResult();
        int NN;
        scanf("%d",&NN);
        for(int i=0;i<NN;i++){
            int tmp;
            scanf("%d",&tmp);
            printf("%.8lf ",myP[D][tmp]);
        }
        printf("\n");
    }

    return 0;
}