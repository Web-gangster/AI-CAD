#pragma once
#include <QOpenGLWidget>
class ViewportWidget : public QOpenGLWidget , protected QOpenGLFunctions
{
    Q_OBJECT
public:
    ViewportWidget(QWidget *parent = nullptr);
    ~ViewportWidget();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
};