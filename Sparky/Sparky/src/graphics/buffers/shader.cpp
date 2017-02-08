#include "shader.h"

namespace cphong { namespace graphics {

    void checkError(GLuint shader) {
        GLint Result = GL_FALSE;
        int InfoLogLength;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &Result);
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &InfoLogLength);
        if (InfoLogLength > 0) {
            std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
            glGetShaderInfoLog(shader, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
            fprintf(stdout, "%s\n", &VertexShaderErrorMessage[0]);
        }
    }

    Shader::Shader(const char* vertexPath, const char* fragmentPath)
    {
        m_vertexId = compileShader(GL_VERTEX_SHADER, vertexPath);
        m_fragmentId = compileShader(GL_FRAGMENT_SHADER, fragmentPath);

        checkError(m_vertexId);
        checkError(m_fragmentId);

        linkProgram();
    }

    Shader::~Shader()
    {
        glDetachShader(m_programId, m_vertexId);
        glDetachShader(m_programId, m_fragmentId);
        glDeleteShader(m_vertexId);
        glDeleteShader(m_fragmentId);
        glDeleteProgram(m_programId);
    }

    void Shader::use() const
    {
        glUseProgram(m_programId);
    }

    void Shader::unuse() const
    {
        glUseProgram(0);
    }

    void Shader::passingUniform(const char* name, const maths::vec2& vector) const
    {
        GLint location = glGetUniformLocation(m_programId, name);
        glUniform2f(location, vector.x, vector.y);
    }

    void Shader::passingUniform(const char* name, const maths::vec3& vector) const
    {
        GLint location = glGetUniformLocation(m_programId, name);
        glUniform3f(location, vector.x, vector.y, vector.z);
    }

    void Shader::passingUniform(const char* name, const maths::vec4& vector) const
    {
        GLint location = glGetUniformLocation(m_programId, name);
        glUniform4f(location, vector.x, vector.y, vector.z, vector.w);
    }

    void Shader::passingUniform(const char* name, const maths::mat4& matrix) const
    {
        GLint location = glGetUniformLocation(m_programId, name);
        glUniformMatrix4fv(location, 1, GL_FALSE, matrix.elements);
    }

    GLuint Shader::compileShader(GLenum type, const char* path)
    {
        GLuint id = glCreateShader(type);
        std::string sourceString = cphong::read_file(path);
        const char* source = sourceString.c_str();
        glShaderSource(id, 1, &source, NULL);
        glCompileShader(id);
        return id;
    }

    void Shader::linkProgram()
    {
        m_programId = glCreateProgram();
        glAttachShader(m_programId, m_vertexId);
        glAttachShader(m_programId, m_fragmentId);
        glLinkProgram(m_programId);
    }

} }