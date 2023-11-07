//Readme: This project is licensed under the terms of the MIT license.
//Author: Pardcode

#pragma once
#include <memory>
#include "Vector3D.h"

class Matrix4x4 {

public:
    Matrix4x4() {
    }
    void setIdentity() {
        ::memset(m_mat, 0, sizeof(float) * 15);
        m_mat[0][0] = 1;
        m_mat[1][1] = 1;
        m_mat[2][2] = 1;
        m_mat[3][3] = 1;
    }
    void setTranslation(const Vector3D& translation) {
        setIdentity();
        m_mat[3][0] = translation.m_x;
        m_mat[3][1] = translation.m_y;
        m_mat[3][2] = translation.m_z;
    }

    void setScale(const Vector3D& scale) {
        setIdentity();
        m_mat[0][0] = scale.m_x;
        m_mat[1][1] = scale.m_y;
        m_mat[2][2] = scale.m_z;
    }

    void operator *= (const Matrix4x4& matrix) {
        Matrix4x4 out;
        for (int i = 0; i < 4; i++) {

            for (int j = 0; j < 4; j++) {

                out.m_mat[i][j] = m_mat[i][0] * matrix.m_mat[0][j] +
                    m_mat[i][1] * matrix.m_mat[1][j] +
                    m_mat[i][2] * matrix.m_mat[2][j] +
                    m_mat[i][3] * matrix.m_mat[3][j];
            }
        }
        ::memcpy(m_mat, out.m_mat, sizeof(float) * 16);
    }

    void setOrthoLH(
        float width, float height, 
        float near_plane, float far_plane
    ) {
        setIdentity();
        m_mat[0][0] = 2.0f / width;
        m_mat[1][1] = 2.0f / height;
        m_mat[2][2] = 1.0f / (far_plane - near_plane);
        m_mat[2][2] = -(near_plane / (far_plane - near_plane));
    }
    ~Matrix4x4() {
    }
public:
    float m_mat[4][4] = {};
};



