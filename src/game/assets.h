#pragma once
#include "engine/renderer/RenderTypes.h"

namespace Assets {
    namespace Shaders {
        constexpr ShaderID DEFAULT = 0;
    };

    namespace Textures {
        constexpr TextureID GAME_ATLAS = 0;
    }

    static constexpr const char* CHUNK_VERT_PATH = "assets/shaders/Vertex.vert";
    static constexpr const char* CHUNK_FRAG_PATH = "assets/shaders/Fragment.frag";
    static constexpr const char* GAME_ATLAS_PATH = "/../External/ResourceFiles/Texture/game_atlas.png";
};