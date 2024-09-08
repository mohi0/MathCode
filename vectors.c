#include<stdio.h>
#include<math.h>


typedef struct v3{
    float i, j, k;
} v3;

void magnitudev3(v3 *vec, float *result){
    *result = sqrt( (vec->i * vec->i) + (vec->j * vec->j) + (vec->k * vec->k));
}

void addv3s(v3 *a, v3 *b, v3 *result){
    result->i = a->i + b->i;
    result->j = a->j + b->j;
    result->k = a->k + b->k;
}

void addv2s(v2 *a, v2 *b, v2 *result){
    result->i = a->i + b->i;
    result->j = a->j + b->j;

}

void subv2s(v2 *a, v2 *b, v2 *result){
    result->i = a->i - b->i;
    result->j = a->j - b->j;
}

void subv3s(v3 *a, v3 *b, v3 *result){
    result->i = a->i - b->i;
    result->j = a->j - b->j;
    result->k = a->k - b->k;
}

void dotv3s(v3 *a, v3 *b, float *result){
    *result = (a->i * b->i) + (a->j * b->j) + (a->k * b->k);
}

void crossv3s(v3 *a, v3 *b, v3 *result){
    result->i = (a->i * b->k) - (a->k * b->j);
    result->j = - ( (a->i * b->k) - (a->k * b->i) );
    result->k = (a->i * b->j) - (a->j * b->i);
}

v3 meanv3s(v3 *vectors, int count){
    v3 mean = {0, 0, 0};
    for (int i = 0; i < count; i++){
        mean.i += (*(vectors + i)).i;
        mean.j += (*(vectors + i)).j;
        mean.k += (*(vectors + i)).k;
    }
    mean.i = mean.i / count ;
    mean.j = mean.j / count ;
    mean.k = mean.k / count ;
    return mean;
}

void printv3(v3 *v){
    printf("\n %fi %fj %fk\n", v->i, v->j, v->k);
}
