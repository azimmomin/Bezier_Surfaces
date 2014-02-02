#ifndef VECTOR_H
#define VECTOR_H

class Vector {
  
public:
  float x;
  float y;
  float z;
  float w;
  
  Vector();

  Vector(float x_val, float y_val, float z_val);

  Vector normalize();

  float magnitude();

  Vector cross(Vector v1);

  float operator*(Vector p);

  Vector operator*(float i);

  Vector operator-(Vector p);
  
  Vector operator+(Vector p);

  Vector negate();

  void show();

};

#endif
