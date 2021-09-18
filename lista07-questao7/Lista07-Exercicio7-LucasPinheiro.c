#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>
#include <string.h>

int login(); //Função de login para acessar o menu().
void menu(); //Função de menu para escolher as opções.
void clear(); //Função para limpar tela.
float calculadora(); //Função calculadora.
void textoAleatorio(); //Função para escolher uma frase aleatória.
// Funções para jogo Batalha Naval.
void jogoBatalhaNaval();
void iniciarTabuleiro();
void mostraTabuleiro();
void naviosIniciar();
void darTiro();
int checarTiro();
void dica();
void alterarTabuleiro();
//Fim das funções do jogo Batalha Naval.

/*typedef struct()
{
    char Usuario[20],
         Senha[32];
} Usuarios;*/

int cadeadoTexto = 0;
int loginEntrou = 0;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    do
    {
        loginEntrou = login();

        if(loginEntrou == 1)
        {
            clear();
            menu();
        }
        else
        {
            clear();
            printf("Usuário ou Senha incorretos! Tente novamente.\n");
        }
    }while(loginEntrou == 0);

    return 0;
}

void clear()
{
    int cont=0;

    while(cont != 100)
    {
        putchar('\n');
        cont++;
    }
}

int login()
{
    char usuario[20] = "admin\n", // {'a', 'd', 'm', 'i', 'n', '\n'},
         senha[32] = "nimda\n"; // {'n', 'i', 'm', 'd', 'a', '\n'};

    char loginUsuario[20],
         loginSenha[32];

    printf("=------------------=\n");
    printf("| Usuário:         |\n");
    printf("| ");
    fgets(loginUsuario, 20, stdin);
    printf("| Senha:           |\n");
    printf("| ");
    fgets(loginSenha, 32, stdin);
    printf("=------------------=\n");

    if(strcmp(loginUsuario, usuario) == 0 && strcmp(loginSenha, senha) == 0)
        return 1;

    return 0;
}

void menu()
{
    int escolha;
    float resultadoCalculadora;

    printf("Bem Vindo(a)!\n");

    do
    {
        printf("=--------- Menu --------=\n");
        printf("|-----------------------|\n");
        printf("| Escolha um dos itens: |\n");
        printf("|-----------------------|\n");
        printf("|     1) Calculadora.   |\n");
        printf("|-----------------------|\n");
        printf("| 2) Quão bosta você é. |\n");
        printf("|-----------------------|\n");
        printf("|    3) Batalha Naval   |\n");
        printf("|-----------------------|\n");
        printf("|        0) Sair.       |\n");
        printf("=-----------------------=\n");
        printf("Escolha: ");
        scanf("%d", &escolha);

        do
        {
            switch(escolha)
            {
                case 0:
                    clear();
                    printf("Saindo...\n(Pressione qualquer tecla)");
                    break;

                case 1:
                    printf("Resultado final da última vez que usou a Calculadora: %.1f\n\n", resultadoCalculadora = calculadora());
                    break;

                case 2:
                    clear();
                    textoAleatorio();
                    break;

                case 3:
                    clear();
                    jogoBatalhaNaval();
                    break;

                default:
                    clear();
                    printf("Escolha inválida!\n");
            }
        }while(escolha < 0 && escolha > 3);
    }while(escolha != 0);
}

float calculadora()
{
    float num1, num2, resultado, resultadoFinal;
    char operacao, escolhaCalculadora;

    do
    {
        clear();
        printf("Digite o primeiro número: ");
        scanf("%f", &num1);

        do{
            printf("Digite a operação que deseja executar: ");
            getchar();
            scanf("%c", &operacao);

            printf("Digite o segundo número: ");
            scanf("%f", &num2);

            switch(operacao)
            {
                case '+':
                    resultado = num1 + num2;
                    break;

                case '-':
                    resultado = num1 - num2;
                    break;

                case '*':
                    resultado = num1 * num2;
                    break;

                case '/':
                    resultado = num1 / num2;
                    break;
            }

            printf("Resultado atual = %.1f\n", resultado);

            do
            {
                printf("Você deseja continuar esta operação? (S ou N)\n");
                getchar();
                scanf("%c", &escolhaCalculadora);

                if(escolhaCalculadora != 'S' && escolhaCalculadora != 'N')
                    printf("Caractere inválido!\n");

                if(escolhaCalculadora == 'S')
                {
                    num1 = resultado;
                    clear();
                    printf("Primeiro número atual: %.1f\n", num1);
                }
            }while(escolhaCalculadora != 'S' && escolhaCalculadora != 'N');
        }while(escolhaCalculadora != 'N');

        do
        {
            printf("Você deseja continuar na Calculadora? (S ou N)\n");
            getchar();
            scanf("%c", &escolhaCalculadora);

            if(escolhaCalculadora != 'S' && escolhaCalculadora != 'N')
                printf("Caractere inválido!\n");
        }while(escolhaCalculadora != 'S' && escolhaCalculadora != 'N');
    }while(escolhaCalculadora != 'N');

    resultadoFinal = resultado;

    clear();

    return resultadoFinal;
}

void textoAleatorio()
{
    int numAleatorio;

    if(cadeadoTexto == 0)
    {
        srand(time(NULL));
        numAleatorio = rand() % 10;

        switch(numAleatorio)
        {
            case 0:
            case 1:
            case 2:
                printf("Não, você não é um(a) bosta!!\n\n");
                break;

            case 3:
            case 4:
            case 5:
                printf("Meio merda, mas ok, dá pra ti tolerar.\n\n");
                break;

            case 6:
            case 7:
            case 8:
                printf("VOCÊ É UM(A) BOSTA, NÃO PRESTA PRA NADA.\n\n");
                break;

            case 9:
                printf("SE VOCÊ TIROU ISSO TU É TÃO ARROMBADO QUANTO O CORNO QUE PROGRAMOU ESSA MERDA!! SÓ NÃO SOMOS PIORES QUE HITLER!\n\n");
                break;

            default:
                printf("Não era pra dar isso...\n\n");
                break;
        }
    }
    else
    {
        printf("Você já sabe!\n\n");
    }

    cadeadoTexto = 1;
}

void jogoBatalhaNaval()
{
    int tabuleiro[5][5],
        navios[3][2],
        tiro[2];

    int tentativas=0,
        acertos=0;

        iniciarTabuleiro(tabuleiro);
        naviosIniciar(navios);

        printf("\n");

        do{
            mostraTabuleiro(tabuleiro);
            darTiro(tiro);
            tentativas++;

            if(checarTiro(tiro,navios))
            {
                dica(tiro,navios,tentativas);
                acertos++;
            }
            else
                 dica(tiro,navios,tentativas);

            alterarTabuleiro(tiro,navios,tabuleiro);

        }while(acertos!=3);

        clear();
        printf("\n\n\nJogo terminado. Você acertou os 3 navios em %d tentativas.\n", tentativas);
        mostraTabuleiro(tabuleiro);
        printf("\n");
}

void iniciarTabuleiro(int tabuleiro[][5])
{
    int linha, coluna;

    for(linha = 0 ; linha < 5 ; linha++ )
        for(coluna = 0 ; coluna < 5 ; coluna++ )
            tabuleiro[linha][coluna] = -1;
}

void mostraTabuleiro(int tabuleiro[][5])
{
    int linha, coluna;

    printf("\t1 \t2 \t3 \t4 \t5");
    printf("\n");

    for(linha=0 ; linha < 5 ; linha++ )
    {
        printf("%d",linha+1);
        for(coluna=0 ; coluna < 5 ; coluna++ )
        {
            if(tabuleiro[linha][coluna] == -1){
                printf("\t[~]");
            }else if(tabuleiro[linha][coluna] == 0){
                printf("\t[X]");
            }else if(tabuleiro[linha][coluna] == 1){
                printf("\t[O]");
            }
        }
            printf("\n");
    }
}

void naviosIniciar(int navios[][2])
{
    srand(time(NULL));
    int navio, anterior;

    for(navio = 0 ; navio < 3 ; navio++)
    {
        navios[navio][0] = rand() % 5;
        navios[navio][1] = rand() % 5;

        // Agora vamos checar se esse par não foi sorteado
        // Se foi, só sai do do...while enquanto sortear um diferente
        for(anterior=0 ; anterior < navio ; anterior++)
        {
            if((navios[navio][0] == navios[anterior][0]) && (navios[navio][1] == navios[anterior][1]))
                do
                {
                    navios[navio][0] = rand() % 5;
                    navios[navio][1] = rand() % 5;
                }while((navios[navio][0] == navios[anterior][0]) && (navios[navio][1] == navios[anterior][1]));
        }
    }
}

void darTiro(int tiro[2])
{
    printf("Linha: ");
    scanf("%d", &tiro[0]);
    tiro[0]--;

    printf("Coluna: ");
    scanf("%d", &tiro[1]);
    tiro[1]--;
}

int checarTiro(int tiro[2], int navios[][2])
{
    int navio;

    for(navio = 0 ; navio < 3 ; navio++)
    {
        if(tiro[0] == navios[navio][0] && tiro[1] == navios[navio][1])
        {
            printf("Você acertou o tiro (%d,%d)\n", tiro[0]+1 , tiro[1]+1);
            return 1;
        }
    }

    return 0;
}

void dica(int tiro[2], int navios[][2], int tentativa)
{
    int linha = 0,
        coluna = 0,
        fila;

    //conta quantos navios há na linha tiro[0]
    for(fila=0 ; fila < 3 ; fila++)
    {
        if(navios[fila][0] == tiro[0])
            linha++;
        if(navios[fila][1] == tiro[1])
            coluna++;
    }

    printf("\nDica %d: \nlinha %d -> %d navios\ncoluna %d -> %d navios\n", tentativa, tiro[0]+1, linha, tiro[1]+1, coluna);
}

void alterarTabuleiro(int tiro[2], int navios[][2], int tabuleiro[][5])
{
    if(checarTiro(tiro,navios))
        tabuleiro[tiro[0]][tiro[1]] = 1;
    else
        tabuleiro[tiro[0]][tiro[1]] = 0;
}
