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
  
  int diagonalZigzag(int matrix[][100],int ROWS,int COLS, int* result,int target_row,int target_col,int start_row,int start_col) {
      int index = 0;
      int target_index = 0;
      int start_index = 0;
      for (int d = 0; d < ROWS + COLS - 1; d++) {
          if (d % 2 == 0) {
              int r = (d < ROWS) ? d : ROWS - 1;
              int c = (d < ROWS) ? 0 : d - (ROWS - 1);
  
              while (r >= 0 && c < COLS) {
                if(r == target_row && c == target_col) target_index=index;
                if(r == start_row && c == start_col) start_index=index;
                  result[index++] = matrix[r][c];
                  r--;
                  c++;
              }
          } else {
              int c = (d < COLS) ? d : COLS - 1;
              int r = (d < COLS) ? 0 : d - (COLS - 1);
  
              while (c >= 0 && r < ROWS) {
                if(r == target_row && c == target_col) target_index=index;
                if(r == start_row && c == start_col) start_index=index;
                  result[index++] = matrix[r][c];
                  r++;
                  c--;
              }
          }
      }
    return start_index-target_index;
  }
  
  
  void fillDiagonalZigzag(int arr[], int rows, int cols, int matrix[][100]) {
      int index = 0;
  
      for (int d = 0; d < rows + cols - 1; d++) {
          if (d % 2 != 0) {
              int r = (d < cols) ? 0 : d - cols + 1;
              int c = (d < cols) ? d : cols - 1;
              while (r < rows && c >= 0) {
                  matrix[r][c] = arr[index++];
                  r++;
                  c--;
              }
          } else {
              int c = (d < rows) ? 0 : d - rows + 1;
              int r = (d < rows) ? d : rows - 1;
              while (r >= 0 && c < cols) {
                  matrix[r][c] = arr[index++];
                  r--;
                  c++;
              }
          }
      }
  }
  
  
  void logic_function(int array[][100],int rows,int cols,int start_row,int start_col,int target_row,int target_col) {
  
    int arr[100];
    int matrix[100][100];
    
    int shiftCount = diagonalZigzag(array,rows,cols,arr,target_row,target_col,start_row,start_col);
    printf("_____%d___",shiftCount);
    if(shiftCount < 0) shiftCount += rows*cols;
  
    shiftRowValues(arr,shiftCount,rows*cols);
    
    fillDiagonalZigzag(arr,rows,cols,array);
    
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