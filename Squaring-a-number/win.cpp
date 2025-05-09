#include <QVBoxLayout>
#include <QMessageBox>

#include <float.h>
#include <math.h>

#include "win.h"

#include "strvalidator.h"

Win::Win(QWidget *parent)
    : QWidget(parent)
{
    m_maxAbsInputValue = sqrt(FLT_MAX);

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
    vLayout1->addStretch();

    QVBoxLayout *vLayout2 = new QVBoxLayout();
    vLayout2->addWidget(nextButton);
    vLayout2->addWidget(exitButton);
    vLayout2->addStretch();

    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addWidget(frame);
    hLayout->addLayout(vLayout2);

    begin();

    connect(exitButton, &QPushButton::clicked, this, &Win::close);
    connect(nextButton, &QPushButton::clicked, this, &Win::begin);
    connect(inputEdit, &QLineEdit::returnPressed, this, &Win::calc);
}

void Win::begin() {
    inputEdit->clear();

    nextButton->setEnabled(false);
    nextButton->setDefault(false);

    inputEdit->setEnabled(true);

    outputEdit->setVisible(false);
    outputEdit->setEnabled(false);
    outputLabel->setVisible(false);

    inputEdit->setFocus();
}

void Win::calc() {
    bool ok = true;
    float r;
    float a;

    QString str = inputEdit->text();
    a = str.toDouble(&ok);
    if(ok) {
        if(abs(a) > m_maxAbsInputValue) {
            QMessageBox msgBox(QMessageBox::Information,
                               "Возведение в квадрат",
                               "Введено слишком большое число",
                               QMessageBox::Ok);
            msgBox.exec();

            return;
        }

        r = a * a;

        str.setNum(r);
        outputEdit->setText(str);

        inputEdit->setEnabled(false);

        outputLabel->setVisible(true);
        outputEdit->setVisible(true);

        nextButton->setDefault(true);
        nextButton->setEnabled(true);
        nextButton->setVisible(true);

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



