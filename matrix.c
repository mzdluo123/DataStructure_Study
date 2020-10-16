#include <stdio.h>
#include <stdlib.h>

typedef struct Tuple
{
    int row;
    int col;
    int value;
} Tuple;

typedef struct Matrix
{
    int row_num, col_num, cnt;
    Tuple **data;
} Matrix;

Matrix *convertToMatrix(int **matrix ,int col , int row)
{

    int notZero = 0;

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (matrix[i][j] != 0)
            {
                notZero++;
            }
        }
    }
    if (notZero == 0)
    {
        return NULL;
    }

    Matrix *structMatrix = malloc(sizeof(Matrix));
    structMatrix->col_num = col;
    structMatrix->row_num = row;
    structMatrix->cnt = notZero;
    Tuple **t = malloc(sizeof(Tuple *) * notZero);
    int offset = 0;
    structMatrix->data = t;
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (matrix[i][j] != 0)
            {
                t[offset] = (Tuple *)malloc(sizeof(Tuple));
                t[offset]->col = i;
                t[offset]->row = j;
                t[offset]->value = matrix[i][j];
                offset++;
            }
        }
    }


    return structMatrix;
}

Matrix* multiply(Matrix *a,Matrix *b){
    if (a->col_num != b->row_num ) // 不能相乘
    {
        return NULL;
    }
     if(0 == a->cnt * b->cnt ){ //有一个是零矩阵
        return;
    }
    
    Matrix *ans = malloc(sizeof(Matrix));
    ans->col_num = a->row_num;
    ans->row_num = b->col_num;
    for (int i = 0; i < a->cnt; i++)
    {
        /* code */
    }
    
}

void printMatrix(Matrix *m){
    printf("size: %d \n", m->cnt);
    printf("row %d \n", m->row_num);
    printf("col %d \n", m->col_num);
    for (int i = 0; i < m->cnt; i++)
    {
       printf("%d %d %d \n", m->data[i]->col,m->data[i]->row,m->data[i]->value);
    }
    
}

int main(int argc, char const *argv[])
{
    int a[10][10] = 
    {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 5, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 7, 0}, 
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
    {0, 0, 0, 9, 0, 0, 0, 0, 8, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

     int b[10][10] = 
    {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 5, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 7, 0}, 
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
    {0, 0, 0, 9, 0, 0, 0, 0, 8, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    Matrix * m = convertToMatrix(&a,10,10);
    printMatrix(m);
    return 0;
}
