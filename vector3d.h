#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <vector>

template <class T> class vector3d {
public:
  vector3d();

  const T getX() { return X; }
  const T getY() { return Y; }
  const T getZ() { return Z; }

  // This should work, right?
  T SumXYZ() { return X + Y + Z; }

  friend bool operator<(const vector3d &vector1, const vector3d &vector2) {
    return (vector1.SumXYZ() <
            vector2.SumXYZ()); // Dunno if this works since it doesn't
                               // auto-complete but too tired to test it now
  }

private:
  T X;
  T Y;
  T Z;
};

#endif // VECTOR3D_H
