#ifndef MAINOPENGLWIDGET_H
#define MAINOPENGLWIDGET_H

#include <stdio.h>
#include <test.h>
#include "tests.h"

#include <QOpenGLWidget>
#include <QMatrix4x4>
#include <QVector2D>
#include <QBasicTimer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QDebug>
#include <QTime>

#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QPainter>
#include <QOpenGLPaintDevice>
#include <QKeyEvent>

class MainOpenGLWidget : public QOpenGLWidget, public QOpenGLFunctions
{
    Q_OBJECT

public:
    explicit MainOpenGLWidget(QWidget *parent = 0);
    ~MainOpenGLWidget();

    void startTest(int newIndex);

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    void timerEvent(QTimerEvent *e) override;

    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
    void keyPressEvent(QKeyEvent *e) override;
    void keyReleaseEvent(QKeyEvent *e) override;

private:
    QBasicTimer timer;
    QMatrix4x4 m_projection;
    QMatrix4x4 m_modelView;
    QOpenGLShaderProgram m_program;
    QOpenGLPaintDevice *m_mainGLPaintDevice = nullptr;
    QPainter *m_painter = nullptr;
    QOpenGLFunctions m_functions;

protected:
    DebugDraw g_debugDraw;
    Camera g_camera;

public:
    int32 testIndex = 0;
    int32 testSelection = 0;

    TestEntry *entry;
    Test *test;
    Settings settings;
    bool rightMouseDown;
    b2Vec2 lastp;

    QList<TestEntry> g_testEntries;
};

#endif // MAINOPENGLWIDGET_H
