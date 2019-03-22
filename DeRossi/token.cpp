/////////////////////////////////////////////////////////////////////
//
// Laboratorio 4: calcolo di semplici espressioni numeriche
//                mediante pile e code
//
// vengono accettati dall'esterno solo numeri positivi.
// Per trattare anche numeri negativi occorre modificare
// l'analizzatore lessicale.
//
///////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

#include "token.h"

using std::cout;
using std::cin;
using std::string;
using std::istringstream;
using std::ostringstream;

/////////////////////////////////////////////////////////////////////
// Funzioni ausiliarie su tipi di dato semplici
/////////////////////////////////////////////////////////////////////

// da stringa a numero
int str2int(const string &s){
    int n;
    istringstream itmp(s);
    itmp >> n;
    return n;
}

// da numero a stringa
string int2str(int n){
    string s;
    ostringstream otmp;
    otmp << n;
    s = otmp.str();
    return s;
};


// ritorna false se e solo se token di tipo sconosciuto o se stringa vuota.
// se stringa non vuota, la stringa perde il pezzo iniziale,
// che diventa token.

bool prossimoToken(string &s, token &t){
    if(s.length() == 0){
        return false;
    }
    istringstream iss(s);
    iss >> t.val;
    if(t.val[0] >= '0' && t.val[0] <= '9'){
        t.k = NUMERO;
        string c = int2str(str2int(t.val));
        if(t.val.compare(c.c_str()) != 0){
            t.k = SCONOSCIUTO;
        }
    }else{
        switch(t.val[0]){
            case '(':{
                t.k = PARENTESI_APERTA;
                break;
            }
            case ')':{
                t.k = PARENTESI_CHIUSA;
                break;
            }
            case '+':{
                t.k = OP_SOMMA;
                break;
            }
            case '-':{
                t.k = OP_SOTTRAZIONE;
                break;
            }
            case '*':{
                t.k = OP_MOLTIPLICAZIONE;
                break;
            }
            default:{ t.k = SCONOSCIUTO; }
        }
        if (t.val.length() > 1) {
            t.k = SCONOSCIUTO;
        }
    }
    if (t.val.length() + 1 > s.length())
        s = "";
    else
        s = s.substr(t.val.length() + 1);
    return t.k != SCONOSCIUTO;
}
