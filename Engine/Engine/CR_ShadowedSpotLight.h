#pragma once

#include "CR_SpotLight.h"

class CR_ShadowedSpotLight : CR_SpotLight{
public:
    CR_ShadowedSpotLight(vec3 color, float range, float cutOff);
    CR_ShadowedSpotLight(vec3 color, float range, float cutOff, float ac, float al, float as);
};

