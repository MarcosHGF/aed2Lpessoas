#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//1
typedef struct pessoa{
    char nome[15];
    int idade;
}Pessoa;

typedef struct node{
    int dado;
    struct node *prox;
    struct node *ant;
}Node;

typedef struct nodep{
    Pessoa *pess;
    struct nodep *prox;
    struct nodep *ant;
}NodeP;

//funções
void insereInicio(NodeP **l, int idade, char nome[15]);
NodeP* busca(NodeP *l, int idade);
void removevalor(NodeP **l, int v);
void invertelista(NodeP *l, NodeP **new);
void mostralista(NodeP *l);

int main(){
    NodeP *l = NULL;
    NodeP *new = NULL;

    insereInicio(&l, 5, "A");
    insereInicio(&l, 12, "B");
    insereInicio(&l, 3, "C");
    insereInicio(&l, 9, "D");
    insereInicio(&l, 4, "E");
    mostralista(l);
    printf("\n");

    busca(l, 12);

    removevalor(&l, 12);

    mostralista(l);

    invertelista(l, &new);
    printf("\n");
    mostralista(l);
    printf("\n");
    mostralista(new);

    return 0;
}
//2

void insereInicio(NodeP **l, int idade, char nome[15]){
    NodeP *aux = (NodeP *)malloc(sizeof(NodeP));
    if (aux == NULL) {
        return;
    }
    aux->pess = (Pessoa *)malloc(sizeof(Pessoa));
    if (aux->pess == NULL) {
        free(aux);
        return;
    }
    strcpy(aux->pess->nome, nome);
    aux->pess->idade = idade;
    aux->ant = NULL;
    aux->prox = *l;

    if (*l != NULL) {
        (*l)->ant = aux;
    }
    *l = aux;
}

//3
NodeP* busca(NodeP *l, int idade){
    NodeP *aux = l;
    NodeP *existe = NULL;

    while(l->prox !=aux){
        if(l->pess->idade == idade){
            existe = l;
            printf("\nencontrado...\n");
            break;
        }
        l = l->prox;
    }
    return existe;
}

//4

void removevalor(NodeP **l, int v){
    NodeP *aux = *l;

    while (aux != NULL) {
        if (aux->pess->idade == v){
            if (aux->ant)
                aux->ant->prox = aux->prox;
            else
                *l = aux->prox;

            if (aux->prox)
                aux->prox->ant = aux->ant;

            free(aux);
            return;
        }
        aux = aux->prox;
    }
}

//5
void invertelista(NodeP *l, NodeP **new){
    NodeP *aux = l;
    *new = NULL;
    while (aux != NULL) {
        insereInicio(new, aux->pess->idade, aux->pess->nome);
        aux = aux->prox;
    }
}

//para teste
void mostralista(NodeP *l){
    NodeP *aux = l;
    while(aux != NULL){
        printf("%d, %s\n", aux->pess->idade, aux->pess->nome);
        aux = aux->prox;
    }
}
