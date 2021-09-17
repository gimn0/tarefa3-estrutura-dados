#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void converteFrase(const char *frase, int tam) {
    char novaFrase[tam];
    int i = 0;

    for(i = 0; i < tam; i++) {
        switch(frase[i]) {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                novaFrase[i] = toupper(frase[i]);
            break;

            default:
                novaFrase[i] = tolower(frase[i]);
            break;
        }
    }

    printf("A frase convertida e': %s", novaFrase);
}


int main()
{
    char frase[100];
    printf("Digite uma frase\n");
    fgets(frase, 99, stdin);

    int tamFra = strlen(frase);
    converteFrase(frase, tamFra);

    return 0;
}
