#include <vld.h>
#include <time.h>
#include <vector>

#include "maths/maths.h"
#include "graphics/window.h"
#include "graphics/renderer2d.h"
#include "graphics/shapes/square.h"
#include "graphics/shapes/staticdrawer.h"
#include "graphics/shapes/dynamicdrawer.h"

int main()
{
    using namespace cphong::graphics;
    using namespace cphong::maths;

    Window* window = new Window(640, 480, "[C]Phong");

    mat4 model = mat4::identity();
    mat4 view = mat4::identity();
    mat4 projection = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 10.0f);

    Shader* shader = new Shader("resource/shaders/square.vert", "resource/shaders/square.frag");
    shader->use();
    shader->passingUniform("model", model);
    shader->passingUniform("view", view);
    shader->passingUniform("projection", projection);
    
    srand((unsigned int)time(NULL));

    std::vector<Drawable*> squares;
    for (float x = 0.0f; x < 16.0f; x += 0.1f)
    {
        for (float y = 0.0f; y < 9.0f; y += 0.1f)
        {
            squares.push_back(new Square(0.08f, 0.08f, x, y, vec4(rand() % 1000 / 1000.0f, 0.0f, 0.4f, 1.0f)));
        }
    }

    DynamicDrawer* drawer = new DynamicDrawer();
    drawer->begin();
    for (Drawable* i : squares)
    {
        drawer->addDrawable(i);
    }
    drawer->end();

    Renderer2D* renderer2d = new Renderer2D();

    while (!window->close())
    {
        window->clear();

        double x, y;
        window->getCursorPos(&x, &y);
        x = x * 16.0f / 640.0f;
        y = 9.0f - y * 9.0f / 480.0f;
        shader->passingUniform("lightPos", vec2((float)x, (float)y));
        /*static_cast<StaticDrawer*>(drawer)->getShader()->use();
        static_cast<StaticDrawer*>(drawer)->getShader()->passingUniform("lightPos", vec2((float)x, (float)y));
        static_cast<StaticDrawer*>(drawer)->getShader()->unuse();*/
        
        renderer2d->submit(drawer);
        renderer2d->flush();

        window->update();
    }

    for (size_t i = 0; i < squares.size(); i++)
    {
        delete squares[i];
    }
    squares.clear();

    shader->unuse();
    delete shader;

    delete renderer2d;
    delete drawer;
    delete window;

    return 0;
}