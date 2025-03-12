#include<stdio.h>

int min(int num1,int num2){
    if(num1 > num2) return num2;
    return num1;
}



void logic_function(int array[][100], int rows, int cols, int *answer) {
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
        if(i==0 && j==0) array[i][j];
        else if(i==0) array[i][j] = array[i][j] + array[i][j-1];
        else if(j==0) array[i][j] = array[i][j] + array[i-1][j];
        else array[i][j] = array[i][j] + min(array[i][j-1],array[i-1][j]);
    }
  }
  answer[0] = array[rows-1][cols-1];
 }



void main(){
//   int rows=5,cols=5;
//   int inputArray[][100] = {
//     {1,2,3,4,5},
//     {6,7,8,9,10},
//     {11,12,13,14,15},
//     {16,17,18,19,20},
//     {21,22,23,24,25}
// };

int rows=3,cols=3;
int answer;
int array[][100] = {
  {1,3,1},
  {1,5,1},
  {4,2,1}
};
// int rows=2,cols=2;
// int inputArray[][100] = {
//   {100,200},
//   {200,100}
// };



logic_function(array,rows,cols,&answer);

// checking answer
for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
        printf("%d ",array[i][j]);
    }
  printf("\n");
}
printf("%d ",answer);
}