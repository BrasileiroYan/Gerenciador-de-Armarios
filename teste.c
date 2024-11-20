#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    char armario = 0;
    int opcao = 0, lugar;

    srand(time(NULL));
    
    do { 
        puts("\nMENU DE OPÇÕES:\n");
        puts("1.Ocupar Armário");
        puts("2.Liberar Armário");
        puts("3.Finalizar\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                {
                int armariOcupado = 0;
                for(int i=0; i<=7; i++){
                    if(!(armario & (1<<i))){
                        armariOcupado = 1;
                        break;
                    }
                }
                if (!armariOcupado){
                    puts("Todos estão ocupados.\n");
                    break;
                }
                do{
                    lugar = rand() % 8;
                }while(armario & (1<<lugar));
                armario = armario | (1<<lugar);
                
                printf("O armário %d foi ocupado!\n", lugar);
                break;
                }
            case 2:
                printf("Digite o armário que deseja liberar [0-7]: ");
                scanf("%d", &lugar);
                if(lugar > 7 || lugar < 0){
                    puts("Armário inválido!\n");

                }else if(!(armario & (1<<lugar))){
                    printf("O armário %d já estava livre!\n", lugar);

                }else{
                    armario = armario & ~(1<<lugar);
                    printf("O armário %d está livre agora!\n", lugar);

                }
                break;
            case 3:
                puts("\nPrograma Finalizado!\n");
                break;
            default:
                puts("Opção Inválida!\n");
        }
        puts("\nARMÁRIOS\n");
        for (int i=7; i>=0; i--){
            if(armario & (1 << i)){
                printf("Armário %d: Ocupado\n", i);
            }
            else{
                printf("Armário %d: Desocupado\n", i);
            }
        } 
    }while(opcao !=3);
    return 0;
}
