#include "dynamicdrawer.h"

namespace cphong { namespace graphics {

    DynamicDrawer::DynamicDrawer() 
        : m_indexCount(0)
    {
        init();
    }

    DynamicDrawer::~DynamicDrawer()
    {
        glDeleteBuffers(1, &m_vertexBufferId);
        glDeleteBuffers(1, &m_indexBufferId);
        glDeleteVertexArrays(1, &m_vertexArrayId);
    }

    void DynamicDrawer::begin()
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferId);
        m_data = static_cast<VertexData*>(glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY));
    }

    void DynamicDrawer::end()
    {
        glUnmapBuffer(GL_ARRAY_BUFFER);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void DynamicDrawer::addDrawable(const Drawable* drawable)
    {
        const Square* square = dynamic_cast<const Square*>(drawable);
        maths::vec2 size = square->getSize();
        maths::vec3 position = square->position();
        maths::vec4 color = square->getColor();

        m_data->vertex = position;
        m_data->color = color;
        m_data++;

        m_data->vertex = maths::vec3(position.x + size.x, position.y, position.z);
        m_data->color = color;
        m_data++;

        m_data->vertex = maths::vec3(position.x + size.x, position.y + size.y, position.z);
        m_data->color = color;
        m_data++;

        m_data->vertex = maths::vec3(position.x, position.y + size.y, position.z);
        m_data->color = color;
        m_data++;

        m_indexCount += 6;
    }

    void DynamicDrawer::enable() const
    {
        glBindVertexArray(m_vertexArrayId);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBufferId);
    }

    void DynamicDrawer::disable() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    void DynamicDrawer::draw() const
    {
        glDrawElements(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_SHORT, (void*)0);
    }

    void DynamicDrawer::init()
    {
        glGenVertexArrays(1, &m_vertexArrayId);
        glBindVertexArray(m_vertexArrayId);

        glGenBuffers(1, &m_vertexBufferId);
        glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferId);
        glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, NULL, GL_STATIC_DRAW);
        glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (void*)0);
        glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (void*)(3 * sizeof(GLfloat)));
        glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
        glEnableVertexAttribArray(SHADER_COLOR_INDEX);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        GLushort indices[RENDERER_INDICES_SIZE];
        for (int i = 0, offset = 0; i < RENDERER_INDICES_SIZE; i += 6, offset += 4)
        {
            indices[i + 0] = offset + 0;
            indices[i + 1] = offset + 1;
            indices[i + 2] = offset + 2;

            indices[i + 3] = offset + 2;
            indices[i + 4] = offset + 3;
            indices[i + 5] = offset + 0;
        }

        glGenBuffers(1, &m_indexBufferId);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBufferId);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, RENDERER_INDICES_SIZE, indices, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        glBindVertexArray(0);
    }

} }