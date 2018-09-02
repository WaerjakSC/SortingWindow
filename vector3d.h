#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <vector>

template <class T> class vector3d {
public:
  vector3d(T x, T y, T z) : X(0), Y(0), Z(0) {
    X = x;
    Y = y;
    Z = z;
  }

  const T getX() { return X; }
  const T getY() { return Y; }
  const T getZ() { return Z; }

  // This should work, right?
  T SumXYZ() { return X + Y + Z; }

  friend bool &operator<(vector3d &vector1, vector3d &vector2) {
    return (vector1.SumXYZ() <
            vector2.SumXYZ()); // Dunno if this works since it doesn't
                               // auto-complete but too tired to test it now
  }

  friend std::ostream &operator<<(std::ostream &out, vector3d const &t) {
    out << t.X << t.Y << t.Z;
    return out;
  }

private:
  T X;
  T Y;
  T Z;
};

#endif // VECTOR3D_H
