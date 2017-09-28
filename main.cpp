#include <QApplication>
#include <QLabel>
#include <QSurfaceFormat>

#include "mainwidget.h"
#include "mainopenglwidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QSurfaceFormat format;
    QSurfaceFormat::setDefaultFormat(format);

    app.setApplicationName("b2GLES");
    app.setApplicationVersion("0.0.1");

    MainWidget widget;
    widget.setFocusPolicy(Qt::ClickFocus);
    widget.resize(800, 600);
    widget.showMaximized();


    return app.exec();
}
