void swap(int* a, int* b);
void rotate_matrix(int** matrix, const int N, const int M);
bool are_matrices_equal(int** matrix, int** target, const int N, const int M);

bool findRotation(int** matrix, int matrixSize, int* matrixColSize, int** target, int targetSize, int* targetColSize) {
    
    const int N = matrixSize;
    const int M = *matrixColSize;

    for (int i = 0; i < 4; i++)
    {
        if (are_matrices_equal(matrix, target, N, M))
            return true;
        
        rotate_matrix(matrix, N, M);
    }

    return false;
}

void swap(int* a, int* b) {

    int temp = *a;
    *a = *b;
    *b = temp;

    return;
}

void rotate_matrix(int** matrix, const int N, const int M) {

    for (int i = 0; i < N; i++)
        for (int j = 0; j < i; j++)
            swap(&matrix[i][j], &matrix[j][i]);
    
    for (int i = 0; i < N; i++)
    {
        int left_index = 0, right_index = M - 1;

        while (left_index < right_index)
        {
            swap(&matrix[i][left_index], &matrix[i][right_index]);

            left_index ++;
            right_index --;
        }
    }

    return;
}

bool are_matrices_equal(int** matrix, int** target, const int N, const int M) {

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (matrix[i][j] != target[i][j])
                return false;
    
    return true;
}