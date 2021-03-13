/* Alunos: Eduardo Purkote e Guilherme Mota 
GRR's      20182960          20197268
   **Arquivo de Biblioteca para as funções e definições das tabelas Hash**
*/
#ifndef __HASH__
#define __HASH__
//Define M para o valor 11 que é o tamanho da tabela Hash
#define M 11

//Estrutura que define a tabela Hash
typedef struct tabelaHash{
	int indice;
	int valor;
	char tabela[2];
	int vazio;
}tabelaHash;

//Definição das Funções  que implementam as tabelas hash

//Função que compara duas tabelas Hash
int compara(const void *a, const void *b);

//Função de Cálculo de Hash para a tabela 1
int h1(int chave);

//Função de Cálculo de Hash para a tabela 2
int h2(int chave);

//Função que inicia o Hash
void iniciarHash(tabelaHash *t, char *Ntabela);

//Função que realiza busca nas tabelas Hash
void * buscar(int chave, tabelaHash *t1, tabelaHash *t2);

//Função de inserção nas tabelas Hash
void inserir(int chave, tabelaHash *t1, tabelaHash *t2);

//Função de remoção nas tabelas Hash
void remover(int chave, tabelaHash *t1, tabelaHash *t2);
#endif
