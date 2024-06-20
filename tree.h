#ifndef TREE
#define TREE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvno{
        int valor;
        int posX, posY;
        struct arvno *no_esq, *no_dir;        
} ArvNo;

ArvNo* inicializarArvNo(){
     ArvNo* nof = (ArvNo*) malloc(sizeof(ArvNo));
     nof->valor = 0;
     nof->no_esq = NULL;
     nof->no_dir = NULL;
     return nof;
}


ArvNo* inserir_arv(ArvNo* raiz, int val){
       if(raiz == NULL){
          ArvNo* auxNo = inicializarArvNo();
          auxNo->valor = val;
          return auxNo;
       } else {
          if(val > raiz->valor){
                 raiz->no_dir = inserir_arv(raiz->no_dir,val);
          } else {
                 raiz->no_esq = inserir_arv(raiz->no_esq,val);
          }
          return raiz;
       }       
}       

ArvNo* remover_arv(ArvNo* raiz, int chave){
       if(raiz == NULL){
          return NULL;
       } else {
          if(raiz->valor == chave){
             if(raiz->no_dir == NULL && raiz->no_esq == NULL){
                free(raiz);
                return NULL;
             } else {
                if(raiz->no_dir != NULL && raiz->no_esq != NULL){
                   ArvNo* aux = raiz->no_esq;
                   while(aux->no_dir != NULL){
                      aux = aux->no_dir;
                   }
                   raiz->valor = aux->valor;
                   aux->valor = chave;
                   raiz->no_esq = remover_arv(raiz->no_esq,chave);
                   return raiz;
                } else {
                   ArvNo *aux;
                   if(raiz->no_esq != NULL){
                        aux = raiz->no_esq;
                   } else {
                        aux = raiz->no_dir;
                   }
                   free(raiz);
                   return aux;
                }
             }
          } else {
             if(chave > raiz->valor){
                raiz->no_dir = remover_arv(raiz->no_dir,chave);
             } else {
                raiz->no_esq = remover_arv(raiz->no_esq,chave);
             }
             return raiz;
          }
       }
}

ArvNo* buscar_arv(ArvNo* raiz,int chave){
       if(raiz){
            if(chave == raiz->valor){
                     return raiz;
            } else if (chave > raiz->valor){
               return buscar_arv(raiz->no_dir,chave);
            } else {
               return buscar_arv(raiz->no_esq,chave);
            }
       }
       return NULL;
}

ArvNo* buscar_invalido_no(ArvNo* raiz){
       if(raiz){
            if(raiz->posX <= 0 || raiz->posX >= 78){
                     return raiz;
            } else {
               ArvNo* aux = buscar_invalido_no(raiz->no_dir);
               if(aux == NULL){
                  aux = buscar_invalido_no(raiz->no_esq);
               }
               return aux;
            }  
       }
       return NULL;
}

int altura(ArvNo* raiz){
    if(raiz == NULL){
       return -1;
    } else {
       int esq = altura(raiz->no_esq);
       int dir = altura(raiz->no_dir);
       if(esq > dir){
          return esq + 1;
       } else {
          return dir + 1; 
       }
    }
}

#endif
