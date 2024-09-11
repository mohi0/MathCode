float average(float *nums, count){
  float sum = 0f;
  for(int i = 0; i < count; i++){
    sum += *(nums + i);
  }
  return sum / count

}
