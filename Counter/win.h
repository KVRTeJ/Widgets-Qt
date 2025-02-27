#ifndef WIN_H
#define WIN_H

#include <QWidget>

#include <QLabel>
#include <QPushButton>

#include "counter.h"

class Win : public QWidget {
    Q_OBJECT
public:
    Win(QWidget *parent = nullptr);

protected:
    QLabel *label1 = nullptr;
    QLabel *label2 = nullptr;

    Counter *edit1 = nullptr;
    Counter *edit2 = nullptr;

    QPushButton *calcButton = nullptr;
    QPushButton *exitButton = nullptr;
};

#endif // WIN_H
