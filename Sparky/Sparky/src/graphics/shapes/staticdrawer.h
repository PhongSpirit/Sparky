#pragma once

#include "drawer.h"

#include "../buffers/vertexarray.h"
#include "../buffers/indexbuffer.h"
#include "../buffers/vertexbuffer.h"
#include "../buffers/shader.h"

namespace cphong { namespace graphics {

    class StaticDrawer : public Drawer
    { 
    private:
        const Drawable* m_drawable;

        VertexArray* m_vertexArray;
        VertexBuffer* m_vertexBuffer;
        IndexBuffer* m_indexBuffer;
        Shader* m_shader;
    public:
        explicit StaticDrawer(const Drawable* drawable);
        ~StaticDrawer() override;

        const Shader* getShader() const;

        void enable() const override;
        void disable() const override;
        void draw() const override;
    private:
        inline void initBuffers();
        inline void initShader();
        inline void init();
    };

} }