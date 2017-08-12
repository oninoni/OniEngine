#include "stdafx.h"

#include "CR_ShadowedDirectionalLight.h"

CR_ShadowedDirectionalLight::CR_ShadowedDirectionalLight(vec3 color) : CR_DirectionalLight(color, true) {}

CR_ShadowedDirectionalLight::~CR_ShadowedDirectionalLight() {
}
