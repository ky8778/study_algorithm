
//! 20200128 Divide & Conquer
// TODO Karatsuba Algorithm
// multiply very big numbers
#include<cstdio>
#include<vector>

using namespace std;

// num[]의 자릿수 올림을 처리한다.
void normalize(vector<int>& num){
    num.push_back(0);
    // 자릿수 올림을 처리한다.
    for(int i=0;i+1<num.size();i++){
        if(num[i]<0){
            int borrow = (abs(num[i])+9)/10;
            num[i+1] -= borrow;
            num[i] += borrow*10;
        }else{
            num[i+1] += num[i]/10;
            num[i] %= 10;
        }
    }
    while(num.size() > 1 && num.back()==0) num.pop_back();
}

vector<int> multiply(const vector<int>& a,const vector<int>& b){
    vector<int> c(a.size()+b.size()+1,0);
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++){
            c[i+j] += a[i]*b[j];
        }
    }
    normalize(c);
    return c;
}

// karatsuba algorithm
// a += b*(10^k)
void addTo(vector<int>& a, const vector<int>& b, int k);

// a -= b;
void subFrom(vector<int>& a, const vector<int>& b);

