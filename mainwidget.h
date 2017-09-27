#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "mainopenglwidget.h"

#include <QGroupBox>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

    void initializeUI();

private slots:
    void changeTestIndex(int newIndex);

private:
    QGroupBox *m_mainMenu;

    /// choose test menu
    QGroupBox *m_chooseTestGroup;
    QComboBox *m_testsComboBox;

    /// setting menu
    QGroupBox *m_settingsGroup;
    QSlider *m_velocityIterationsSlider;
    QSlider *m_positionIterationsSlider;
    QSlider *m_hzSlider;
    QCheckBox *m_enableSleepCheckBox;
    QCheckBox *m_enableWarmStartingCheckBox;
    QCheckBox *m_enableContinuousCheckBox;
    QCheckBox *m_enableSubSteppingCheckBox;

    /// draw settings menu
    QGroupBox *m_drawSettingsGroup;
    QCheckBox *m_drawShapesCheckBox;
    QCheckBox *m_drawJointsCheckBox;
    QCheckBox *m_drawAABBsCheckBox;
    QCheckBox *m_drawContactPointsCheckBox;
    QCheckBox *m_drawContactNormalsCheckBox;
    QCheckBox *m_drawContactImpulseCheckBox;
    QCheckBox *m_drawFrictionImpulseCheckBox;
    QCheckBox *m_drawCOMsCheckBox;
    QCheckBox *m_drawStatsCheckBox;
    QCheckBox *m_drawProfileCheckBox;

    /// menu buttons
    QGroupBox *m_buttonsGroup;
    QPushButton *m_pauseButton;
    QPushButton *m_singleStepButton;
    QPushButton *m_restartButton;
    QPushButton *m_quitButton;

    ///
    QVBoxLayout *m_vBoxLayout;
    MainOpenGLWidget *m_mainOpenGLWidget;
    QHBoxLayout *m_hBoxLayout;
};

#endif // MAINWIDGET_H
