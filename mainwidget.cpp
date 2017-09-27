#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent)
{
    initializeUI();
}

MainWidget::~MainWidget()
{
}

void MainWidget::initializeUI()
{
    m_mainMenu = new QGroupBox("Menu");
    m_vBoxLayout = new QVBoxLayout;
    m_hBoxLayout = new QHBoxLayout;

    QVBoxLayout *vBoxLayout = new QVBoxLayout;

    m_mainOpenGLWidget = new MainOpenGLWidget(this);

    /// choose test group
    {
        /// tests combo box
        {
            m_testsComboBox = new QComboBox();
            for (int i = 0 ; i < m_mainOpenGLWidget->g_testEntries.count(); i++) {
                m_testsComboBox->addItem(m_mainOpenGLWidget->g_testEntries[i].name);
            }
            m_testsComboBox->setCurrentIndex(m_mainOpenGLWidget->testIndex);
            connect(m_testsComboBox, SIGNAL(currentIndexChanged(int)), SLOT(changeTestIndex(int)));
            vBoxLayout->addWidget(m_testsComboBox, 1);
        }

        m_chooseTestGroup = new QGroupBox("Test");
        m_chooseTestGroup->setLayout(vBoxLayout);
        m_vBoxLayout->addWidget(m_chooseTestGroup);
    }

    /// global settings group
    {
        vBoxLayout = new QVBoxLayout;

        /// velocity iterations slider
        {
            vBoxLayout->addWidget(new QLabel("Vel Iters"));
            m_velocityIterationsSlider = new QSlider(Qt::Horizontal);
            m_velocityIterationsSlider->setMinimum(0);
            m_velocityIterationsSlider->setMaximum(50);
            m_velocityIterationsSlider->setTickPosition(QSlider::TicksLeft);
            m_velocityIterationsSlider->setValue(m_mainOpenGLWidget->settings.velocityIterations);
            connect(m_velocityIterationsSlider, &QSlider::valueChanged, [ = ](const int newValue) {
                m_mainOpenGLWidget->settings.velocityIterations = newValue;
            });
            vBoxLayout->addWidget(m_velocityIterationsSlider);
        }

        /// position iterations slider
        {
            vBoxLayout->addWidget(new QLabel("Pos Iters"));
            m_positionIterationsSlider = new QSlider(Qt::Horizontal);
            m_positionIterationsSlider->setMinimum(0);
            m_positionIterationsSlider->setMaximum(50);
            m_positionIterationsSlider->setTickPosition(QSlider::TicksLeft);
            m_positionIterationsSlider->setValue(m_mainOpenGLWidget->settings.positionIterations);
            connect(m_positionIterationsSlider, &QSlider::valueChanged, [ = ](const int newValue) {
                m_mainOpenGLWidget->settings.positionIterations = newValue;
            });
            vBoxLayout->addWidget(m_positionIterationsSlider);
        }

        /// hz slider
        {
            vBoxLayout->addWidget(new QLabel("Hertz"));
            m_hzSlider = new QSlider(Qt::Horizontal);
            m_hzSlider->setMinimum(5);
            m_hzSlider->setMaximum(120);
            m_hzSlider->setTickPosition(QSlider::TicksLeft);
            m_hzSlider->setValue(m_mainOpenGLWidget->settings.hz);
            connect(m_hzSlider, &QSlider::valueChanged, [ = ](const int newValue) {
                m_mainOpenGLWidget->settings.hz = newValue;
            });
            vBoxLayout->addWidget(m_hzSlider);
        }

        /// enable sleep check box
        {
            m_enableSleepCheckBox = new QCheckBox("Sleep");
            m_enableSleepCheckBox->setChecked(m_mainOpenGLWidget->settings.enableSleep);
            connect(m_enableSleepCheckBox, &QCheckBox::stateChanged, [ = ](const int checkState) {
                m_mainOpenGLWidget->settings.enableSleep = checkState;
            });
            vBoxLayout->addWidget(m_enableSleepCheckBox);
        }

        /// enable warm starting check box
        {
            m_enableWarmStartingCheckBox = new QCheckBox("Warm Starting");
            m_enableWarmStartingCheckBox->setChecked(m_mainOpenGLWidget->settings.enableWarmStarting);
            connect(m_enableWarmStartingCheckBox, &QCheckBox::stateChanged, [ = ](const int checkState) {
                m_mainOpenGLWidget->settings.enableWarmStarting = checkState;
            });
            vBoxLayout->addWidget(m_enableWarmStartingCheckBox);
        }

        /// enable continuous check box
        {
            m_enableContinuousCheckBox = new QCheckBox("Time of Impact");
            m_enableContinuousCheckBox->setChecked(m_mainOpenGLWidget->settings.enableContinuous);
            connect(m_enableContinuousCheckBox, &QCheckBox::stateChanged, [ = ](const int checkState) {
                m_mainOpenGLWidget->settings.enableContinuous = checkState;
            });
            vBoxLayout->addWidget(m_enableContinuousCheckBox);
        }

        /// enable sub stepping check box
        {
            m_enableSubSteppingCheckBox = new QCheckBox("Sub-Stepping");
            m_enableSubSteppingCheckBox->setChecked(m_mainOpenGLWidget->settings.enableSubStepping);
            connect(m_enableSubSteppingCheckBox, &QCheckBox::stateChanged, [ = ](const int checkState) {
                m_mainOpenGLWidget->settings.enableSubStepping = checkState;
            });
            vBoxLayout->addWidget(m_enableSubSteppingCheckBox);
        }

        m_settingsGroup = new QGroupBox("Settings");
        m_settingsGroup->setLayout(vBoxLayout);
        m_vBoxLayout->addWidget(m_settingsGroup);
    }

    /// draw settings group
    {
        vBoxLayout = new QVBoxLayout;

        /// draw shapes check box
        {
            m_drawShapesCheckBox = new QCheckBox("Shapes");
            m_drawShapesCheckBox->setChecked(m_mainOpenGLWidget->settings.drawShapes);
            connect(m_drawShapesCheckBox, &QCheckBox::stateChanged, [ = ](const int checkState) {
                m_mainOpenGLWidget->settings.drawShapes = checkState;
            });
            vBoxLayout->addWidget(m_drawShapesCheckBox);
        }

        /// draw joints check box
        {
            m_drawJointsCheckBox = new QCheckBox("Joints");
            m_drawJointsCheckBox->setChecked(m_mainOpenGLWidget->settings.drawJoints);
            connect(m_drawJointsCheckBox, &QCheckBox::stateChanged, [ = ](const int checkState) {
                m_mainOpenGLWidget->settings.drawJoints = checkState;
            });
            vBoxLayout->addWidget(m_drawJointsCheckBox);
        }

        /// draw AABBs check box
        {
            m_drawAABBsCheckBox = new QCheckBox("AABBs");
            m_drawAABBsCheckBox->setChecked(m_mainOpenGLWidget->settings.drawAABBs);
            connect(m_drawAABBsCheckBox, &QCheckBox::stateChanged, [ = ](const int checkState) {
                m_mainOpenGLWidget->settings.drawAABBs = checkState;
            });
            vBoxLayout->addWidget(m_drawAABBsCheckBox);
        }

        /// draw contact points check box
        {
            m_drawContactPointsCheckBox = new QCheckBox("Contact Points");
            m_drawContactPointsCheckBox->setChecked(m_mainOpenGLWidget->settings.drawContactPoints);
            connect(m_drawContactPointsCheckBox, &QCheckBox::stateChanged, [ = ](const int checkState) {
                m_mainOpenGLWidget->settings.drawContactPoints = checkState;
            });
            vBoxLayout->addWidget(m_drawContactPointsCheckBox);
        }

        /// draw contact normals check box
        {
            m_drawContactNormalsCheckBox = new QCheckBox("Contact Normals");
            m_drawContactNormalsCheckBox->setChecked(m_mainOpenGLWidget->settings.drawContactNormals);
            connect(m_drawContactNormalsCheckBox, &QCheckBox::stateChanged, [ = ](const int checkState) {
                m_mainOpenGLWidget->settings.drawContactNormals = checkState;
            });
            vBoxLayout->addWidget(m_drawContactNormalsCheckBox);
        }

        /// draw contact impulse check box
        {
            m_drawContactImpulseCheckBox = new QCheckBox("Contact Impulses");
            m_drawContactImpulseCheckBox->setChecked(m_mainOpenGLWidget->settings.drawContactImpulse);
            connect(m_drawContactImpulseCheckBox, &QCheckBox::stateChanged, [ = ](const int checkState) {
                m_mainOpenGLWidget->settings.drawContactImpulse = checkState;
            });
            vBoxLayout->addWidget(m_drawContactImpulseCheckBox);
        }

        /// draw friction impulse check box
        {
            m_drawFrictionImpulseCheckBox = new QCheckBox("Friction Impulses");
            m_drawFrictionImpulseCheckBox->setChecked(m_mainOpenGLWidget->settings.drawFrictionImpulse);
            connect(m_drawFrictionImpulseCheckBox, &QCheckBox::stateChanged, [ = ](const int checkState) {
                m_mainOpenGLWidget->settings.drawFrictionImpulse = checkState;
            });
            vBoxLayout->addWidget(m_drawFrictionImpulseCheckBox);
        }

        /// draw COMs check box
        {
            m_drawCOMsCheckBox = new QCheckBox("Center of Masses");
            m_drawCOMsCheckBox->setChecked(m_mainOpenGLWidget->settings.drawCOMs);
            connect(m_drawCOMsCheckBox, &QCheckBox::stateChanged, [ = ](const int checkState) {
                m_mainOpenGLWidget->settings.drawCOMs = checkState;
            });
            vBoxLayout->addWidget(m_drawCOMsCheckBox);
        }

        /// draw stats check box
        {
            m_drawStatsCheckBox = new QCheckBox("Statistics");
            m_drawStatsCheckBox->setChecked(m_mainOpenGLWidget->settings.drawStats);
            connect(m_drawStatsCheckBox, &QCheckBox::stateChanged, [ = ](const int checkState) {
                m_mainOpenGLWidget->settings.drawStats = checkState;
            });
            vBoxLayout->addWidget(m_drawStatsCheckBox);
        }

        /// draw profile check box
        {
            m_drawProfileCheckBox = new QCheckBox("Profile");
            m_drawProfileCheckBox->setChecked(m_mainOpenGLWidget->settings.drawProfile);
            connect(m_drawProfileCheckBox, &QCheckBox::stateChanged, [ = ](const int checkState) {
                m_mainOpenGLWidget->settings.drawProfile = checkState;
            });
            vBoxLayout->addWidget(m_drawProfileCheckBox);
        }

        m_drawSettingsGroup = new QGroupBox("Draw settings");
        m_drawSettingsGroup->setLayout(vBoxLayout);
        m_vBoxLayout->addWidget(m_drawSettingsGroup);
    }

    /// options group
    {
        vBoxLayout = new QVBoxLayout;
        m_pauseButton = new QPushButton("Pause");
        connect(m_pauseButton, &QPushButton::clicked, [ = ]() {
            m_mainOpenGLWidget->settings.pause = !m_mainOpenGLWidget->settings.pause;
        });
        vBoxLayout->addWidget(m_pauseButton);

        m_singleStepButton = new QPushButton("Single Step");
        connect(m_singleStepButton, &QPushButton::clicked, [ = ]() {
            m_mainOpenGLWidget->settings.singleStep = !m_mainOpenGLWidget->settings.singleStep;
        });
        vBoxLayout->addWidget(m_singleStepButton);

        m_restartButton = new QPushButton("Restart");
        connect(m_restartButton, &QPushButton::clicked, [ = ]() {
            changeTestIndex(m_mainOpenGLWidget->testIndex);
        });
        vBoxLayout->addWidget(m_restartButton);

        m_quitButton = new QPushButton("Quit");
        connect(m_quitButton, &QPushButton::clicked, [ = ]() {
            this->close();
        });
        vBoxLayout->addWidget(m_quitButton);

        m_buttonsGroup = new QGroupBox("Options");
        m_buttonsGroup->setLayout(vBoxLayout);
        m_vBoxLayout->addWidget(m_buttonsGroup);
    }

    m_mainMenu->setLayout(m_vBoxLayout);

    m_hBoxLayout->addWidget(m_mainOpenGLWidget, 4);
    m_hBoxLayout->addWidget(m_mainMenu, 1);

    setLayout(m_hBoxLayout);

    m_mainOpenGLWidget->setFocus();
}

void MainWidget::changeTestIndex(int newIndex)
{
    m_mainOpenGLWidget->startTest(newIndex);
}
