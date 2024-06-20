#ifndef PRINTER
#define PRINTER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.c>
#include "tree.h"

#define SPC 3
#define CTR 40
#define MASK 2
#define MENU_S 2
#define MENU_T 1
#define TREE_S 13
#define TREE_T 12

//FUNÇÕES AUXILIARES
void showmessage(int x, int y, char* text);
void showvalue(int x, int y, int value);
void clearscreen();
void maptree(ArvNo* raiz,int posX,int posY,char origem);

//IMPLEMENTACÃO
void printmenu(char* infotext){
     
     //ESTRUTURA DO MENU
     showmessage(1,MENU_T,"====== MENU DA ARVORE ======================================");
     showmessage(1,MENU_S+1,"| 1 - Inserir na Árvore");
     showmessage(1,MENU_S+2,"| 2 - Remover na Árvore");
     showmessage(1,MENU_S+3,"| 3 - Procurar na Árvore");
     showmessage(1,MENU_S+4,"| 0 - Fechar Programa");
     showmessage(1,MENU_S+5,"============================================================");
     
     //RETORNO DE TENTATIVA
     showmessage(1,MENU_S+6,"Info: ");
     gotoxy(7,MENU_S+6);
     printf("%s",infotext);
     
     //ESTRUTURA IMPRESSOR
     showmessage(1,TREE_T,"===== ÁRVORE ===============================================");
     
     //POSICIONA RESPOSTA DO USER
     showmessage(1,MENU_S+7,"Resposta: ");
     gotoxy(10,MENU_S+7);
}

void printtree(ArvNo* raiz){
     //LEITURA E IMPRESSÃO DA ARVORE
     if (raiz != NULL){
        showvalue(raiz->posX,raiz->posY,raiz->valor);
        printtree(raiz->no_esq);
        printtree(raiz->no_dir);
     }
}

void maptree(ArvNo* raiz,int posX,int posY,char origem){
    if (raiz != NULL){
       if(origem == 'R'){
           raiz->posX = posX;
           raiz->posY = posY;
           maptree(raiz->no_esq,posX-(SPC),posY+1,'E');
           maptree(raiz->no_dir,posX+(SPC),posY+1,'D');
       } else {
           if(origem == 'E' && raiz->no_dir != NULL){
              int alt = altura(raiz->no_dir),temp = 0,x = 0;
              do{
                 x++; 
                 temp += SPC*x; 
              } while(x < alt+1);
              posX -= temp;
           } else if(origem == 'D' && raiz->no_esq != NULL){
              int alt = altura(raiz->no_esq),temp = 0,x = 0;
              do{
                 x++; 
                 temp += SPC*x; 
              } while(x < alt+1);
              posX += temp;
           }
           raiz->posX = posX;
           raiz->posY = posY;
           maptree(raiz->no_esq,posX-(SPC),posY+1,'E');
           maptree(raiz->no_dir,posX+(SPC),posY+1,'D');
       }
    }
}

void showmessage(int x, int y, char* text){
     gotoxy(x,y);
     clreol();
     printf("%s\n", text);
}

void showvalue(int x, int y, int value){
     gotoxy(x,y);
     clreol();
     printf("%.2d\n", value);
}

void clearscreen(){
     clrscr();
     printmenu("");
}



#endif
