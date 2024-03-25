#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define TAMANHO_TABELA 75


typedef struct {
    char nome[50];
    char telefone[15];
} Contato;

typedef struct {
    Contato contato;
    int ocupado;
} EntradaHash;

typedef struct {
    EntradaHash tabela[TAMANHO_TABELA];
} TabelaHash;

int hash_divisao(char *chave) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        soma += chave[i];
    }
    return soma % TAMANHO_TABELA;
}
