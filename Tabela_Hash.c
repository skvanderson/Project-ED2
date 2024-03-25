#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int hash_divisao(char *chave) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        soma += chave[i];
    }
    return soma % TAMANHO_TABELA;
}

void inicializar_tabela(TabelaHash *tabela){
    for (int i =0; i< TAMANHO_TABELA; i++;) {
        tabela->tabela[i].ocupado = 0;
    }
    
}

int contato_existe(TabelaHash tabela, Contato contato) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        if (tabela.tabela[i].ocupado && strcmp(tabela.tabela[i].contato.nome, contato.nome) == 0 && strcmp(tabela.tabela[i].contato.telefone, contato.telefone) == 0) {
            return 1;
        }
    }
    return 0;
}
