#include <QLayout>

#include "windows.h"

Windows::Windows() {
    setWindowTitle("Обработка событий");

    area = new Area(this);
    btn = new QPushButton("Завершить", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(area);
    layout->addWidget(btn);
    connect(btn, &QPushButton::clicked, this, &QWidget::close);
}
