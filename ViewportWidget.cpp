#include "ViewportWidget.h"
#include <QOpenGLFunctions>

static const char* vertSrc = R"(
    #version 330 core
    layout(location = 0) in vec3 aPos;
    uniform mat4 model;
    uniform mat4 view;
    uniform mat4 projection;
    void main() {
        gl_Position = projection * view * model * vec4(aPos, 1.0);
    }
)";
static const char* fragSrc = R"(
    #version 330 core
    out vec4 FragColor;
    void main() {
        FragColor = vec4(0.2, 0.7, 1.0, 1.0);
    }
)";

ViewportWidget::ViewportWidget(QWidget *parent)
    : QOpenGLWidget(parent)
    , vbo(QOpenGLBuffer::VertexBuffer)
{

}
ViewportWidget::~ViewportWidget()
{
}
void ViewportWidget::initializeGL(){
    initializeOpenGLFunctions();
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    shaderProgram.addShaderFromSourceCode(QOpenGLShader::Vertex, vertSrc);
    shaderProgram.addShaderFromSourceCode(QOpenGLShader::Fragment, fragSrc);
    shaderProgram.link();
    float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f,
    };
    vao.create();
    vao.bind();
    vbo.create();
    vbo.bind();
    vbo.allocate(vertices, sizeof(vertices));
    shaderProgram.enableAttributeArray(0);
    shaderProgram.setAttributeArray(0, GL_FLOAT, 0, 3, 0);
    vbo.release();
    vao.release();
    m_model.setToIdentity();
    m_view.setToIdentity();
    m_view.translate(0.0f, 0.0f, -3.0f);
    m_projection.setToIdentity();
    m_projection.perspective(45.0f, float(width())/float(height()), 1.0f, 100.0f);
}
void ViewportWidget::resizeGL(int w, int h){
    glViewport(0,0,w,h);
}
void ViewportWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    shaderProgram.bind();
    shaderProgram.setUniformValue("model", m_model);
    shaderProgram.setUniformValue("projection", m_projection);
    shaderProgram.setUniformValue("view", m_view);
    vao.bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);
    vao.release();
    shaderProgram.release();
    
}