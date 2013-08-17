#include "textedit.h"
#include <QAbstractSlider>
#include <iostream>
#include <QTimer>
#include <QTextCursor>

textEdit::textEdit(QWidget *parent) :
    QTextEdit(parent)
{
    //optain vertical and horizontal scroll bar poiters
    verticalScrollBar=QTextEdit::verticalScrollBar();
    horizontalScrollBar=QTextEdit::horizontalScrollBar();

    //optain the signal that is emited when the scroll bar position is changed and conect it to a slot who emit a useful signal.
    connect(verticalScrollBar,SIGNAL(valueChanged(int))
            ,this,SLOT(verticalScrollPosChange(int)));
    connect(horizontalScrollBar,SIGNAL(valueChanged(int))
            ,this,SLOT(horizontalScrollPosChange(int)));
    //optain the signal that is emited when the cursor position is changed and connect it to the cursorPositionChanged() slot
    connect(this,SIGNAL(cursorPositionChanged()),this,SLOT(cursorPositionChanged()));
    //connect time to updateTime
    connect(&time1,SIGNAL(timeout()),this,SLOT(updateText()));
    //asigne 1 segund (period)
    timeInterval=1000;
    //set timer interval to timer
    time1.setInterval(timeInterval);
    //start timer
    time1.start();
    //inicializa the line position
    linePos=-1;
}

void textEdit::verticalScrollPosChange(int pos) {
    //emit a signal equivalen to that the slot capture, but more useful
    emit verticalScrollMoved(pos);
}

void textEdit::horizontalScrollPosChange(int pos) {
    //emit a signal equivalen to that the slot capture, but more useful
    emit horizontalScrollMoved(pos);
}

void textEdit::cursorPositionChanged() {
    //avoid inecessary emits of sursorLineChanged
    if(linePos==textCursor().blockNumber())
        return;
    //update the line position
    linePos=textCursor().blockNumber();
    //emit a signal that is useful to know when the line is changed
    emit cursorLineChanged(linePos);
}


//experimental
void textEdit::updateText() {
    QString text=toPlainText();
    QString word;
    QString newText="<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\"><html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">p, li { white-space: pre-wrap; }</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\"><p  style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">";
    QTextCursor cursor=textCursor();

    for(int i=0;i<text.size();i++) {
        if(text[i]==' 'or text[i]=='(' or text[i]==')' or  text[i]==';' or text[i]=='{' or text[i]=='}'
                or text[i]=='\n') {
            newText+=wordAnalize(word);
            if(text[i]=='\n') {
                newText+="</p><p  style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">";
            }
            else
                        newText+=text[i];
            word.clear();
            continue;
        }
        word+=text[i];
    }
    setText(newText+word+"</p></body></html>");
    setTextCursor(cursor);
}

QString textEdit::wordAnalize(QString word) {
    QString variabls[11]={"void","virtual","int","static","char","long","struct"
                        "short","bool","float","double"};

    for(int i=0;i<11;i++) {
        if(variabls[i]==word) {
            QString tmp("<font color=\"red\">"+word+"</font>");
            return tmp;
        }
    }
    return word;
}

void textEdit::setUpdateTextTimerInterval(int time) {
    //set the time interval
    timeInterval=time;
    //apply the time interval
    time1.setInterval(timeInterval);
}

int textEdit::updateTimerInterval() {
    //return the time propiety
    return timeInterval;
}
