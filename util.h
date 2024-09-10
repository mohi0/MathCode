#include<stdio.h>
#include<stdlib.h>

float* reverseFloatArray(float *arr1, int arrSize){
    float *arr = malloc(arrSize * sizeof(float));
    for (int i = 0; i < arrSize; i++){
        printf("is %f \n", *(arr1 + (arrSize - 1 - i)) );
        *(arr + i) = *(arr1 + (arrSize - 1 - i));
    }
    return arr;
}

