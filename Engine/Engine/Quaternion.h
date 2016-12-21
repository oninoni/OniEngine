#pragma once

class Quaternion {
private:
    vec4 quaternion;
    bool quaternionChanged;

    mat4 rotationMatrix;
    mat4 rotationMatrixInverse;
public:
    Quaternion();
    Quaternion(float xDir, float yDir, float zDir, float angle);
    Quaternion(vec3 direction, float angle);
    Quaternion(vec3 euler);

    bool operator==(Quaternion other);

    void setEuler(vec3 euler);

    void setDirection(vec3 direction);
    vec3 getDirection();

    void setAngle(float angle);
    float getAngle();

    //Quaternion inverse() const;
    //float magnitude() const;
    //Quaternion normalize();

    mat4 getRotationMatrix(bool invert);
};