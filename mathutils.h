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

float arithmaticProgNthTerm(float seq[], float n){
    float d = commonDifference(d);
    return seq[0] + (n - 1) * d;
}

