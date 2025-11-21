#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

void inicializar_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

int posicao_valida(int linha, int coluna) {
    return (linha >= 0 && linha < TAMANHO_TABULEIRO && 
            coluna >= 0 && coluna < TAMANHO_TABULEIRO);
}

int pode_posicionar_horizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                                int linha, int coluna_inicial) {
    if (coluna_inicial + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return 0;
    }
    
    for (int j = coluna_inicial; j < coluna_inicial + TAMANHO_NAVIO; j++) {
        if (tabuleiro[linha][j] != AGUA) {
            return 0;
        }
    }
    
    return 1;
}

int pode_posicionar_vertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                              int linha_inicial, int coluna) {
    if (linha_inicial + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return 0;
    }
    
    for (int i = linha_inicial; i < linha_inicial + TAMANHO_NAVIO; i++) {
        if (tabuleiro[i][coluna] != AGUA) {
            return 0;
        }
    }
    
    return 1;
}

void posicionar_navio_horizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                                  int linha, int coluna_inicial) {
    for (int j = coluna_inicial; j < coluna_inicial + TAMANHO_NAVIO; j++) {
        tabuleiro[linha][j] = NAVIO;
    }
}

void posicionar_navio_vertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                                int linha_inicial, int coluna) {
    for (int i = linha_inicial; i < linha_inicial + TAMANHO_NAVIO; i++) {
        tabuleiro[i][coluna] = NAVIO;
    }
}

void exibir_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n");
    printf("    0 1 2 3 4 5 6 7 8 9\n");
    printf("  +---------------------+\n");
    
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d | ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("|\n");
    }
    
    printf("  +---------------------+\n");
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    int navio_horizontal[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navio_vertical[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};
    
    int linha_h = 2;
    int coluna_h = 1;
    
    int linha_v = 5;
    int coluna_v = 7;
    
    printf("========================================\n");
    printf("      BATALHA NAVAL - NÍVEL NOVATO\n");
    printf("========================================\n");
    
    inicializar_tabuleiro(tabuleiro);
    
    printf("\nPosicionando navios...\n");
    
    if (pode_posicionar_horizontal(tabuleiro, linha_h, coluna_h)) {
        posicionar_navio_horizontal(tabuleiro, linha_h, coluna_h);
        printf("Navio horizontal posicionado na linha %d, colunas %d-%d\n", 
               linha_h, coluna_h, coluna_h + TAMANHO_NAVIO - 1);
    } else {
        printf("ERRO: Não foi possível posicionar o navio horizontal!\n");
        return 1;
    }
    
    if (pode_posicionar_vertical(tabuleiro, linha_v, coluna_v)) {
        posicionar_navio_vertical(tabuleiro, linha_v, coluna_v);
        printf("Navio vertical posicionado na coluna %d, linhas %d-%d\n", 
               coluna_v, linha_v, linha_v + TAMANHO_NAVIO - 1);
    } else {
        printf("ERRO: Não foi possível posicionar o navio vertical!\n");
        return 1;
    }
    
    printf("\n========================================\n");
    printf("         TABULEIRO FINAL\n");
    printf("========================================\n");
    printf("\nLegenda: 0 = Água | 3 = Navio\n");
    
    exibir_tabuleiro(tabuleiro);
    
    printf("\n========================================\n");
    printf("     NAVIOS POSICIONADOS COM SUCESSO!\n");
    printf("========================================\n");
    
    return 0;
}