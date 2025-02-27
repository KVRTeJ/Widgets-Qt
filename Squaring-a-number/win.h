#ifndef WIN_H
#define WIN_H

#include <QWidget>

#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>


class Win : public QWidget {
    Q_OBJECT // Макрос для Qt, который обеспечивает коррктное создание сигналов и слотов
public:
    Win(QWidget *parent = nullptr);
    ~Win() = default;

public slots:
    void begin();
    void calc();

protected:
    QFrame *frame = nullptr;
    QLabel *inputLabel = nullptr;
    QLineEdit *inputEdit = nullptr;
    QLabel *outputLabel = nullptr;
    QLineEdit *outputEdit = nullptr;
    QPushButton *nextButton = nullptr;
    QPushButton *exitButton = nullptr;
};

#endif // WIN_H
