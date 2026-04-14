#include "ViewportWidget.h"
#include <QOpenGLFunctions>
ViewportWidget::ViewportWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{

}
ViewportWidget::~ViewportWidget()
{
}
void ViewportWidget::initializeGL(){
    initializeOpenGLFunctions();
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
}
void ViewportWidget::resizeGL(int w, int h){
    glViewport(0,0,w,h);
}
void ViewportWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}