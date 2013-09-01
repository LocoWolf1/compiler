#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class createxpresion;
}

class createExpresion : public QDialog
{
    Q_OBJECT
    
public:
    explicit createExpresion(QWidget *parent = 0);
    ~createExpresion();
private:
    int states;
    int elements;
    int **table;
private:
    Ui::createxpresion *ui;
private slots:
    void nStates(int);
    void nElements();
    void changeTableSize();    
    void createFile();
    void addToBase();
    void accept();
};

#endif // DIALOG_H
