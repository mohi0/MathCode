#include<stdio.h>
#include<math.h>


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
