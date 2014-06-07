TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

HEADERS += \
    affector.h \
    area.h \
    emitter.h \
    particle.h \
    affector/accelerationAffector.h \
    affector/velocityAffector.h \
    ParticleSystem.h \
    affector/deathAffector.h \
    affector/randomVelocityAffector.h \
    randomizer.h \
    emitter/lineEmitter.h \
    emitter/pointEmitter.h \
    emitter/circleEmitter.h \
    affector/gravityAffector.h \
    affector/baseAffector.h \
    drawer.h \
    affector/randomSizeAffector.h \
    affector/randomAngleAffector.h \
    affector/randomTextureAffector.h \
    affector/randomColorAffector.h \
    affector/randomMaskAffector.h \
    drawer/SFMLdrawer.h \
    randomizer/uniformRandomizer.h \
    affector/randomAngularVelocityAffector.h \
    affector/angularAccelerationAffector.h \
    affector/angleOnDirectionAffector.h \
    affector/colorFaderAffector.h

SOURCES += \
    area.cpp \
    emitter.cpp \
    main.cpp

unix:!macx: LIBS += -lsfml-graphics -lsfml-window -lsfml-system
