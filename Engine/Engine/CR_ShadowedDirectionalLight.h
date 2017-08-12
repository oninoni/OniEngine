#pragma once

#include "CR_DirectionalLight.h"

class CR_ShadowedDirectionalLight : CR_DirectionalLight{
public:
    CR_ShadowedDirectionalLight(vec3 color);
    ~CR_ShadowedDirectionalLight();
};

