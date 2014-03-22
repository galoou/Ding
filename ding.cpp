#include "ding.h"

#include <QSound>

Ding::Ding(QObject *parent, int interval) :
    QObject(parent)
{
    this->interval    = interval;
    this->timer       = new QTimer(this);
    this->elapsedTime = 0;

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

    resetElapsedTime();
}

void Ding::resetElapsedTime()
{
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

    resetElapsedTime();
}

void Ding::bell()
{
    QSound::play(":/sounds/bell.wav");
}
