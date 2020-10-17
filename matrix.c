#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1500 //表示稀疏矩阵的非零元素的最大个数
#define MAX_ROW 1500  //表示稀疏矩阵的行数的最大个数
typedef struct Triple
{
    int i, j; //表示非零元素的行下表和列下标
    int val;  //非零元素的值，此处以int类型为例
} Triple;
typedef struct RLSMatrix
{

    Triple data[MAX_SIZE];     //非零元三元组表
    int rpos[MAX_ROW];         //每行第一个非零元素的位置
    int row_num, col_num, cnt; //稀疏矩阵的行数、列数以及非零元素的个数
} RLSMatrix;

void MultRLSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix *rs)
{
    int arow, brow, p, q, ccol, ctemp[MAX_ROW + 1], t, tp;
    if (M.col_num != N.row_num)
    { //不能相乘
        return;
    }
    if (0 == M.cnt * N.cnt)
    { //有一个是零矩阵
        return;
    }

    rs->row_num = M.row_num;
    rs->col_num = N.col_num;
    rs->cnt = 0;
   
    for (arow = 1; arow <= M.row_num; arow++)
    {
        for (ccol = 1; ccol <= rs->col_num; ccol++)
        {
            ctemp[ccol] = 0; //rs的当前行的各列元素清零
        }
        rs->rpos[arow] = rs->cnt + 1; //开始时从第一个存储位置开始存，后面是基于前面的
        if (arow < M.row_num)
        {
            tp = M.rpos[arow + 1]; 
        }
        else
        {
            tp = M.cnt + 1;  
        }
        for (p = M.rpos[arow]; p < tp; p++)
        {
            brow = M.data[p].j;
            
            if (brow < N.row_num)
            {
                t = N.rpos[brow + 1 ];
            }
            else
            {
                t = N.cnt + 1;
            }
            for (q = N.rpos[brow]; q < t; q++)
            {
                ccol = N.data[q].j; 
                ctemp[ccol] += M.data[p].val * N.data[q].val;
            } 
        }     
    
        for (ccol = 1; ccol <= rs->col_num; ccol++)
        {
            if (0 != ctemp[ccol])
            {
                if (++rs->cnt > MAX_SIZE)
                { 
                    return;
                }
                rs->data[rs->cnt].i = arow;
                rs->data[rs->cnt].j = ccol;
                rs->data[rs->cnt].val = ctemp[ccol];
            }
        }
    } //for_arow
}

RLSMatrix *convertToMatrix(int **matrix, int col, int row)
{

    int notZero = 0;
    RLSMatrix *structMatrix = malloc(sizeof(RLSMatrix));

    for (int i = 0; i < col; i++)
    {
        char flag = 0;
        structMatrix->rpos[i] = col;
        for (int j = 0; j < row; j++)
        {
            if (*((int *)matrix + row * i + j))
            {
                notZero++;
                if (!flag)
                {
                    structMatrix->rpos[i] = j;
                    flag = 1;
                }
            }
        }
    }
    if (notZero == 0)
    {
        return NULL;
    }

    structMatrix->col_num = col;

    structMatrix->row_num = row;
    structMatrix->cnt = notZero;

    int offset = 0;
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (*((int *)matrix + row * i + j))
            {
                structMatrix->data[offset].i = i;
                structMatrix->data[offset].j = j;
                structMatrix->data[offset].val = *((int *)matrix + row * i + j);

                offset++;
            }
        }
    }

    return structMatrix;
}

void printMatrix(RLSMatrix *m)
{
    printf("size: %d \n", m->cnt);
    printf("row %d \n", m->row_num);
    printf("col %d \n", m->col_num);
    for (int i = 0; i < m->cnt; i++)
    {
        printf("%d %d %d \n", m->data[i].i,m->data[i].j,m->data[i].val);
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
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    int b[10][10] =
        {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 5, 0, 0, 0, 0, 0, 0},
            {0, 6, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 7, 0},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 9, 0, 0, 0, 0, 8, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    RLSMatrix *m = convertToMatrix(&a, 10, 10);
    printMatrix(m);
    RLSMatrix *n = convertToMatrix(&b, 10, 10);
    printMatrix(n);
    RLSMatrix *ans = malloc(sizeof(RLSMatrix));
    MultRLSMatrix(*m, *n, ans);

    printMatrix(ans);
    return 0;
}
