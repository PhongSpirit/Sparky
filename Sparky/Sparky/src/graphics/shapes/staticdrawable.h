#pragma once

#include "drawable.h"

#include "../buffers/vertexarray.h"
#include "../buffers/indexbuffer.h"
#include "../buffers/vertexbuffer.h"
#include "../buffers/shader.h"

namespace cphong { namespace shapes {

    class StaticDrawable : public Drawable
    {
    protected:
        graphics::VertexArray* m_vertexArray;
        graphics::VertexBuffer* m_vertexBuffer;
        graphics::IndexBuffer* m_indexBuffer;
        graphics::Shader* m_shader;
    public:
        virtual ~StaticDrawable();

        const graphics::Shader* getShader() const;

        virtual void enable() const override;
        virtual void disable() const override;
        virtual void draw() const override;
    };

} }