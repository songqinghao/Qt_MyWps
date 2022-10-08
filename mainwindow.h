#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "childwnd.h"
#include<QCloseEvent>
#include<QSignalMapper>
#include<QMdiSubWindow>
#include<QtPrintSupport/QPrinter>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initWindow();
    void docNew();
    void docOpen();

    void docSave();
    void docSaveAs();

    void docUndo();
    void docRedo();
    void docCut();
    void docCopy();
    void docPaste();

    void textBold();
    void textItalic();
    void textUnderline();

    void textFamily(const QString& fmly);
    void textSize(const QString& ps);
    void paraStyle(int nStyle);

    void textColor();
    void docPrint();
    void docPrintPreview();
private slots:
    void on_newfile_Action_triggered();
    void refreshMenus();
    void addSubWndListMenu();
    void on_close_Action_triggered();

    void on_closeAll_Action_triggered();

    void on_title_Action_triggered();

    void on_casecde_Action_2_triggered();

    void on_next_Action_triggered();

    void on_previous_Action_triggered();

    void setActiveSubWindow(QWidget* wnd);
    void on_openfile_Action_triggered();

    void on_savefile_Action_triggered();

    void on_saveotherfile_Action_triggered();

    void on_back_Action_triggered();

    void on_redo_Action_triggered();

    void on_cut_Action_triggered();

    void on_copy_Action_triggered();

    void on_paste_Action_triggered();

    void on_bold_Action_triggered();

    void on_italy_Action_triggered();

    void on_underline_Action_triggered();

    void on_fontComboBox_activated(const QString &arg1);

    void on_sizeComBox_activated(const QString &arg1);

    void on_comboBox_activated(int index);

    void on_LeftAlign_Action_triggered();

    void on_rightAlign_Action_triggered();

    void on_centerAlign_Action_triggered();

    void on_justiceAlign_Action_triggered();

    void on_color_Action_triggered();

    void on_print_Action_triggered();

    void printPreview(QPrinter* printer);
    void on_printandvisit_Action_triggered();

protected:
    void closeEvent(QCloseEvent *event);
private:
    void formatEnable();
    ChildWnd* activateChildWnd();
    QMdiSubWindow* findChildWnd(const QString& docName);
private:
    Ui::MainWindow *ui;

    //一样的信号产生不一样的操作
    QSignalMapper* m_WndMapper;//信号映射器

};

#endif // MAINWINDOW_H
