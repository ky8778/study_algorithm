//! 2020.03.08
// TODO AS_TRIPATHCNT
#include<cstdio>
using namespace std;
const int MAX = 105;
int N;
int myMap[MAX][MAX];
int distDP[MAX][MAX];
int cntDP[MAX][MAX];

int getMax(int n1,int n2){
    if(n1>n2) return n1;
    else return n2;
}

int getDist(int y,int x){
    if(y>=N) return 0;
    int& ret = distDP[y][x];
    if(ret!=-1) return ret;
    
    ret = getMax(myMap[y][x]+getDist(y+1,x),myMap[y][x]+getDist(y+1,x+1));
    return ret;
}

int getResult(int y,int x){
    if(y>=N-1) return 1;
    int& ret = cntDP[y][x];
    if(ret!=-1) return ret;

    if(distDP[y+1][x]==distDP[y+1][x+1]) ret = getResult(y+1,x) + getResult(y+1,x+1);
    else if(distDP[y+1][x]>distDP[y+1][x+1]) ret = getResult(y+1,x);
    else ret = getResult(y+1,x+1);
    return ret;
}

int main()
{
	int T;
	// freopen("input.txt", "r", stdin);
	scanf("%d",&T);

	for(int test_case = 1; test_case <= T; ++test_case)
	{
        scanf("%d",&N);
		for(int i=0;i<N;i++){
            for(int j=0;j<=i;j++){
                scanf("%d",&myMap[i][j]);
                cntDP[i][j] = -1;
                distDP[i][j] = -1;
            }
        }
        getDist(0,0);
        printf("%d\n",getResult(0,0));
	}
	return 0;
}