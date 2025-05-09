#pragma once

#include "imgui_utils.h"
#include "macro.h"
#include "mathf.h"

#include <CDT.h>

namespace Utils {
    template<typename T>
    std::vector<CDT::V2d<T>> ImVec22V2f(std::vector<ImVec2> im_vec2s) {
        std::vector<CDT::V2d<T>> pointsV2d(im_vec2s.size());
        std::transform(
            all(im_vec2s),
            pointsV2d.begin(),
            [](const ImVec2 &p) {
                return CDT::V2d<T>{p.x, p.y};
            });
        return pointsV2d;
    }

    template<typename T>
    ImVec2 V2d2ImVec2(CDT::V2d<T> v2d) {
        return ImVec2(v2d.x, v2d.y);
    }
}