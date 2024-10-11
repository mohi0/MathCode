//nums is an array pointer, count is number of elements in the array
float average(float *nums, int count){
  float sum = 0.0f;
  for(int i = 0; i < count; i++){
    sum += *(nums + i);
  }
  return sum / count;

}

//sortedArr is array pointer of sorted array, count is the number of elements in the sorted array
float median(float *sortedArr, int count){
    float median;
    if (count  % 2 == 0)
    {
        median =  ( *(sortedArr + count / 2 - 1) + *(sortedArr + count / 2) ) / 2;
    }
    return median;
}

//sortedArr is the array and count is the number of elements in the array
float mode(float sortedArr[], int count){
    float median = median(&sortedArr, count);
    float mean = average(&sortedArr, count);
    return 3 * median - 2 * mean;
}
