// 2019.10.17
// algorithm : Brute Force
// 3H 정도 풀고 오답부분(Input을 받는 home,dist,chick의 크기를 정확히 계산하지 못함.)을 질문으로 해결.

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 55;
int N,M,sizeHome,sizeChick;
int map[MAX][MAX];
pair <int,int> dist[2*MAX][2*MAX];
pair <int,int> home[2*MAX];
pair <int,int> chick[2*MAX];
bool check[MAX];

void getDistance(){
    //printf("home : %d, chick : %d\n",sizeHome,sizeChick);
    for(int i=0;i<sizeHome;i++){
        //printf("home index : (%d,%d)\n",home[i].first,home[i].second);
        for(int j=0;j<sizeChick;j++){
            //printf("chick index : (%d %d)\n",chick[j].first,chick[j].second);
            int dx = chick[j].second - home[i].second;
            int dy = chick[j].first - home[i].first;
            if(dx<0) dx = -dx;
            if(dy<0) dy = -dy;
            dist[i][j].first = dx + dy;
            dist[i][j].second = j;
        }
    }
}

int distBF(int n,int m){
    if(n>=sizeChick){
        if(m<=M && m>0){
            // compute distance
            int result = 0;
            for(int i=0;i<sizeHome;i++){
                int index = 0;
                for(int j=0;j<sizeChick;j++){
                    index = dist[i][j].second;
                    if(check[index]==true){
                        result+=dist[i][j].first;
                        break;
                    }
                }
            }
            return result;
        }else return -1;
    }
    int first = distBF(n+1,m);
    if(first<0) first = 987987987;

    check[n] = true;
    int second = distBF(n+1,m+1);
    if(second<0) second = 987987987;

    check[n] = false;
    return first < second ? first : second;
}

int getResult(){
    int result = 0;
    getDistance();
    
    for(int i=0;i<sizeHome;i++){
        sort(dist[i],dist[i]+sizeChick);
    }

    /////////////////////////////////////////
    // code for Debug
    // for(int i=0;i<sizeHome;i++){
    //     for(int j=0;j<sizeChick;j++){
    //         printf("%d %d\t",dist[i][j].first,dist[i][j].second);
    //     }
    //     printf("\n");
    // }
    /////////////////////////////////////////

    result = distBF(0,0);
    
    return result;
}

int main(){
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&map[i][j]);
            if(map[i][j]==1) home[sizeHome++] = pair <int,int> (i,j);
            else if(map[i][j]==2) chick[sizeChick++] = pair <int,int> (i,j);
        }
    }
    
    printf("%d\n",getResult());

    return 0;
}