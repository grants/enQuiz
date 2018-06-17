#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QString>
#include <QNetworkAccessManager>
#include <QTextCodec>
#include <QNetworkReply>
#include <QWebPage>
#include <QWebView>
#include <QWebElement>
#include <QWebElementCollection>
#include <QtWebKit>
#include <QWebFrame>
#include <QRegExp>
#include <QListView>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QMessageBox>
#include <QKeyEvent>
#include <QEvent>
#include <QMap>
#include <QVariant>
#include <QDir>
#include <QSqlDriver>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
	
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	bool eventFilter(QObject *, QEvent *);
	
signals:
	void addToQuiz();
	void quizToDb(QString, QString, QString);
	void exportWordsPaper();
	void beginExport(QString filedir);
	void exportthem(QString, QString);
	
private slots:
	void on_pushButton_clicked();
	void viewLoadFinished(bool);
	
	void on_lineEdit_returnPressed();
	
	void on_actionVersion_triggered();
	void addToQuizAct();
	void exportQuizFiles(QString filedir);
	
	void on_pushButton_addtoquiz_clicked();
	void quizToDbAct(QString, QString, QString);
	
	void on_pushButton_exporttofile_clicked();
	void exportWordsPaperAct();
	void exportthemact(QString, QString);
	
private:
	Ui::MainWindow *ui;
	QWebView *webview;
	QString dbStorePath;
};


#endif // MAINWINDOW_H
