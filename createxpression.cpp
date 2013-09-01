#include "createxpresion.h"
#include "ui_createxpresion.h"
#include <iostream>
#include <fstream>

createExpresion::createExpresion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createxpresion)
{
    ui->setupUi(this);
    //inicialize
    states=0;
    elements=0;
}

createExpresion::~createExpresion()
{
    delete ui;
}

void createExpresion::nStates(int num) {
    //set the number of states
    states=num;
    //change the table size
    changeTableSize();
}

void createExpresion::nElements() {
    //Check if the element is in use
    for(int i=0;i<ui->tableWidget->rowCount();i++) {
        if(ui->tableWidget->verticalHeaderItem(i)->text()==ui->plainTextEdit->toPlainText())
            return;
    }
    //Check if the new element is empty
    if(ui->plainTextEdit->toPlainText()=="")
        return;
    //Indicate that the number of elements is increased
    elements++;
    //create a new row
    QTableWidgetItem *item=new QTableWidgetItem(ui->plainTextEdit->toPlainText());
    //change the size of the table
    changeTableSize();
    //add the header
    ui->tableWidget->setVerticalHeaderItem(elements-1,item);
}

void createExpresion::changeTableSize() {
    //set the number of fcolums and rows
    ui->tableWidget->setColumnCount(states);
    ui->tableWidget->setRowCount(elements);
}

void createExpresion::createFile() {
    //create the file
    std::ofstream out(ui->lineEdit->text().toStdString().c_str());
    //introduce basic data: elements, states, type
    out<<elements<<" "<<states<<" "<<ui->comboBox->currentIndex()<<std::endl;
    //elements
    for(int i=0;i<ui->tableWidget->rowCount();i++) {
        out<<ui->tableWidget->verticalHeaderItem(i)->text().toStdString();
    }
    out<<std::endl;
    //the table
    for(int i=0;i<ui->tableWidget->columnCount();i++) {
        for(int j=0;j<ui->tableWidget->rowCount();j++) {
            if(ui->tableWidget->item(i,j)==0 or ui->tableWidget->item(i,j)->text()=="")
                out<<" ";
            else
                out<<ui->tableWidget->item(i,j)->text().toStdString();
        }
        out<<std::endl;
    }
    out.close();
}

void createExpresion::accept() {
    //create the file;
    createFile();
    addToBase();
    QDialog::accept();
}

void createExpresion::addToBase() {
    int tam=0;
    std::string *datName=NULL;
    int *datID=NULL;
    std::ifstream in("base");
    if(in.is_open()) {
        in>>tam;
        datName=new std::string[tam];
        datID=new int[tam];
        for(int i=0;i<tam;i++) {
            in>>datName[i];
            in>>datID[i];
        }
        in.close();
    }
    std::ofstream out("base");
    if(tam==0)
        out<<1<<std::endl;
    else
        out<<tam+1<<std::endl;
    for(int i=0;i<tam;i++) {
        out<<datName[i]<<" "<<datID[i]<<std::endl;
    }

    out<<ui->lineEdit->text().toStdString()<<" "<<ui->spinBox_2->value();
    out.close();
    delete[] datName;
    delete[] datID;
}
