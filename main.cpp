#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.setWindowIcon(QIcon(":/enquiz.ico"));
	w.show();
	a.setWindowIcon(QIcon(":/enquiz.icns"));
	return a.exec();
}
