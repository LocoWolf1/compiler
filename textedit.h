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
#include <QTimer>




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
    ///@brief used to invoc updateText after a periord time
    QTimer time1;
    ///@brief time interval for update updateTime()
    int timeInterval;
private:
    QString wordAnalize(QString word);
public:
    explicit textEdit(QWidget *parent = 0);
    ///@brief the time period after that the updateTime is called
    int updateTimerInterval();
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
    //experimental
    ///@brief update the text color and detect mistakes
    void updateText();
    ///@brief set time interval used to updateText
    void setUpdateTextTimerInterval(int time);

};

#endif // TEXTEDIT_H
