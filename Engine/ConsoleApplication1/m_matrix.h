#pragma once

#include "m_vector.h"

template<typename T, int M, int N>
struct matrix;

// Compare

template<typename T, int M, int N>
bool operator==(const matrix<T, M, N> & a, const matrix<T, M, N> & b) {
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (a[i][j] != b[i][j])
                return false;
    return true;
}

template<typename T, int M, int N>
bool operator!=(const matrix<T, M, N> & a, const matrix<T, M, N> & b) {
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (a[i][j] != b[i][j])
                return true;
    return false;
}

// +

template<typename T, int M, int N>
matrix<T, M, N> operator+(const matrix<T, M, N> & a, const matrix<T, M, N> & b) {
    matrix<T, M, N> c;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            c[i][j] = a[i][j] + b[i][j];
    return c;
}

template<typename T, int M, int N>
matrix<T, M, N> operator+=(matrix<T, M, N> & a, const matrix<T, M, N> & b) {
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            a[i][j] += b[i][j];
    return a;
}

// -

template<typename T, int M, int N>
matrix<T, M, N> operator-(const matrix<T, M, N> & a, const matrix<T, M, N> & b) {
    matrix<T, M, N> c;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            c[i][j] = a[i][j] - b[i][j];
    return c;
}

template<typename T, int M, int N>
matrix<T, M, N> operator-=(matrix<T, M, N> & a, const matrix<T, M, N> & b) {
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            a[i][j] -= b[i][j];
    return a;
}

// *

template<typename T, int M, int N, int O>
matrix<T, M, O> operator*(const matrix<T, M, N> & a, const matrix<T, N, O> & b) {
    matrix<T, M, O> c;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < O; j++)
            for (int k = 0; k < N; k++)
            c[i][j] += a[i][k] * b[k][j];
    return c;
}

template<typename T>
matrix<T, 4, 4> operator*(const matrix<T, 4, 4> & a, const matrix<T, 4, 4> & b) {
    matrix<T, 4, 4> c;
    c[0][0] = b[0][0] * a[0][0] + b[1][0] * a[0][1] + b[2][0] * a[0][2] + b[3][0] * a[0][3];
    c[1][0] = b[0][0] * a[1][0] + b[1][0] * a[1][1] + b[2][0] * a[1][2] + b[3][0] * a[1][3];
    c[2][0] = b[0][0] * a[2][0] + b[1][0] * a[2][1] + b[2][0] * a[2][2] + b[3][0] * a[2][3];
    c[3][0] = b[0][0] * a[3][0] + b[1][0] * a[3][1] + b[2][0] * a[3][2] + b[3][0] * a[3][3];
    c[0][1] = b[0][1] * a[0][0] + b[1][1] * a[0][1] + b[2][1] * a[0][2] + b[3][1] * a[0][3];
    c[1][1] = b[0][1] * a[1][0] + b[1][1] * a[1][1] + b[2][1] * a[1][2] + b[3][1] * a[1][3];
    c[2][1] = b[0][1] * a[2][0] + b[1][1] * a[2][1] + b[2][1] * a[2][2] + b[3][1] * a[2][3];
    c[3][1] = b[0][1] * a[3][0] + b[1][1] * a[3][1] + b[2][1] * a[3][2] + b[3][1] * a[3][3];
    c[0][2] = b[0][2] * a[0][0] + b[1][2] * a[0][1] + b[2][2] * a[0][2] + b[3][2] * a[0][3];
    c[1][2] = b[0][2] * a[1][0] + b[1][2] * a[1][1] + b[2][2] * a[1][2] + b[3][2] * a[1][3];
    c[2][2] = b[0][2] * a[2][0] + b[1][2] * a[2][1] + b[2][2] * a[2][2] + b[3][2] * a[2][3];
    c[3][2] = b[0][2] * a[3][0] + b[1][2] * a[3][1] + b[2][2] * a[3][2] + b[3][2] * a[3][3];
    c[0][3] = b[0][3] * a[0][0] + b[1][3] * a[0][1] + b[2][3] * a[0][2] + b[3][3] * a[0][3];
    c[1][3] = b[0][3] * a[1][0] + b[1][3] * a[1][1] + b[2][3] * a[1][2] + b[3][3] * a[1][3];
    c[2][3] = b[0][3] * a[2][0] + b[1][3] * a[2][1] + b[2][3] * a[2][2] + b[3][3] * a[2][3];
    c[3][3] = b[0][3] * a[3][0] + b[1][3] * a[3][1] + b[2][3] * a[3][2] + b[3][3] * a[3][3];
    return c;
}

template<typename T>
matrix<T, 3, 3> operator*(const matrix<T, 3, 3> & a, const matrix<T, 3, 3> & b) {
    matrix<T, 3, 3> c;
    c[0][0] = b[0][0] * a[0][0] + b[1][0] * a[0][1] + b[2][0] * a[0][2];
    c[1][0] = b[0][0] * a[1][0] + b[1][0] * a[1][1] + b[2][0] * a[1][2];
    c[2][0] = b[0][0] * a[2][0] + b[1][0] * a[2][1] + b[2][0] * a[2][2];
    c[0][1] = b[0][1] * a[0][0] + b[1][1] * a[0][1] + b[2][1] * a[0][2];
    c[1][1] = b[0][1] * a[1][0] + b[1][1] * a[1][1] + b[2][1] * a[1][2];
    c[2][1] = b[0][1] * a[2][0] + b[1][1] * a[2][1] + b[2][1] * a[2][2];
    c[0][2] = b[0][2] * a[0][0] + b[1][2] * a[0][1] + b[2][2] * a[0][2];
    c[1][2] = b[0][2] * a[1][0] + b[1][2] * a[1][1] + b[2][2] * a[1][2];
    c[2][2] = b[0][2] * a[2][0] + b[1][2] * a[2][1] + b[2][2] * a[2][2];
    return c;
}

template<typename T, int M, int N>
matrix<T, M, N> operator*=(matrix<T, M, N> & a, const matrix<T, M, N> & b) {
    a = a * b;
    return a;
}

template<typename T, int M, int N>
matrix<T, M, N> operator*(const matrix<T, M, N> & a, T b) {
    matrix<T, M, N> c;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            c[i][j] = a[i][j] * b;
    return c;
}

template<typename T, int M, int N>
matrix<T, M, N> operator*(T a, const matrix<T, M, N> & b) {
    matrix<T, M, N> c;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            c[i][j] = a * b[i][j];
    return c;
}

template<typename T, int M, int N>
matrix<T, M, N> operator*=(matrix<T, M, N> & a, T b) {
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            a[i][j] *= b;
    return a;
}

template<typename T, int M, int N>
vector<T ,M> operator*(const matrix<T, M, N> & a, const vector<T, N> & b) {
    matrix<T, 1, N> c;
    c[0] = b;
    return (c * a)[0];
}


// /

template<typename T, int M, int N>
matrix<T, M, N> operator/(const matrix<T, M, N> & a, T b) {
    matrix<T, M, N> c;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            c[i][j] = a[i][j] / b;
    return c;
}

template<typename T, int M, int N>
matrix<T, M, N> operator/(T a, const matrix<T, M, N> & b) {
    matrix<T, M, N> c;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            c[i][j] = a / b[i][j];
    return c;
}

template<typename T, int M, int N>
matrix<T, M, N> operator/=(matrix<T, M, N> & a, T b) {
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            a[i][j] /= b;
    return a;
}

template <typename T, int M, int N>
std::ostream & operator<<(std::ostream & s, const matrix<T, M, N> & a) {
    for (int i = 0; i < M; i++)
        s << a[i] << std::endl;
    return s;
}

template <typename T, int M, int N>
T determinant(const matrix<T, M, N> & a) {
    T b = 0;
    for (int i = 0; i < ((N < M) ? N : M); i++) {
        b += determinant(a.minor(i, i));
    }
    return b;
}

template <typename T>
T determinant(const matrix<T, 1, 1> & a) {
    return a[0][0];
}

template <typename T>
T determinant(const matrix<T, 2, 2> & a) {
    return a[0][0] * a[1][1] -
        a[1][0] * a[0][1];
}

template <typename T>
T determinant(const matrix<T, 3, 3> & a) {
    return a[0][0] * a[1][1] * a[2][2] +
        a[0][1] * a[1][2] * a[2][0] +
        a[0][2] * a[1][0] * a[2][1] -
        a[2][0] * a[1][1] * a[0][2] -
        a[2][1] * a[1][2] * a[0][0] -
        a[2][2] * a[1][0] * a[0][1];
}

template<typename T, int M, int N>
struct matrix {
    matrix() {
        clear();
    }

    inline vector<T, N> operator[](int i) const {
        return data[i];
    }

    inline vector<T, N> & operator[](int i) {
        return data[i];
    }

    matrix<T, N, M> transpose() const {
        matrix<T, N, M> a;
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                a[j][i] = data[i][j];
        return a;
    }

    void clear() {
        for (int i = 0; i < M; i++)
            data[i] = vector<T, N>();
    }

    void identity() {
        clear();
        for (int i = 0; i < ((N < M) ? N : M); i++)
            data[i][i] = 1;
    }

    matrix<T, M, N> inverse() const {
        return (1 / determinant()) * adjugate();
    }

    T determinant() const {
        return ::determinant(*this);
    }

    matrix<T, M - 1, N - 1> minor(int i, int j) const {
        matrix<T, M - 1, N - 1> b;
        int x2 = 0;
        for (int x1 = 0; x1 < M; x1++) {
            if (x1 == i)
                continue;
            int y2 = 0;
            for (int y1 = 0; y1 < N; y1++) {
                if (y1 == j)
                    continue;
                b[x2][y2] = data[x1][y1];
                y2++;
            }
            x2++;
        }
        return b;
    }

    matrix<T, M, N> adjugate() const {
        return cofactormatrix().transpose();
    }

    matrix<T, M, N> cofactormatrix() const {
        matrix<T, M, N> a;
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                a[i][j] = cofactor(i, j);
        return a;
    }

    T cofactor(int i, int j) const {
        if ((i + j) % 2 == 0) {
            return minor(i, j).determinant();
        }
        else {
            return -minor(i, j).determinant();
        }
    }

    vector<T, N> data[M];
};

typedef matrix<float, 2, 2> mat2;
typedef matrix<float, 3, 3> mat3;
typedef matrix<float, 4, 4> mat4;

typedef matrix<int, 2, 2> imat2;
typedef matrix<int, 3, 3> imat3;
typedef matrix<int, 4, 4> imat4;

typedef matrix<uint, 2, 2> umat2;
typedef matrix<uint, 3, 3> umat3;
typedef matrix<uint, 4, 4> umat4;

