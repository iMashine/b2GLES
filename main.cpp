#include <QApplication>
#include <QLabel>
#include <QSurfaceFormat>

#include "mainwidget.h"
#include "mainopenglwidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QSurfaceFormat format;
//    format.setDepthBufferSize(24);
//    format.setSamples(4);
//    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);

    app.setApplicationName("b2GLES");
    app.setApplicationVersion("0.0.1");

    MainWidget widget;
    widget.setFocusPolicy(Qt::ClickFocus);
//    MainOpenGLWidget widget;
    widget.resize(800, 600);
    widget.showMaximized();


    return app.exec();
}
