uniform mat4 model;
uniform mat4 view;

uniform mat4 modelViewProjection;

uniform sampler2DArray f_materialTexture;
uniform sampler2DArrayShadow f_shadowMaps;

uniform vec4 f_color;
uniform float f_specularReflectance;
uniform float f_specularExponent;
uniform float f_dispMapScale;
uniform float f_dispMapBias;

uniform vec3 l_ambient;