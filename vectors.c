#include<stdio.h>
#include<math.h>


typedef struct v3{
    float i, j, k;
} v3;

typedef struct v2{
    float i, j;
} v2;

//allocates the space for vectors of some size, 
//vcount is the number of vectors
//count is the number of elements in each vector (dimensions)
void* initV(size_t elementSize, int count, int vcount){
    return malloc(count * vcount * elementSize);
}

//calculates the magnitude if a vector example A is a vector 
// magnitudev3 calculates |A| 
void magnitudev3(v3 *vec, float *result){
    *result = sqrt( (vec->i * vec->i) + (vec->j * vec->j) + (vec->k * vec->k));
}

//add two vectors of type v3
// result = a + b
void addv3s(v3 *a, v3 *b, v3 *result){
    result->i = a->i + b->i;
    result->j = a->j + b->j;
    result->k = a->k + b->k;
}

//add two vectors of type v2
// result = a + b
void addv2s(v2 *a, v2 *b, v2 *result){
    result->i = a->i + b->i;
    result->j = a->j + b->j;

}

//subtract vectors of type v2
// result = a - b
void subv2s(v2 *a, v2 *b, v2 *result){
    result->i = a->i - b->i;
    result->j = a->j - b->j;
}

//subtract vectors of type v3
// result = a + b
void subv3s(v3 *a, v3 *b, v3 *result){
    result->i = a->i - b->i;
    result->j = a->j - b->j;
    result->k = a->k - b->k;
}

//dot product of two v3
// result = a ・ b
void dotv3s(v3 *a, v3 *b, float *result){
    *result = (a->i * b->i) + (a->j * b->j) + (a->k * b->k);
}

//cross product of two v3
// result = a x b
void crossv3s(v3 *a, v3 *b, v3 *result){
    result->i = (a->i * b->k) - (a->k * b->j);
    result->j = - ( (a->i * b->k) - (a->k * b->i) );
    result->k = (a->i * b->j) - (a->j * b->i);
}

//calculates angle between two v3
//result = angle between a and b
void anglev3s(v3 *a, v3 *b, float *result){
    float dotProd, magnitudeA, magnitudeB; 
    dotv3s(a, b, &dotProd);
    magnitudev3(a, &magnitudeA); magnitudev3(b, &magnitudeB);
    *result = acosf(dotProd / (magnitudeA * magnitudeB));
}

//calculates normal vector to plane defined by vectors a and b
// norm = vector perpendicular to plane of a and b
void normToPlane(v3 *a, v3 *b, v3 *norm){
    crossv3s(a, b, norm);
}


//calculates mean of vectors
// vectors is an array pointer each element of array of size v3, 
// count is the number of vectors in the array
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
