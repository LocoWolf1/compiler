/**
  *@file textedit.h
  *@brief this header contain all required definitions about the textEdit class. This class is used
  *for the text edit part of the program
  *@author Aron Wolf
  *@date 15/8/2013
*/

#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QTextEdit>
#include <QScrollBar>

class textEdit : public QTextEdit
{
    Q_OBJECT
private:
    ///@brief the vertical scroll Bar of the text edit
    QScrollBar *verticalScrollBar;
    ///@brief the horizontal scroll Bar of the text edit
    QScrollBar *horizontalScrollBar;
    ///@brief it is used to now the last line position.
    int linePos;
public:
    explicit textEdit(QWidget *parent = 0);
signals:
    ///@brief signal that is emitted when the vertical scroll bar is changed
    void verticalScrollMoved(int);
    ///@brief signal that is emitted when the horizontal scroll bar is changed
    void horizontalScrollMoved(int);
    ///@brief Signal that is emitted when the cursor change to a other line
    void cursorLineChanged(int);
public slots:
    ///@brief used to optain and make a signal when the position os the vertical
    ///scroll bar change
    void verticalScrollPosChange(int);
    ///@brief used to optain and make a signal when the position os the horizontal
    ///scroll bar change
    void horizontalScrollPosChange(int pos);
    ///@brief cursor position
    void cursorPositionChanged();

};

#endif // TEXTEDIT_H
