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

/*
class operator TMatrix.Multiply(A, B: TMatrix): TMatrix;
var
  I, J, K: Integer;
begin
  if A.Cols = B.Rows then
  begin
    Result.SetSize(B.Cols, A.Rows);
    for I := 0 to Result.Rows - 1 do
      for J := 0 to Result.Cols - 1 do
        for K := 0 to A.Cols - 1 do
          Result[J, I] := Result[J, I] + A[K, I] * B[J, K];
  end
  else
    raise EMatrixMultiply.Create(A.Cols, B.Rows);
end;     
*/

/*template<typename T>
matrix<T, 4, 4> operator*(const matrix<T, 4, 4> & a, const matrix<T, 4, 4> & b) {

}*/

template<typename T, int M, int N>
matrix<T, M, N> operator*=(matrix<T, M, N> & a, const matrix<T, M, N> & b) {
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            a[i][j] *= b[i][j];
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
        for (int i = 0; i < min(N, M); i++)
            data[i][i] = 1;
    }

    vector<T, N> data[M];
};

typedef matrix<float, 4, 4> mat4;