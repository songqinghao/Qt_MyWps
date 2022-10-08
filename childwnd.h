#ifndef CHILDWND_H
#define CHILDWND_H
#include<QTextEdit>
#include<QCloseEvent>
class ChildWnd : public QTextEdit
{
    Q_OBJECT
public:
    ChildWnd();
    QString m_CurDocPath;                   //当前文档路径
    void newDoc();                          //新建文档
    bool loadDoc(const QString& docName);
    void setCurDoc(const QString& docName); //设置一些属性和标题
    QString getCurDocName();                //文档路径中提取文档名
    bool saveDoc();                         //保存文档
    bool saveAsDoc();                       //另存为
    bool saveDocOpt(QString docname);       //具体操作

    void setFormatOnSelectedWord(const QTextCharFormat& fmt);     //设置字体格式

    //设置对齐
    void setAlignOfDocumentText(int aligntype);
    //设置项目符号
    void setParaSyle(int pstyle);


protected:
    void closeEvent(QCloseEvent *event);
private:
    bool promptSave();
private slots:
    void docBeModified();                   //文档修改时，窗口的标题栏加个"*"
private:
    bool m_bSaved;                          //文档是否保存
};

#endif // CHILDWND_H
