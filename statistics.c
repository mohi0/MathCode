float average(float *nums, int count){
  float sum = 0.0f;
  for(int i = 0; i < count; i++){
    sum += *(nums + i);
  }
  return sum / count;

}

float median(float *sortedArr, int count){
    float median;
    if (count  % 2 == 0)
    {
        median =  ( *(sortedArr + count / 2 - 1) + *(sortedArr + count / 2) ) / 2;
    }
    return median;
}

float mode(float sortedArr[], int count){
    float median = median(&sortedArr, count);
    float mean = average(&sortedArr, count);
    return 3 * median - 2 * mean;
}
