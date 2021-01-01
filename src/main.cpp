#include <QApplication>
#include <QWidget>
#include <MainWindow.h>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    MainWindow mainWindow;
    mainWindow.setWindowIcon(::QIcon("icon.ico"));
    mainWindow.show();

    return app.exec();
}