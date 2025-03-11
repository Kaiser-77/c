
int detectFoldType(int inputArray[][100], int n){
    int minCorner = 100;
    int foldType = 0; 
    
    if (inputArray[0][0] < minCorner) { // Top-Left
        minCorner = inputArray[0][0];
        foldType = 1;
    }
    if (inputArray[0][n-1] < minCorner) { // Top-Right
        minCorner = inputArray[0][n-1];
        foldType = 2;
    }
    if (inputArray[n-1][n-1] < minCorner) { // Bottom-Right
        minCorner = inputArray[n-1][n-1];
        foldType = 3;
    }
    if (inputArray[n-1][0] < minCorner) { // Bottom-Left
        minCorner = inputArray[n-1][0];
        foldType = 4;
    }

  return foldType;
}


void logic_function(int inputArray[][100], int rows, int cols) {
   
    int n = rows;
    int foldType = detectFoldType(inputArray,rows);


    // Fold based on the detected type
    for(int i =0;i<n;i++){
      if (foldType == 1) {
          for(int j=0;j<n-1-i;j++){
            inputArray[n-1-j][n-1-i] += inputArray[i][j];
            inputArray[i][j] = 0;
          }
        } else if (foldType == 2) {
            for(int j=i+1;j<n;j++){
                inputArray[j][i] += inputArray[i][j];
                inputArray[i][j] = 0;
              }
        } else if (foldType == 3) {
            for(int j=0;j<n-1-i;j++){
                inputArray[i][j] += inputArray[n-1-j][n-1-i];
                inputArray[n-1-j][n-1-i] = 0;
              }
        } else if (foldType == 4) {
            for(int j=i+1;j<n;j++){
                inputArray[i][j] += inputArray[j][i];
                inputArray[j][i] = 0;
              }
        }
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
  
  
  
  logic_function(inputArray,rows,cols);
  
  // checking answer
  for(int i=0;i<rows*cols;i++){
    printf("%d ",inputArray[i]);
  }
  }