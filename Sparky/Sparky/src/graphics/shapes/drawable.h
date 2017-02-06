#pragma once

#include "../buffers/vertexarray.h"
#include "../buffers/indexbuffer.h"
#include "../buffers/vertexbuffer.h"
#include "../buffers/shader.h"

namespace cphong { namespace shapes {

    class Drawable
    {
    protected:
        graphics::VertexArray* m_vertexArray;
        graphics::VertexBuffer* m_vertexBuffer;
        graphics::IndexBuffer* m_indexBuffer;
        graphics::Shader* m_shader;
    public:
        Drawable() = default;
        virtual ~Drawable();

        const graphics::Shader* getShader() const;

        virtual void enable() const;
        virtual void disable() const;
        virtual void draw() const;
    private:
        virtual void prepare() = 0;
    };

} }