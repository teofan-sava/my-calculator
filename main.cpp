//
// Created by teofan on 6/24/26.
//

#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QPushButton button("Hello, Qt World!");
    button.resize(300, 100);
    button.show();

    return QApplication::exec();
}