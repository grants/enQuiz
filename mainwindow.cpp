#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
		QMainWindow(parent),
		ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	ui->listView_sentence->installEventFilter(this);
	connect(this, SIGNAL(addToQuiz()), this, SLOT(addToQuizAct()));
	ui->pushButton_addtoquiz->setEnabled(false);
	connect(this, SIGNAL(quizToDb(QString,QString,QString)), 
									this, SLOT(quizToDbAct(QString,QString,QString)));
	connect(this, SIGNAL(exportWordsPaper()), this, SLOT(exportWordsPaperAct()));
	connect(this, SIGNAL(beginExport(QString)), this, SLOT(exportQuizFiles(QString)));
	connect(this, SIGNAL(exportthem(QString,QString)), this, SLOT(exportthemact(QString,QString)));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButton_clicked() {
	QString searchWord = ui->lineEdit->text();
	QString searchUrl = "http://cn.bing.com/dict/search?q="+searchWord+"&go=提交&qs=n&form=CM&pq="+searchWord+"&sc=6-3&sp=-1&sk=";
	webview = new QWebView(this);
	connect(webview, SIGNAL(loadFinished(bool)), 
									this, SLOT(viewLoadFinished(bool)));
	webview->load(QUrl(searchUrl));
}


void MainWindow::viewLoadFinished(bool loadok) {
	if (loadok) {
		QWebFrame *frame = webview->page()->mainFrame();
		QWebElement document = frame->documentElement();
		QWebElement headWordEle = document.findFirst("div#headword");
		QWebElement prUSe = document.findFirst("div.hd_prUS");
		QWebElement prBRe = document.findFirst("div.hd_pr");
		QWebElementCollection translations = document.findAll("div.qdef ul li");
		QWebElementCollection sentencesEn = document.findAll("div#sentenceSeg div.se_li div.sen_en");
		QWebElementCollection sentencesCn = document.findAll("div#sentenceSeg div.se_li div.sen_cn");
		QString headWord = headWordEle.toPlainText().trimmed();
		QString prUS = prUSe.toPlainText().trimmed();
		QString prBR = prBRe.toPlainText().trimmed();
		QString underline = "";
		QStandardItemModel *sentenceModel = new QStandardItemModel(sentencesEn.count(), 1, this);
		QString trans = "";
		QRegExp headwordrx(headWord, Qt::CaseInsensitive);
		for (int c = 0; c < headWord.count(); ++c) {
			underline += "__";
		}
		for (int i = 0; i < sentencesEn.count(); ++i) {
			QString sentence = sentencesEn[i].toPlainText().trimmed().replace(
						headwordrx, underline)
					+ "\n" + sentencesCn[i].toPlainText().trimmed();
			QStandardItem *sentenceItem = new QStandardItem(sentence);
			sentenceModel->setItem(i, 0, sentenceItem);
		}
		foreach(QWebElement tranone, translations) {
			trans += tranone.toPlainText().trimmed() + "  ";
		}
		
		ui->label_headword->setText(headWord);
		ui->label_usap->setText(prUS);
		ui->label_brp->setText(prBR);
		ui->label_trans->setText(trans.trimmed());
		ui->listView_sentence->setModel(sentenceModel);
		webview->deleteLater();
		ui->listView_sentence->setFocus();
		ui->listView_sentence->setCurrentIndex(sentenceModel->index(0,0));
		ui->pushButton_addtoquiz->setEnabled(true);
		
	} else {
		QMessageBox::information(this, "Error Message", "Network error. Can't load the web page.");
	}
}

void MainWindow::on_lineEdit_returnPressed() {
	this->on_pushButton_clicked();
}

void MainWindow::on_actionVersion_triggered() {
	QMessageBox::information(this, "Version 1.0.0", 
																										"EnQuiz Version 1.0.0.\nCopyright 2015 Qihao. Published Under LGPL License.\nMust online and has SQLite in your computer.");
}

void MainWindow::addToQuizAct() {
	QModelIndex index = ui->listView_sentence->selectionModel()->currentIndex();
	QString quiz =  ui->listView_sentence->model()->data(index).toString();
	QString answer = ui->label_headword->text() + " " + ui->label_usap->text() + " " 
			+ ui->label_brp->text() + " " + ui->label_trans->text();
	QString word = ui->label_headword->text();
	if (QMessageBox::Yes == QMessageBox::question(this, "Notice", "Add this sentence into quiz, are you sure?", QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes)) {
		emit quizToDb(word, quiz, answer);
	}	
}

void MainWindow::exportQuizFiles(QString filedir) {
	QString tf = filedir + "/quiz.txt";
	QString af = filedir + "/answer.txt";
	QFile testfile(tf);
	QFile answerfile(af);
	if (testfile.exists() || answerfile.exists()) {
		if (QMessageBox::Yes == QMessageBox::question(this, "Notice", "File already exists, overwrite them?", QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes)) {
			testfile.close();
			answerfile.close();
			emit exportthem(tf, af);
		}
	} else {
		testfile.close();
		answerfile.close();
		emit exportthem(tf, af);
	}
}

bool MainWindow::eventFilter(QObject *object, QEvent *event) {
	if (object == (QObject *)ui->listView_sentence && event->type() == QEvent::KeyPress) {
		QKeyEvent *key = dynamic_cast<QKeyEvent *>(event);
		if (key->key() == Qt::Key_Enter || key->key() == Qt::Key_Return) {
			emit addToQuiz();
			return true;
		}
	}
	return QMainWindow::eventFilter(object, event);
}

void MainWindow::on_pushButton_addtoquiz_clicked() {
	emit addToQuiz();
}

void MainWindow::quizToDbAct(QString word, QString quiz, QString answer) {
	QDir dbdir(QDir::homePath()+ QDir::separator() +"cherry");
	if (!dbdir.exists()) {
		dbdir.mkdir(QDir::homePath()+ QDir::separator() +"cherry");
	}
	QSqlDatabase db;
	if (QSqlDatabase::contains("sqconn")) {
		db = QSqlDatabase::database("sqconn");
	} else {
		db = QSqlDatabase::addDatabase("QSQLITE", "sqconn");
	}
	db.setHostName("localhost");
	db.setDatabaseName(dbdir.path()+ QDir::separator() +"enquiz.db");
	if (! db.open()) {
		QMessageBox::information(this, "DB Error", "Sqlite Database Open Error");
	} else {
		QSqlQuery query(db);
		if (query.exec("create table if not exists enquiz(id INTEGER, word TEXT, quiz TEXT, answer TEXT, PRIMARY KEY(id ASC))")) {
			query.prepare("insert into enquiz (word, quiz, answer) values (:word, :quiz, :answer)");
			query.bindValue(":word", word);
			query.bindValue(":quiz", quiz);
			query.bindValue(":answer", answer);
			if (query.exec()) {
				QMessageBox::information(this, "Notice", "Add quiz successful ^_^ ");
				ui->lineEdit->setText("");
				ui->lineEdit->setFocus();
			} else {
				QMessageBox::information(this, "Notice", "Add Quiz Failed. -_-u " + query.lastError().driverText());
			}
		} else {
			QMessageBox::information(this, "Notice", "Create DB Table Failed. -_-u " + query.lastError().driverText());
		}
		db.close();
	}
}

void MainWindow::on_pushButton_exporttofile_clicked() {
	unsigned int ws = 0;
	QString wordsum = "";
	QDir dbdir(QDir::homePath()+ QDir::separator() +"cherry");
	QSqlDatabase db;
	if (QSqlDatabase::contains("sqconn")) {
		db = QSqlDatabase::database("sqconn");
	} else {
		db = QSqlDatabase::addDatabase("QSQLITE", "sqconn");
	}
	db.setHostName("localhost");
	db.setDatabaseName(dbdir.path()+ QDir::separator() +"enquiz.db");
	if (! db.open()) {
		QMessageBox::information(this, "DB Error", "Sqlite Database Open Error");
	} else {
		QSqlQuery query(db);
		query.exec("select count(*) as totalwords from enquiz");
		while (query.next()) {
			ws = query.value(0).toInt();
			wordsum = query.value(0).toString();
		}
		db.close();
	}
	if (ws == 0) {
		QMessageBox::information(this, "No Words", "No word can be exported. Please add some first.");
	} else {
		if (QMessageBox::Yes == QMessageBox::question(this, "Notice", "Export "+wordsum+" words test paper file, are you sure?", QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes)) {
			emit exportWordsPaper();
		}	
	}
}

void MainWindow::exportWordsPaperAct() {
	QFileDialog saveDialog;
	saveDialog.setFileMode(QFileDialog::Directory);
	saveDialog.setOption(QFileDialog::ShowDirsOnly);
	QString filedir = saveDialog.getExistingDirectory( 
		this, 
		tr("Choose A Directory to Generate My English Quiz Paper File"));
	if (!filedir.isNull()) {
		emit beginExport(filedir);
	}
}

void MainWindow::exportthemact(QString testfilepath, QString answerfilepath) {
	QFile testfile(testfilepath);
	QFile answerfile(answerfilepath);
	QString quizstr;
	QString answerstr;
	
	QSqlDatabase db;
	if (QSqlDatabase::contains("sqconn")) {
		db = QSqlDatabase::database("sqconn");
	} else {
		db = QSqlDatabase::addDatabase("QSQLITE", "sqconn");
	}
	db.setHostName("localhost");
	QDir dbdir(QDir::homePath()+ QDir::separator() +"cherry");
	db.setDatabaseName(dbdir.path()+ QDir::separator() +"enquiz.db");
	if (! db.open()) {
		QMessageBox::information(this, "DB Error", "Sqlite Database Open Error");
	} else {
		QSqlQuery query(db);
		query.prepare("select id, word, quiz, answer from enquiz");
		if (query.exec()) {
			while (query.next()) {
				//quizstr += QString("%1. %2\n").arg(query.value("id").toString()).arg(query.value("quiz").toString());
				//answerstr += QString("%1. %2\n").arg(query.value("id").toString()).arg(query.value("answer").toString());
				quizstr += QString("%1. %2\n").arg(query.value(1).toString()).arg(query.value(3).toString());
				answerstr += QString("%1. %2\n").arg(query.value(1).toString()).arg(query.value(4).toString());
			}
			if ( testfile.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text) ) {
				QTextStream stream( &testfile );
				stream << quizstr << endl;
			}
			if ( answerfile.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text) ) {
				QTextStream stream( &answerfile );
				stream << answerstr << endl;
			}
			QMessageBox::information(this, "Notice", "Export Quiz Paper File Successful. ^_^");
		} else {
			QMessageBox::information(this, "Notice", "Export file Failed. -_-u " + query.lastError().driverText());
		}
		db.close();
	}
	testfile.close();
	answerfile.close();
}


