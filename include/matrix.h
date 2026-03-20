typedef struct
{
    int rows;
    int cols;
    int **data;
} Matrix;

void printMatrix(Matrix *mat);

Matrix *mat(int rows, int cols, int *data);

void fillMatrix(Matrix *mat, int *data);

void endMatrix(Matrix *mat);
