/*
Maze Problem 
Starting point is m[0][0], need to find a path go to m[9][9]. 0 means OK, 1 means cannot go there, boundary is 0 and 9, cannot go beyond boundary. Each step can be made horizontally or vertically for one more grid (diagonal
jump is not allowed).
Your program should print a series of grid coordinates that start from m[0][0] and go to m[9][9]
Hint: No need to find the shortest path, only need to find one path that gets you to desitination.
*/
#include <stdio.h>

#define N 10

int maze[N][N] = {
    {0, 1, 1, 1, 0, 1, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 0, 1, 0, 0, 0, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
    {0, 1, 1, 0, 0, 0, 1, 1, 0, 0},
    {0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0, 0, 1, 1, 1, 0},
    {0, 0, 1, 0, 0, 1, 0, 1, 0, 0},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 0}
};

int path[N][N];

// Function to print the path
void printPath() {
    printf("Path:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(path[i][j]==1)
                printf("(%d,%d) ", i, j);
            else
                printf("      ");
        }
        printf("\n");
    }
}

// Function to solve the maze
int solveMaze(int x, int y) {
    // If the current position is outside the maze or blocked, return false
    if (x < 0 || y < 0 || x >= N || y >= N || maze[x][y] == 1)
        return 0;

    // If the current position is the destination, return true
    if (x == N - 1 && y == N - 1) {
        path[x][y] = 1;
        return 1;
    }

    // Mark the current position as part of the path
    path[x][y] = 1;

    // Move horizontally and vertically
    if (solveMaze(x + 1, y) || solveMaze(x, y + 1)) {
        return 1;
    }
    // If no path is found, backtrack
    path[x][y] = 0;
    return 0;
}

int main() {
    // Initialize the path matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            path[i][j] = 0;
        }
    }

    // Solve the maze starting from (0,0)
    if (solveMaze(0, 0)) {
        printPath();
    } else {
        printf("No path found.\n");
    }

    return 0;
}
