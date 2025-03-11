#include<stdio.h>


int traverseArray(int inputArray[][100], int rows, int cols, int start_row, int start_col, int end_row, int end_col, int* arr) {

  int index = 0, row = start_row, col = start_col;
  // int up = (((rows-start_row)%2 == 0) && rows > 2) ? 1 : 0; 
  int up = ((start_row + start_col)%2 == 0) ? 1 : 0; 
  int totalElements = rows * cols;
    
    while (index < totalElements) {
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
        if(row == rows-1 && col == cols-1 && totalElements > 4){
          arr[index++] = inputArray[row][col];
          row = 0;
          col = 0;
        }
        if (index >= totalElements) break; 
    }
  return index;
}


void logic_function(int inputArray[][100], int rows, int cols, int start_row, int start_col, int end_row, int end_col, int outputArray[100]) {
  int arr1[100];  
  int arr2[100];  
  int size1 = traverseArray(inputArray,rows,cols,start_row,start_col,end_row,end_col,arr1);

  for(int i=0;i<rows*cols;i++){
    printf("%d ",arr1[i]);
  }
  printf("\n");
  int land,j=0;
  int i=0;
  while(1){
    arr2[j] = arr1[i];
    j++;
    land = arr1[i]%(size1-1-i);
    i = (land == 0) ? i+1 : i+land;
    if( i == size1-1) {
      arr2[j] = arr1[i];
      j++;
      break;}
  }

  outputArray[0] = j;
  for(int i=0; i<j+1;i++){
    outputArray[i+1] = arr2[i];
  }

}

void main(){
  printf("Hello there...\n");
//   int rows=5,cols=5;
//   int inputArray[][100] = {
//     {1,2,3,4,5},
//     {6,7,8,9,10},
//     {11,12,13,14,15},
//     {16,17,18,19,20},
//     {21,22,23,24,25}
// };

// int rows=3,cols=3;
// int inputArray[][100] = {
//   {4,5,2},
//   {7,3,1},
//   {1,2,3}
// };
int rows=2,cols=2;
int inputArray[][100] = {
  {100,200},
  {200,100}
};

int outputArray[100];


logic_function(inputArray,rows,cols,0,1,0,0,outputArray);

// checking answer
for(int i=0;i<rows*cols;i++){
  printf("%d ",outputArray[i]);
}
}