#ifndef WINDOWS_H
#define WINDOWS_H

#include <QWidget>
#include <QPushButton>

#include "Area.h"

class Windows : public QWidget
{
    Q_OBJECT
public:
    Windows();
protected:
    Area *area = nullptr;
    QPushButton *btn = nullptr;
};

#endif // WINDOWS_H
