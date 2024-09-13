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
