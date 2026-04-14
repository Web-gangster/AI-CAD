#include <QApplication>
#include "MainWindow.h"
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow window;
    window.setWindowTitle("Qt Mini Blender");
    window.showMaximized();
    return app.exec();
}