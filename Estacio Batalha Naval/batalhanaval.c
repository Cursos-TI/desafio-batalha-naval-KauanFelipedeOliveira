#include <stdio.h>

#define TAM 10     // Tamanho fixo do tabuleiro (10x10)
#define NAVIO 3    // Valor usado para representar um navio
#define TAMANHO_NAVIO 3 // Cada navio ocupa 3 posições

int main() {
    // ===============================
    // 1️⃣ Declaração e inicialização do tabuleiro
    // ===============================
    int tabuleiro[TAM][TAM];
    int i, j;

    // Preenche todo o tabuleiro com 0 (água)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ===============================
    // 2️⃣ Definição dos navios (vetores 1D)
    // ===============================
    int navioHorizontal[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};

    // ===============================
    // 3️⃣ Coordenadas iniciais dos navios
    // ===============================
    // OBS: As coordenadas são definidas diretamente no código.
    // Exemplo: o navio horizontal começa na linha 2, coluna 4.
    int linhaHorizontal = 2;
    int colunaHorizontal = 4;

    // O navio vertical começa na linha 5, coluna 7.
    int linhaVertical = 5;
    int colunaVertical = 7;

    // ===============================
    // 4️⃣ Posicionamento do navio horizontal no tabuleiro
    // ===============================
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        if (colunaHorizontal + i < TAM) { // garante que não sai do tabuleiro
            tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
        }
    }

    // ===============================
    // 5️⃣ Posicionamento do navio vertical no tabuleiro
    // ===============================
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        if (linhaVertical + i < TAM) { // garante que não sai do tabuleiro
            // Garante que não há sobreposição com o outro navio
            if (tabuleiro[linhaVertical + i][colunaVertical] == 0) {
                tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
            }
        }
    }

    // ===============================
    // 6️⃣ Exibição do tabuleiro
    // ===============================
    printf("=== TABULEIRO DE BATALHA NAVAL ===\n\n");

    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda: 0 = Água | 3 = Navio\n");

    return 0;
}
