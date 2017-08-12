#include "stdafx.h"

#include "CR_ShadowedSpotLight.h"

CR_ShadowedSpotLight::CR_ShadowedSpotLight(vec3 color, float range, float cutOff) : CR_SpotLight(color, range, cutOff, true){}
CR_ShadowedSpotLight::CR_ShadowedSpotLight(vec3 color, float range, float cutOff, float ac, float al, float as) : CR_SpotLight(color, range, cutOff, true, ac, al, as){}