#include<stdio.h>
#include<stdlib.h>
#include<math.h>


typedef struct Cartesian2D {
    float x, y;
} Cartesian;

typedef struct Polar2D {
    float r, ar;
} Polar2D;

typedef struct Cartesian3D {
    float x, y, z;
} Cartesian3D;

typedef struct Polar3D {
    float r, ar, az;
} Polar3D;

typedef struct Complex_{
    float real, imag;
} Complex_;

float numsRMS(float nums[], int count){
    float sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += nums[i] * nums[i];
    }
    return sqrtf(sum / count);
}

float sumAll(float nums[], int count){
    float sum = 0;
    for (int i = 0; i < count; i++){
        sum += nums[i];
    }
    return sum;
}

float nthRoot(float value, int root){
    return pow(value, 1.0 / root);
}

float geoMean(float nums[], int count){
    float prod = 1;
    for (int i = 0; i < count; i++)
    {
        prod  *= nums[i];
    }
    return nthRoot(prod, count);
}

float harmonicMean(float nums[], int count){
    float sum = 0;
    for (int i = 0; i < count; i++){
        sum += 1 / nums[i];
    }
    return count / sum;
}


//for arithmatic progressions
float commonDifference(float seq[]){
    float d = seq[1] - seq[0];
    d = seq[2] - seq[1];
    return d;
}

float arithmaticProgNthTerm(float seq[], int n){
    float d = commonDifference(seq);
    return seq[0] + (n - 1) * d;
}

float* arithmaticProgNterms(float seq[], int n){
    float *terms = (float*) malloc(n * sizeof(float));
    float d = commonDifference(seq);
    for (int i = 0; i < n; i++)
    {
        *(terms + i) = seq[0] + (i - 1) *  d;
    }
    return terms;
}

//geomrtric progressions ... 

float commonRatio(float seq[]){    
    float r = seq[2]/seq[1];
    r = seq[1]/seq[0];
    return r;
}

float geometricProNthTerm(float seq[], int n){
    float r = commonRatio(seq);
    return seq[0] * powf(r, n - 1);
}

float geometricSum(float a, float r, int n){
    if(r == 1){
        return a * n;
    }else{
        return a * ( powf(r, n) - 1 ) / (r - 1);
    }
}

//sigmoid function
float sigmoid(float z){
    return 1 / (1 + exp(-z));
}

// Needs Improvement
float rootsOfQuadratic(a, b, c){
    float discriminant = pow(b, 2) - 4 * a * c;

    float root1 = 0f;
    float root2 = 0f; 
    if(discriminant > 0){
        root1 = -b + sqrt(discriminant) / 2 * a;
        root2 = -b - sqrt(discriminant) / 2 * a;
    }
    if(discriminant == 0){
        root1 = -b / 2 * a;
        root2 = root1;
    }
    if(discriminant < 0){
        float real1 = -b /  ( 2 * a );
        float imag1 = sqrt(- (pow(b, 2) - 4 * a * c)) / 2 * a;
    }
}


//needs testing
Polar2D cartesinToPolar(Cartesian2D c){
    float r = sqrt(pow(c.x, 2), pow(c.y, 2));
    float ar = atan(c.y/c.x);
    Polar2D polar = { .r = r, .ar = ar };
    return polar
}

//needs testing
Cartesian2D cartesinToPolar(Polar p){
    float x = p.r * cosf(p.ar);
    float y = p.r * sinf(p.ar);
    Cartesian2D c = { .x = x, .y = y };
    return c
}

Polar3D cartesian3DtoPolar3D(Cartesian3D c){
    float r = sqrt(pow(c.x, 2) + pow(c.y, 2) + pow(c.z, 2));
    float az = atanf(c.z / sqrt(pow(c.x, 2) + pow(c.y, 2)));
    float ar = atan(c.y / c.x);
    Polar3D p = {.r = r, .az = az, .ar = ar};
    return p;
}

Cartesian3D polar3DtoCartesian3D(Polar3D p){
    float x = p.r * cosf(p.az) * cosf(p.ar);
    float y = p.r * cosf(p.az) * sinf(p.ar);
    float z = p.r * sinf(p.az);
    Cartesian3D c = {.x = x, .y = y, .z = z};
    return c;
}

//factorial 
int factorial(int N){
    int pr = 1;
    int n = N;
    while(n > 1){
        pr *= n;
        n = n - 1;
    }
    return pr;
}



