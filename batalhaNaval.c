#include <stdio.h>

#define linha 10
#define coluna 10
#define linhaHab 5
#define colunaHab 5
// logica da sobreposicao do cone
void sobreposicaoCone(int tabuleiro[linha][coluna], int cone[linhaHab][colunaHab], int inicioLinha, int inicioColuna) {
    for (int i = 0; i < linhaHab; i++) {
        for (int j = 0; j < colunaHab; j++) {
            if (cone[i][j] == 1 ) {
                if (tabuleiro[i+inicioLinha][j+inicioColuna] == 3) {
                    tabuleiro[i+inicioLinha][j+inicioColuna] = 5;
                }else if (tabuleiro[i+inicioLinha][j+inicioColuna] == 0) {
                    tabuleiro[i+inicioLinha][j+inicioColuna] = 1;
                }   
            }  
        }
    }
}
// logica da sobreposicao da cruz
void sobreposicaoCruz(int tabuleiro[linha][coluna], int cruz[linhaHab][colunaHab], int inicioLinha, int inicioColuna) {
    for (int i = 0; i < linhaHab; i++) {
        for (int j = 0; j < colunaHab; j++) {
            if (cruz[i][j] == 1 ) {
                if (tabuleiro[i+inicioLinha][j+inicioColuna] == 3) {
                    tabuleiro[i+inicioLinha][j+inicioColuna] = 5;
                }else if (tabuleiro[i+inicioLinha][j+inicioColuna] == 0) {
                    tabuleiro[i+inicioLinha][j+inicioColuna] = 1;
                }   
            }  
        }
    }
}
// logica da sobreposicao do octaedro
void sobreposicaoOcta(int tabuleiro[linha][coluna], int octaedro[linhaHab][colunaHab], int inicioLinha, int inicioColuna) {
    for (int i = 0; i < linhaHab; i++) {
        for (int j = 0; j < colunaHab; j++) {
            if (octaedro[i][j] == 1 ) {
                if (tabuleiro[i+inicioLinha][j+inicioColuna] == 3) {
                    tabuleiro[i+inicioLinha][j+inicioColuna] = 5;
                }else if (tabuleiro[i+inicioLinha][j+inicioColuna] == 0) {
                    tabuleiro[i+inicioLinha][j+inicioColuna] = 1;
                }  
            }  
        }
    }
}

int main() {
// Definicao de variaveis.
    int tabuleiro[linha][coluna];
    int cone[linhaHab][colunaHab];
    int cruz[linhaHab][colunaHab];
    int octaedro[linhaHab][colunaHab];
    char letrasTab[linha];
    int numeracaoVert[linha];
// formando a matriz do tabuleiro.
for (int i = 0; i < linha; i++) {
    numeracaoVert[i] = i+ 1; // antes do tabuleiro
    for (int j = 0; j < coluna; j++) {
        tabuleiro[i][j] = 0; // tabuleiro 
    }
}
//Definicao das coordenadas dos navios.
    for (int i = 0, j = 5; i <= 2 && j >= 3 ; i++, j--) {
        tabuleiro[i][7] = 3; // Navio A na vertical
        tabuleiro[8][i] = 3; //Navio B na horizontal 
        tabuleiro[i][i] = 3; //Navio C na vertical
        tabuleiro[i + 4][j] = 3; //Navio D na vertical
    } 
// formando matrizes de habilidades
    for (int i = 0; i < linhaHab; i++) {
        for (int j = 0; j < colunaHab; j++) {
            cone[i][j] = 0;
            cruz[i][j] = 0;
            octaedro[i][j] = 0;
        }
    }
// Definicao da imagem do cone em sua matriz.
for (int i = 1; i < linhaHab; i++) {
    for (int j = 0; j < colunaHab; j++) {                       
        if (j == 2 && i < 4 ) {
            cone[i][j] = 1;
        }else {
            cone[2][1] = 1;
            cone[2][3] = 1;
            cone[3][j] = 1;
        }
    }   
}
// Definicao da imagem da cruz em sua matriz.
for (int i = 0; i < linhaHab; i++) {
    for (int j = 0; j < colunaHab; j++) {
        cruz[i][2] = 1;
        cruz[2][j] = 1;
    }   
}
// Definicao da imagem do octaedro em sua matriz.
    for (int i = 0; i < linhaHab; i++) {            
        for (int j = 0; j < colunaHab; j++) {
            if ((i == 1 || i == 3) && (j > 0 && j< 4) ) {
                octaedro[1][j] = 1;
                octaedro[3][j] = 1;
            } else{
                octaedro[i][2] = 1;
                octaedro[2][j] = 1;
            }
        }   
    }
//Atribuicao das letras ao vetor letras da tabela e impressao das letras em cima do tabuleiro.
for (int i = 65, j = 0; i < 75 && j < 10; i++, j++) {
    letrasTab[j] = i;
    printf(" %c", letrasTab[j]);  
}
printf("\n");
// sobreposicao de habilidades no tabuleiro
    sobreposicaoCone(tabuleiro, cone, 5, 1);
    sobreposicaoCruz(tabuleiro, cruz, 2, 5);
    sobreposicaoOcta(tabuleiro, octaedro, 0, 0);

//imprimindo tabuleiro e numeracao vertical antes do tabuleiro   
    for (int i = 0; i < linha ; i++) {
        printf("%d", numeracaoVert[i]); //numeracao vertical antes do tabuleiro.
        for (int j = 0; j < coluna; j++) {
            printf(" %d", tabuleiro[i][j]); // tabuleiro 
        }
        printf("\n");
    }
    return 0;
    
}
