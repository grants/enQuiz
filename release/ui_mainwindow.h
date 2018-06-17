/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(609, 597);
        QIcon icon;
        icon.addFile(QStringLiteral(":/enquiz.icns"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionVersion = new QAction(MainWindow);
        actionVersion->setObjectName(QStringLiteral("actionVersion"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QFont font;
        font.setPointSize(18);
        lineEdit->setFont(font);
        lineEdit->setCursorPosition(0);

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        label_headword = new QLabel(centralWidget);
        label_headword->setObjectName(QStringLiteral("label_headword"));
        label_headword->setStyleSheet(QStringLiteral("font-size:18px;color:#FF8600;font-weight:bold;"));
        label_headword->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(label_headword);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        label_usap = new QLabel(centralWidget);
        label_usap->setObjectName(QStringLiteral("label_usap"));
        label_usap->setFont(font);
        label_usap->setStyleSheet(QStringLiteral("color:#91491A;"));

        horizontalLayout_2->addWidget(label_usap);

        label_brp = new QLabel(centralWidget);
        label_brp->setObjectName(QStringLiteral("label_brp"));
        label_brp->setFont(font);
        label_brp->setStyleSheet(QStringLiteral("color:#91491A;"));

        horizontalLayout_2->addWidget(label_brp);


        verticalLayout->addLayout(horizontalLayout_2);

        label_trans = new QLabel(centralWidget);
        label_trans->setObjectName(QStringLiteral("label_trans"));
        label_trans->setFont(font);
        label_trans->setStyleSheet(QStringLiteral("color:#6D7F47;"));
        label_trans->setWordWrap(true);

        verticalLayout->addWidget(label_trans);

        listView_sentence = new QListView(centralWidget);
        listView_sentence->setObjectName(QStringLiteral("listView_sentence"));
        QFont font1;
        font1.setPointSize(14);
        listView_sentence->setFont(font1);
        listView_sentence->setStyleSheet(QStringLiteral("color:#0D6AB2;"));
        listView_sentence->setProperty("isWrapping", QVariant(false));
        listView_sentence->setSpacing(2);

        verticalLayout->addWidget(listView_sentence);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        pushButton_exporttofile = new QPushButton(centralWidget);
        pushButton_exporttofile->setObjectName(QStringLiteral("pushButton_exporttofile"));

        horizontalLayout_3->addWidget(pushButton_exporttofile);

        pushButton_addtoquiz = new QPushButton(centralWidget);
        pushButton_addtoquiz->setObjectName(QStringLiteral("pushButton_addtoquiz"));

        horizontalLayout_3->addWidget(pushButton_addtoquiz);


        verticalLayout->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 609, 22));
        menuEnQuiz = new QMenu(menuBar);
        menuEnQuiz->setObjectName(QStringLiteral("menuEnQuiz"));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "EnQuiz version 1.0.0", 0));
        actionVersion->setText(QApplication::translate("MainWindow", "Version", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        label->setText(QApplication::translate("MainWindow", "Input a word:", 0));
#ifndef QT_NO_TOOLTIP
        lineEdit->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\345\233\236\350\275\246\346\210\226search button</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton->setText(QApplication::translate("MainWindow", "Search", 0));
        label_headword->setText(QApplication::translate("MainWindow", "Please search an English word above then press enter.", 0));
        label_usap->setText(QApplication::translate("MainWindow", "USA Pronunce", 0));
        label_brp->setText(QApplication::translate("MainWindow", "British Pronunce", 0));
        label_trans->setText(QApplication::translate("MainWindow", "Chinese translation for this word.", 0));
#ifndef QT_NO_TOOLTIP
        listView_sentence->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>The one sentence selected will be add into the quiz db &quot;Questions&quot; part,  along with this word, its produnction and translation will into the &quot;Answers&quot; part.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_exporttofile->setText(QApplication::translate("MainWindow", "Export To Text File", 0));
        pushButton_addtoquiz->setText(QApplication::translate("MainWindow", "Add To Quiz (Enter In Sentence)", 0));
        menuEnQuiz->setTitle(QApplication::translate("MainWindow", "EnQuiz", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
