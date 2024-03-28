void traverse(char **grid, int i, int j, int row, int* col) {
    if(grid[i][j]=='0')
        return;
    grid[i][j]='0';
    if(i>0)
        traverse(grid, i-1, j, row, col);
    if(i+1<row)
        traverse(grid, i+1, j, row, col);
    if(j>0)
        traverse(grid, i, j-1, row, col);
    if(j+1<*col)
        traverse(grid, i, j+1, row, col);
    return;
}
int numIslands(char** grid, int gridSize, int* gridColSize) {
    int i = 0, j = 0;
    int num = 0;
    for (i=0;i<gridSize;i++) {
        for(j=0;j<*gridColSize;j++) {
            if(grid[i][j]=='1') {
                num+=1;
                traverse(grid, i, j, gridSize, gridColSize);
            }
        }
    }
    return num;
}
