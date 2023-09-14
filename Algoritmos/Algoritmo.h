#ifndef ALGORITMO_H
#define ALGORITMO_H

#include <iostream>
#include <string>
using namespace std;
#include "../DadosEntrada.h"

class DadosEntrada;

class Algoritmo{
    public:
        Algoritmo(string);
        double duracao;
        virtual void ordenar(DadosEntrada *) = 0; // ;)
        ~Algoritmo(){}
        string nome;
        double getTempoAtual();
        void exibir_duracao(DadosEntrada);
};

#endif