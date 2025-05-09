#ifndef WIN_H
#define WIN_H

#include <QWidget>

#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>


class Win : public QWidget {
    Q_OBJECT
public:
    Win(QWidget *parent = nullptr);
    ~Win() = default;

public slots:
    void begin();
    void calc();

protected:
    QFrame *frame = nullptr;

    QLabel *inputLabel = nullptr;
    QLabel *outputLabel = nullptr;

    QLineEdit *inputEdit = nullptr;
    QLineEdit *outputEdit = nullptr;

    QPushButton *nextButton = nullptr;
    QPushButton *exitButton = nullptr;

private:
    float m_maxAbsInputValue = 0;
};

#endif // WIN_H
