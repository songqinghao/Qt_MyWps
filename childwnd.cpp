#include "childwnd.h"
#include <QFileInfo>
#include<QFileDialog>
#include<QTextDocumentWriter>
#include<QMessageBox>
#include<QTextCursor>
#include<QTextBlockFormat>
#include<QTextListFormat>
#include<QtWidgets>
#include<QDebug>
ChildWnd::ChildWnd()
{
    //子窗口关闭时销毁该类的实例对象
    setAttribute(Qt::WA_DeleteOnClose);

    m_bSaved=false;
}

void ChildWnd::newDoc()
{
    //生命周期要长所以用static
    static int wndSeqNum=1;
    m_CurDocPath=QString("WPS 文档 %1").arg(wndSeqNum++);

    //设置窗口标题，文件改动后名称后加个"*"号标识
    setWindowTitle(m_CurDocPath+"[*]"+" - WPS");
    connect(document(),SIGNAL(contentsChanged()),
            this,SLOT(docBeModified()));


}

bool ChildWnd::loadDoc(const QString &docName)
{
    if(!docName.isEmpty()){
        QFile file(docName);
        if(!file.exists())return false;

        //只读类型
        if(!file.open(QFile::ReadOnly))return false;
        QByteArray text=file.readAll();
        if(Qt::mightBeRichText(text))//如果是富文本
            setHtml(text);  //设置为富文本
        else{
            setPlainText(text); //设置为纯文本
        }
        setCurDoc(docName);
        connect(document(),SIGNAL(contentsChanged()),
                this,SLOT(docBeModified()));
    }
    return true;
}

//设置一些属性和标题
void ChildWnd::setCurDoc(const QString &docName)
{
    //canonicalFilePath()返回标准名称路径，会过滤点". .."
    m_CurDocPath=QFileInfo(docName).canonicalFilePath();
    m_bSaved=true;  //文档已被保存
    document()->setModified(false); //设置成未改动
    setWindowModified(false);   //窗口标题不显示"*"这个改动标识
    setWindowTitle(getCurDocName()+"[*]");  //设置子窗口标题
}

QString ChildWnd::getCurDocName()
{
    return QFileInfo(m_CurDocPath).fileName();  //获取文件的名字
}

bool ChildWnd::saveDoc()
{
    //如果这个文档已经存在过
    if(m_bSaved)return saveDocOpt(m_CurDocPath);
    else{
        saveAsDoc();
    }
}

bool ChildWnd::saveAsDoc()
{
    //获取保存的文件名
    QString docName=QFileDialog::getSaveFileName(this,
                                 "另存为",
                                 m_CurDocPath,
                                 "HTML文档(*.html *.htm);;"
                                 "所有文件(*.*)");
    if(docName.isEmpty())return false;
    else{
        return saveDocOpt(docName);
    }
}

bool ChildWnd::saveDocOpt(QString docname)
{
    //判断我们的那个文档后缀是不是html
    if(!(docname.endsWith(".htm",Qt::CaseInsensitive)||
            docname.endsWith(".html",Qt::CaseInsensitive))){
        docname+=".html";
    }

    QTextDocumentWriter write(docname);
    bool isSuccess=write.write(this->document());//直接把该文件直接写入
    if(isSuccess)setCurDoc(docname);
    return isSuccess;

}

void ChildWnd::setFormatOnSelectedWord(const QTextCharFormat &fmt)
{
    QTextCursor tcursor=textCursor();
    //如果没选中操作
    if(!tcursor.hasSelection()){
        tcursor.select(QTextCursor::WordUnderCursor);//选中的字符串是在我们光标的选中范围下面
    }
    tcursor.mergeBlockCharFormat(fmt);//合并格式
    mergeCurrentCharFormat(fmt);//设置格式，可以暂时理解成刷新操作
}

void ChildWnd::setAlignOfDocumentText(int aligntype)
{
    if(aligntype==1){
        setAlignment(Qt::AlignLeft|Qt::AlignAbsolute);
    }else if(aligntype==2){
        setAlignment(Qt::AlignRight|Qt::AlignAbsolute);
    }else if(aligntype==3){
        setAlignment(Qt::AlignCenter|Qt::AlignAbsolute);
    }else if(aligntype==4){
        setAlignment(Qt::AlignJustify|Qt::AlignAbsolute);
    }
}

void ChildWnd::setParaSyle(int pstyle)
{
    QTextCursor tcursor=textCursor();
    QTextListFormat::Style sname;   //文本链表格式
    if(pstyle!=0){
        switch(pstyle){
        case 1:
            sname=QTextListFormat::ListDisc;//黑心实心圆
            break;
        case 2:
            sname=QTextListFormat::ListCircle;//空心圆
            break;
        case 3:
            sname=QTextListFormat::ListSquare;//方形
            break;
        case 4:
            sname=QTextListFormat::ListDecimal;//十进制整数
            break;
        case 5:
            sname=QTextListFormat::ListLowerAlpha;//小写字母
            break;
        case 6:
            sname=QTextListFormat::ListUpperAlpha;//大写字母
            break;
        case 7:
            sname=QTextListFormat::ListLowerRoman;//小写罗马
            break;
        case 8:
            sname=QTextListFormat::ListUpperRoman;//大写罗马
            break;
        default:
            sname=QTextListFormat::ListDisc;
            break;
        }
        //开始文本块的操作
        tcursor.beginEditBlock();
        //返回当前光标的文本块格式
        QTextBlockFormat tBlockFmt=tcursor.blockFormat();
        QTextListFormat tListFmt;
        if(tcursor.currentList()){
            tListFmt=tcursor.currentList()->format();
            //qDebug()<<"有链表格式";
        }else{
            //设置缩进为当前文本块的缩进+一个tab
            tListFmt.setIndent(tBlockFmt.indent()+1);
            //qDebug()<<tBlockFmt.indent();
            tBlockFmt.setIndent(0);
            tcursor.setBlockFormat(tBlockFmt);
        }

        tListFmt.setStyle(sname);
        tcursor.createList(tListFmt);

        tcursor.endEditBlock();
    }else{
        QTextBlockFormat tbfmt;
        tbfmt.setObjectIndex(-1);
        tcursor.mergeBlockFormat(tbfmt);
    }
}

void ChildWnd::closeEvent(QCloseEvent *event)
{
    if(promptSave()){
        event->accept();
    }else{
        event->ignore();
    }
}

bool ChildWnd::promptSave()
{
    //文档没进行修改
    if(!document()->isModified())return true;

    QMessageBox::StandardButton result;
    result=QMessageBox::warning(this,"系统提示",
                                QString("文档%1已修改，是否保存？").arg(getCurDocName()),
                                QMessageBox::Yes|
                                QMessageBox::Discard|
                                QMessageBox::No);

    if(result==QMessageBox::Yes){
        return saveDoc();
    }else if(result==QMessageBox::No){
        return false;
    }
    return true;

}

void ChildWnd::docBeModified()
{
    //qDebug()<<"触发修改信号！"<<endl;
    setWindowModified(document()->isModified());
}
