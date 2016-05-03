#include <cstdlib>
#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>


static int make_resources() {
    return 1;
}

static void update_fade_factor()  {
}

static void render() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(400, 300);
    glutCreateWindow("Hello world");
    glutDisplayFunc(&render);
    glutIdleFunc(&update_fade_factor);
    glewInit();
    if (!GLEW_VERSION_2_0) {
        std::cerr << "OpenGL v.2.0 is not available" << std::endl;
        return 1;
    }
    if (!make_resources()) {
        std::cerr << "Failed to load resources" << std::endl;
        return 1;
    }
    glutMainLoop();
    return 0;
}
