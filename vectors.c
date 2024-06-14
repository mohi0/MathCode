#include<stdio.h>
#include<math.h>


typedef struct v3{
    float i, j, k;
} v3;

void addv3s(v3 *a, v3 *b, v3 *result){
    result->i = a->i + b->i;
    result->j = a->j + b->j;
    result->k = a->k + b->k;
}

void subv3s(v3 *a, v3 *b, v3 *result){
    result->i = a->i - b->i;
    result->j = a->j - b->j;
    result->k = a->k - b->k;
}

void dotv3s(v3 *a, v3 *b, float *result){
    *result = (a->i * b->i) + (a->j * b->j) + (a->k * b->k);
}

void printv3(v3 *v){
    printf("\n %fi %fj %fk\n", v->i, v->j, v->k);
}
