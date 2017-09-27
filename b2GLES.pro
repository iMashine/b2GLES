QT       += core gui widgets

TARGET = b2GLES
TEMPLATE = app

SOURCES += main.cpp \
    mainopenglwidget.cpp \
    mainwidget.cpp \
    camera.cpp \
    debugdraw.cpp \
    renderpoints.cpp \
    renderlines.cpp \
    rendertriangles.cpp \
    test.cpp

HEADERS  += \
    mainopenglwidget.h \
    mainwidget.h \
    camera.h \
    debugdraw.h \
    renderpoints.h \
    renderlines.h \
    rendertriangles.h \
    test.h \
    tests.h \
    include/Box2D/Collision/Shapes/b2ChainShape.h \
    include/Box2D/Collision/Shapes/b2CircleShape.h \
    include/Box2D/Collision/Shapes/b2EdgeShape.h \
    include/Box2D/Collision/Shapes/b2PolygonShape.h \
    include/Box2D/Collision/Shapes/b2Shape.h \
    include/Box2D/Collision/b2BroadPhase.h \
    include/Box2D/Collision/b2Collision.h \
    include/Box2D/Collision/b2Distance.h \
    include/Box2D/Collision/b2DynamicTree.h \
    include/Box2D/Collision/b2TimeOfImpact.h \
    include/Box2D/Common/b2BlockAllocator.h \
    include/Box2D/Common/b2Draw.h \
    include/Box2D/Common/b2GrowableStack.h \
    include/Box2D/Common/b2Math.h \
    include/Box2D/Common/b2Settings.h \
    include/Box2D/Common/b2StackAllocator.h \
    include/Box2D/Common/b2Timer.h \
    include/Box2D/Dynamics/Contacts/b2ChainAndCircleContact.h \
    include/Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.h \
    include/Box2D/Dynamics/Contacts/b2CircleContact.h \
    include/Box2D/Dynamics/Contacts/b2Contact.h \
    include/Box2D/Dynamics/Contacts/b2ContactSolver.h \
    include/Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.h \
    include/Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.h \
    include/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.h \
    include/Box2D/Dynamics/Contacts/b2PolygonContact.h \
    include/Box2D/Dynamics/Joints/b2DistanceJoint.h \
    include/Box2D/Dynamics/Joints/b2FrictionJoint.h \
    include/Box2D/Dynamics/Joints/b2GearJoint.h \
    include/Box2D/Dynamics/Joints/b2Joint.h \
    include/Box2D/Dynamics/Joints/b2MotorJoint.h \
    include/Box2D/Dynamics/Joints/b2MouseJoint.h \
    include/Box2D/Dynamics/Joints/b2PrismaticJoint.h \
    include/Box2D/Dynamics/Joints/b2PulleyJoint.h \
    include/Box2D/Dynamics/Joints/b2RevoluteJoint.h \
    include/Box2D/Dynamics/Joints/b2RopeJoint.h \
    include/Box2D/Dynamics/Joints/b2WeldJoint.h \
    include/Box2D/Dynamics/Joints/b2WheelJoint.h \
    include/Box2D/Dynamics/b2Body.h \
    include/Box2D/Dynamics/b2ContactManager.h \
    include/Box2D/Dynamics/b2Fixture.h \
    include/Box2D/Dynamics/b2Island.h \
    include/Box2D/Dynamics/b2TimeStep.h \
    include/Box2D/Dynamics/b2World.h \
    include/Box2D/Dynamics/b2WorldCallbacks.h \
    include/Box2D/Rope/b2Rope.h \
    include/Box2D/Box2D.h \
    include/Tests/AddPair.h \
    include/Tests/ApplyForce.h \
    include/Tests/BasicSliderCrank.h \
    include/Tests/BodyTypes.h \
    include/Tests/Breakable.h \
    include/Tests/Bridge.h \
    include/Tests/BulletTest.h \
    include/Tests/Cantilever.h \
    include/Tests/Car.h \
    include/Tests/Chain.h \
    include/Tests/chainProblem.h \
    include/Tests/CharacterCollision.h \
    include/Tests/CollisionFiltering.h \
    include/Tests/CollisionProcessing.h \
    include/Tests/CompoundShapes.h \
    include/Tests/Confined.h \
    include/Tests/ContinuousTest.h \
    include/Tests/ConvexHull.h \
    include/Tests/ConveyorBelt.h \
    include/Tests/DistanceTest.h \
    include/Tests/Dominos.h \
    include/Tests/DumpShell.h \
    include/Tests/DynamicTreeTest.h \
    include/Tests/EdgeShapes.h \
    include/Tests/EdgeTest.h \
    include/Tests/Gears.h \
    include/Tests/HeavyOnLight.h \
    include/Tests/HeavyOnLightTwo.h \
    include/Tests/Mobile.h \
    include/Tests/MobileBalanced.h \
    include/Tests/MotorJoint.h \
    include/Tests/OneSidedPlatform.h \
    include/Tests/Pinball.h \
    include/Tests/PolyCollision.h \
    include/Tests/PolyShapes.h \
    include/Tests/Prismatic.h \
    include/Tests/Pulleys.h \
    include/Tests/Pyramid.h \
    include/Tests/RayCast.h \
    include/Tests/Revolute.h \
    include/Tests/Rope.h \
    include/Tests/RopeJoint.h \
    include/Tests/SensorTest.h \
    include/Tests/ShapeEditing.h \
    include/Tests/Skier.h \
    include/Tests/SliderCrank.h \
    include/Tests/SphereStack.h \
    include/Tests/TheoJansen.h \
    include/Tests/Tiles.h \
    include/Tests/TimeOfImpact.h \
    include/Tests/Tumbler.h \
    include/Tests/VaryingFriction.h \
    include/Tests/VaryingRestitution.h \
    include/Tests/VerticalStack.h \
    include/Tests/Web.h

LIBS += -L$$PWD/lib/ -lBox2D
LIBS += -lOpengl32

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

PRE_TARGETDEPS += $$PWD/lib/libBox2D.a
