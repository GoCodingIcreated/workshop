#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

GLuint VBO;

static void RenderSceneCB() {
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_POINTS, 0, 1);
    glDisableVertexAttribArray(0);
    
    glutSwapBuffers();
}

static void InitGlutCallBacks() {
    glutDisplayFunc(RenderSceneCB);
}

static void CreateVertexBuffer() {
    glm::vec3 v(0.0f);
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(v), glm::value_ptr(v), GL_STATIC_DRAW);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tutorial 02");

    InitGlutCallBacks();

    GLenum res = glewInit();
    if (res != GLEW_OK) {
        std::cerr << "ERROR:" << glewGetErrorString(res) << std::endl;
        return 1;
    }
    
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    CreateVertexBuffer();
    
    glutMainLoop();
}
