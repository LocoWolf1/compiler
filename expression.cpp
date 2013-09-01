#include "expression.h"
#include <fstream>
#include <iostream>

expression::expression()
{
    int num;
    short *id;
    std::string *str;
    std::string *file;
    std::ifstream in("base.txt");
    in>>num;
    str=new std::string[num];
    file=new std::string[num];
    id=new short[num];
    for(int i=0;i<num;i++) {
        in>>str[i];
        in>>id[i];
        in>>file[i];
    }
    in.close();
    for(int i=0;i<num;i++) {
        in.open(str[i].c_str());
        express tmp;
        in>>tmp.nSymbols;
        in>>tmp.nStates;
        in>>tmp.type;
        tmp.symbols=new char[tmp.nSymbols];
        for(int i=0;i<tmp.nSymbols;i++) {
            in>>tmp.symbols[i];
        }
        tmp.table=new char**[tmp.nSymbols];
        for(int i=0;i<tmp.nSymbols;i++) {
            tmp.table[i]=new char*[tmp.nStates];
            for(int j=0;j<tmp.nStates;j++)
                tmp.table[i][j]=new char[2];
        }
        char trash;
        for(int i=0;i<tmp.nSymbols;i++) {
            for(int j=0;j<tmp.nStates;j++) {
                in>>tmp.table[i][j][0];
            }
            in>>trash;
        }
        for(int i=0;i<tmp.nSymbols;i++) {
            for(int j=0;j<tmp.nStates;j++) {
                in>>tmp.table[i][j][1];
            }
            in>>trash;
        }
        tmp.extra=NULL;
        in.close();
    }
}
