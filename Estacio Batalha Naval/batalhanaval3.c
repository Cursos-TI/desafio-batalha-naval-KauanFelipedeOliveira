#include <stdio.h>

#define TAM 10       // Tamanho do tabuleiro
#define NAVIO 3      // Valor que representa um navio
#define HABILIDADE 5 // Valor que representa área afetada por habilidades
#define TAM_HAB 5    // Tamanho fixo das matrizes de habilidades (5x5)

// ----------------------------------------------------------
// Função: Inicializa o tabuleiro com 0 (água)
// ----------------------------------------------------------
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;
}

// ----------------------------------------------------------
// Função: Exibe o tabuleiro formatado
// ----------------------------------------------------------
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n   ");
    for (int c = 0; c < TAM; c++) printf("%d ", c);
    printf("\n");
    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0)
                printf("~ ");  // Água
            else if (tabuleiro[i][j] == NAVIO)
                printf("N ");  // Navio
            else if (tabuleiro[i][j] == HABILIDADE)
                printf("* ");  // Área de habilidade
        }
        printf("\n");
    }
}

// ----------------------------------------------------------
// Função: Cria uma matriz em formato de cone (5x5)
// ----------------------------------------------------------
void criarCone(int cone[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= (TAM_HAB/2 - i) && j <= (TAM_HAB/2 + i))
                cone[i][j] = 1; // dentro do cone
            else
                cone[i][j] = 0; // fora do cone
        }
    }
}

// ----------------------------------------------------------
// Função: Cria uma matriz em formato de cruz (5x5)
// ----------------------------------------------------------
void criarCruz(int cruz[TAM_HAB][TAM_HAB]) {
    int meio = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == meio || j == meio)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }
}

// ----------------------------------------------------------
// Função: Cria uma matriz em formato de octaedro (losango)
// ----------------------------------------------------------
void criarOctaedro(int octaedro[TAM_HAB][TAM_HAB]) {
    int meio = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(meio - i) + abs(meio - j) <= meio)
                octaedro[i][j] = 1; // dentro do losango
            else
                octaedro[i][j] = 0;
        }
    }
}

// ----------------------------------------------------------
// Função: Aplica a habilidade no tabuleiro
// ----------------------------------------------------------
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
    int meio = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (habilidade[i][j] == 1) {
                int linhaTab = origemLinha + (i - meio);
                int colunaTab = origemColuna + (j - meio);

                // Verifica limites do tabuleiro
                if (linhaTab >= 0 && linhaTab < TAM && colunaTab >= 0 && colunaTab < TAM) {
                    // Só marca se não tiver navio
                    if (tabuleiro[linhaTab][colunaTab] == 0)
                        tabuleiro[linhaTab][colunaTab] = HABILIDADE;
                }
            }
        }
    }
}

// ----------------------------------------------------------
// Função: Posiciona navios no tabuleiro
// ----------------------------------------------------------
void posicionarNavios(int tabuleiro[TAM][TAM]) {
    // Navio horizontal (tamanho 3)
    for (int j = 2; j < 5; j++)
        tabuleiro[1][j] = NAVIO;

    // Navio vertical (tamanho 3)
    for (int i = 5; i < 8; i++)
        tabuleiro[i][4] = NAVIO;
}

// ----------------------------------------------------------
// Função principal
// ----------------------------------------------------------
int main() {
    int tabuleiro[TAM][TAM];
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    // 1️⃣ Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // 2️⃣ Posiciona navios fixos
    posicionarNavios(tabuleiro);

    // 3️⃣ Cria habilidades especiais
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // 4️⃣ Define posições das habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 2, 2);       // Cone no canto superior esquerdo
    aplicarHabilidade(tabuleiro, cruz, 5, 7);       // Cruz no meio-direita
    aplicarHabilidade(tabuleiro, octaedro, 8, 3);   // Octaedro na parte inferior

    // 5️⃣ Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
