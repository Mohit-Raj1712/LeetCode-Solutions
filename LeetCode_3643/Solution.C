/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 void swap(int* a, int* b);
 
int** reverseSubmatrix(int** grid, int gridSize, int* gridColSize, int x, int y, int k, int* returnSize, int** returnColumnSizes) {

    *returnSize = gridSize;
    *returnColumnSizes = (int*) malloc (gridSize * sizeof(int*));

    for (int i = 0; i < gridSize; i++)
        (*returnColumnSizes)[i] = *gridColSize;

    int top_index = x, bottom_index = x + k - 1;

    while (top_index < bottom_index)
    {
        for (int index = y; index < y + k; index ++)
            swap(&grid[top_index][index], &grid[bottom_index][index]);

        top_index ++;
        bottom_index --;
    }

    return grid;
}

void swap(int* a, int* b) {

    int temp = *a;
    *a = *b;
    *b = temp;

    return;
}