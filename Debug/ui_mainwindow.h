/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *newfile_Action;
    QAction *openfile_Action;
    QAction *savefile_Action;
    QAction *saveotherfile_Action;
    QAction *print_Action;
    QAction *printandvisit_Action;
    QAction *exit_Action;
    QAction *back_Action;
    QAction *redo_Action;
    QAction *cut_Action;
    QAction *copy_Action;
    QAction *paste_Action;
    QAction *bold_Action;
    QAction *italy_Action;
    QAction *underline_Action;
    QAction *LeftAlign_Action;
    QAction *centerAlign_Action;
    QAction *rightAlign_Action;
    QAction *close_Action;
    QAction *closeAll_Action;
    QAction *title_Action;
    QAction *casecde_Action_2;
    QAction *next_Action;
    QAction *previous_Action;
    QAction *about_Action;
    QAction *justiceAlign_Action;
    QAction *color_Action;
    QWidget *centralWidget;
    QComboBox *comboBox;
    QFontComboBox *fontComboBox;
    QComboBox *sizeComBox;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_E;
    QMenu *menu_O;
    QMenu *menu_D;
    QMenu *menu_2;
    QMenu *menu_W;
    QMenu *menu_H;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(689, 584);
        newfile_Action = new QAction(MainWindow);
        newfile_Action->setObjectName(QStringLiteral("newfile_Action"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        newfile_Action->setIcon(icon);
        openfile_Action = new QAction(MainWindow);
        openfile_Action->setObjectName(QStringLiteral("openfile_Action"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        openfile_Action->setIcon(icon1);
        savefile_Action = new QAction(MainWindow);
        savefile_Action->setObjectName(QStringLiteral("savefile_Action"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        savefile_Action->setIcon(icon2);
        saveotherfile_Action = new QAction(MainWindow);
        saveotherfile_Action->setObjectName(QStringLiteral("saveotherfile_Action"));
        print_Action = new QAction(MainWindow);
        print_Action->setObjectName(QStringLiteral("print_Action"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/print.png"), QSize(), QIcon::Normal, QIcon::Off);
        print_Action->setIcon(icon3);
        printandvisit_Action = new QAction(MainWindow);
        printandvisit_Action->setObjectName(QStringLiteral("printandvisit_Action"));
        exit_Action = new QAction(MainWindow);
        exit_Action->setObjectName(QStringLiteral("exit_Action"));
        back_Action = new QAction(MainWindow);
        back_Action->setObjectName(QStringLiteral("back_Action"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        back_Action->setIcon(icon4);
        redo_Action = new QAction(MainWindow);
        redo_Action->setObjectName(QStringLiteral("redo_Action"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        redo_Action->setIcon(icon5);
        cut_Action = new QAction(MainWindow);
        cut_Action->setObjectName(QStringLiteral("cut_Action"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        cut_Action->setIcon(icon6);
        copy_Action = new QAction(MainWindow);
        copy_Action->setObjectName(QStringLiteral("copy_Action"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        copy_Action->setIcon(icon7);
        paste_Action = new QAction(MainWindow);
        paste_Action->setObjectName(QStringLiteral("paste_Action"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        paste_Action->setIcon(icon8);
        bold_Action = new QAction(MainWindow);
        bold_Action->setObjectName(QStringLiteral("bold_Action"));
        bold_Action->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/images/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        bold_Action->setIcon(icon9);
        italy_Action = new QAction(MainWindow);
        italy_Action->setObjectName(QStringLiteral("italy_Action"));
        italy_Action->setCheckable(true);
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/images/italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        italy_Action->setIcon(icon10);
        underline_Action = new QAction(MainWindow);
        underline_Action->setObjectName(QStringLiteral("underline_Action"));
        underline_Action->setCheckable(true);
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/images/under.png"), QSize(), QIcon::Normal, QIcon::Off);
        underline_Action->setIcon(icon11);
        LeftAlign_Action = new QAction(MainWindow);
        LeftAlign_Action->setObjectName(QStringLiteral("LeftAlign_Action"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/images/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        LeftAlign_Action->setIcon(icon12);
        centerAlign_Action = new QAction(MainWindow);
        centerAlign_Action->setObjectName(QStringLiteral("centerAlign_Action"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/images/center.png"), QSize(), QIcon::Normal, QIcon::Off);
        centerAlign_Action->setIcon(icon13);
        rightAlign_Action = new QAction(MainWindow);
        rightAlign_Action->setObjectName(QStringLiteral("rightAlign_Action"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/images/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        rightAlign_Action->setIcon(icon14);
        close_Action = new QAction(MainWindow);
        close_Action->setObjectName(QStringLiteral("close_Action"));
        closeAll_Action = new QAction(MainWindow);
        closeAll_Action->setObjectName(QStringLiteral("closeAll_Action"));
        title_Action = new QAction(MainWindow);
        title_Action->setObjectName(QStringLiteral("title_Action"));
        casecde_Action_2 = new QAction(MainWindow);
        casecde_Action_2->setObjectName(QStringLiteral("casecde_Action_2"));
        next_Action = new QAction(MainWindow);
        next_Action->setObjectName(QStringLiteral("next_Action"));
        previous_Action = new QAction(MainWindow);
        previous_Action->setObjectName(QStringLiteral("previous_Action"));
        about_Action = new QAction(MainWindow);
        about_Action->setObjectName(QStringLiteral("about_Action"));
        justiceAlign_Action = new QAction(MainWindow);
        justiceAlign_Action->setObjectName(QStringLiteral("justiceAlign_Action"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/images/justify.png"), QSize(), QIcon::Normal, QIcon::Off);
        justiceAlign_Action->setIcon(icon15);
        color_Action = new QAction(MainWindow);
        color_Action->setObjectName(QStringLiteral("color_Action"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/images/color.ico"), QSize(), QIcon::Normal, QIcon::Off);
        color_Action->setIcon(icon16);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(0, 0, 111, 22));
        fontComboBox = new QFontComboBox(centralWidget);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));
        fontComboBox->setGeometry(QRect(110, 0, 279, 22));
        sizeComBox = new QComboBox(centralWidget);
        sizeComBox->setObjectName(QStringLiteral("sizeComBox"));
        sizeComBox->setGeometry(QRect(390, 0, 181, 22));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));
        mdiArea->setGeometry(QRect(0, 20, 691, 491));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 689, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_E = new QMenu(menuBar);
        menu_E->setObjectName(QStringLiteral("menu_E"));
        menu_O = new QMenu(menuBar);
        menu_O->setObjectName(QStringLiteral("menu_O"));
        menu_D = new QMenu(menu_O);
        menu_D->setObjectName(QStringLiteral("menu_D"));
        menu_2 = new QMenu(menu_O);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_W = new QMenu(menuBar);
        menu_W->setObjectName(QStringLiteral("menu_W"));
        menu_H = new QMenu(menuBar);
        menu_H->setObjectName(QStringLiteral("menu_H"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_E->menuAction());
        menuBar->addAction(menu_O->menuAction());
        menuBar->addAction(menu_W->menuAction());
        menuBar->addAction(menu_H->menuAction());
        menu->addAction(newfile_Action);
        menu->addAction(openfile_Action);
        menu->addAction(savefile_Action);
        menu->addAction(saveotherfile_Action);
        menu->addAction(print_Action);
        menu->addAction(printandvisit_Action);
        menu->addAction(exit_Action);
        menu_E->addAction(back_Action);
        menu_E->addAction(redo_Action);
        menu_E->addAction(cut_Action);
        menu_E->addAction(copy_Action);
        menu_E->addAction(paste_Action);
        menu_O->addAction(menu_D->menuAction());
        menu_O->addAction(menu_2->menuAction());
        menu_O->addAction(color_Action);
        menu_D->addAction(bold_Action);
        menu_D->addAction(italy_Action);
        menu_D->addAction(underline_Action);
        menu_2->addAction(LeftAlign_Action);
        menu_2->addAction(centerAlign_Action);
        menu_2->addAction(rightAlign_Action);
        menu_2->addAction(justiceAlign_Action);
        menu_W->addAction(close_Action);
        menu_W->addAction(closeAll_Action);
        menu_W->addAction(title_Action);
        menu_W->addAction(casecde_Action_2);
        menu_W->addAction(next_Action);
        menu_W->addAction(previous_Action);
        menu_H->addAction(about_Action);
        mainToolBar->addAction(newfile_Action);
        mainToolBar->addAction(openfile_Action);
        mainToolBar->addAction(savefile_Action);
        mainToolBar->addSeparator();
        mainToolBar->addAction(back_Action);
        mainToolBar->addAction(redo_Action);
        mainToolBar->addAction(copy_Action);
        mainToolBar->addSeparator();
        mainToolBar->addAction(color_Action);
        mainToolBar->addAction(bold_Action);
        mainToolBar->addAction(italy_Action);
        mainToolBar->addAction(underline_Action);
        mainToolBar->addSeparator();
        mainToolBar->addAction(LeftAlign_Action);
        mainToolBar->addAction(centerAlign_Action);
        mainToolBar->addAction(rightAlign_Action);
        mainToolBar->addAction(justiceAlign_Action);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        newfile_Action->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272(N)", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        newfile_Action->setStatusTip(QApplication::translate("MainWindow", "\346\226\260\345\273\272\344\270\200\344\270\252\346\226\207\344\273\266", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        newfile_Action->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        openfile_Action->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200(O)", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        openfile_Action->setStatusTip(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\200\344\270\252\346\226\207\344\273\266", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        openfile_Action->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        savefile_Action->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230(S)", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        savefile_Action->setStatusTip(QApplication::translate("MainWindow", "\344\277\235\345\255\230\345\275\223\345\211\215\346\226\207\344\273\266", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        savefile_Action->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        saveotherfile_Action->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272(A)", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        saveotherfile_Action->setStatusTip(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        print_Action->setText(QApplication::translate("MainWindow", "\346\211\223\345\215\260(P)", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        print_Action->setStatusTip(QApplication::translate("MainWindow", "\346\211\223\345\215\260", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        print_Action->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        printandvisit_Action->setText(QApplication::translate("MainWindow", "\346\211\223\345\215\260\351\242\204\350\247\210", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        printandvisit_Action->setStatusTip(QApplication::translate("MainWindow", "\346\211\223\345\215\260\351\242\204\350\247\210", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        exit_Action->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        exit_Action->setStatusTip(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        back_Action->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200(U)", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        back_Action->setStatusTip(QApplication::translate("MainWindow", "\346\222\244\351\224\200", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        back_Action->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_SHORTCUT
        back_Action->setShortcut(QApplication::translate("MainWindow", "Ctrl+U", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        redo_Action->setText(QApplication::translate("MainWindow", "\351\207\215\345\201\232(R)", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        redo_Action->setStatusTip(QApplication::translate("MainWindow", "\351\207\215\345\201\232", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        redo_Action->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        cut_Action->setText(QApplication::translate("MainWindow", "\345\211\252\345\210\207(T)", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        cut_Action->setStatusTip(QApplication::translate("MainWindow", "\345\211\252\345\210\207", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        cut_Action->setShortcut(QApplication::translate("MainWindow", "Ctrl+T", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        copy_Action->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266(C)", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        copy_Action->setStatusTip(QApplication::translate("MainWindow", "\345\244\215\345\210\266", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        copy_Action->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        paste_Action->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264(P)", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        paste_Action->setStatusTip(QApplication::translate("MainWindow", "\347\262\230\350\264\264", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        paste_Action->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        bold_Action->setText(QApplication::translate("MainWindow", "\345\212\240\347\262\227(B)", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        bold_Action->setStatusTip(QApplication::translate("MainWindow", "\345\212\240\347\262\227", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        bold_Action->setShortcut(QApplication::translate("MainWindow", "Ctrl+B", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        italy_Action->setText(QApplication::translate("MainWindow", "\345\200\276\346\226\234(I)", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        italy_Action->setStatusTip(QApplication::translate("MainWindow", "\345\200\276\346\226\234", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        italy_Action->setShortcut(QApplication::translate("MainWindow", "Ctrl+I", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        underline_Action->setText(QApplication::translate("MainWindow", "\344\270\213\345\210\222\347\272\277(U)", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        underline_Action->setStatusTip(QApplication::translate("MainWindow", "\344\270\213\345\210\222\347\272\277", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        underline_Action->setShortcut(QApplication::translate("MainWindow", "Ctrl+U", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        LeftAlign_Action->setText(QApplication::translate("MainWindow", "\345\267\246\345\257\271\351\275\220(L)", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        LeftAlign_Action->setStatusTip(QApplication::translate("MainWindow", "\345\267\246\345\257\271\351\275\220", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        LeftAlign_Action->setShortcut(QApplication::translate("MainWindow", "Ctrl+L", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        centerAlign_Action->setText(QApplication::translate("MainWindow", "\345\261\205\344\270\255(C)", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        centerAlign_Action->setStatusTip(QApplication::translate("MainWindow", "\345\261\205\344\270\255", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        centerAlign_Action->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        rightAlign_Action->setText(QApplication::translate("MainWindow", "\345\217\263\345\257\271\351\275\220(R)", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        rightAlign_Action->setStatusTip(QApplication::translate("MainWindow", "\345\217\263\345\257\271\351\275\220", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        close_Action->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255(O)", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        close_Action->setStatusTip(QApplication::translate("MainWindow", "\345\205\263\351\227\255\345\275\223\345\211\215\347\252\227\345\217\243", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        closeAll_Action->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\346\211\200\346\234\211(A)", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        closeAll_Action->setStatusTip(QApplication::translate("MainWindow", "\345\205\263\351\227\255\346\211\200\346\234\211\347\252\227\345\217\243", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        title_Action->setText(QApplication::translate("MainWindow", "\345\271\263\351\223\272(T)", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        title_Action->setStatusTip(QApplication::translate("MainWindow", "\345\271\263\351\223\272", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        casecde_Action_2->setText(QApplication::translate("MainWindow", "\345\261\202\345\217\240(C)", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        casecde_Action_2->setStatusTip(QApplication::translate("MainWindow", "\345\261\202\345\217\240", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        next_Action->setText(QApplication::translate("MainWindow", "\344\270\213\344\270\200\344\270\252(X)", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        next_Action->setStatusTip(QApplication::translate("MainWindow", "\344\270\213\344\270\200\344\270\252\347\252\227\345\217\243", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        next_Action->setShortcut(QApplication::translate("MainWindow", "Ctrl+Tab", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        previous_Action->setText(QApplication::translate("MainWindow", "\345\211\215\344\270\200\344\270\252(V)", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        previous_Action->setStatusTip(QApplication::translate("MainWindow", "\345\211\215\344\270\200\344\270\252\347\252\227\345\217\243", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        previous_Action->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+Tab", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        about_Action->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216(A)", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        about_Action->setStatusTip(QApplication::translate("MainWindow", "\345\205\263\344\272\216", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        about_Action->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        justiceAlign_Action->setText(QApplication::translate("MainWindow", "\344\270\244\347\253\257\345\257\271\351\275\220(J)", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        justiceAlign_Action->setStatusTip(QApplication::translate("MainWindow", "\344\270\244\347\253\257\345\257\271\351\275\220", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        color_Action->setText(QApplication::translate("MainWindow", "\351\242\234\350\211\262(C)", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\240\207\345\207\206", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\351\241\271\347\233\256\347\254\246\345\217\267(\342\227\217)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\351\241\271\347\233\256\347\254\246\345\217\267(\342\227\246)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\351\241\271\347\233\256\347\254\246\345\217\267(\342\227\274)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\351\241\271\347\233\256\347\254\246\345\217\267(1,2,3)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\351\241\271\347\233\256\347\254\246\345\217\267(a,b,c)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\351\241\271\347\233\256\347\254\246\345\217\267(A,B,C)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\351\241\271\347\233\256\347\254\246\345\217\267(i,ii,iii)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\351\241\271\347\233\256\347\254\246\345\217\267(I,II,III)", Q_NULLPTR)
        );
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", Q_NULLPTR));
        menu_E->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221(&E)", Q_NULLPTR));
        menu_O->setTitle(QApplication::translate("MainWindow", "\346\240\274\345\274\217(&O)", Q_NULLPTR));
        menu_D->setTitle(QApplication::translate("MainWindow", "\345\255\227\344\275\223(D)", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\346\256\265\350\220\275", Q_NULLPTR));
        menu_W->setTitle(QApplication::translate("MainWindow", "\347\252\227\344\275\223(&W)", Q_NULLPTR));
        menu_H->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
