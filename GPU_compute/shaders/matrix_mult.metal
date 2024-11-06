//this code needs testing

#include <metal_stdlib>
using namespace metal;

kernel void matrixMultiply(const device float* A [[buffer(0)]], const device float* B [[buffer(1)]], device float* C [[buffer(2)]],
    uint widthA [[threadgroup_size(0)]], uint heightA [[threadgroup_size(1)]],
    uint widthB [[threadgroup_size(2)]], uint heightB [[threadgroup_size(3)]],
    uint widthC [[threadgroup_size(4)]], uint heightC [[threadgroup_size(5)]],
    uint tId [[thread_index_in_threadgroup_x]], uint tIdY [[thread_index_in_threadgroup_y]] ) {
    
    if (tId < widthC && tIdY < heightC) {
        float sum = 0.0f;
        for (uint k = 0; k < widthA; ++k) {
            sum += A[tId * widthA + k] * B[k * widthB + tIdY];
        }
        C[tId * widthC + tIdY] = sum;
    }
}
