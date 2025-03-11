#include<stdio.h>


void rotate(int inputArray[][100],int rows,int cols,int tempArr[][100]){

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            tempArr[j][rows-1-i] = inputArray[i][j];
        }
    }
}
void copy(int inputArray[][100],int rows,int cols,int tempArr[][100]){

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            inputArray[i][j] = tempArr[i][j];
        }
    }
}

void logic_function(int inputArray[][100],int rows,int cols,int degree){
    
    int tempArr[100][100];
    // int rotate_count = (degree < 0) ? (360+degree)/90 : (360+degree)/90;
    int rotate_count = (4 + (degree/90))%4;
    for(int k=0;k<rotate_count;k++){
        rotate(inputArray,rows,cols,tempArr);
        copy(inputArray,rows,cols,tempArr);
    }
}

void main(){
  printf("Hello there...\n");
  int rows=5,cols=5;
  int inputArray[][100] = {
    {1,2,3,4,5},
    {6,7,8,9,10},
    {11,12,13,14,15},
    {16,17,18,19,20},
    {21,22,23,24,25}
};

// int rows=3,cols=3;
// int inputArray[][100] = {
//   {4,5,2},
//   {7,3,1},
//   {1,2,3}
// };

// int rows=2,cols=2;
// int inputArray[][100] = {
//   {100,200},
//   {200,100}
// };


logic_function(inputArray,rows,cols,90);

// checking answer
for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
        printf("%d ",inputArray[i][j]);
    }
}

}