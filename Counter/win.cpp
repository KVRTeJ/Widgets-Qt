#include <QVBoxLayout>

#include "win.h"

Win::Win(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("Счетчик");
    label1 = new QLabel("Счет по 1", this);
    label2 = new QLabel("Счет по 5", this);

//    edit1 = new Counter("0", this);
//    edit2 = new Counter("0", this);

//    calcButton = new QPushButton("+1", this);
//    exitButton = new QPushButton("Выход", this);

    QHBoxLayout *labelsLayout = new QHBoxLayout();
    labelsLayout->addWidget(label1);
    labelsLayout->addWidget(label2);

//    QHBoxLayout *linesEditLayout = new QHBoxLayout();
//    linesEditLayout->addWidget(edit1);
//    linesEditLayout->addWidget(edit2);

//    QHBoxLayout *buttomsLayout = new QHBoxLayout();
//    buttomsLayout->addWidget(calcButton);
//    buttomsLayout->addWidget(exitButton);

//    QVBoxLayout *layout = new QVBoxLayout();
//    layout->addLayout(labelsLayout);
//    layout->addLayout(linesEditLayout);
//    layout->addLayout(buttomsLayout);

//    connect(exitButton, SIGNAL(clicled(bool)), this, SLOT(close()));
//    connect(calcButton, SIGNAL(clicked(bool)), edit1, SLOT(add_one()));
//    connect(edit1, SIGNAL(tick_signal()), edit2, SLOT(add_one()));
}
