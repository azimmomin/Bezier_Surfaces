#include <iostream>
#include <cmath>
#include "vector.h"
#include "normal.h"
inline float sqr(float x) { return x*x; }

using namespace std;

Vector::Vector() {
  z = 0.0f;
  y = 0.0f;
  x = 0.0f;
  w = 0.0f;
}
Vector::Vector(float x_val, float y_val, float z_val) {
  x = x_val;
  y = y_val;
  z = z_val;
  w = 0.0;
}
Vector Vector::normalize() {
  float magnitude = this->magnitude();
  if (magnitude <= 0.0000001) {
    Vector zeroVector(0, 0, 0);
    return zeroVector;
  }
  Vector newV(x / magnitude, y / magnitude, z / magnitude);
  return newV;
}
float Vector::magnitude() {
  return sqrt(sqr(x) + sqr(y) + sqr(z));
}
Vector Vector::cross(Vector v1) {
  Vector crossV;
  crossV.x = (y * v1.z) - (z * v1.y);
  crossV.y = (z * v1.x) - (x * v1.z);
  crossV.z = (x * v1.y) - (y * v1.x);
  return crossV;
}
float Vector::operator*(Vector p) {
  return (x*p.x + y*p.y + z*p.z);
}
Vector Vector::operator*(float i) {
  Vector newVector(i*x, i*y, i*z);
  return newVector;
}
Vector Vector::operator-(Vector p) {
  Vector newVector(x - p.x, y - p.y, z - p.z);
  return newVector;
}
Vector Vector::operator+(Vector p) {
  Vector newVector(x + p.x, y + p.y, z + p.z);
  return newVector;
}
Vector Vector::negate() {
  Vector newVector(-this->x, -this->y, -this->z);
  return newVector;

}
void Vector::show() {
  cout << "Vector: " << x << " " << y << " " << z << " " << w << endl;
}
