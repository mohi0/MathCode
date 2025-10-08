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

__m128 meanVecs_m128(__m128 *vecs, int count){
  __m128 vecSum = addVecs_m128(vecs, count);
  __m128 div = _mm_set1_ps(count);
  vecSum = _mm_div_ps(vecSum, div);
  return vecSum;
}

float dotProduct_m128(__m128  *vecs, int count){
  __m128 vecDot = _mm_set_ps(1.0, 1.0, 1.0, 1.0);
  for(int i = 0; i < count; i++){
    vecDot = _mm_mul_ps(vecDot, (*(vecs + i)));
  }
  //sum of all elements in __m128
  vecDot = _mm_add_ps(vecDot, _mm_movehl_ps(vecDot, vecDot)); 
  vecDot = _mm_add_ss(vecDot, _mm_shuffle_ps(vecDot, vecDot, _MM_SHUFFLE(1, 1, 1, 1))); 
  return _mm_cvtss_f32(vecDot);
}

float magnitudeVecs_128(__m128 *vecs, int count){
  float magnitude = 0;
  for(int i = 0; i < count; i++){
    __m128 ve = (*(vecs + i));
    ve = _mm_mul_ps(ve, ve);
    magnitude += sqrt(ve[0] + ve[1] + ve[2] + ve[3]);
  }
  return magnitude;
}

float cosineSimilarity(__m128 *vecs, int count){
  float magnitude = 0;
  float dot = dotProduct_m128(&vecs, count);
  for(int i = 0; i < count; i++){
    __m128 ve = (*(vecs + i));
    ve = _mm_mul_ps(ve, ve);
    magnitude *= sqrt(ve[0] + ve[1] + ve[2] + ve[3]);
  }
  return dot / magnitude;
}


_m128 crossProduct(_m128 *vec1, _m128 *vec2){
  _m128 v1 = *vec1;
  _m128 v2 = *vec2;
  const int YZXW = _MM_SHUFFLE(3, 0, 2, 1);
  _m128 v1_yzx = _mm_shuffle_ps(v1, v1, YZXW);
  const int ZXYW = _MM_SHUFFLE(3, 1, 0, 2);
  _m128 v2_zxy = _mm_shuffle_ps(v2, v2, ZXYW);
  _m128 mul1 = _mm_mul_ps(v1_yzx, v2_zxy);
  _m128 v1_zxy = _mm_shuffle_ps(v1, v1, ZXYW);
  _m128 v2_yzx = _mm_shuffle_ps(v2, v2, YZXW);
  _m128 mul2 = _mm_mul_ps(v1_zxy, v2_yzx);
  _m128 result = _mm_sub_ps(mul1, mul2);
  return result;
}
