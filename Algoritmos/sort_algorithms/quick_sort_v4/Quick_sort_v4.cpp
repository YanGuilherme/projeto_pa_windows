#include "Quick_sort_v4.h"
#include <cstdlib> // Para a função rand()

QuickSortV4::QuickSortV4() : Algoritmo("quick_sort_v4_pivo_aleatorio") {}

QuickSortV4::~QuickSortV4() {
}

void QuickSortV4::executar(DadosEntrada *entrada) {
    double inicio = getTempoAtual();
    quick_sort_v4(entrada->vector, 0, entrada->get_tamanho());
    double fim = getTempoAtual();
    duracao = fim - inicio;
}

int QuickSortV4::escolherPivoAleatorio(int inicio, int fim) {
    return rand() % (fim - inicio) + inicio;
}

void QuickSortV4::quick_sort_v4(int *entrada, int inicio, int fim) {
    if (inicio < fim) {
        int i, j, pivo, aux;

        int indicePivo = escolherPivoAleatorio(inicio, fim);
        pivo = entrada[indicePivo];

        i = inicio;
        j = fim - 1;

        while (i <= j) {
            while (entrada[i] < pivo && i < fim) {
                i++;
            }
            while (entrada[j] > pivo && j > inicio) {
                j--;
            }
            if (i <= j) {
                aux = entrada[i];
                entrada[i] = entrada[j];
                entrada[j] = aux;
                i++;
                j--;
            }
        }

        if (j > inicio)
            quick_sort_v4(entrada, inicio, j + 1);
        if (i < fim)
            quick_sort_v4(entrada, i, fim);
    }
}
