#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "childwnd.h"
#include<QWidget>
#include<QMdiSubWindow>
#include<QFileDialog>
#include<QColorDialog>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include<QtPrintSupport/QPrintPreviewDialog>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initWindow()
{
    this->setWindowTitle("我的WPS");
    //初始化字号列表
    QFontDatabase fontdb;
    //fontdb.standardSize:返回字号链表，存的都是int型
    foreach(int fontsize,fontdb.standardSizes()){
        //conbox的项存储的都是QString类型
        ui->sizeComBox->addItem(QString::number(fontsize));
    }

    //开始默认的字号
    QFont defFont;     //保存当前应用程序默认的字体
    QString sFontSize;
    int defFontSize;   //当前应用程序默认的字号
    int defFontindex;  //字体在组合框中的索引号
    defFont=QApplication::font();   //返回当前应用的字号

    defFontSize=defFont.pointSize();
    sFontSize=QString::number(defFontSize);
    //查找文本，返回索引位置
    defFontindex=ui->sizeComBox->findText(sFontSize);
    //设置当前索引号
    ui->sizeComBox->setCurrentIndex(defFontindex);

    //水平滚动条，根据需要设置
    ui->mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    //垂直滚动条,感觉需要设置
    ui->mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    refreshMenus();
    //有活动子窗口的信号就调用refreshMenus
    connect(ui->mdiArea,&QMdiArea::subWindowActivated,
            this,&MainWindow::refreshMenus);
    addSubWndListMenu();
    //点击菜单，触发增加子窗口列表菜单
    connect(ui->menu_W,&QMenu::aboutToShow,
            this,addSubWndListMenu);


    //初始化信号映射器
    m_WndMapper=new QSignalMapper(this);

    //产生信号，把对应窗口设置为活动窗口，把QWidget*的参数带过去
    connect(m_WndMapper,SIGNAL(mapped(QWidget*)),
            this,SLOT(setActiveSubWindow(QWidget*)));


    //把段落对齐放在一个分组中，保持互斥性，一次只能选中一种
    QActionGroup *alignGroup=new QActionGroup(this);
    alignGroup->addAction(ui->LeftAlign_Action);
    alignGroup->addAction(ui->rightAlign_Action);
    alignGroup->addAction(ui->centerAlign_Action);
    alignGroup->addAction(ui->justiceAlign_Action);


}


void MainWindow::docNew()
{

    ChildWnd* childWnd=new ChildWnd();
    ui->mdiArea->addSubWindow(childWnd);//添加子窗口

    //当文档的复制信号有用的时候我们主窗口中的剪切和复制就可以用
    connect(childWnd,SIGNAL(copyAvailable(bool)),
            ui->cut_Action,SLOT(setEnabled(bool)));

    connect(childWnd,SIGNAL(copyAvailable(bool)),
            ui->copy_Action,SLOT(setEnabled(bool)));

    childWnd->newDoc();
    childWnd->show();

    formatEnable();
}

//实现打开文档的实现
void MainWindow::docOpen()
{

    QString docName=QFileDialog::getOpenFileName(this,"打开文档","","文本文件(*.txt);;"
                                                "HTML文件(*.html *.htm);;"
                                                "所有文件(*.*)");
    //查找看是否已经打开过了，看是否在当前的子窗体中存在了
    if(!docName.isEmpty()){
        QMdiSubWindow *existed=findChildWnd(docName);
        if(existed){//如果存在就把已存在的哪个子窗体设置为活动窗体
            ui->mdiArea->setActiveSubWindow(existed);
        }else{
            ChildWnd *childWnd=new ChildWnd;
            ui->mdiArea->addSubWindow(childWnd);

            connect(childWnd,SIGNAL(copyAvailable(bool)),
                    ui->cut_Action,SLOT(setEnabled(bool)));

            connect(childWnd,SIGNAL(copyAvailable(bool)),
                    ui->copy_Action,SLOT(setEnabled(bool)));

            if(childWnd->loadDoc(docName)){
                //状态栏提示
                statusBar()->showMessage("文档已打开",3000);
                childWnd->show();
                formatEnable();
            }else{
                childWnd->close();
            }
        }
    }
}

void MainWindow::docSave()
{
    if(activateChildWnd()&&activateChildWnd()->saveDoc()){
        statusBar()->showMessage("文件保存成功",3000);
    }
}

void MainWindow::docSaveAs()
{
    if(activateChildWnd()&&activateChildWnd()->saveAsDoc()){
        statusBar()->showMessage("文件保存成功",3000);
    }
}

void MainWindow::docUndo()
{
    if(activateChildWnd()){
       activateChildWnd()->undo();
    }
}

void MainWindow::docRedo()
{
    if(activateChildWnd()){
       activateChildWnd()->redo();
    }
}

void MainWindow::docCut()
{
    if(activateChildWnd()){
       activateChildWnd()->cut();
    }
}

void MainWindow::docCopy()
{
    if(activateChildWnd()){
       activateChildWnd()->copy();
    }
}

void MainWindow::docPaste()
{
    if(activateChildWnd()){
        activateChildWnd()->paste();     }
}

void MainWindow::textBold()
{
    QTextCharFormat fmt;
    //是否由选中加粗按钮，如果由就加粗没有的话就普通
    fmt.setFontWeight(ui->bold_Action->isChecked()?QFont::Bold:QFont::Normal);
    if(activateChildWnd()){
        activateChildWnd()->setFormatOnSelectedWord(fmt);
    }
}

void MainWindow::textItalic()
{
    QTextCharFormat fmt;
    fmt.setFontItalic(ui->italy_Action->isChecked());
    if(activateChildWnd())
        activateChildWnd()->setFormatOnSelectedWord(fmt);

}

void MainWindow::textUnderline()
{
    QTextCharFormat fmt;
    fmt.setFontUnderline(ui->underline_Action->isChecked());
    if(activateChildWnd())
        activateChildWnd()->setFormatOnSelectedWord(fmt);

}

void MainWindow::textFamily(const QString &fmly)
{
    QTextCharFormat fmt;
    fmt.setFontFamily(fmly);
    if(activateChildWnd()){
        activateChildWnd()->setFormatOnSelectedWord(fmt);
    }
}

void MainWindow::textSize(const QString &ps)
{
    //浮点类型double
    qreal pointSize=ps.toFloat();
    if(pointSize>0){
        QTextCharFormat fmt;
        fmt.setFontPointSize(pointSize);
        if(activateChildWnd()){
            activateChildWnd()->setFormatOnSelectedWord(fmt);
        }
    }
}

void MainWindow::paraStyle(int nStyle)
{
    if(activateChildWnd())
    {
        activateChildWnd()->setParaSyle(nStyle);
    }
}

void MainWindow::textColor()
{
    if(activateChildWnd()){
        QColor color=QColorDialog::getColor(activateChildWnd()->textColor(),this);
        if(!color.isValid())return;
        QTextCharFormat fmt;
        fmt.setForeground(color);
        activateChildWnd()->setFormatOnSelectedWord(fmt);

        QPixmap pix(16,16);
        pix.fill(color);
        ui->color_Action->setIcon(pix);
    }
}

void MainWindow::docPrint()
{
    QPrinter pter(QPrinter::HighResolution);//像素为打印机指定的像素
    QPrintDialog* ddlg=new QPrintDialog(&pter,this);
    if(activateChildWnd()){
        //根据用户选择
        ddlg->setOption(QAbstractPrintDialog::PrintSelection,true);//保留用户打印的设置
        ddlg->setWindowTitle("打印文档");

        ChildWnd* childWnd=activateChildWnd();
        if(ddlg->exec()==QDialog::Accepted){
            childWnd->print(&pter);//参数就是打印机
        }
        delete ddlg;
    }
}

void MainWindow::docPrintPreview()
{
    QPrinter pter;
    QPrintPreviewDialog preview(&pter,this);
    connect(&preview,SIGNAL(paintRequested(QPrinter*)),
            this,SLOT(printPreview(QPrinter*)));
    preview.exec();
}

void MainWindow::formatEnable()
{
    ui->bold_Action->setEnabled(true);
    ui->italy_Action->setEnabled(true);
    ui->underline_Action->setEnabled(true);
    ui->LeftAlign_Action->setEnabled(true);
    ui->centerAlign_Action->setEnabled(true);
    ui->rightAlign_Action->setEnabled(true);
    ui->justiceAlign_Action->setEnabled(true);
    ui->color_Action->setEnabled(true);

}

ChildWnd *MainWindow::activateChildWnd()
{
    QMdiSubWindow* actWnd=ui->mdiArea->activeSubWindow();//返回活动子窗口
    if(actWnd){
        return qobject_cast<ChildWnd*>(actWnd->widget());
    }else{
        return 0;
    }
}

QMdiSubWindow *MainWindow::findChildWnd(const QString &docName)
{
    //标准的文件路径
    QString strFile=QFileInfo(docName).canonicalFilePath();
    foreach(QMdiSubWindow* subWnd,ui->mdiArea->subWindowList()){
        //先转换成我们自己的子窗口类型
        ChildWnd* childWnd=qobject_cast<ChildWnd*>(subWnd->widget());
        if(childWnd->m_CurDocPath==strFile)return subWnd;//找到了
    }

    return 0;
}

void MainWindow::on_newfile_Action_triggered()
{
    docNew();
}


void MainWindow::refreshMenus()
{
    bool hasChild;
    hasChild=(activateChildWnd() != 0);

    ui->savefile_Action->setEnabled(hasChild);
    ui->saveotherfile_Action->setEnabled(hasChild);
    ui->print_Action->setEnabled(hasChild);
    ui->printandvisit_Action->setEnabled(hasChild);
    ui->paste_Action->setEnabled(hasChild);
    ui->close_Action->setEnabled(hasChild);
    ui->closeAll_Action->setEnabled(hasChild);
    ui->title_Action->setEnabled(hasChild);
    ui->casecde_Action_2->setEnabled(hasChild);
    ui->next_Action->setEnabled(hasChild);
    ui->previous_Action->setEnabled(hasChild);

    //用户当前有没有选中文本，存在活动子窗口而且有内容给选中
    bool hasSelect=(activateChildWnd()&&
                    (activateChildWnd()->textCursor().hasSelection()));
    ui->cut_Action->setEnabled(hasSelect);
    ui->copy_Action->setEnabled(hasSelect);
    ui->bold_Action->setEnabled(hasSelect);
    ui->italy_Action->setEnabled(hasSelect);
    ui->underline_Action->setEnabled(hasSelect);
    ui->LeftAlign_Action->setEnabled(hasSelect);
    ui->rightAlign_Action->setEnabled(hasSelect);
    ui->centerAlign_Action->setEnabled(hasSelect);
    ui->justiceAlign_Action->setEnabled(hasSelect);
    ui->color_Action->setEnabled(hasSelect);

    qDebug()<<hasSelect;
}

void MainWindow::addSubWndListMenu()
{
    //先进行清空
    ui->menu_W->clear();
    ui->menu_W->addAction(ui->close_Action);
    ui->menu_W->addAction(ui->closeAll_Action);
    ui->menu_W->addSeparator();
    ui->menu_W->addAction(ui->title_Action);
    ui->menu_W->addAction(ui->casecde_Action_2);
    ui->menu_W->addSeparator();
    ui->menu_W->addAction(ui->next_Action);
    ui->menu_W->addAction(ui->previous_Action);

    QList<QMdiSubWindow*>wnds=ui->mdiArea->subWindowList();
    if(!wnds.isEmpty()){
        ui->menu_W->addSeparator();
    }

    for(int i=0;i<wnds.size();i++){
        ChildWnd* childWnd=qobject_cast<ChildWnd*>(wnds.at(i)->widget());
        QString menuitem_text;
        menuitem_text=QString("%1 %2").arg(i+1).arg(childWnd->getCurDocName());

        //返回刚刚添加的菜单项
        QAction* menuitem_act=ui->menu_W->addAction(menuitem_text);

        //如果返回的这个菜单项又是活动窗口
        menuitem_act->setCheckable(true);
        menuitem_act->setChecked(childWnd==activateChildWnd());

        //和菜单联系起来
        //如果我们添加的菜单给点击了，那么我们就用我们的信号映射器来相应它
        connect(menuitem_act,SIGNAL(triggered(bool)),
                m_WndMapper,SLOT(map()));

        m_WndMapper->setMapping(menuitem_act,wnds.at(i));//添加一个信号，信号发送者是谁
    }
    formatEnable();
}

void MainWindow::on_close_Action_triggered()
{
   //关闭活动子窗口
   ui->mdiArea->closeActiveSubWindow();
}

void MainWindow::on_closeAll_Action_triggered()
{
    ui->mdiArea->closeAllSubWindows();
}

//平铺
void MainWindow::on_title_Action_triggered()
{
    ui->mdiArea->tileSubWindows();
}



void MainWindow::on_next_Action_triggered()
{
    ui->mdiArea->activateNextSubWindow();
}

void MainWindow::on_previous_Action_triggered()
{
    ui->mdiArea->activatePreviousSubWindow();
}

void MainWindow::setActiveSubWindow(QWidget *wnd)
{
    if(!wnd)return;
    ui->mdiArea->setActiveSubWindow(qobject_cast<QMdiSubWindow*>(wnd));
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    ui->mdiArea->closeAllSubWindows();
    if(ui->mdiArea->currentSubWindow()){
        event->ignore();//忽略此事件
    }else{
        event->accept();
    }
}

void MainWindow::on_casecde_Action_2_triggered()
{
    ui->mdiArea->cascadeSubWindows();
}

//打开文档
void MainWindow::on_openfile_Action_triggered()
{
    docOpen();
}

void MainWindow::on_savefile_Action_triggered()
{
    docSave();
}

void MainWindow::on_saveotherfile_Action_triggered()
{
    docSaveAs();
}

void MainWindow::on_back_Action_triggered()
{
    docUndo();
}

void MainWindow::on_redo_Action_triggered()
{
    docRedo();
}

void MainWindow::on_cut_Action_triggered()
{
    docCut();
}

void MainWindow::on_copy_Action_triggered()
{
    docCopy();
}

void MainWindow::on_paste_Action_triggered()
{
    docPaste();
}

void MainWindow::on_bold_Action_triggered()
{
    textBold();
}

void MainWindow::on_italy_Action_triggered()
{
    textItalic();
}

void MainWindow::on_underline_Action_triggered()
{
    textUnderline();
}

void MainWindow::on_fontComboBox_activated(const QString &arg1)
{
    textFamily(arg1);
}

void MainWindow::on_sizeComBox_activated(const QString &arg1)
{
    textSize(arg1);
}

void MainWindow::on_comboBox_activated(int index)
{
    paraStyle(index);
}

void MainWindow::on_LeftAlign_Action_triggered()
{
    if(activateChildWnd()){
        activateChildWnd()->setAlignOfDocumentText(1);
    }
}

void MainWindow::on_rightAlign_Action_triggered()
{
    if(activateChildWnd()){
        activateChildWnd()->setAlignOfDocumentText(2);
    }
}

void MainWindow::on_centerAlign_Action_triggered()
{
    if(activateChildWnd()){
        activateChildWnd()->setAlignOfDocumentText(3);
    }
}

void MainWindow::on_justiceAlign_Action_triggered()
{
    if(activateChildWnd()){
        activateChildWnd()->setAlignOfDocumentText(4);
    }
}

void MainWindow::on_color_Action_triggered()
{
    textColor();
}

void MainWindow::on_print_Action_triggered()
{
    docPrint();
}

void MainWindow::printPreview(QPrinter *printer)
{
    activateChildWnd()->print(printer);
}

void MainWindow::on_printandvisit_Action_triggered()
{
    docPrintPreview();
}
