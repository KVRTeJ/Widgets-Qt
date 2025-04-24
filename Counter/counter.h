#ifndef COUNTER_H
#define COUNTER_H

#include <QLineEdit>

class Counter : public QLineEdit {
    Q_OBJECT
public:
    Counter(const QString &contents, QWidget *parent = nullptr) : QLineEdit(contents, parent)
    {}

signals:
    void tick_signal();

public slots:
    void add_one() {
        QString str = text();
        int r = str.toInt();

        ++r;
        str.setNum(r);
        setText(str);

        if((r != 0) && !(r % 5)) {
            emit tick_signal();
        }
    }
};

#endif // COUNTER_H
