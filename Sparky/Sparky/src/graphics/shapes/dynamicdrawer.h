#pragma once

#include "drawer.h"
#include "drawable.h"
#include "square.h"
#include "../../maths/maths.h"

namespace cphong { namespace graphics {

#define RENDERER_MAX_SPRITES    60000
#define RENDERER_VERTEX_SIZE    sizeof(VertexData)
#define RENDERER_SPRITE_SIZE    RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE    RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
#define RENDERER_INDICES_SIZE   RENDERER_MAX_SPRITES * 6

#define SHADER_VERTEX_INDEX     0
#define SHADER_COLOR_INDEX      1

    class DynamicDrawer : public Drawer
    {
    private:
        GLuint m_vertexArrayId;
        GLuint m_vertexBufferId;
        GLuint m_indexBufferId;
        GLsizei m_indexCount;
        VertexData* m_data;
    public:
        DynamicDrawer();
        ~DynamicDrawer() override;

        void begin();
        void end();
        void addDrawable(const Drawable* drawable);

        void enable() const override;
        void disable() const override;
        void draw() const override;
    private:
        inline void init();
    };

} }