#include <QVBoxLayout>
#include <QMessageBox>

#include "win.h"

#include "strvalidator.h"

Win::Win(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Возведение в квадрат");

    frame = new QFrame(this);

    frame->setFrameShape(QFrame::Panel);
    frame->setFrameShadow(QFrame::Raised);

    inputLabel = new QLabel("Введите число:", this);
    inputEdit = new QLineEdit("", this);
    StrValidator *v = new StrValidator(inputEdit);
    inputEdit->setValidator(v);

    outputLabel = new QLabel("Результат:", this);
    outputEdit = new QLineEdit("", this);

    nextButton = new QPushButton("Следующее", this);
    exitButton = new QPushButton("Выход", this);

    QVBoxLayout *vLayout1 = new QVBoxLayout(frame);
    vLayout1->addWidget(inputLabel);
    vLayout1->addWidget(inputEdit);
    vLayout1->addWidget(outputLabel);
    vLayout1->addWidget(outputEdit);

    QVBoxLayout *vLayout2 = new QVBoxLayout();
    vLayout2->addWidget(nextButton);
    vLayout2->addWidget(exitButton);
    vLayout2->addStretch();

    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addWidget(frame);
    hLayout->addLayout(vLayout2);

    begin();

    connect(exitButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(nextButton, SIGNAL(clicked(bool)), this, SLOT(begin()));
    connect(inputEdit, SIGNAL(returnPressed()), this, SLOT(calc()));
}

void Win::begin() {
    inputEdit->clear();

    nextButton->setEnabled(false);
    nextButton->setDefault(false);

    inputEdit->setEnabled(true);
    outputLabel->setVisible(false);

//  Вместо setEnabled(false) я предпочел сделать QLineEdit readonly
    outputEdit->setReadOnly(true);
    inputEdit->setFocus();
}

void Win::calc() {
    bool ok = true;
    float r;
    float a;

    QString str = inputEdit->text();
    a = str.toDouble(&ok);
    if(ok) {
        r = a * a;

        str.setNum(r);
        outputEdit->setText(str);
        outputLabel->setVisible(true);

        nextButton->setDefault(true);
        nextButton->setEnabled(true);
        nextButton->setFocus();
    } else {
        if(!str.isEmpty()) {
            QMessageBox msgBox(QMessageBox::Information,
                               "Возведение в квадрат",
                               "Введено неверное значение",
                               QMessageBox::Ok);
            msgBox.exec();
        }
    }
}



