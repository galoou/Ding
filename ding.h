#ifndef DING_H
#define DING_H

#include <QObject>
#include <QTimer>

class Ding : public QObject
{
    Q_OBJECT
public:
    explicit Ding(QObject *parent = 0, int interval = 60);
    ~Ding();

private:
    QTimer *timer;
    int interval;
    int elapsedTime;

signals:
    void onPlay(int);
    void elapsedTimeChanged(int);

public slots:
    void play();
    void stop();

private slots:
    void resetElapsedTime();
    void incrementElapsedTime();
    void bell();
};

#endif // DING_H
