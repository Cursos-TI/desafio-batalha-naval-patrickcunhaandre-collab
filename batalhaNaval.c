#include <stdio.h>
#include <ctype.h>
#include <windows.h>

#define LINHAS 10
#define COLUNAS 10
#define AGUA 0
#define NAVIO 3

void impressaotabuleiro(int tabuleiro[LINHAS][COLUNAS]);
void shipdrop(int tabuleiro[LINHAS][COLUNAS]);
void limparTela() {
        printf("\033[H\033[J"); // Limpa a tela para manter a interface amigável
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    
    limparTela();
    printf(
    "===========================================================================\n"
    "                                                                           \n"
    "        ██████╗  █████╗ ████████╗ ██████╗  ██╗     ██╗   ██╗   ██████╗     \n"
    "        ██╔══██╗██╔══██╗╚══██╔══╝██╔═══██╗ ██║     ██║   ██║  ██║   ██║    \n"
    "        ██████╔╝███████║   ██║   ████████║ ██║     ████████║  ████████║    \n"
    "        ██╔══██╗██╔══██║   ██║   ██║   ██║ ██║     ██║   ██║  ██║   ██║    \n"
    "        ██████╔╝██║  ██║   ██║   ██║   ██║ ██████╗ ██║   ██║  ██║   ██║    \n"
    "        ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝   ╚═╝ ╚═════╝ ╚═╝   ╚═╝  ╚═╝   ╚═╝    \n"
    "                                                                           \n"
    "        ███╗   ██╗ █████╗ ██╗   ██╗ █████╗  ██╗                            \n"
    "        ████╗  ██║██╔══██╗██║   ██║██╔══██╗ ██║                            \n"
    "        ██╔██╗ ██║███████║██║   ██║███████║ ██║                            \n"
    "        ██║╚██╗██║██╔══██║╚██╗ ██╔╝██╔══██║ ██║                            \n"
    "        ██║ ╚████║██║  ██║ ╚████╔╝ ██║  ██║ ██████╗                        \n"
    "        ╚═╝  ╚═══╝╚═╝  ╚═╝  ╚═══╝  ╚═╝  ╚═╝ ╚═════╝    by Patrick Andre    \n"
    "                                                                           \n"
    "===========================================================================\n"
    );
    //Falsa tela de loading para experiencia do usuário
        printf("      Carregando ");
    for (int i = 1; i < 40; ++i){
        Sleep(100);
        printf("█");
    }
    Sleep(1000);

    int menu;
    
    do {
        limparTela();
        printf("Escolha uma opção do menu\n"
                "1- Jogar\n"
                "2- Sair\n");
        do {
            if (scanf("%i", &menu) != 1) {
                printf("Entrada invalida! Digite um numero.\n");
                
                while (getchar() != '\n'); // limpa o buffer

                menu = 0; // força continuar no loop
            }
            else if (menu < 1 || menu > 2) {
                printf("Opcao invalida. Digite novamente: ");
            }
        } while (menu < 1 || menu > 2);
        
        switch (menu)
        {
        case 1:
            //Inicio do jogo
            int tabuleiro[LINHAS][COLUNAS];
            limparTela();
            //Inicializa o tabuleiro com apenas água
            for (int i = 0; i < LINHAS; i++) {
                for (int j = 0; j < COLUNAS; j++) {
                    tabuleiro[i][j] = AGUA;
                }
            }
            printf("Seu tabuleiro de jogo:\n\n");
            impressaotabuleiro(tabuleiro);
            
            shipdrop(tabuleiro);
            limparTela();            
            impressaotabuleiro(tabuleiro);
            printf("posicione o segundo navio:\n\n");
            shipdrop(tabuleiro);
            limparTela();            
            impressaotabuleiro(tabuleiro);
            printf("posicione o terceiro navio:\n\n");
            shipdrop(tabuleiro);
            limparTela();            
            impressaotabuleiro(tabuleiro);
            char continuar;
            printf("Voltar ao início? S/N: ");
            scanf(" %c", &continuar);
            continuar = toupper(continuar);
            if (continuar == 'S') {
                menu = 0;
            } else if (continuar == 'N') {
                limparTela();
                printf("Obrigado por jogar!\n");
                menu = 2;
            }

        break;
        default:
            limparTela();
            printf("Obrigado por jogar!\n");
        break;
        }
    } while (menu != 2);
    return 0;
}

// Imprime o tabuleiro atualizado
void impressaotabuleiro(int tabuleiro[LINHAS][COLUNAS]) {
    printf("|  ");
    for ( int i = 0; i < COLUNAS; i++) {
        printf("|");
        printf("%c", 'A' + i);
    }

    printf("|\n");
    for ( int i = 0; i < LINHAS ; i++) {
        if (i < 9){
            printf("| %i", i+1);
        } else {
            printf("|%i", i+1);
        }
        for (int j = 0; j < COLUNAS; j++){
            if (tabuleiro[i][j] == AGUA) {
                printf("|~");
            } else if (tabuleiro[i][j] == NAVIO) {
                printf("|N");
            } else {
                printf("|X");
            }
        }
        printf("|\n");
    }
}

//Posiciona os navios
void shipdrop(int tabuleiro[LINHAS][COLUNAS]) {
    char posXletra;
    int posnavioX, posnavioY;
    int shiprotation = 0; // 1 = Horizontal, 2 = Vertical, 3 = diagonal direita, 4 = diagonal esquerda


    printf("\nEscolha o sentido que o navio será posicionado:\n\n1- Horizontal\n2- Vertical\n3- Diagonal direita\n4- Diagonal esquerda\n");
    do { //Validação da opção
        scanf("%i", &shiprotation);
        if (shiprotation < 1 || shiprotation > 4 || shiprotation == 'A'){
            printf("Entrada inválida!\nDigite novamente: ");
        }
        while (getchar() != '\n');
    } while (shiprotation < 1 || shiprotation > 4 || shiprotation == 'A');
    int ocupado;
    do { 
        ocupado = 0;  
        printf("\nEscolha a Coluna para seu navio: ");
        do { //Validação da opção
            scanf(" %c", &posXletra);
            posXletra = toupper(posXletra);
            posnavioX = posXletra - 'A';
        
            if (posnavioX < 0 || posnavioX> COLUNAS){
                printf("Entrada inválida!\nDigite novamente: ");
            }
            while (getchar() != '\n');
        } while (posnavioX < 0 || posnavioX> COLUNAS);
        
        printf("\nEscolha uma Linha para o navio: ");
        do { //Validação da opção
            scanf("%i", &posnavioY);
            if (posnavioY < 0 || posnavioY> LINHAS){
                printf("Entrada inválida!\nDigite novamente: ");
            }
            posnavioY--;
        } while (posnavioY < 0 || posnavioY > LINHAS || posnavioY == 'A');
        
        //Correção de posição para o navio não sair da zona do tabuleiro
        if (shiprotation !=2){
            if (posnavioX == 0){
                posnavioX += 1;
            } else if (posnavioX >= COLUNAS -1){
                posnavioX = COLUNAS-2;
            }
        }
        if (shiprotation != 1){
            if (posnavioY == 0){
                posnavioY += 1;
            } else if (posnavioY >= LINHAS -1){
                posnavioY = LINHAS-2;
            }
        }
        if (tabuleiro[posnavioY][posnavioX-1] == NAVIO ||
        tabuleiro[posnavioY][posnavioX]   == NAVIO ||
        tabuleiro[posnavioY][posnavioX+1] == NAVIO ||
        tabuleiro[posnavioY-1][posnavioX] == NAVIO ||
        tabuleiro[posnavioY+1][posnavioX] == NAVIO ||
        tabuleiro[posnavioY-1][posnavioX+1] == NAVIO ||
        tabuleiro[posnavioY+1][posnavioX-1] == NAVIO ||
        tabuleiro[posnavioY-1][posnavioX-1] == NAVIO ||
        tabuleiro[posnavioY+1][posnavioX+1] == NAVIO) 
        { ocupado = 1;
        printf("\nPosicao ocupada! Escolha outra.\n"); }
    } while (ocupado == 1);

    if (shiprotation == 1 ){
        //Navio Horizontal
        tabuleiro [posnavioY][posnavioX-1] = NAVIO;
        tabuleiro [posnavioY][posnavioX] = NAVIO;
        tabuleiro [posnavioY][posnavioX+1] = NAVIO;
    } else if (shiprotation == 2){
        //Navio Vertical
        tabuleiro [posnavioY][posnavioX] = NAVIO;
        tabuleiro [posnavioY-1][posnavioX] = NAVIO;
        tabuleiro [posnavioY+1][posnavioX] = NAVIO;
        //Navio Diagonal direita
    }   else if (shiprotation == 3){
        tabuleiro[posnavioY-1][posnavioX+1] = NAVIO;
        tabuleiro[posnavioY][posnavioX] = NAVIO;
        tabuleiro[posnavioY+1][posnavioX-1] = NAVIO;
        //Navio Diagonal esquerda
    }   else if (shiprotation == 4){
        tabuleiro[posnavioY-1][posnavioX-1] = NAVIO;
        tabuleiro[posnavioY][posnavioX] = NAVIO;
        tabuleiro[posnavioY+1][posnavioX+1] = NAVIO;
    }   else {
        printf("Opção inválida\n\n");
    }
}
