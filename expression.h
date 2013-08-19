/**
  *@file exprecion.h
  *@brief this header contain all required definitions about the exprecion class and other classes and structres that it use.
  *@author Aron Wolf
  *@date 18/8/2013
*/

#ifndef EXPRECION_H
#define EXPRECION_H

#include <stack>
#include <vector>

///@brief the structre is used to safe all necesary information to analize a string with a regular expression
struct express {
    ///@brief in the table every colum is a state and every file a symbol. The third dimenci´on is used toknow the part of the exprecion who is used to form a new exprcion,this is idicated with a one
    char ***table;
    ///@brief the simbols of the exprecion, they have the same order that in the table
    char *symbols;
    ///@brief the number of states
    int nStates;
    ///@brief the number of symbols
    int nSymbols;
    /**@brief the type of exprecion:
     *6: indicate that the expression is nomral
     *5: indicate that the expression is like a if, for...
     *4: indicate that the expression is a declaration of a variabl
     *3: indicate that the expression is like a class or struct
     *2: indicate that the expression is like a declaration of a object o structure
     *1: indicate that the expression is a object o structure
     **/
    char type;
    ///@brief extra informations like method of classes
    void *extra;
    ///@brief of current states
    std::stack<int> st;
};

///@brief used to now if the variabls is from the same level.
struct variabl {
    ///@brief the name of variable
    char var;
    ///@brief the level of the variale
    int level;
};

///@brief used to make a variabls that can be used in a vector
typedef std::stack<variabl> varStack;

class expression
{
private:
    int level;
    std::vector<varStack> var;
public:
    expression();
};

#endif // EXPRECION_H
