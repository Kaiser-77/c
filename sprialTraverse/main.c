#include<stdio.h>


void logic_function(int inputArray[][100], int rows, int cols, int* outputArray){
    int index = 0,r,c;
    int cycle_count = rows/2;
    for (int i=0;i<cycle_count;i++){
        r=i;
        c=i;
        // for(c=i;c<=rows-2-i;c++){
        //     outputArray[index++] = inputArray[r][c];
        // }
        // for(r=i;r<=rows-2-i;r++){
        //     outputArray[index++] = inputArray[r][c];
        // }
    
        // for(c=rows-1-i;c>i;c--){
        //     outputArray[index++] = inputArray[r][c];
        // }
    
        // for(r=rows-1-i;r>i;r--){
        //     outputArray[index++] = inputArray[r][c];
        // }

      

     

      // Traverse Right to Left
      for (c = cols - 1 - i; c > i; c--) {
        outputArray[index++] = inputArray[r][c];
      }

      for (r = i; r < rows - 1 - i; r++) {
        outputArray[index++] = inputArray[r][c];
    }
    // Traverse Left to Right
    for (c = i; c < cols - 1 - i; c++) {
      outputArray[index++] = inputArray[r][c];
  }
      // Traverse Bottom to Top
      for (r = rows - 1 - i; r > i; r--) {
          outputArray[index++] = inputArray[r][c];
      }
       
      
        
    }
    if(rows%2==1) outputArray[index] = inputArray[cycle_count][cycle_count];

}

void main(){
    printf("Hello there...\n");
    int rows=4,cols=5;
    int inputArray[][100] = {
      {1,2,3,4,5},
      {6,7,8,9,10},
      {11,12,13,14,15},
      {16,17,18,19,20}
  };

//   int rows=4,cols=4;
//   int inputArray[][100] = {
//     {1,2,3,4},
//     {5,6,7,8},
//     {9,10,11,12},
//     {13,14,15,16}
//   };
  
  // int rows=3,cols=3;
  // int inputArray[][100] = {
  //   {4,5,2},
  //   {7,3,1},
  //   {1,2,3}
  // };
//   int rows=2,cols=2;
//   int inputArray[][100] = {
//     {100,200},
//     {200,100}
//   };
  
  int outputArray[100];
  
  
  logic_function(inputArray,rows,cols,outputArray);
  
  // checking answer
  for(int i=0;i<rows*cols;i++){
    printf("%d ",outputArray[i]);
  }
  }