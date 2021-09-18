#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50],
         email[40];
    int telefone;
} Contato;

void clear(){ // Funcao para limpar a tela
    int cont=0;

    while(cont != 100)
    {
        putchar('\n');
        cont++;
    }
}

int menu(){
    int esc = 0; // Item escolhido

    printf("========= Menu ==========\n");
    printf("| 1 - Adicionar contato |\n");
    printf("| 2 - Lista de contatos |\n");
    printf("| 0 - Sair              |\n");
    printf("=========================\n");
    scanf("%d", &esc);

    return esc;
}

int addCont(Contato *arrCont, int i){ // Funcao de leitura de contatos
    printf("Nome do contato:\n");
    setbuf(stdin, NULL);
    fgets(arrCont[i].nome, 49, stdin);
    printf("E-mail do contato:\n");
    setbuf(stdin, NULL);
    fgets(arrCont[i].email, 39, stdin);
    printf("Telefone do contato:\n");
    scanf("%d", &arrCont[i].telefone);

    return i + 1;
}

void listCont(Contato *arrCont, int i){ // Funcao para imprimir a lista de contatos
    int j = 0, // contador local
        sair = 0;

        printf("=========== Lista ===========\n");
    for(j = 0; j < i; j++){
        printf("Nome do %d contato     | %s", j + 1, arrCont[j].nome);
        printf("E-mail do %d contato   | %s", j + 1, arrCont[j].email);
        printf("Telefone do %d contato | %d\n", j + 1, arrCont[j].telefone);
        printf("=============================\n");
    }

    do{
        printf("\nDeseja sair? (1 - Sim)\n");
        scanf("%d", &sair);
    }while(sair != 1);
}

int main()
{
    Contato arrCont[10]; // array de contatos
    int esc = 0, // variavel que armazena a escolha
        i = 0; // contador global de contatos

    do{
        esc = menu();
        clear();

        switch(esc){
            case 1:
                if(i < 10){
                    i = addCont(arrCont, i);
                    clear();
                } else {
                    printf("========================= AVISO ==========================\n");
                    printf("| Infelizmente nao ha' mais espaco na lista de contatos. |\n");
                    printf("==========================================================\n");
                }
            break;

            case 2:
                listCont(arrCont, i);
                clear();
            break;

            case 0:
            break;
        }
    }while(esc != 0);

    return 0;
}
