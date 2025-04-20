// SIMD instructions with x86

#include <x86intrin.h>

//function to add n vectors with SIMD
__m128 addVecs_m128(__m128 *vecs, int count){
  __m128 vecSum = _mm_set_ps(0.0, 0.0, 0.0, 0.0);
  for(int i = 0; i < count; i++){
    vecSum = _mm_add_ps(vecSum, (*(vecs + i)));
  }
  return vecSum;
}

void meanVecs_m128(__m128 *vecs, int count){} //todo
