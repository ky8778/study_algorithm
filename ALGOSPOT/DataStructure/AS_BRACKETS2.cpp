//! 2020.04.03
// TODO stack AS_BRACKETS2
#include<cstdio>
#include<string.h>
#include<stack>
using namespace std;

const int MAX = 10050;
stack <int> myStack;
char myStr[MAX];
int T,len_myStr;

bool getResult(){
    for(int i=0;i<len_myStr;i++){
        if(myStr[i]=='(' || myStr[i]=='{' || myStr[i]=='[') myStack.push(myStr[i]);
        else{
            if(myStr[i]==')'){
                if(!myStack.empty() && myStack.top()=='(') myStack.pop();
                else return false;
            }else if(myStr[i]=='}'){
                if(!myStack.empty() && myStack.top()=='{') myStack.pop();
                else return false;
            }else{
                if(!myStack.empty() && myStack.top()=='[') myStack.pop();
                else return false;
            }
        }
    }

    return myStack.empty() ? true : false;
}

int main(){
    // freopen("input.txt","r",stdin);
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        scanf("%s",myStr);
        len_myStr = strlen(myStr);
        if(getResult()) printf("YES\n");
        else printf("NO\n");
        stack <int> empty;
        myStack.swap(empty);
    }

    return 0;
}