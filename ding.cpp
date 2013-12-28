#include "ding.h"

#include <QApplication>
#include <QDir>
#include <QSound>

Ding::Ding(QObject *parent, int interval) :
    QObject(parent)
{
    this->timer = new QTimer(this);
    this->elapsedTime = 0;
    this->interval = interval;

    connect(timer, SIGNAL(timeout()), this, SLOT(incrementElapsedTime()));
}

Ding::~Ding()
{
    delete timer;
}


void Ding::play()
{
    elapsedTime = 0;
    emit elapsedTimeChanged(elapsedTime);

    timer->start(1000);
    emit onPlay(interval);

    bell();
}

void Ding::stop()
{
    timer->stop();

    elapsedTime = 0;
    emit elapsedTimeChanged(elapsedTime);
}

void Ding::incrementElapsedTime()
{
    elapsedTime++;
    emit elapsedTimeChanged(elapsedTime);

    if (elapsedTime < interval)
        return;

    bell();

    elapsedTime = 0;
    emit elapsedTimeChanged(elapsedTime);
}

void Ding::bell()
{
    QDir dir(QApplication::applicationDirPath());
    dir.cdUp();
    dir.cd("Resources");

    QSound::play(dir.filePath("bell.wav"));
}
