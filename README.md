🚢 Batalha Naval - Completo
Projeto completo de simulação do jogo Batalha Naval em C, desenvolvido em três níveis progressivos, explorando matrizes bidimensionais, posicionamento estratégico e habilidades especiais com áreas de efeito.
📋 Sobre o Projeto
Este repositório contém a implementação completa do Desafio Batalha Naval, que explora o uso de vetores e matrizes em C através da criação de um jogo de Batalha Naval com funcionalidades progressivas. O projeto está dividido em três níveis de dificuldade, cada um adicionando novas mecânicas e complexidade.
🎯 Níveis Implementados
🥉 Nível Novato
Foco: Matrizes básicas e posicionamento simples
Funcionalidades:

Tabuleiro 10x10
2 navios de tamanho 3
Posicionamento horizontal e vertical
Validação de limites
Validação de sobreposição

ElementoValorDescriçãoÁgua0Posição vaziaNavio3Posição ocupada por navio
Conceitos:

Matrizes bidimensionais
Loops aninhados
Validação de entrada
Funções modulares


🥈 Nível Aventureiro
Foco: Navios diagonais e validação complexa
Funcionalidades:

Tabuleiro 10x10
4 navios de tamanho 3
1 horizontal, 1 vertical, 2 diagonais
Validação completa para todas as direções
Detecção de sobreposição avançada

OrientaçãoSímboloDescriçãoHorizontal→Move-se nas colunasVertical↓Move-se nas linhasDiagonal Principal↘ (\)Linha e coluna aumentamDiagonal Secundária↙ (/)Linha aumenta, coluna diminui
Conceitos:

Navegação diagonal em matrizes
Validação em 4 direções
Incremento/decremento simultâneo
Lógica de coordenadas complexa


🥇 Nível Mestre
Foco: Habilidades especiais com áreas de efeito
Funcionalidades:

Tabuleiro 10x10 completo
4 navios posicionados
3 habilidades especiais:

🔻 Cone - Expansão triangular
➕ Cruz - Linhas perpendiculares
◇ Octaedro - Formato losango


Sobreposição de matrizes
Áreas de efeito dinâmicas

ElementoValorDescriçãoÁgua0Posição vaziaNavio3Posição ocupadaHabilidade5Área de efeito ativa
Conceitos:

Matrizes de habilidade separadas
Sobreposição de matrizes
Cálculo de áreas de efeito
Distância Manhattan
Construção dinâmica com condicionais
