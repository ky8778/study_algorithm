//! 2020.04.08
// TODO KMP https://www.algospot.com/judge/problem/read/NAMING
#include<iostream>
#include<string>
#include<vector>

using namespace std;
string S,R;

vector<int> getPartialMatch(const string& s){
    int size_S = s.size();
    vector<int> ret(size_S,0);
    int start = 1, matched = 0;
    while(start + matched < size_S){
        if(s[start + matched] == s[matched]){
            matched++;
            ret[start + matched - 1] = matched;
        }else{
            if(matched == 0) start++;
            else{
                start += matched - ret[matched - 1];
                matched = ret[matched - 1];
            }
        }
    }
    return ret;
}

vector<int> KMP(const string& H, const string& N){
    int size_H = H.size(), size_N = N.size();
    vector<int> ret;
    vector<int> pi_table = getPartialMatch(N);
    int start = 0, matched = 0;
    while(start <= size_H - size_N){
        if(matched < size_N && H[start + matched] == N[matched]){
            matched++;
            if(matched == (size_N)) ret.push_back(start);
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
    string S1,S2;
    getline(cin,S1);
    getline(cin,S2);
    S+=S1;
    S+=S2;
    R+=S;

    for(int i=0;i<S.size();i++){
        R[i] = S[S.size()-i-1];
    }
    cout << S << endl;
    cout << R << endl;
    vector<int> result = KMP(R,S);
    
    for(int i=0;i<result.size();i++){
        printf("%d ",result[i]);
    }
    printf("\n");

    return 0;
}