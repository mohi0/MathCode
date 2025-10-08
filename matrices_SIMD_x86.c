//SIMD code for computing matrices. __m128 data type (mostly)

typedef struct matSimd_m128 {
  int rows, cols;
  __m128 *matrix;
};

matSimd_m128 addMat(matSimd_m128 *mat1, matSimd_m128 *mat2){
  if(mat1->rows == mat2->rows && mat1->cols == mat2->cols){
    for (int i = 0; i < mat1->rows; i++){
      
    }
  }
}
