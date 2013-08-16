#include "textedit.h"
#include <QAbstractSlider>
#include <iostream>

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
    std::cout<<"hola"<<std::endl;
}
