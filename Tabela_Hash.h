#ifndef TABELA_HASH_H
#define TABELA_HASH_H
#define TAMANHO_TABELA 75

typedef struct {
    char nome[25];
    char telefone[15];
} Contato;

typedef struct {
    Contato contato;
    int ocupado;
} EntradaHash;

typedef struct {
    EntradaHash tabela[TAMANHO_TABELA];
} TabelaHash;

void inicializar_tabela(TabelaHash *tabela);
int contato_existe(TabelaHash tabela, Contato contato);
void inserir_contato(TabelaHash *tabela, Contato contato);
Contato buscar_contato(TabelaHash tabela, char *chave);
void listar_contatos(TabelaHash tabela);
void remover_contato(TabelaHash *tabela, char *nome);

#endif
