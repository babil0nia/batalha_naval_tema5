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

int pode_posicionar_diagonal_principal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                                        int linha_inicial, int coluna_inicial) {
    if (linha_inicial + TAMANHO_NAVIO > TAMANHO_TABULEIRO || 
        coluna_inicial + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return 0;
    }
    
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha_inicial + i][coluna_inicial + i] != AGUA) {
            return 0;
        }
    }
    
    return 1;
}

int pode_posicionar_diagonal_secundaria(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                                         int linha_inicial, int coluna_inicial) {
    if (linha_inicial + TAMANHO_NAVIO > TAMANHO_TABULEIRO || 
        coluna_inicial - TAMANHO_NAVIO + 1 < 0) {
        return 0;
    }
    
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha_inicial + i][coluna_inicial - i] != AGUA) {
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

void posicionar_navio_diagonal_principal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                                          int linha_inicial, int coluna_inicial) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_inicial + i][coluna_inicial + i] = NAVIO;
    }
}

void posicionar_navio_diagonal_secundaria(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                                           int linha_inicial, int coluna_inicial) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_inicial + i][coluna_inicial - i] = NAVIO;
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
    
    int linha_h = 2;
    int coluna_h = 1;
    
    int linha_v = 0;
    int coluna_v = 7;
    
    int linha_d1 = 5;
    int coluna_d1 = 1;
    
    int linha_d2 = 6;
    int coluna_d2 = 8;
    
    printf("========================================\n");
    printf("    BATALHA NAVAL - NÍVEL AVENTUREIRO\n");
    printf("========================================\n");
    
    inicializar_tabuleiro(tabuleiro);
    
    printf("\nPosicionando 4 navios...\n");
    printf("----------------------------------------\n");
    
    if (pode_posicionar_horizontal(tabuleiro, linha_h, coluna_h)) {
        posicionar_navio_horizontal(tabuleiro, linha_h, coluna_h);
        printf("✓ Navio 1 (Horizontal): linha %d, colunas %d-%d\n", 
               linha_h, coluna_h, coluna_h + TAMANHO_NAVIO - 1);
    } else {
        printf("✗ ERRO: Não foi possível posicionar navio horizontal!\n");
        return 1;
    }
    
    if (pode_posicionar_vertical(tabuleiro, linha_v, coluna_v)) {
        posicionar_navio_vertical(tabuleiro, linha_v, coluna_v);
        printf("✓ Navio 2 (Vertical): coluna %d, linhas %d-%d\n", 
               coluna_v, linha_v, linha_v + TAMANHO_NAVIO - 1);
    } else {
        printf("✗ ERRO: Não foi possível posicionar navio vertical!\n");
        return 1;
    }
    
    if (pode_posicionar_diagonal_principal(tabuleiro, linha_d1, coluna_d1)) {
        posicionar_navio_diagonal_principal(tabuleiro, linha_d1, coluna_d1);
        printf("✓ Navio 3 (Diagonal \\): início (%d,%d), fim (%d,%d)\n", 
               linha_d1, coluna_d1, 
               linha_d1 + TAMANHO_NAVIO - 1, coluna_d1 + TAMANHO_NAVIO - 1);
    } else {
        printf("✗ ERRO: Não foi possível posicionar navio diagonal principal!\n");
        return 1;
    }
    
    if (pode_posicionar_diagonal_secundaria(tabuleiro, linha_d2, coluna_d2)) {
        posicionar_navio_diagonal_secundaria(tabuleiro, linha_d2, coluna_d2);
        printf("✓ Navio 4 (Diagonal /): início (%d,%d), fim (%d,%d)\n", 
               linha_d2, coluna_d2, 
               linha_d2 + TAMANHO_NAVIO - 1, coluna_d2 - TAMANHO_NAVIO + 1);
    } else {
        printf("✗ ERRO: Não foi possível posicionar navio diagonal secundária!\n");
        return 1;
    }
    
    printf("\n========================================\n");
    printf("         TABULEIRO COMPLETO\n");
    printf("========================================\n");
    printf("\nLegenda: 0 = Água | 3 = Navio\n");
    
    exibir_tabuleiro(tabuleiro);
    
    printf("\n========================================\n");
    printf("    4 NAVIOS POSICIONADOS COM SUCESSO!\n");
    printf("========================================\n");
    
    return 0;
}