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

void inserir_contato(TabelaHash *tabela, Contato contato) {
    int posicao_inicial, posicao_atual;
    posicao_inicial = hash_divisao(contato.nome);
    posicao_atual = posicao_inicial;
    if (contato_existe(*tabela, contato)) {
        printf("Contato já está salvo na sua agenda.\n");
        return;
    }
    while (tabela->tabela[posicao_atual].ocupado) {
        posicao_atual = (posicao_atual + 1) % TAMANHO_TABELA;
        if (posicao_atual == posicao_inicial) {
            printf("Tabela cheia. Não foi possível inserir o contato.\n");
            return;
        }
    }
        strcpy(tabela->tabela[posicao_atual].contato.nome, contato.nome);
        strcpy(tabela->tabela[posicao_atual].contato.telefone, contato.telefone);
        tabela->tabela[posicao_atual].ocupado = 1;
}

Contato buscar_contato(TabelaHash tabela, char *chave) {
    int telefone_valido = 1;
    for (int i = 0; i < strlen(chave); i++) {
        if (i == 5 || i == 10) {
            if (chave[i] != '-') {
                telefone_valido = 0;
                break;
            }
        } else {
            if (!isdigit(chave[i])) {
                telefone_valido = 0;
                break;
            }
        }
    }

if (telefone_valido) {
        for (int i = 0; i < TAMANHO_TABELA; i++) {
            if (tabela.tabela[i].ocupado && strcmp(tabela.tabela[i].contato.telefone, chave) == 0) {
            return tabela.tabela[i].contato;
            }
        }
    } else {
        for (int i = 0; i < TAMANHO_TABELA; i++) {
            if (tabela.tabela[i].ocupado && strcmp(tabela.tabela[i].contato.nome, chave) == 0) {
            return tabela.tabela[i].contato;
            }
        }
    }
    Contato contato_vazio = {"", ""};
    return contato_vazio;
}

void listar_contatos(TabelaHash tabela) {
    printf("Lista de Contatos:\n");
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        if (tabela.tabela[i].ocupado) {
        printf("Nome: %s, Telefone: %s\n", tabela.tabela[i].contato.nome, tabela.tabela[i].contato.telefone);
        }
    }
}

void remover_contato(TabelaHash *tabela, char *nome) {
    int posicao_inicial, posicao_atual;
    posicao_inicial = hash_divisao(nome);
    posicao_atual = posicao_inicial;

    while (tabela->tabela[posicao_atual].ocupado) {
        if (strcmp(tabela->tabela[posicao_atual].contato.nome, nome) == 0) {
            tabela->tabela[posicao_atual].ocupado = 0;
            printf("Contato Removido\n");
            return;
        }
        posicao_atual = (posicao_atual + 1) % TAMANHO_TABELA;
        if (posicao_atual == posicao_inicial) {
            printf("Contato não encontrado.\n");
            return;
        }
    }

    printf("Contato não encontrado.\n");
}
