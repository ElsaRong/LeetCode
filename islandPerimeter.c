int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    int i, j = 0;
    int landNum = 0;
    int intersection = 0;
    printf("gridSize=%d, *gridColSize=%d\n", gridSize, *gridColSize);
    for (i = 0; i < *gridColSize; i++)  //列递增
    {
        for (j = 0; j < gridSize; j++)  //行递增
        {
            if (grid[j][i] == 1) 
            {
                landNum++;
                if (((i-1) >= 0) && (grid[j][i-1] == 1))  //向左找
                    intersection++;
                if (((j+1) < gridSize) && (grid[j+1][i] == 1)) //向上找
                    intersection++;
            }
        }
    }
    return 4*landNum - 2*intersection;
}
