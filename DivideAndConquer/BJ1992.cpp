
//! 20200128
// TODO Divide & Conquer
// BJ1992 : https://www.acmicpc.net/problem/1992

#include<cstdio>
#include<string>
using namespace std;

const int MAX = 70;
int inputMap[MAX][MAX];
int N;

int checkMap(int rowStart,int colStart,int lenMap){
    int start = inputMap[rowStart][colStart];
    for(int r=rowStart;r<rowStart+lenMap;r++){
        for(int c=colStart;c<colStart+lenMap;c++){
            if(inputMap[r][c] != start) return -1;
        }
    }
    return start;
}

void getResult(int rowStart,int colStart,int lenMap, string& result){
    if(lenMap<=1){
        result.push_back('0' + inputMap[rowStart][colStart]);
        return;
    }else{
        int tmpResult = checkMap(rowStart,colStart,lenMap);
        if(tmpResult==-1){
            result.push_back('(');
            lenMap /= 2;
            getResult(rowStart,colStart,lenMap,result);
            getResult(rowStart,colStart+lenMap,lenMap,result);
            getResult(rowStart+lenMap,colStart,lenMap,result);
            getResult(rowStart+lenMap,colStart+lenMap,lenMap,result);
            result.push_back(')');
        }else{
            result.push_back('0'+tmpResult);
        }
    }
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        char tmp[MAX];
        scanf("%s",tmp);
        for(int j=0;j<N;j++){
            inputMap[i][j] = tmp[j]-'0';
        }
    }
    // printf("test\n");
    string final;
    getResult(0,0,N,final);
    printf("%s",final.c_str());

    return 0;
}