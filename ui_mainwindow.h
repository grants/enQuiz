/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionVersion;
    QAction *actionQuit;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label_headword;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_usap;
    QLabel *label_brp;
    QLabel *label_trans;
    QListView *listView_sentence;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_exporttofile;
    QPushButton *pushButton_addtoquiz;
    QMenuBar *menuBar;
    QMenu *menuEnQuiz;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(609, 597);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/enquiz.icns"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionVersion = new QAction(MainWindow);
        actionVersion->setObjectName(QString::fromUtf8("actionVersion"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QFont font;
        font.setPointSize(18);
        lineEdit->setFont(font);
        lineEdit->setCursorPosition(0);

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        label_headword = new QLabel(centralWidget);
        label_headword->setObjectName(QString::fromUtf8("label_headword"));
        label_headword->setStyleSheet(QString::fromUtf8("font-size:18px;color:#FF8600;font-weight:bold;"));
        label_headword->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(label_headword);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        label_usap = new QLabel(centralWidget);
        label_usap->setObjectName(QString::fromUtf8("label_usap"));
        label_usap->setFont(font);
        label_usap->setStyleSheet(QString::fromUtf8("color:#91491A;"));

        horizontalLayout_2->addWidget(label_usap);

        label_brp = new QLabel(centralWidget);
        label_brp->setObjectName(QString::fromUtf8("label_brp"));
        label_brp->setFont(font);
        label_brp->setStyleSheet(QString::fromUtf8("color:#91491A;"));

        horizontalLayout_2->addWidget(label_brp);


        verticalLayout->addLayout(horizontalLayout_2);

        label_trans = new QLabel(centralWidget);
        label_trans->setObjectName(QString::fromUtf8("label_trans"));
        label_trans->setFont(font);
        label_trans->setStyleSheet(QString::fromUtf8("color:#6D7F47;"));
        label_trans->setWordWrap(true);

        verticalLayout->addWidget(label_trans);

        listView_sentence = new QListView(centralWidget);
        listView_sentence->setObjectName(QString::fromUtf8("listView_sentence"));
        QFont font1;
        font1.setPointSize(14);
        listView_sentence->setFont(font1);
        listView_sentence->setStyleSheet(QString::fromUtf8("color:#0D6AB2;"));
        listView_sentence->setProperty("isWrapping", QVariant(false));
        listView_sentence->setSpacing(2);

        verticalLayout->addWidget(listView_sentence);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        pushButton_exporttofile = new QPushButton(centralWidget);
        pushButton_exporttofile->setObjectName(QString::fromUtf8("pushButton_exporttofile"));

        horizontalLayout_3->addWidget(pushButton_exporttofile);

        pushButton_addtoquiz = new QPushButton(centralWidget);
        pushButton_addtoquiz->setObjectName(QString::fromUtf8("pushButton_addtoquiz"));

        horizontalLayout_3->addWidget(pushButton_addtoquiz);


        verticalLayout->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 609, 22));
        menuEnQuiz = new QMenu(menuBar);
        menuEnQuiz->setObjectName(QString::fromUtf8("menuEnQuiz"));
        MainWindow->setMenuBar(menuBar);
        QWidget::setTabOrder(lineEdit, pushButton);
        QWidget::setTabOrder(pushButton, listView_sentence);

        menuBar->addAction(menuEnQuiz->menuAction());
        menuEnQuiz->addAction(actionVersion);
        menuEnQuiz->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "EnQuiz version 1.0.0", 0, QApplication::UnicodeUTF8));
        actionVersion->setText(QApplication::translate("MainWindow", "Version", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Input a word:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\345\233\236\350\275\246\346\210\226search button</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButton->setText(QApplication::translate("MainWindow", "Search", 0, QApplication::UnicodeUTF8));
        label_headword->setText(QApplication::translate("MainWindow", "Please search an English word above then press enter.", 0, QApplication::UnicodeUTF8));
        label_usap->setText(QApplication::translate("MainWindow", "USA Pronunce", 0, QApplication::UnicodeUTF8));
        label_brp->setText(QApplication::translate("MainWindow", "British Pronunce", 0, QApplication::UnicodeUTF8));
        label_trans->setText(QApplication::translate("MainWindow", "Chinese translation for this word.", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        listView_sentence->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>The one sentence selected will be add into the quiz db &quot;Questions&quot; part,  along with this word, its produnction and translation will into the &quot;Answers&quot; part.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButton_exporttofile->setText(QApplication::translate("MainWindow", "Export To Text File", 0, QApplication::UnicodeUTF8));
        pushButton_addtoquiz->setText(QApplication::translate("MainWindow", "Add To Quiz (Enter In Sentence)", 0, QApplication::UnicodeUTF8));
        menuEnQuiz->setTitle(QApplication::translate("MainWindow", "EnQuiz", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
