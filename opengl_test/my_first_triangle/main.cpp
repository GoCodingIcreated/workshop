#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
GLuint VBO;

static void RenderSceneCB() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(0);
    
    glutSwapBuffers();
}

static void InitGlutCallBacks() {
    glutDisplayFunc(RenderSceneCB);
}



static void CreateVertexBuffer() {
    glm::vec3 v[3];
    v[0] = glm::vec3(-1.0f, -1.0f, 0.0f);
    v[1] = glm::vec3(1.0f, -1.0f, 0.0f);
    v[2] = glm::vec3(0.0f, 1.0f, 0.0f);
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //float data[] = {1.0, 0.0, 1.0, 0.0, 0.0, -1.0, -1.0, 0.0, 1.0};
    float data[] = {-1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f};
   // float data[] = {1000000000.0f, 0.1f, 100.0f};
    //std::cout << sizeof(data) << std::endl;
    glBufferData(GL_ARRAY_BUFFER, sizeof(data) , data, GL_STATIC_DRAW);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(768, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tutorial 03");
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
