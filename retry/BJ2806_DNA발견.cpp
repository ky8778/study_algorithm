#include <stdio.h>
#define MAX 15
int T,N;
int result;
bool check[MAX][MAX];

void init_condition(){
    for(int j=0;j<MAX;j++){
        for(int i=0;i<MAX;i++){
            check[j][i] = false;
        }
    }
    result=0;
}

void check_map(int y,int x,int dir){
    if(x>=N||x<0||y>=N||y<0){
        return;
    }else{
        check[y][x]=true;
        switch(dir){
            case 0:
                check_map(y+1,x,dir);
                break;
            case 1:
                check_map(y,x+1,dir);
                break;
            case 2:
                check_map(y+1,x+1,dir);
                break;
            case 3:
                check_map(y,x-1,dir);
                break;
            case 4:
                check_map(y-1,x,dir);
                break;
            case 5:
                check_map(y-1,x-1,dir);
                break;
            case 6:
                check_map(y-1,x+1,dir);
                break;
            case 7:
                check_map(y+1,x-1,dir);
                break;
        }
    }
}

void getResult(int y){
    if(y>=N){
        result++;
    }else{
        for(int i=0;i<N;i++){
            if(check[y][i]==false){
                bool check_tmp[MAX][MAX];
                for(int jj=0;jj<MAX;jj++){
                    for(int ii=0;ii<MAX;ii++){
                        check_tmp[jj][ii]=check[jj][ii];
                    }
                }
                
                for(int j=0;j<8;j++){
                    check_map(y,i,j);
                }
                getResult(y+1);
                
                for(int jj=0;jj<MAX;jj++){
                    for(int ii=0;ii<MAX;ii++){
                        check[jj][ii]=check_tmp[jj][ii];
                    }
                }
            }
        }
    }
}

int main(){
    scanf("%d",&T);
    
    for(int i=0;i<T;i++){
        scanf("%d",&N);
        /////////////////////// algorithm  /////////////////////
        init_condition();
        getResult(0);
        ////////////////////////////////////////////////////////
        printf("#%d %d\n",i+1,result);
        
    }
    
    return 0;
}
