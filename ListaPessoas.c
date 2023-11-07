#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodePessoa {
    int idade;
    char nome[15];
    struct nodePessoa *ant;
    struct nodePessoa *prox;
} nodep;

typedef struct no{
    struct nodep *inicio;
    struct nodep *fim;
    int tamanholista;
    int i;
} listaDuplamente;

void crialista(listaDuplamente *l);
nodep *aloca(int i, char *n);
void insereInicio(listaDuplamente *l, int i, char *n);
void imprimeLista(listaDuplamente *l);
int busca(listaDuplamente *l, int v);
void removevalor(listaDuplamente *l, int v);
void inverte(listaDuplamente *l);

int main() {
    listaDuplamente lista;
    crialista(&lista);
    int i,d;
    char n[15];

    for (i = 0; i < 5; i++) {
        printf("idade: ");
        scanf("%d", &d);
        printf("nome: ");
        gets(n);

        insereInicio(&lista, d, n);
    }

    imprimeLista(&lista);
    inverte(&lista);
    //busca(&lista, 7);
    //removevalor(&lista, 5);
    printf("invertida\n");
    imprimeLista(&lista);

return 0;
}

void crialista(listaDuplamente *l) {
    l->inicio = NULL;
    l->fim = NULL;
    l->tamanholista = 0;
}

nodep *aloca(int i, char *n) {
    nodep *pess = (nodep *)malloc(sizeof(nodep));

    if (pess == NULL) {
        return NULL;
    }

    strcpy(pess->nome, n);
    pess->idade = i;
    pess->prox = NULL;
    pess->ant = NULL;

    return pess;
}

void insereInicio(listaDuplamente *l, int i, char *n) {
    nodep *pess = aloca(i, n);

    if (pess == NULL) {
        return;
    }

    if (l->inicio == NULL) {
        l->inicio = pess;
        l->fim = pess;
    } else {
        pess->prox = l->inicio;
        l->inicio = pess;
    }
    
    l->tamanholista++;
}

void imprimeLista(listaDuplamente *l) {
    nodep *aux= l->inicio;
    while (aux != NULL) {
        printf("idade: %d, nome: %s\n", aux->idade, aux->nome);
        aux = aux->prox;
    }
}

int busca(listaDuplamente *l, int v){
    nodep *aux = l->inicio;

    while(aux != NULL){
        if(aux->idade == v){
            printf("encontrado...\n");
            return aux;
        }
        aux = aux->prox;
    }
    return 0;
}

void removevalor(listaDuplamente *l, int v) {
    nodep *aux = l->inicio;

    while (aux != NULL) {
        if (aux->idade == v) {
            if (aux->ant != NULL)
                aux->ant->prox = aux->prox;
            else {
                l->inicio = aux->prox;
            }
            if (aux->prox != NULL)
                aux->prox->ant = aux->ant;
            else {
                l->fim = aux->ant;
            }
            free(aux);
            break;
        }
        aux = aux->prox;
    }
}

void inverte(listaDuplamente *l){
    nodep *aux = NULL;
    nodep *atual = l->inicio;

    while (atual != NULL) {
        aux = atual->ant;
        atual->ant = atual->prox;
        atual->prox = aux;

        atual = atual->ant;
    }
    aux = l->inicio;
    l->inicio = l->fim;
    l->fim = aux;
}
