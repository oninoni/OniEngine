#pragma once

#include "stdafx.h"

class Transform {
private:
    bool inverted;

    vec3 d_forward;
    bool forwardHasChanged;

    vec3 d_left;
    bool leftHasChanged;

    vec3 d_up;
    bool upHasChanged;

    vec3 t_translation;
    bool translationHasChanged;
    mat4 translationMatrix;

    vec3 t_rotation;
    bool rotationHasChanged;
    mat4 rotationMatrix;

    vec3 t_scale;
    bool scaleHasChanged;
    mat4 scaleMatrix;

    vec3 t_offset;
    bool offsetHasChanged;
    mat4 offsetMatrix;

    bool hasChanged;
    mat4 transformationMatrix;
public:
    Transform(bool invert = false);
    ~Transform();

    mat4 getTransformationMatrix();

    vec3 getTranslation();
    void setTranslation(vec3 t);
    void setTranslation(float x, float y, float z);

    vec3 getRotation();
    void setRotation(vec3 r);
    void setRotation(float x, float y, float z);

    vec3 getScale();
    void setScale(vec3 s);
    void setScale(float x, float y, float z);

    vec3 getOffset();
    void setOffset(vec3 s);
    void setOffset(float x, float y, float z);

    vec3 getForward();
    vec3 getLeft();
    vec3 getUp();

    __declspec(property(get = getTranslation, put = setTranslation)) vec3 position;
    __declspec(property(get = getRotation, put = setRotation)) vec3 rotation;
    __declspec(property(get = getScale, put = setScale)) vec3 scale;
    __declspec(property(get = getOffset, put = setOffset)) vec3 offset;
};