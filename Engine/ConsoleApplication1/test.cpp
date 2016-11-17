#include "m_vector.h"
#include "m_matrix.h"

#include <iostream>

using namespace std;


int main() {
    
    vec3 a(1.0f, 2.0f, 3.0f);
    cout << a << endl;
    vec3 b(10.0f, 7.0f, 2.0f);
    cout << b << endl;

    cout << b.distanceTo(a) << endl;

    vec3 z;
    z[0] = 1;
    cout << z << endl;

    mat4 matA, matB;

    cout << asdf.transpose();;

    return 0;
}