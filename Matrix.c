#include "Matrix.h"

typedef struct matrix2x2 MATRIX_2x2;
typedef struct matrix3x3 MATRIX_3x3;
typedef struct matrix4x4 MATRIX_4x4;


void add(int rows, int columns, double *mat1Array, double *mat2Array, double *result){
    int i = 0; 
    while(i < (rows * columns)){
        *(result + i) = *(mat1Array + i) + *(mat2Array + i);
        i++;
    }
}

void subtract(int rows, int columns, double *mat1Array, double *mat2Array, double *result){
    int i = 0; 
    while(i < (rows * columns)){
        *(result + i) = *(mat1Array + i) - *(mat2Array + i);
        i++;
    }
}

void multiply_matrix_matrix(int rowsMat1, int colsMat1, int rowsMat2, int colsMat2, double *mat1Array, double *mat2Array, double*result){
    double product = 0;
    int s = 0;
    int resIndex = 0;
    int prevRowStride = 0;
    while(s < colsMat2){
        int prevColstride = 0;
        int startR = 0;
        while(startR < colsMat2){
            int colStride = prevColstride; 
            int rowStride = prevRowStride;
            int start = 0;
            while (start < rowsMat2){
                printf("r:%d,c:%d el1:%lf el2:%lf ", rowStride, colStride, *(mat1Array + rowStride), *(mat2Array + colStride));
                product += *(mat1Array + rowStride) * *(mat2Array + colStride);
                colStride += colsMat2;
                rowStride++;
                start++;
            }
            *(result + resIndex) = product;
            rowStride = 0; colStride = 0;
            prevColstride++; 
            printf("\n product:%lf \t resIndex:%d \n", product, resIndex);
            startR++;
            product = 0;
            resIndex++;
        }
        prevRowStride+=rowsMat2;
        s++;
    }
}


MATRIX_3x3 Add_Matrix3x3(MATRIX_3x3 matrix1, MATRIX_3x3 matrix2){
    MATRIX_3x3 sumMatrix = matrix1;
    add(3, 3, (&matrix1)->matrix, (&matrix2)->matrix, (&sumMatrix)->matrix);
    return sumMatrix;
}

MATRIX_2x2 Add_Matrix2x2(MATRIX_2x2 matrix1, MATRIX_2x2 matrix2){
    MATRIX_2x2 sumMatrix;
    for (int rowIndex = 0; rowIndex < 2; rowIndex++){
        for(int columnIndex = 0; columnIndex < 2; columnIndex++){
            sumMatrix.matrix[rowIndex][columnIndex] = matrix1.matrix[rowIndex][columnIndex] + matrix2.matrix[rowIndex][columnIndex];
        }
    }
    return sumMatrix;
}

MATRIX_3x3 Subtract_Matrix3x3(MATRIX_3x3 matrix1, MATRIX_3x3 matrix2){
    MATRIX_3x3 subtractMatrix;
    for (int rowIndex = 0; rowIndex < 3; rowIndex++){
        for(int columnIndex = 0; columnIndex < 3; columnIndex++){
            subtractMatrix.matrix[rowIndex][columnIndex] = matrix1.matrix[rowIndex][columnIndex] - matrix2.matrix[rowIndex][columnIndex];
        }
    }
    return subtractMatrix;
}
MATRIX_2x2 Subtract_Matrix2x2(MATRIX_2x2 matrix1, MATRIX_2x2 matrix2){
    MATRIX_2x2 subtractMatrix;
    for (int rowIndex = 0; rowIndex < 2; rowIndex++){
        for(int columnIndex = 0; columnIndex < 2; columnIndex++){
            subtractMatrix.matrix[rowIndex][columnIndex] = matrix1.matrix[rowIndex][columnIndex] - matrix2.matrix[rowIndex][columnIndex];
        }
    }
    return subtractMatrix;
}

MATRIX_3x3 Multiply_Matrix3x3(MATRIX_3x3 matrix1, MATRIX_3x3 matrix2){
    MATRIX_3x3 productMatrix;
    for(int rowIndex = 0; rowIndex < 3; rowIndex++){
        for (int columnIndex = 0; columnIndex < 3; columnIndex++){
            productMatrix.matrix[rowIndex][columnIndex] = 0;
            for(int loopIndex = 0; loopIndex < 3; loopIndex++){
                productMatrix.matrix[rowIndex][columnIndex] += matrix1.matrix[rowIndex][loopIndex] * matrix2.matrix[loopIndex][columnIndex];
            }
        }
    }
    return productMatrix;
}
MATRIX_2x2 Multiply_Matrix2x2(MATRIX_2x2 matrix1, MATRIX_2x2 matrix2){
    MATRIX_2x2 productMatrix;
    for(int rowIndex = 0; rowIndex < 2; rowIndex++){
        for (int columnIndex = 0; columnIndex < 2; columnIndex++){
            productMatrix.matrix[rowIndex][columnIndex] = 0;
            for(int loopIndex = 0; loopIndex < 2; loopIndex++){
                productMatrix.matrix[rowIndex][columnIndex] += matrix1.matrix[rowIndex][loopIndex] * matrix2.matrix[loopIndex][columnIndex];
            }
        }
    }
    return productMatrix;
}

MATRIX_3x3 Multiply_Matrix_scalar3x3(MATRIX_3x3 matrix1, double scalar){
    MATRIX_3x3 productMatrix;
    for(int rowIndex = 0; rowIndex < 3; rowIndex++){
        for (int columnIndex = 0; columnIndex < 3; columnIndex++){
            productMatrix.matrix[rowIndex][columnIndex] = 0;
            productMatrix.matrix[rowIndex][columnIndex] = matrix1.matrix[rowIndex][columnIndex] * scalar;
        }
    }
    return productMatrix;
}
MATRIX_2x2 Multiply_Matrix_scalar2x2(MATRIX_2x2 matrix1, double scalar){
    MATRIX_2x2 productMatrix;
    for(int rowIndex = 0; rowIndex < 2; rowIndex++){
        for (int columnIndex = 0; columnIndex < 2; columnIndex++){
            productMatrix.matrix[rowIndex][columnIndex] = 0;
            productMatrix.matrix[rowIndex][columnIndex] = matrix1.matrix[rowIndex][columnIndex] * scalar;
        }
    }
    return productMatrix;
}

double Determinant_Matrix2x2(MATRIX_2x2 mat1){
    double det = mat1.matrix[0][0] * mat1.matrix[1][1] - mat1.matrix[0][1] * mat1.matrix[1][0];
    return det;
}

double Determinant_Matrix3x3(MATRIX_3x3 mat1){
    double det = mat1.matrix[1][1] * mat1.matrix[2][2] - mat1.matrix[1][2] * mat1.matrix[2][1];
    det += -1 * (mat1.matrix[1][0] * mat1.matrix[2][2] - mat1.matrix[1][2] * mat1.matrix[2][0]);
    det += mat1.matrix[1][0] * mat1.matrix[2][1] - mat1.matrix[1][1] * mat1.matrix[2][0];
    return det;
}
