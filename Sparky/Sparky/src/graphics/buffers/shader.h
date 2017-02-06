#pragma once

#include <GL/glew.h>

#include "../../utils/file.h"
#include "../../maths/maths.h"

namespace cphong { namespace graphics {

    class Shader
    {
    private:
        GLuint m_programId;
        GLuint m_vertexId;
        GLuint m_fragmentId;
    public:
        Shader(const char* vertexPath, const char* fragmentPath);
        ~Shader();

        void use() const;
        void unuse() const;

        void passingUniform(const char* name, const maths::vec2& vector) const;
        void passingUniform(const char* name, const maths::vec3& vector) const;
        void passingUniform(const char* name, const maths::vec4& vector) const;
        void passingUniform(const char* name, const maths::mat4& matrix) const;
    private:
        inline GLuint compileShader(GLenum type, const char* path);
        inline void linkProgram();
    };

} }