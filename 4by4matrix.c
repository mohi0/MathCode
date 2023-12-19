/*
C program for reading a 4x4 matrix and then performing mathematical operations on the the matrices
This C program was written to read the 4x4 matrix written in MATLAB format of matrices in a .txt file 
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct{
    float matrix[4][4];
    int current_row_index;
    int current_column_index;
}Matlab_Matrix;

Matlab_Matrix matricesArr[100];
int matricesArrCurrentIndex = 0;

char currentValStr[20];
int currentValStrIndex = 0;

Matlab_Matrix currentMatrix;


void emptyCurrentValStr(){
    for(int i = 0; i < 20; i++){
        currentValStr[i] = '0';
    }
}



void readMatrix(){

    int NEW_ROW = 1; 
    int VALUE = 2;
    int SPACE = 3;
    int MATRIX_END = 4;

    int NO_OP = -1;

    int CURRENT_OP_CODE;
    int PREV_OP_CODE;

    currentMatrix.current_column_index = 0;
    currentMatrix.current_row_index = 0;

    FILE *file;
    file = fopen("matrix.txt", "r");

    char c;
    while ((c = fgetc(file)) != EOF)
    {
        if(c == ' '){
            CURRENT_OP_CODE = SPACE;
        }else if(c == ';'){
            CURRENT_OP_CODE = NEW_ROW;
        }else if(c == ']'){
            CURRENT_OP_CODE = MATRIX_END;
        }else if(isdigit(c) == 1 || c == '.'){
            CURRENT_OP_CODE = VALUE;
        }

        if(CURRENT_OP_CODE == VALUE && PREV_OP_CODE == VALUE){
            currentValStr[currentValStrIndex] = c;
            currentValStrIndex++;
        }else if(CURRENT_OP_CODE == VALUE && CURRENT_OP_CODE != PREV_OP_CODE){
            currentValStrIndex = 0;
            emptyCurrentValStr();
            currentValStr[currentValStrIndex] = c;
            currentValStrIndex++;
        }
        if(CURRENT_OP_CODE != VALUE && PREV_OP_CODE == VALUE){
            currentValStrIndex = 0;
            currentMatrix.matrix[currentMatrix.current_row_index][currentMatrix.current_column_index] = atof(currentValStr);
            currentMatrix.current_column_index++;
        }

        if(CURRENT_OP_CODE == NEW_ROW){
            currentMatrix.current_column_index = 0;
            currentMatrix.current_row_index++;
        }
        if(CURRENT_OP_CODE == MATRIX_END){
            matricesArr[matricesArrCurrentIndex] = currentMatrix;
            matricesArrCurrentIndex++;
            currentMatrix = (Matlab_Matrix){
                {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, 0, 0
            };
            currentMatrix.current_row_index = 0;
        }
        //at end set PREV_OP_CODE
        PREV_OP_CODE = CURRENT_OP_CODE;
        CURRENT_OP_CODE = NO_OP;
    }   
}

Matlab_Matrix addMatrices(Matlab_Matrix matrix1, Matlab_Matrix matrix2){
    Matlab_Matrix sumMatrix;
    for (int rowIndex = 0; rowIndex < 4; rowIndex++){
        for(int columnIndex = 0; columnIndex < 4; columnIndex++){
            sumMatrix.matrix[rowIndex][columnIndex] = matrix1.matrix[rowIndex][columnIndex] + matrix2.matrix[rowIndex][columnIndex];
        }
    }
    return sumMatrix;
}

Matlab_Matrix substractMatrices(Matlab_Matrix matrix1, Matlab_Matrix matrix2){
    Matlab_Matrix differenceMatrix;
    for (int rowIndex = 0; rowIndex < 4; rowIndex++){
        for(int columnIndex = 0; columnIndex < 4; columnIndex++){
            differenceMatrix.matrix[rowIndex][columnIndex] = differenceMatrix.matrix[rowIndex][columnIndex] - differenceMatrix.matrix[rowIndex][columnIndex];
        }
    }
    return differenceMatrix;
}

Matlab_Matrix multiplyMatrix(Matlab_Matrix matrix1, Matlab_Matrix matrix2){
    Matlab_Matrix productMatrix;

    for(int rowIndex = 0; rowIndex < 4; rowIndex++){
        for (int columnIndex = 0; columnIndex < 4; columnIndex++){
            for(int loopIndex = 0; loopIndex < 4; loopIndex++){
                productMatrix.matrix[rowIndex][columnIndex] += matrix1.matrix[rowIndex][loopIndex] * matrix2.matrix[loopIndex][columnIndex];
            }
        }
    }
    return productMatrix;
}

void printMatrix(Matlab_Matrix matrixToPrint){
    for (int i = 0; i < 4; i++){
        for(int x = 0; x < 4; x++){
            printf("%f \t", matrixToPrint.matrix[i][x]);
        }
        printf("\n");
    }
}

int main(){
    readMatrix();
    printf("\n Two Matrices\n");
    for (int l = 0; l < 2; l++){
        printf("\n Matrix %d \n", l+1);
        printMatrix(matricesArr[l]);
    }

    Matlab_Matrix sumMatrix = addMatrices(matricesArr[0], matricesArr[1]);

    printf("\n Sum of Two Matrices\n");
    printMatrix(sumMatrix);

    Matlab_Matrix differenceMatrix = substractMatrices(matricesArr[0], matricesArr[1]);
    printf("\n Difference of Two Matrices\n");
    printMatrix(differenceMatrix);

    Matlab_Matrix productMatrix = multiplyMatrix(matricesArr[0], matricesArr[1]);
    printf("\n Product of Two Matrices\n");
    printMatrix(productMatrix);


    return 0;
}
