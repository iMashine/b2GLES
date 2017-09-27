#include "mainopenglwidget.h"

MainOpenGLWidget::MainOpenGLWidget(QWidget *parent) : QOpenGLWidget(parent)
{
    g_testEntries = {
        {"Character Collision", CharacterCollision::Create},
        {"Tiles", Tiles::Create},
        {"Heavy on Light", HeavyOnLight::Create},
        {"Heavy on Light Two", HeavyOnLightTwo::Create},
        {"Vertical Stack", VerticalStack::Create},
        {"Basic Slider Crank", BasicSliderCrank::Create},
        {"Slider Crank", SliderCrank::Create},
        {"Sphere Stack", SphereStack::Create},
        {"Convex Hull", ConvexHull::Create},
        {"Tumbler", Tumbler::Create},
        {"Ray-Cast", RayCast::Create},
        {"Dump Shell", DumpShell::Create},
        {"Apply Force", ApplyForce::Create},
        {"Continuous Test", ContinuousTest::Create},
        {"Time of Impact", TimeOfImpact::Create},
        {"Motor Joint", MotorJoint::Create},
        {"One-Sided Platform", OneSidedPlatform::Create},
        {"Mobile", Mobile::Create},
        {"MobileBalanced", MobileBalanced::Create},
        {"Conveyor Belt", ConveyorBelt::Create},
        {"Gears", Gears::Create},
        {"Varying Restitution", VaryingRestitution::Create},
        {"Cantilever", Cantilever::Create},
        {"Edge Test", EdgeTest::Create},
        {"Body Types", BodyTypes::Create},
        {"Shape Editing", ShapeEditing::Create},
        {"Car", Car::Create},
        {"Prismatic", Prismatic::Create},
        {"Revolute", Revolute::Create},
        {"Pulleys", Pulleys::Create},
        {"Polygon Shapes", PolyShapes::Create},
        {"Web", Web::Create},
        {"RopeJoint", RopeJoint::Create},
        {"Pinball", Pinball::Create},
        {"Bullet Test", BulletTest::Create},
        {"Confined", Confined::Create},
        {"Pyramid", Pyramid::Create},
        {"Theo Jansen's Walker", TheoJansen::Create},
        {"Edge Shapes", EdgeShapes::Create},
        {"PolyCollision", PolyCollision::Create},
        {"Bridge", Bridge::Create},
        {"Breakable", Breakable::Create},
        {"Chain", Chain::Create},
        {"Collision Filtering", CollisionFiltering::Create},
        {"Collision Processing", CollisionProcessing::Create},
        {"Compound Shapes", CompoundShapes::Create},
        {"Distance Test", DistanceTest::Create},
        {"Dominos", Dominos::Create},
        {"Dynamic Tree", DynamicTreeTest::Create},
        {"Sensor Test", SensorTest::Create},
        {"Varying Friction", VaryingFriction::Create},
        {"Add Pair Stress Test", AddPair::Create}
    };
}

MainOpenGLWidget::~MainOpenGLWidget()
{
    g_debugDraw.Destroy();

    if (test) {
        delete test;
        test = NULL;
    }
}

void MainOpenGLWidget::startTest(int newIndex)
{
    delete test;
    testSelection = newIndex;
    test = g_testEntries[testIndex].createFcn();
    test->g_debugDraw = g_debugDraw;
    test->m_painter = m_painter;
    setFocus();
}

void MainOpenGLWidget::initializeGL()
{
    makeCurrent();
    m_functions.initializeOpenGLFunctions();
    m_functions.glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    g_debugDraw.Create(&g_camera, &m_functions);

    testIndex = b2Clamp(testIndex, 0, g_testEntries.count() - 1);
    testSelection = testIndex;

    test = g_testEntries[testIndex].createFcn();
    test->g_debugDraw = g_debugDraw;

    timer.start(16, this);
}

void MainOpenGLWidget::resizeGL(int w, int h)
{
    qreal aspect = qreal(w) / qreal(h ? h : 1);
    const qreal zNear = 3.0, zFar = 7.0, fov = 45.0;
    m_projection.setToIdentity();
    m_projection.perspective(fov, aspect, zNear, zFar);
}

void MainOpenGLWidget::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e)
    update();
}

void MainOpenGLWidget::mousePressEvent(QMouseEvent *e)
{

}

void MainOpenGLWidget::mouseReleaseEvent(QMouseEvent *e)
{

}

void MainOpenGLWidget::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_Escape:
        this->close();
        break;

    case Qt::Key_Left: {
        g_camera.m_center.x -= 0.5f;
        break;
    }

    case Qt::Key_Right: {
        g_camera.m_center.x += 0.5f;
        break;
    }

    case Qt::Key_Down: {
        g_camera.m_center.y -= 0.5f;
        break;
    }

    case Qt::Key_Up: {
        g_camera.m_center.y += 0.5f;
        break;
    }

    case Qt::Key_Home: {
        g_camera.m_zoom = 1.0f;
        g_camera.m_center.Set(0.0f, 20.0f);
        break;
    }

    case Qt::Key_Z:
        // Zoom out
        g_camera.m_zoom = b2Min(1.1f * g_camera.m_zoom, 20.0f);
        break;

    case Qt::Key_X:
        // Zoom in
        g_camera.m_zoom = b2Max(0.9f * g_camera.m_zoom, 0.02f);
        break;

    case Qt::Key_R:
        // Reset test
        delete test;
        test = entry->createFcn();
        break;

    case Qt::Key_Space:
        // Launch a bomb.
        if (test) {
            test->LaunchBomb();
        }
        break;

    case Qt::Key_O:
        settings.singleStep = true;
        break;

    case Qt::Key_P:
        settings.pause = !settings.pause;
        break;

    case Qt::Key_BracketLeft:
        // Switch to previous test
        --testSelection;
        if (testSelection < 0) {
            testSelection = g_testEntries.count() - 1;
        }
        break;

    case Qt::Key_BracketRight:
        // Switch to next test
        ++testSelection;
        if (testSelection == g_testEntries.count()) {
            testSelection = 0;
        }
        break;

    default:
        if (test) {
            test->Keyboard(e->key());
        }
    }
}

void MainOpenGLWidget::keyReleaseEvent(QKeyEvent *e)
{
    test->KeyboardUp(e->key());
}

void MainOpenGLWidget::paintGL()
{
    makeCurrent();
    m_functions.glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
    m_functions.glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (!m_painter || m_painter->window().width() != width() ||
            m_painter->window().height() != height()) {
        delete m_painter;
        delete m_mainGLPaintDevice;
        m_mainGLPaintDevice = new QOpenGLPaintDevice(width(), height());
        m_painter = new QPainter(m_mainGLPaintDevice);
        test->m_painter = m_painter;
    }

    m_painter->save();
    m_painter->setBrush(QBrush(Qt::green));
    m_painter->setPen(QColor(199, 217, 80, 100));

    for (int i = 0; i < 5; i++) {
        m_painter->drawLine(QPointF(rand() % this->width(), rand() % this->height()), QPointF(rand() % this->width(), rand() % this->height()));
    }
    m_painter->restore();

    m_painter->beginNativePainting();

    test->Step(&settings);
    test->DrawTitle(g_testEntries[testIndex].name);

    if (testSelection != testIndex) {
        testIndex = testSelection;
        delete test;

        test = g_testEntries[testIndex].createFcn();
        test->g_debugDraw = g_debugDraw;
        test->m_painter = m_painter;
    }

    m_painter->endNativePainting();
}
