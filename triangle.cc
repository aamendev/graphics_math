#include "./triangle.h"

namespace Lina{ namespace Math{

    Triangle::Triangle(Point3D&& p1, Point3D&& p2, Point3D&& p3) :
        mPoints({p1, p2, p3})
    {
    }

    Triangle::Triangle(const Point3D& p1, const Point3D& p2, const Point3D& p3):
        mPoints({p1, p2, p3})
    {
    }


    Plane Triangle::getPlane() const
    {
        return Plane(mPoints[0], mPoints[1], mPoints[2]);
    }

    bool Triangle::lineIntersects(Line2& l)
    {
        const float FLT_MIN = 0.0005;
        Plane p = getPlane();
        auto [l1, l2] = l.getPoints();
        Point3D pi = p.intersect(l1, l2 - l1);
        Vector3D w = pi - mPoints[0];
        Vector3D u = mPoints[2] - mPoints[0];
        Vector3D v = mPoints[1] - mPoints[0];

        float den = u.dot(u) * v.dot(v) - (u.dot(v) * u.dot(v));
        float alphaNum = w.dot(u) * v.dot(v) - (w.dot(v) * u.dot(v));
        float betaNum = w.dot(v) * u.dot(u) - (w.dot(u) * u.dot(v));

        float alpha = alphaNum / den;
        float beta = betaNum / den;

        if (alpha > FLT_MIN && beta > FLT_MIN && alpha + beta < 1 - FLT_MIN
                && alpha < 1 - FLT_MIN && beta < 1 - FLT_MIN)
        {
            return true;
        }
        return false;
    }

    void Triangle::debug()
    {
        std::cout << "\nTRIANGLE:\n\t{";
        std::cout<<"p0: " << mPoints[0] << ", p1: " << mPoints[1] << ", p2: " << mPoints[2];
        std::cout<<'}';
    }
}}
