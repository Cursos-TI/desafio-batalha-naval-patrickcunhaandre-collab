#include <stdio.h>

void impressaotabuleiro(int tabuleiro[10][10], char colunas[10]);

int main (){

    char colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10];
    int posnavioX, posnavioY;
    
    //Inicializa o tabuleiro com apenas água
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    impressaotabuleiro(tabuleiro, colunas);

    // posicionar o primeiro navio

    posnavioX = 3;
    posnavioY = 4;

    tabuleiro [posnavioX][posnavioY] = 3;
    tabuleiro [posnavioX-1][posnavioY] = 3;
    tabuleiro [posnavioX+1][posnavioY] = 3;


    // posicionar o segundo navio

    posnavioX = 6;
    posnavioY = 2;

    tabuleiro [posnavioX][posnavioY-1] = 3;
    tabuleiro [posnavioX][posnavioY] = 3;
    tabuleiro [posnavioX][posnavioY+1] = 3;

    printf("\n----------------------------------\n");
    impressaotabuleiro(tabuleiro, colunas);

    return 0;
}

// Imprime o tabuleiro atualizado
void impressaotabuleiro(int tabuleiro[10][10], char colunas[10]) {
    printf("|  ");
    for ( int i = 0; i < 10; i++) {
        printf("|");
        printf("%c", colunas[i]);
    }

    printf("|\n");
    for ( int i = 0; i < 10 ; i++) {
        if (i < 9){
            printf("| %i", i+1);
        } else {
            printf("|%i", i+1);
        }
        for (int j = 0; j < 10; j++){
            if (tabuleiro[j][i] == 0) {
                printf("|~");
            } else {
                printf("|N");
            }
        }
        printf("|\n");
    }
}
