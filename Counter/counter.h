#ifndef COUNTER_H
#define COUNTER_H

#include <QWidget>

class Counter : public QWidget
{
    Q_OBJECT

public:
    Counter(QWidget *parent = nullptr);
    ~Counter();
};
#endif // COUNTER_H
