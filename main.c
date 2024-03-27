#include "Tabela_Hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void limpar_tela() {
    system("clear");
}

int main() {
    TabelaHash tabela;
    Contato novo_contato;
    int opcao;
    char nome_busca[50], nome_remover[50], opcao_str[50];

    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabela.tabela[i].ocupado = 0;
    }
    srand(time(NULL));

    while (1) {
        printf("\nBem-Vindo à Lista Telefônica\n\n");
        printf("1-Novo Contato\n");
        printf("2-Buscar Contato\n");
        printf("3-Remover Contato\n");
        printf("4-Sair\n");
        printf("5-Listar Todos os Contatos\n");
        printf("Escolha uma opção: ");
        scanf("%s", opcao_str);

        limpar_tela();

        int is_numeric = 1;
        for (int i = 0; opcao_str[i] != '\0'; i++) {
            if (!isdigit(opcao_str[i])) {
                is_numeric = 0;
                break;
            }
        }

        if (!is_numeric) {
            printf("Opção inválida. Por favor, digite um número.\n");
            continue;
        }
        opcao = atoi(opcao_str);

        switch (opcao) {
            case 1:
                printf("Qual é o nome do novo contato?\n");
                scanf("%s", novo_contato.nome);
                printf("Qual é o número deste contato?\n");
                scanf("%s", novo_contato.telefone);
                inserir_contato(&tabela, novo_contato);
                break;
            case 2:
                printf("Qual contato deseja buscar? (Digite o nome ou número de telefone)\n");
                scanf("%s", nome_busca);
                novo_contato = buscar_contato(tabela, nome_busca);
                if (strcmp(novo_contato.nome, "") != 0) {
                    printf("Informações do Contato:\nNome: %s\nTelefone: %s\n", novo_contato.nome, novo_contato.telefone);
                } else {
                    printf("Contato inexistente.\n");
                }
                break;
            case 3:
                printf("Digite o nome do contato a ser removido: ");
                scanf("%s", nome_remover);
                remover_contato(&tabela, nome_remover);
                break;
            case 4:
                printf("Até mais!\n");
                exit(0);
            case 5:
                listar_contatos(tabela);
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
    return 0;
}
