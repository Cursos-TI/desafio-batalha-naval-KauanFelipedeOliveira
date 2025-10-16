#include <stdio.h>

#define TAM 10   // Tamanho do tabuleiro (10x10)
#define NAVIO 3  // Valor que representa uma parte do navio
#define TAM_NAVIO 3  // Tamanho fixo dos navios

// Função para inicializar o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para exibir o tabuleiro formatado
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n   ");
    for (int c = 0; c < TAM; c++) printf("%d ", c);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i); // índice da linha
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Verifica se o navio pode ser posicionado (sem sair dos limites ou sobrepor outro)
int podePosicionar(int tabuleiro[TAM][TAM], int linha, int coluna, int direcao, int diagonal) {
    for (int k = 0; k < TAM_NAVIO; k++) {
        int i = linha, j = coluna;

        // Escolhe direção com base nos parâmetros
        if (diagonal == 1) {         // diagonal principal ↘
            i += k;
            j += k;
        } else if (diagonal == 2) {  // diagonal secundária ↙
            i += k;
            j -= k;
        } else if (direcao == 0) {   // horizontal →
            j += k;
        } else {                     // vertical ↓
            i += k;
        }

        // Verifica se sai do tabuleiro
        if (i < 0 || i >= TAM || j < 0 || j >= TAM)
            return 0;

        // Verifica sobreposição
        if (tabuleiro[i][j] == NAVIO)
            return 0;
    }
    return 1; // pode posicionar
}

// Posiciona o navio se possível
void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int direcao, int diagonal) {
    if (!podePosicionar(tabuleiro, linha, coluna, direcao, diagonal)) {
        printf("Erro: não foi possível posicionar o navio em (%d,%d)\n", linha, coluna);
        return;
    }

    for (int k = 0; k < TAM_NAVIO; k++) {
        if (diagonal == 1)
            tabuleiro[linha + k][coluna + k] = NAVIO;      // diagonal principal ↘
        else if (diagonal == 2)
            tabuleiro[linha + k][coluna - k] = NAVIO;      // diagonal secundária ↙
        else if (direcao == 0)
            tabuleiro[linha][coluna + k] = NAVIO;          // horizontal →
        else
            tabuleiro[linha + k][coluna] = NAVIO;          // vertical ↓
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    // === POSICIONAMENTO DOS 4 NAVIOS ===
    // 1 - Horizontal (linha 2, col 1 → direita)
    posicionarNavio(tabuleiro, 2, 1, 0, 0);

    // 2 - Vertical (linha 0, col 7 ↓)
    posicionarNavio(tabuleiro, 0, 7, 1, 0);

    // 3 - Diagonal principal (↘) começando em (5,0)
    posicionarNavio(tabuleiro, 5, 0, 0, 1);

    // 4 - Diagonal secundária (↙) começando em (4,9)
    posicionarNavio(tabuleiro, 4, 9, 0, 2);

    // === EXIBIR TABULEIRO ===
    exibirTabuleiro(tabuleiro);

    return 0;
}
