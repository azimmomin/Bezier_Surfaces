#pragma once
#ifndef POINT_H
#define POINT_H

#include "vector.h"

class Point {
  
public:
  float x;
  float y;
  float z;
  float w;
  
  Point();

  Point(Vector v);

  Point(float x_val, float y_val, float z_val);

  float operator*(Point p);

  Point operator*(float i);

  Vector operator-(Point p);
  
  Point operator+(Vector v);

  Point operator+(Point p);

  void show();

};

#endif
