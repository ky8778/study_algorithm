//! 2020.04.07
// TODO KMP https://www.acmicpc.net/problem/1786

#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> getPartialMatch(const string& N){
    int size_N = N.size();
    vector<int> pi_table(size_N,0);
    int start = 1, matched = 0;
    while(start + matched < size_N){
        if(N[start + matched] == N[matched]){
            matched++;
            pi_table[start + matched-1] = matched;
        }else{
            if(matched == 0) start++;
            else{
                start += matched - pi_table[matched - 1];
                matched = pi_table[matched - 1];
            }
        }
    }
    return pi_table;
}

vector<int> KMP(const string& H, const string& N){
    int size_H = H.size(), size_N = N.size();
    vector<int> ret;
    vector<int> pi_table = getPartialMatch(N);
    int start = 0, matched = 0;
    while(start <= size_H - size_N){
        if(matched < size_N && H[start + matched] == N[matched]){
            matched++;
            if(matched == size_N) ret.push_back(start);
        }else{
            if(matched==0) start++;
            else{
                start += matched - pi_table[matched-1];
                matched = pi_table[matched-1]; 
            }
        }
    }
    return ret;
}

int main(){
    string T, P;
    vector<int> result;
    getline(cin,T);
    getline(cin,P);
    result = KMP(T,P);
    printf("%d\n",result.size());
    for(int i=0;i<result.size();i++)
        printf("%d\n",result[i]+1);
    return 0;
}