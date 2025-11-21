#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

void inicializar_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

void inicializar_habilidade(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidade[i][j] = 0;
        }
    }
}

void criar_habilidade_cone(int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    inicializar_habilidade(cone);
    
    int centro = TAMANHO_HABILIDADE / 2;
    
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int largura = i + 1;
            int inicio = centro - i / 2;
            int fim = centro + i / 2;
            
            if (j >= inicio && j <= fim) {
                cone[i][j] = 1;
            }
        }
    }
}

void criar_habilidade_cruz(int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    inicializar_habilidade(cruz);
    
    int centro = TAMANHO_HABILIDADE / 2;
    
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == centro || j == centro) {
                cruz[i][j] = 1;
            }
        }
    }
}

void criar_habilidade_octaedro(int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    inicializar_habilidade(octaedro);
    
    int centro = TAMANHO_HABILIDADE / 2;
    
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int dist_vertical = (i > centro) ? (i - centro) : (centro - i);
            int dist_horizontal = (j > centro) ? (j - centro) : (centro - j);
            
            if (dist_vertical + dist_horizontal <= centro) {
                octaedro[i][j] = 1;
            }
        }
    }
}

void aplicar_habilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                        int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE],
                        int origem_linha, int origem_coluna) {
    int offset = TAMANHO_HABILIDADE / 2;
    
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                int tab_linha = origem_linha - offset + i;
                int tab_coluna = origem_coluna - offset + j;
                
                if (tab_linha >= 0 && tab_linha < TAMANHO_TABULEIRO &&
                    tab_coluna >= 0 && tab_coluna < TAMANHO_TABULEIRO) {
                    if (tabuleiro[tab_linha][tab_coluna] != NAVIO) {
                        tabuleiro[tab_linha][tab_coluna] = HABILIDADE;
                    }
                }
            }
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

void exibir_habilidade(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    printf("\n");
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        printf("  ");
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                printf("3 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    
    int linha_h = 2;
    int coluna_h = 1;
    
    int linha_v = 0;
    int coluna_v = 7;
    
    int linha_d1 = 5;
    int coluna_d1 = 1;
    
    int linha_d2 = 6;
    int coluna_d2 = 8;
    
    printf("========================================\n");
    printf("      BATALHA NAVAL - NÍVEL MESTRE\n");
    printf("   Habilidades Especiais e Áreas de Efeito\n");
    printf("========================================\n");
    
    inicializar_tabuleiro(tabuleiro);
    
    printf("\n[1] Posicionando navios...\n");
    printf("----------------------------------------\n");
    
    if (pode_posicionar_horizontal(tabuleiro, linha_h, coluna_h)) {
        posicionar_navio_horizontal(tabuleiro, linha_h, coluna_h);
        printf("✓ Navio horizontal: linha %d, colunas %d-%d\n", 
               linha_h, coluna_h, coluna_h + TAMANHO_NAVIO - 1);
    }
    
    if (pode_posicionar_vertical(tabuleiro, linha_v, coluna_v)) {
        posicionar_navio_vertical(tabuleiro, linha_v, coluna_v);
        printf("✓ Navio vertical: coluna %d, linhas %d-%d\n", 
               coluna_v, linha_v, linha_v + TAMANHO_NAVIO - 1);
    }
    
    if (pode_posicionar_diagonal_principal(tabuleiro, linha_d1, coluna_d1)) {
        posicionar_navio_diagonal_principal(tabuleiro, linha_d1, coluna_d1);
        printf("✓ Navio diagonal \\: (%d,%d) → (%d,%d)\n", 
               linha_d1, coluna_d1, 
               linha_d1 + TAMANHO_NAVIO - 1, coluna_d1 + TAMANHO_NAVIO - 1);
    }
    
    if (pode_posicionar_diagonal_secundaria(tabuleiro, linha_d2, coluna_d2)) {
        posicionar_navio_diagonal_secundaria(tabuleiro, linha_d2, coluna_d2);
        printf("✓ Navio diagonal /: (%d,%d) → (%d,%d)\n", 
               linha_d2, coluna_d2, 
               linha_d2 + TAMANHO_NAVIO - 1, coluna_d2 - TAMANHO_NAVIO + 1);
    }
    
    printf("\n[2] Criando habilidades especiais...\n");
    printf("----------------------------------------\n");
    
    criar_habilidade_cone(cone);
    printf("✓ Habilidade CONE criada (expansão triangular)\n");
    printf("  Formato:");
    exibir_habilidade(cone);
    
    criar_habilidade_cruz(cruz);
    printf("\n✓ Habilidade CRUZ criada (linhas perpendiculares)\n");
    printf("  Formato:");
    exibir_habilidade(cruz);
    
    criar_habilidade_octaedro(octaedro);
    printf("\n✓ Habilidade OCTAEDRO criada (formato losango)\n");
    printf("  Formato:");
    exibir_habilidade(octaedro);
    
    printf("\n[3] Aplicando habilidades no tabuleiro...\n");
    printf("----------------------------------------\n");
    
    aplicar_habilidade(tabuleiro, cone, 4, 4);
    printf("✓ CONE aplicado na posição (4,4)\n");
    
    aplicar_habilidade(tabuleiro, cruz, 7, 4);
    printf("✓ CRUZ aplicada na posição (7,4)\n");
    
    aplicar_habilidade(tabuleiro, octaedro, 1, 4);
    printf("✓ OCTAEDRO aplicado na posição (1,4)\n");
    
    printf("\n========================================\n");
    printf("         TABULEIRO FINAL\n");
    printf("========================================\n");
    printf("\nLegenda:\n");
    printf("  0 = Água\n");
    printf("  3 = Navio\n");
    printf("  5 = Área de Efeito (Habilidade)\n");
    
    exibir_tabuleiro(tabuleiro);
    
    printf("\n========================================\n");
    printf("  HABILIDADES APLICADAS COM SUCESSO!\n");
    printf("========================================\n");
    
    return 0;
}