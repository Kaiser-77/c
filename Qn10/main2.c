#include<stdio.h>

void shiftRowValues(int* arr, int num,int size){
    int temp;
    for(int i=0;i<num;i++){
      temp = arr[size-1];
      for(int j=size-1;j>0;j--){
        arr[j] = arr[j-1];
      }
      arr[0] = temp;
    }
  }
  
  
  int traverseArray(int inputArray[][100], int rows, int cols, int start_row, int start_col, int end_row, int end_col, int* arr,int sir,int sic,int tir, int tic) {

    int index = 0, row = start_row, col = start_col;
    int starting_i,target_i;
    int up = ((start_row + start_col)%2 == 0) ? 1 : 0; 
    int totalElements = rows * cols;
      
      while (index < totalElements) {
        if(row == sir && col == sic) starting_i = index;
        if(row == tir && col == tic) target_i = index;
          arr[index++] = inputArray[row][col];
          if (row == end_row && col == end_col) break; 
          
          if (up) { 
              if (col + 1 < cols && row - 1 >= 0) {
                  row--, col++;
              }
              else {
                  up = 0;
                  if (col + 1 < cols) col++; 
                  else row++; 
              }
          } else { 
              if ((row + 1 < rows && col - 1 >= 0) ) {
                  row++, col--;
              } 
              else {
                  up = 1;
                  if (row + 1 < rows) row++; 
                  else col++; 
              }
          }
      
          if (index >= totalElements) break; 
      }
    return target_i - starting_i;
  }
  
  int fillArrayZigZag(int inputArray[][100], int rows, int cols, int start_row, int start_col, int end_row, int end_col, int* arr) {

    int index = 0, row = start_row, col = start_col;
    int up = ((start_row + start_col)%2 == 0) ? 1 : 0; 
    int totalElements = rows * cols;
      
      while (index < totalElements) {
          inputArray[row][col] = arr[index++];
          if (row == end_row && col == end_col) break; 
          
          if (up) { 
              if (col + 1 < cols && row - 1 >= 0) {
                  row--, col++;
              }
              else {
                  up = 0;
                  if (col + 1 < cols) col++; 
                  else row++; 
              }
          } else { 
              if ((row + 1 < rows && col - 1 >= 0) ) {
                  row++, col--;
              } 
              else {
                  up = 1;
                  if (row + 1 < rows) row++; 
                  else col++; 
              }
          }
          if (index >= totalElements) break; 
      }
    return 0;
  }
  

  void logic_function(int array[][100],int rows,int cols,int start_row,int start_col,int target_row,int target_col) {
  
    int arr[100];
    int matrix[100][100];
    
    int shiftCount = traverseArray(array,rows,cols,0,0,rows-1,cols-1,arr,0,0,0,1);
    if(shiftCount < 0) shiftCount += rows*cols;
    shiftRowValues(arr,shiftCount,rows*cols);
    
    // fillDiagonalZigzag(arr,rows,cols,array);
    fillArrayZigZag(array,rows,cols,0,0,rows-1,cols-1,arr);
    
  }

  void main(){
    printf("Hello there...\n");
    int rows=5,cols=5;
    int array[][100] = {
      {1,2,6,7,15},
      {3,5,8,14,16},
      {4,9,13,17,22},
      {10,12,18,21,23},
      {11,19,20,24,25}
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
  
  // int outputArray[100];
  
  
  logic_function(array,rows,cols,0,1,0,0);
  
  // checking answer
  for(int i=0;i<rows;i++){
    for(int j=0;j<rows;j++){
      printf("%d ",array[i][j]);
    }
  }

  }