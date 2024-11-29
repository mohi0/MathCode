// for geometry related functions
#include<math.h>
typedef struct PointCartesian2D {
  float x, y;
};

float distance(PointCartesian2D p1, PointCartesian2D p2){
  return sqrtf(powf(p2.x - p1.x) + powf(p2.y - p2.1));
}

