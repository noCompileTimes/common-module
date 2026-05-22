#pragma once

namespace math
{
    [[nodiscard]] static auto matrix(const quat& quat) noexcept
    {
        mat4 matrix;

        const auto wx = quat.w * quat.x;
        const auto wy = quat.w * quat.y;
        const auto wz = quat.w * quat.z;

        const auto xx = quat.x * quat.x;
        const auto xy = quat.x * quat.y;
        const auto xz = quat.x * quat.z;

        const auto yy = quat.y * quat.y;
        const auto yz = quat.y * quat.z;

        const auto zz = quat.z * quat.z;

        matrix[0].x = 1.0f - 2.0f * (yy + zz);
        matrix[0].y =        2.0f * (xy + wz);
        matrix[0].z =        2.0f * (xz - wy);
        matrix[0].w =        0.0f;

        matrix[1].x =        2.0f * (xy - wz);
        matrix[1].y = 1.0f - 2.0f * (xx + zz);
        matrix[1].z =        2.0f * (yz + wx);
        matrix[1].w =        0.0f;

        matrix[2].x =        2.0f * (xz + wy);
        matrix[2].y =        2.0f * (yz - wx);
        matrix[2].z = 1.0f - 2.0f * (xx + yy);
        matrix[2].w =        0.0f;

        matrix[3].x =        0.0f;
        matrix[3].y =        0.0f;
        matrix[3].z =        0.0f;
        matrix[3].w =        1.0f;

        return matrix;
    }
}