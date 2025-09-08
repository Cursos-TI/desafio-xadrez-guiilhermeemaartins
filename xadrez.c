#include <stdio.h>
#include <string.h>

// Definindo constantes para os movimentos, para maior legibilidade
#define CIMA "Cima\n"
#define BAIXO "Baixo\n"
#define ESQUERDA "Esquerda\n"
#define DIREITA "Direita\n"
#define CIMA_DIREITA "Cima e Direita\n"
#define CIMA_ESQUERDA "Cima e Esquerda\n"
#define BAIXO_DIREITA "Baixo e Direita\n"
#define BAIXO_ESQUERDA "Baixo e Esquerda\n"

// --- PROTÓTIPOS DAS FUNÇÕES RECURSIVAS ---
// Certifique-se de que não há a palavra 'static' aqui.
void moverTorre(int casas);
void moverBispo(int casas);
void moverRainha(int casas);

// --- FUNÇÃO PARA O MOVIMENTO DA TORRE (RECURSIVO) ---
// A Torre se move verticalmente ou horizontalmente.
void moverTorre(int casas) {
    // Caso base da recursão: se o número de casas for 0 ou menor, a função para.
    if (casas <= 0) {
        return;
    }
    // Lógica da recursão: imprime a direção e chama a si mesma com um número de casas decrementado.
    printf(DIREITA);
    moverTorre(casas - 1);
}

// --- FUNÇÃO PARA O MOVIMENTO DO BISPO (RECURSIVO COM LOOPS ANINHADOS) ---
// O Bispo se move na diagonal.
void moverBispo(int casas) {
    // O loop mais externo controla o movimento vertical
    for (int i = 0; i < casas; i++) {
        // O loop interno controla o movimento horizontal
        for (int j = 0; j < 1; j++) {
            // A lógica recursiva é acionada aqui para simular a progressão da diagonal
            // Caso base: se i ou j exceder as casas, a recursão para
            if (i > casas - 1) {
                return;
            }
            printf(CIMA_DIREITA);
        }
    }
    // A chamada recursiva continua a mover o bispo
    if (casas > 1) {
        moverBispo(casas - 1);
    }
}

// --- FUNÇÃO PARA O MOVIMENTO DA RAINHA (RECURSIVO) ---
// A Rainha combina os movimentos da Torre e do Bispo.
void moverRainha(int casas) {
    // Caso base da recursão
    if (casas <= 0) {
        return;
    }

    // Movimento da Torre
    printf(CIMA);

    // Movimento do Bispo
    printf(CIMA_ESQUERDA);

    // Chamada recursiva para continuar o movimento
    moverRainha(casas - 1);
}

// --- FUNÇÃO PRINCIPAL ---
int main() {
    int numCasas = 3; // Número de casas a serem movidas (constante para as peças recursivas)

    printf("--- Movimento da Torre ---\n");
    moverTorre(numCasas);
    printf("\n");

    printf("--- Movimento do Bispo ---\n");
    moverBispo(numCasas);
    printf("\n");

    printf("--- Movimento da Rainha ---\n");
    moverRainha(numCasas);
    printf("\n");

    printf("--- Movimento do Cavalo ---\n");
    // Loops aninhados para o Cavalo (2 casas para cima, 1 para a direita)
    int moveCima = 2;
    int moveDireita = 1;
    for (int i = 0; i < moveCima; i++) {
        for (int j = 0; j < moveDireita; j++) {
            // O primeiro loop controla as 2 casas para cima
            if (i < moveCima) {
                printf(CIMA);
                // O segundo loop controla a 1 casa para a direita
                if (j < moveDireita) {
                    printf(DIREITA);
                }
            }
            // Usa 'break' para sair do loop interno após um movimento completo
            break;
        }
    }
    printf("\n");

    return 0;
}