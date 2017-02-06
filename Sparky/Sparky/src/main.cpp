#include <vld.h>

#include "graphics/window.h"
#include "graphics/shapes/square.h"
#include "graphics/shapes/drawable.h"
#include "graphics/shapes/light.h"
#include "graphics/renderer2d.h"

#include "maths/maths.h"

int main()
{
    using namespace cphong::graphics;
    using namespace cphong::shapes;
    using namespace cphong::maths;

    Window* window = new Window(640, 480, "[C]Phong");

    Drawable* square = new Square(vec2(6.0f, 4.0f), vec3(5.0f, 2.0f, 0.0f), vec4(0.7f, 0.0f, 0.3f, 1.0f));
    Drawable* square1 = new Square(vec2(5.0f, 2.0f), vec3(0.0f, 0.0f, 0.0f), vec4(0.2f, 0.7f, 0.3f, 1.0f));

    Renderer2D* renderer2d = new Renderer2D();;

    Light* light = new Light();
    light->push(square);
    light->push(square1);

    while (!window->close())
    {
        window->clear();

        double x, y;
        window->getCursorPos(&x, &y);
        x = x * 16.0f / 640.0f;
        y = 9.0f - y * 9.0f / 480.0f;
        light->setLightPos(x, y);
        light->light();

        renderer2d->submit(square);
        renderer2d->submit(square1);
        renderer2d->flush();

        window->update();
    }

    delete light;
    delete renderer2d;
    delete square;
    delete square1;
    delete window;

    return 0;
}