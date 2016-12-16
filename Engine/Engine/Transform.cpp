#include "stdafx.h"

#include "Transform.h"

Transform::Transform() {
    translationHasChanged = true;
    rotationHasChanged = true;
    scaleHasChanged = true;
    offsetHasChanged = true;
    forwardHasChanged = true;
    leftHasChanged = true;
    upHasChanged = true;

    scale = vec3(1, 1, 1);
}


Transform::~Transform() {

}

mat4 Transform::getTransformationMatrix(bool inverted) {
    if (translationHasChanged) {
        translationMatrix.setTranslationMatrix(t_translation, false);
        translationMatrixInverse.setTranslationMatrix(t_translation, true);
        translationHasChanged = false;
        hasChanged = true;
    }

    if (rotationHasChanged) {
        rotationMatrix.setRotationMatrix(t_rotation, false);
        rotationMatrixInverse.setRotationMatrix(t_rotation, true);
        rotationHasChanged = false;
        hasChanged = true;

        forwardHasChanged = true;
        leftHasChanged = true;
        upHasChanged = true;
    }

    if (scaleHasChanged) {
        scaleMatrix.setScaleMatrix(t_scale, false);
        scaleMatrixInverse.setScaleMatrix(t_scale, true);
        scaleHasChanged = false;
        hasChanged = true;
    }

    if (offsetHasChanged) {
        offsetMatrix.setTranslationMatrix(t_offset, false);
        offsetMatrixInverse.setTranslationMatrix(t_offset, true);
        offsetHasChanged = false;
        hasChanged = true;
    }

    if (hasChanged) {
        transformationMatrixInverse.identity();

        transformationMatrixInverse *= offsetMatrixInverse;
        transformationMatrixInverse *= scaleMatrixInverse;
        transformationMatrixInverse *= rotationMatrixInverse;
        transformationMatrixInverse *= translationMatrixInverse;

        transformationMatrix.identity();
       
        transformationMatrix *= translationMatrix;
        transformationMatrix *= rotationMatrix;
        transformationMatrix *= scaleMatrix;
        transformationMatrix *= offsetMatrix;

        hasChanged = false;
    }

    return inverted ? transformationMatrixInverse : transformationMatrix;
}

vec3 Transform::getTranslation() const{
    return t_translation;
}

void Transform::setTranslation(vec3 t) {
    if (t == t_translation)
        return;

    translationHasChanged = true;
    t_translation = t;
}

void Transform::setTranslation(float x, float y, float z) {
    setTranslation(vec3(x, y, z));
}

vec3 Transform::getRotation() const{
    return t_rotation;
}

void Transform::setRotation(vec3 r) {
    if (r == t_rotation)
        return;

    rotationHasChanged = true;
    t_rotation = r;
}

void Transform::setRotation(float x, float y, float z) {
    setRotation(vec3(x, y, z));
}

vec3 Transform::getScale() const{
    return t_scale;
}

void Transform::setScale(vec3 s) {
    if (s == t_scale)
        return;

    scaleHasChanged = true;
    t_scale = s;
}

void Transform::setScale(float x, float y, float z) {
    setScale(vec3(x, y, z));
}

vec3 Transform::getOffset() const{
    return t_offset;
}

void Transform::setOffset(vec3 o) {
    if (o == t_offset)
        return;

    offsetHasChanged = true;
    t_offset = o;
}

void Transform::setOffset(float x, float y, float z) {

}

vec3 Transform::getForward() {
    if (forwardHasChanged) {
        vec4 f = transformationMatrixInverse * vec4(0, 0, -1, 0);
        d_forward = vec3(f);
        d_forward.normalize();
        forwardHasChanged = false;
    }
    return d_forward;
}

vec3 Transform::getLeft() {
    if (leftHasChanged) {
        vec4 f = transformationMatrixInverse * vec4(-1, 0, 0, 0);
        d_left = vec3(f);
        d_left.normalize();
        leftHasChanged = false;
    }
    return d_left;
}

vec3 Transform::getUp() {
    if (upHasChanged) {
        vec4 f = transformationMatrixInverse * vec4(0, 1, 0, 0);
        d_up = vec3(f);
        d_up.normalize();
        upHasChanged = false;
    }
    return d_up;
}