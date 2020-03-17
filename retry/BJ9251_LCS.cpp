//! 2020.03.17
// TODO BJ9251_LCS
#include<iostream>
#include<string>
using namespace std;

const int MAX = 1050;
int DP[MAX][MAX];
string A,B;

int getMax(int n1,int n2){
    if(n1>n2) return n1;
    else return n2;
}

int getResult(int idxA,int idxB){
    if(idxA>=A.size() || idxB>=B.size()) return 0;
    
    int& ret = DP[idxA][idxB];
    if(ret!=-1) return ret;
    if(A[idxA]==B[idxB]){
        ret = 1+getResult(idxA+1,idxB+1);
    }
    else ret = 0;
    ret = getMax(ret,getResult(idxA+1,idxB));
    ret = getMax(ret,getResult(idxA,idxB+1));
    return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    getline(cin,A);
    getline(cin,B);
    for(int i=0;i<A.size();i++){
        for(int j=0;j<B.size();j++){
            DP[i][j] = -1;
        }
    }
    cout << getResult(0,0) << endl;

    return 0;
}