void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int i=0, j=0;
    for(i=0;i<matrixSize;i++) {
        for(j=i+1;j<matrixSize;j++) {
                int n = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = n;
        }
    } 
    for(i=0;i<matrixSize;i++) {
        for (j=0;j<matrixSize/2;j++) {
                int n = matrix[i][j];
                matrix[i][j] = matrix[i][matrixSize-j-1];
                matrix[i][matrixSize-j-1] = n;
        }
    }
}
