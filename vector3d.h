#ifndef VECfloatOR3D_H
#define VECfloatOR3D_H

#include <iostream>
#include <vector>

class vector3d {
public:
  vector3d(float x = 0.0, float y = 0.0, float z = 0.0) : X(x), Y(y), Z(z) {}

  float getX() { return X; }
  float getY() { return Y; }
  float getZ() { return Z; }

  float SumXYZ() { return X + Y + Z; }

  friend bool operator>(vector3d &vector1, vector3d &vector2) {
    return (vector1.SumXYZ() >
            vector2.SumXYZ()); // Dunno if this works since it doesn't
                               // auto-complete but too tired to test it now
  }

  friend std::ostream &operator<<(std::ostream &out, const vector3d &vector) {
    out << "XYZ(" << vector.X << ", " << vector.Y << ", " << vector.Z << ")";
    return out;
  }

private:
  float X, Y, Z;
};

#endif // VECfloatOR3D_H
