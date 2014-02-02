#ifndef TESSELLATE_H
#define TESSELLATE_H
#include <vector>
#include "point.h"
#include "normal.h"
#include "patch.h"
#include "vector.h"
#include <string>

class Shape {
public:
  virtual void draw() = 0;
  virtual void show() = 0;
};

class Tessellate {
public:
  vector<Shape*> shapes;
  float f;
  float minX;
  float maxX;
  float minY;
  float maxY;
  float minZ;
  float maxZ;
  Tessellate();
  Tessellate(vector<Patch*>& patches);
  void draw();
  int getLength(std::string substring);
  void loadOBJ(std::string filename);
  void loadBEZ(std::string filename);
  void load(vector<Patch*>& patches);
  void bezCurveInterp(Point curve[], float t, Point *p, Vector *dp);
  void findPoint(Patch *patch, float u, float v, Point *point, Normal *normal);
  virtual void subdividePatch(Patch *patch) = 0;
};

class Render {
public:
  Tessellate *tessellate;
  float tx;
  float ty;
  float tz;
  float ax;
  float ay;
  Render();
  Render(Tessellate *t);
  void draw();
};

class Renderer {
public:
  vector<Render*> renders;
  Renderer();
  Renderer(vector<Render*>& rs);
  void draw(int selected);
};

class Quad : public Shape {
public:
  Point *points[4];
  Normal *normals[4];
  Quad();
  Quad(Point *p0, Normal *n0, Point *p1, Normal *n1, Point *p2, Normal *n2, Point *p3, Normal *n3);
  virtual void draw();
  virtual void show();
};

class Uniform : public Tessellate {
public:
  Uniform();
  virtual void subdividePatch(Patch *patch);
};

class UVGroup {
public:
  Point *p;
  Normal *n;
  float u;
  float v;
  UVGroup();
  UVGroup(Point *p_0, Normal *n_0, float u_0, float v_0);
};

class UVTri {
public:
  Point *p0;
  Point *p1;
  Point *p2;
  Normal *n0;
  Normal *n1;
  Normal *n2;
  float u0;
  float u1;
  float u2;
  float v0;
  float v1;
  float v2;
  UVGroup get(int index);
  UVTri();
  UVTri(UVGroup uv0, UVGroup uv1, UVGroup uv2);
  UVTri(Point *p_0, Normal *n_0, float u_0, float v_0, Point *p_1, Normal *n_1, float u_1, float v_1, Point *p_2, Normal *n_2, float u_2, float v_2);
};

class Tri : public Shape {
public:
  Point *points[3];
  Normal *normals[3];
  Tri();
  Tri(UVTri uvTri);
  Tri(Point *p0, Normal *n0, Point *p1, Normal *n1, Point *p2, Normal *n2);
  virtual void draw();
  virtual void show();
};

class Polygon : public Shape {
public:
  vector<Point*> points;
  //vector<Normal*> normals;
  Normal *n;
  Polygon();
  virtual void draw();
  virtual void show();
};

class Adaptive : public Tessellate {
public:
  Adaptive();
  virtual void subdividePatch(Patch *patch);
};

#endif
