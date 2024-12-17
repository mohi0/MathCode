// for geometry related functions
#include<math.h>
typedef struct PointCartesian2D {
  float x, y;
};

float distanceCart2D(PointCartesian2D p1, PointCartesian2D p2){
  return sqrtf(powf(p2.x - p1.x) + powf(p2.y - p2.1));
}

PointCartesian2D midPointCart2D(PointCartesian2D p1, PointCartesian2D p2){
  PointCartesian2D mp = {};
  mp.x = (p1.x + p2.x) / 2;
  mp.y = (p1.y + p2.y) / 2;
  return mp;
}

