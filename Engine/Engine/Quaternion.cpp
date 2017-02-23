#include "stdafx.h"

#include "Quaternion.h"

Quaternion::Quaternion() : Quaternion(vec3(0, 0, -1), 0){}

Quaternion::Quaternion(float xDir, float yDir, float zDir, float angle) : Quaternion(vec3(xDir, yDir, zDir), angle) {}

Quaternion::Quaternion(vec3 direction, float angle) {
    quaternion = vec4(direction, angle);
    normalize();
}

Quaternion::Quaternion(vec3 euler) {
    setEuler(euler);
}

bool Quaternion::operator==(Quaternion other) {
    return (this->quaternion == other.quaternion);
}

void Quaternion::setEuler(vec3 euler) {
    float t0 = cos(euler.roll / 360.0f * PI);
    float t1 = sin(euler.roll / 360.0f * PI);
    float t2 = cos(euler.pitch / 360.0f * PI);
    float t3 = sin(euler.pitch / 360.0f * PI);
    float t4 = cos(euler.yaw / 360.0f * PI);
    float t5 = sin(euler.yaw / 360.0f * PI);

    quaternion.w = t0 * t2 * t4 + t1 * t3 * t5;
    quaternion.x = t0 * t3 * t4 - t1 * t2 * t5;
    quaternion.y = t0 * t2 * t5 + t1 * t3 * t4;
    quaternion.z = t1 * t2 * t4 - t0 * t3 * t5;

    quaternionChanged = true;
}

void Quaternion::setDirection(vec3 direction) {
    vec3 oldDirection = vec3(quaternion);
    if (oldDirection == direction)
        return;

    quaternion = vec4(direction.x, direction.y, direction.z, quaternion.w);
    quaternionChanged = true;
}

vec3 Quaternion::getDirection() {
    return vec3(quaternion);
}

void Quaternion::setAngle(float angle) {
    angle /= 180;
    if (quaternion.w == angle)
        return;

    quaternion.w = angle;
    normalize();
}

float Quaternion::getAngle() {
    return quaternion.w;
}

Quaternion Quaternion::normalize() {
    quaternion = quaternion.normalize();
    quaternionChanged = true;
    return *this;
}
/*
Quaternion Quaternion::inverse() const {
    return Quaternion(-quaternion.x, -quaternion.y, -quaternion.z, quaternion.w);
}

float Quaternion::magnitude() const {
    return std::sqrt();
}
*/
mat4 Quaternion::getRotationMatrix(bool invert) {
    if (quaternionChanged) {
        //quaternion.normalize();

        rotationMatrix.identity();

        rotationMatrix[0][0] = 1 - 2 * quaternion.y * quaternion.y - 2 * quaternion.z * quaternion.z;
        rotationMatrix[0][1] =     2 * quaternion.x * quaternion.y - 2 * quaternion.z * quaternion.w;
        rotationMatrix[0][2] =     2 * quaternion.x * quaternion.z + 2 * quaternion.y * quaternion.w;

        rotationMatrix[1][0] =     2 * quaternion.x * quaternion.y + 2 * quaternion.z * quaternion.w;
        rotationMatrix[1][1] = 1 - 2 * quaternion.x * quaternion.x - 2 * quaternion.z * quaternion.z;
        rotationMatrix[1][2] =     2 * quaternion.y * quaternion.z - 2 * quaternion.x * quaternion.w;

        rotationMatrix[2][0] =     2 * quaternion.x * quaternion.z - 2 * quaternion.y * quaternion.w;
        rotationMatrix[2][1] =     2 * quaternion.y * quaternion.z + 2 * quaternion.x * quaternion.w;
        rotationMatrix[2][2] = 1 - 2 * quaternion.x * quaternion.x - 2 * quaternion.y * quaternion.y;

        rotationMatrixInverse.identity();
        /*
        vec4 qInverse = vec4(-quaternion.x, -quaternion.y, -quaternion.z, quaternion.w);

        rotationMatrixInverse[0][0] = 1 - 2 * qInverse.y * qInverse.y - 2 * qInverse.z * qInverse.z;
        rotationMatrixInverse[0][1] =     2 * qInverse.x * qInverse.y - 2 * qInverse.z * qInverse.w;
        rotationMatrixInverse[0][2] =     2 * qInverse.x * qInverse.z - 2 * qInverse.y * qInverse.w;

        rotationMatrixInverse[1][0] =     2 * qInverse.x * qInverse.y - 2 * qInverse.z * qInverse.w;
        rotationMatrixInverse[1][1] = 1 - 2 * qInverse.x * qInverse.x - 2 * qInverse.z * qInverse.z;
        rotationMatrixInverse[1][2] =     2 * qInverse.y * qInverse.z - 2 * qInverse.x * qInverse.w;

        rotationMatrixInverse[2][0] =     2 * qInverse.x * qInverse.z - 2 * qInverse.y * qInverse.w;
        rotationMatrixInverse[2][1] =     2 * qInverse.y * qInverse.z - 2 * qInverse.x * qInverse.w;
        rotationMatrixInverse[2][2] = 1 - 2 * qInverse.x * qInverse.x - 2 * qInverse.y * qInverse.y;
        */
        rotationMatrixInverse = rotationMatrix.inverse();

        quaternionChanged = false;
    }

    if (invert)
        return rotationMatrixInverse;
    return rotationMatrix;
}
