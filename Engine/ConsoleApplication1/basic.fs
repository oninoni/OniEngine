#version 420

struct BaseLight{
    vec3 l_color;
    float l_intensity;
}

struct DirectionalLight{
    BaseLight base;
    vec3 l_direction;
}

uniform sampler2D f_ambient;
uniform sampler2D f_diffuse;
uniform sampler2D f_specular;
uniform vec4 f_color;

uniform vec3 l_ambient;

uniform DirectionalLight l_directionalLight;

in vec3 f_normal;
in vec2 f_uv;

out vec4 out_color;


vec4 calcLight(BaseLight base, vec3 direction){
    float diffuseFactor = dot(-direction, f_normal);
    vec4 diffuseColor = vec4(0, 0, 0, 0);
    
    if(diffuseFactor > 0){
        diffuseColor = texture(f_diffuse, f_uv) * f_color * vec4(base.l_color, 1.0) * base.l_intensity * diffuseFactor;
    }
    
    return diffuseColor;
}

vec4 calcDirectionalLight(DirectionLight dLight){
    return calcLight(dLight.base, dLight.l_direction);
}

void main(){
    vec4 total_Light = texture(f_ambient, f_uv) * f_color * vec4(l_ambient, 1);
    
    total_Light += calcDirectionalLight(l_directionalLight);
    
    out_color = total_Light;
}