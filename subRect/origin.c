#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printSubmatrix(char** matrix, int startRow, int endRow, int startCol, int endCol) {
    printf("Maximal Rectangle Submatrix:\n");
    for (int i = startRow; i <= endRow; i++) {
        for (int j = startCol; j <= endCol; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0) return 0;

    int numCols = matrixColSize[0];
    int* heights = (int*)calloc(numCols, sizeof(int));
    int maxArea = 0;

    // Tracking variables for maximal rectangle
    int startRow = -1, endRow = -1, startCol = -1, endCol = -1;

    for (int i = 0; i < matrixSize; i++) {
        // Update histogram heights
        for (int j = 0; j < numCols; j++) {
            heights[j] = (matrix[i][j] == '0') ? 0 : heights[j] + 1;
        }

        // Arrays to find left and right boundaries
        int* nextSmaller = (int*)malloc(numCols * sizeof(int));
        int* prevSmaller = (int*)malloc(numCols * sizeof(int));
        for (int j = 0; j < numCols; j++) prevSmaller[j] = -1;
        for (int j = 0; j < numCols; j++) nextSmaller[j] = numCols;

        int* stack = (int*)malloc(numCols * sizeof(int));
        int top = -1;

        // Find next smaller element
        for (int j = numCols - 1; j >= 0; j--) {
            printf("topppp = %d \n",top);

            while (top != -1 && heights[stack[top]] >= heights[j]) top--;
            if (top != -1) nextSmaller[j] = stack[top];
            stack[++top] = j;
        }

        top = -1;
        // Find previous smaller element
        for (int j = 0; j < numCols; j++) {
            while (top != -1 && heights[stack[top]] >= heights[j]) top--;
            if (top != -1) prevSmaller[j] = stack[top];
            stack[++top] = j;
        }

        // Calculate max area & track coordinates
        for (int j = 0; j < numCols; j++) {
            int width = nextSmaller[j] - prevSmaller[j] - 1;
            int area = heights[j] * width;
            if (area > maxArea) {
                maxArea = area;
                startRow = i - heights[j] + 1;
                endRow = i;
                startCol = prevSmaller[j] + 1;
                endCol = nextSmaller[j] - 1;
            }
        }

        free(nextSmaller);
        free(prevSmaller);
        free(stack);
    }

    free(heights);

    if (maxArea > 0) {
        printSubmatrix(matrix, startRow, endRow, startCol, endCol);
    }

    return maxArea;
}

int main() {
    char* matrix[] = {
        "10100",
        "10111",
        "11111",
        "10010"
    };
    int matrixSize = 4;
    int matrixColSize[] = {5, 5, 5, 5};

    int maxArea = maximalRectangle(matrix, matrixSize, matrixColSize);
    printf("Maximal Rectangle Area: %d\n", maxArea);

    return 0;
}
