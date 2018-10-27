#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

//FUNÇÃO PARA MOSTRAR SAUDAÇÃO PERSONALIZADA DE ACORDO COM A HORA
char *msgSaudacao(int hora) {

    char *saud[] = {"Bom dia!", "Boa tarde!", "Boa noite!"};

    if (hora >= 12 && hora <18)
    {
        return saud[1];
    }
    else if(hora >= 0 && hora < 12)
    {
        return saud[0];
    }
    else {
        return saud[2];
    }
}

int main() {

    //DEFINIR O IDIOMA DO PROGRAMA
    setlocale(LC_ALL, "Portuguese");

    //VARIAVEIS DAS HORAS
    time_t data;
    time(&data);

    struct tm *horaData = localtime(&data);

    //VARIAVEIS
    int menu = 1, msg_alerta = 0, i;
    char msg_error[] = " Opção inválida! Por favor, tente novamente!";

    do {
        switch(menu) {
        case 1:

            system("cls");
            //MENU PRINCIPAL
            printf("\n");
            printf("  '||                  '||''''|                    '||` \n");
            printf("   ||                   ||  .                  ''   ||  \n");
            printf("   ||     .|''|, .|'',  ||''|    '''|.  .|'',  ||   ||  \n");
            printf("   ||     ||  || ||     ||      .|''||  ||     ||   ||  \n");
            printf("  .||...| `|..|' `|..' .||.     `|..||. `|..' .||. .||. \n");
            printf("\n");
            printf(" +-----------------------------------------------------+");
            printf("\n");
            printf(" | Menu Principal | %s | %i/%i/%i - %02i:%02i:%02i |", msgSaudacao(horaData->tm_hour), horaData->tm_mday, horaData->tm_mon + 1, horaData-> tm_year + 1900, horaData->tm_hour, horaData->tm_min, horaData->tm_sec);
            printf("\n");
            printf(" +-----------------------------------------------------+");
            printf("\n");
            printf("\n");
            printf(" 1.) Títulos\t\t3.) Locação\n");
            printf(" 2.) Clientes\t\t4.) Devolução");
            printf("\n");
            printf("\n");

            if (msg_alerta == 1) {
            printf("%s\n\n", msg_error);
            }

            printf(" Selecione [1 - 4 | 0 para sair]: ");
            scanf(" %d", &menu);

        break;
        default:
            msg_alerta = 1;
            menu = 1;
        break;
        }
    } while(menu != 0);
}
