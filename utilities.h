#pragma once
#include "matrix3d.h"
#include "vector3d.h"
#include "point3d.h"
#include "plane.h"
#include "transform4d.h"
#include "line.h"
#include "quatrenion.h"
#include <utility>
#include <iostream>
namespace Lina{ namespace Math{ namespace Util{

    Matrix3D rotationMatrix(float theta, const Vector3D& axis);
    Matrix3D reflectionMatrix(const Vector3D& axis);
    Matrix3D identityMatrix();
    Matrix3D involutionMatrix(const Vector3D& axis);
    Matrix3D scaleMatrix(float s, const Vector3D& axis);
    Matrix3D skewMatrix(float theta, const Vector3D& v0,
            const Vector3D& v1);
    Transform4D zUp();
    Transform4D yUp();
    Vector3D xAxis();
    Vector3D yAxis();
    Vector3D zAxis();
    Vector3D lerp(const Vector3D& v0, const Vector3D& v1, float beta);

    Plane xyPlane();
    Plane xzPlane();
    Plane yzPlane();

    Transform4D planeReflectionMatrix(const Plane& f);
    Transform4D translationMatrix(const Vector3D& translate);
    Transform4D scaleMatrix(const Vector3D& scale);
    Transform4D transMatrix(const Matrix3D& transform,const Vector3D& translate);
    Transform4D rotationMatrix4D(float theta,const Vector3D& axis);
    Matrix4D projMatrix(float fov, float ar, float nearf = 0.0f, float farf = 1000.0f);

    Line connectOrigin(const Point3D& p);

    Quatrenion lerp(const Quatrenion& q1, const Quatrenion& q2, float beta);
    Quatrenion slerp(const Quatrenion& q1, const Quatrenion& q2, float beta);

    std::pair<Quatrenion, Quatrenion> dualQuatrenion(const Quatrenion& q0, const Quatrenion& q1);

    float distance(const Point3D& q, const Point3D& p, const Vector3D& v);
    float distance(const Point3D& p0, const Vector3D& v0,
            const Point3D& p1, const Vector3D& v1);

    inline Point3D origin()
    {
        return {0.0, 0.0, 0.0};
    }
}}}

