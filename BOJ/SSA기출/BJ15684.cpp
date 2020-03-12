// 2019.10.19
/* algorithm
Brute Force & 최적화.
3H 이상
*/
#include<cstdio>
#include<vector>

using namespace std;

const int MAX = 35;
int map[MAX][MAX];
int DP[MAX][MAX];
int N,M,H;
bool check[MAX][MAX];

int checkLine(int index){
    for(int i=1;i<=H;i++){
        if(map[i][index]==1) index++;
        else if(map[i][index-1]==1) index--;
        //printf("index : %d\n",index);
    }
    return index;
}

bool checkMap(){
    for(int i=1;i<=N;i++){
        if(checkLine(i)!=i) return false;
    }
    return true;
}

int DFS(int makeCnt,int istart,int jstart){
    if(makeCnt>3) return -1;
    if(checkMap()) return makeCnt;

    int min = 4;
    
    for(int j=jstart;j<=N;j++){
        if((map[istart][j]+map[istart][j-1]+map[istart][j+1])==0){
            map[istart][j] = 1;
            int tmp = DFS(makeCnt+1,istart,j);
            if(tmp<0) tmp = 987987987;
            if(tmp<min) min = tmp;
            map[istart][j] = 0;
        }
    }

    for(int i=istart+1;i<=H;i++){
        for(int j=1;j<=N;j++){
            if((map[i][j]+map[i][j-1]+map[i][j+1])==0){
                map[i][j] = 1;
                int tmp = DFS(makeCnt+1,i,j);
                if(tmp<0) tmp = 987987987;
                if(tmp<min) min = tmp;
                map[i][j] = 0;
            }
        }
    }
    
    if(min>3) return -1;
    else return min;
}

int main(){
    scanf("%d %d %d",&N,&M,&H);
    for(int i=0;i<M;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        map[a][b] = 1;
    }
    
    printf("%d\n",DFS(0,1,1));
    return 0;
}