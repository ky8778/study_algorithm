// BJ1874 : https://www.acmicpc.net/problem/1874
#include<stdio.h>

#define MAX 100050

int top;
int stack[MAX];
int input[MAX];
int sortedInput[MAX];
char result[MAX*2];

void stackInit(void){
    top = 0;
}

int stackIsEmpty(void){
    return (top==0);
}

int stackIsFull(void){
    return (top == MAX);
}

int stackPush(int value){
    if(stackIsFull()){
        printf("Stack Overflow!!\n");
        return 0;
    }
    stack[top] = value;
    top++;
    return 1;
}

int stackPop(int *value){
    if(top==0){
        printf("Stack is Empty!!");
        return 0;
    }
    top--;
    *value = stack[top];
    return 1;
}

void quickSort(int inputArr[],int first,int last){
    int pivot;
    int temp;
    int i;
    int j;

    if(first<last){
        pivot = first;
        i = first;
        j = last;
        while(i<j){
            while(inputArr[i]<=inputArr[pivot]&&i<last) i++;
            while(inputArr[j]>inputArr[pivot]) j--;
            if(i<j){
                temp = inputArr[i];
                inputArr[i] = inputArr[j];
                inputArr[j] = temp;
            }
        }
        temp = inputArr[pivot];
        inputArr[pivot] = inputArr[j];
        inputArr[j] = temp;

        quickSort(inputArr,first,j-1);
        quickSort(inputArr,j+1,last);
    }
}

// sorting된 array를 받아서 push와 pop을 이용해서 해당 수열을 만드는게 가능한지 확인하는 함수.
// index에 해당하는 숫자보다 작거나 같은 수 이면 push 아니면 pop
int getResult(int sizeArr){
    int resultIdx = 0;
    int inputIdx = 0;

    for(int i=0;i<sizeArr;i++){
        while(input[i]>=sortedInput[inputIdx] && inputIdx<sizeArr){
            stackPush(sortedInput[inputIdx]);
            result[resultIdx] = '+';
            resultIdx++;
            inputIdx++;
        }
        
        int tempValue;
        if(stackPop(&tempValue)==0) return 0;
        else{
            if(tempValue==input[i]){
                result[resultIdx] = '-';
                resultIdx++;
            }else{
                return 0;
            }
        }
    }

    result[resultIdx] = '0';
    return resultIdx;
}

int main(){
    int N;
    scanf("%d",&N);
    for(int n=0;n<N;n++){
        scanf("%d",&input[n]);
        sortedInput[n] = input[n];
    }
    
    quickSort(sortedInput,0,N-1);
    stackInit();

    if(getResult(N)==0) printf("NO\n");
    else{
        int index = 0;
        while(result[index]!='0'){
            printf("%c\n",result[index]);
            index++;
        }
    }

    return 0;
}
