#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tree.h"
#include "printer.h"

//DECLARA��O GLOBAL
ArvNo* arvore = NULL;

//SELETOR E FUN��ES
void seletor(int opcao);

//IMPLEMENTA��O
int main(){
    setlocale(LC_ALL,"");
    
    int opcao = -1;
    
    do{
       clearscreen();
       maptree(arvore,CTR,TREE_S+1,'R');
       printtree(arvore);
       printmenu("Escolha uma op��o do MENU");                    
       scanf("%d",&opcao);
       fflush(stdin);
       seletor(opcao);
       
    }while(opcao != 0);
    
    gotoxy(1,20);
    system("pause");
}

void seletor(int opcao){
     int tmp = -1;
     ArvNo* aux;
     switch (opcao){   
         case 1:       
              while(tmp < 0 || tmp >= 100){
                 printmenu("Informe o valor que ser� inserido(0-99): ");         
                 scanf("%d",&tmp);
                 fflush(stdin);
              }
              arvore = inserir_arv(arvore,tmp);
              maptree(arvore,CTR,TREE_S+1,'R');
              aux = buscar_invalido_no(arvore);
              if(aux){
                  arvore = remover_arv(arvore,tmp);
                  printmenu("Esse lado da �rvore est� CHEIO![Pressione para Seguir]");
                  getch(); 
              }
              break;
         case 2:
              while(tmp < 0 || tmp >= 100){
                 printmenu("Informe o valor que ser� removido(0-99): ");         
                 scanf("%d",&tmp);
                 fflush(stdin);
              }
              arvore = remover_arv(arvore,tmp);
              break;
         case 3:
              while(tmp < 0 || tmp >= 100){
                 printmenu("Informe o valor que deseja encontrar(0-99): ");         
                 scanf("%d",&tmp);
                 fflush(stdin);
              }
              aux = buscar_arv(arvore,tmp);
              if(aux){
                 printmenu("Valor Encontrado!");
                 showmessage(1,MENU_S+7,"Posi��o: ");
                 gotoxy(10,MENU_S+7);
                 printf("X: %d | Y: %d",aux->posX,aux->posY);
              } else {
                 printmenu("Valor N�O Encontrado!");
              }
              getch();
              break;
         case 0:
              printmenu("At� uma proxima! Por FelipinKK"); 
              break;
         default:
              printmenu("Op��o Inv�lida! Pressione qualquer tecla para continuar!");
              getch();   
              break;
     }
}


