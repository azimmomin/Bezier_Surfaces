#ifndef PATCH_H
#define PATCH_H
#include "point.h"

class Patch {
 private:
  int counter;
 public:
  Point points[16];
  Patch();
  void addPoints(Point p0, Point p1, Point p2, Point p3);
  void addPoint(Point p0);
  int getCounter();
  void show();
};

#endif
