// for geometry related functions
#include<math.h>
#include "mathutils.h"

float distanceCart2D(Cartesian2D p1, Cartesian2D p2){
  return sqrtf(powf(p2.x - p1.x, 2) + powf(p2.y - p1.y, 2));
}

Cartesian2D midPointCart2D(Cartesian2D p1, Cartesian2D p2){
  Cartesian2D mp = {};
  mp.x = (p1.x + p2.x) / 2;
  mp.y = (p1.y + p2.y) / 2;
  return mp;
}


float distanceCart3D(Cartesian3D p1, Cartesian3D p2){
  return sqrtf(powf(p2.x - p1.x, 2) + powf(p2.y - p1.y, 2) + powf(p2.z - p1.z, 2));
}


Cartesian3D midPointCart3D(Cartesian3D p1, Cartesian3D p2){
  Cartesian3D mp = {};
  mp.x = (p1.x + p2.x) / 2;
  mp.y = (p1.y + p2.y) / 2;
  mp.z = (p1.z + p2.z) / 2;
  return mp;
}

Cartesian2D centeroidCart2D(Cartesian2D *points, int count){
  float xSum = 0;
  float ySum = 0;
  
  for(int i = 0; i < count; i++){
    xSum += (points + i)->x;
    ySum += (points + i)->y;
  }
  
  Cartesian2D cp = {};
  cp.x = xSum / count;
  cp.y = ySum / count;

  return Cartesian2D;
}

Cartesian3D centeroidCart3D(Cartesian3D *points, int count){
  float xSum = 0;
  float ySum = 0;
  float zSum = 0;
  for(int i = 0; i < count; i++){
    xSum += (points + i)->x;
    ySum += (points + i)->y;
    zSum += (points + i)->z;
  }
  
  Cartesian3D cp = {};
  cp.x = xSum / count;
  cp.y = ySum / count;
  cp.z = zSum / count;

  return Cartesian3D;
}

bool checkPointLineCart2D(float a, float b, float c, Cartesian2D pt){
  float eval = a * pt.x + c;
  return (pt.y * -b) == eval;
}

bool checkPointOnCircleCart2D(Cartesian2D center, Cartesian2D point, float radius){
  float cmpr = powf(point.x - center.x, 2) + powf(point.y - center.y, 2);
  return powf(radius, 2) == cmpr;
}

bool checkPointInCircleCart2D(Cartesian2D center, Cartesian2D point, float radius){
  float cmpr = powf(point.x - center.x, 2) + powf(point.y - center.y, 2);
  return powf(radius, 2) > cmpr;
}

bool checkPointOnSphere(Cartesian3D center, Cartesian3D point, float radius){
  float cmpr = powf(point.x - center.x, 2) + powf(point.y - center.y, 2) + powf(point.z - center.z, 2);
  return powf(radius, 2) == cmpr;
}

bool checkPointInSphere(Cartesian3D center, Cartesian3D point, float radius){
  float cmpr = powf(point.x - center.x, 2) + powf(point.y - center.y, 2) + powf(point.z - center.z, 2);
  return powf(radius, 2) > cmpr;
}

