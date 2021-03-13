
/* Alunos: Eduardo Purkote e Guilherme Mota 
GRR's      20182960          20197268
   **Arquivo de Funções Auxiliares**
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "myht.h"



//Função que compara duas tabelas Hash
int compara(const void *a, const void *b)
{
  if(((tabelaHash*)a)->valor == ((tabelaHash*)b)->valor)
  {
    return 0;
  }
  else if(((tabelaHash*)a)->valor < ((tabelaHash*)b)->valor)
  {
    return -1;
  }
  else
  {
    return 1;
  }
}

//Função de Cálculo de Hash para a tabela 1
int h1(int chave)
{
  return chave % M; 	
}

//Função de Cálculo de Hash para a tabela 2
int h2(int chave)
{
  return (int)floor(M * (chave * 0.9 - floor(chave * 0.9)));
}

//Função que inicia o Hash
void iniciarHash(tabelaHash *t, char *Ntabela)
{
  for (int i = 0; i < M; i++)
  {
    t[i].indice = i;
	t[i].valor = 0;
	strcpy(t[i].tabela, Ntabela);
	t[i].vazio = 1;
  }
} 

//Função que realiza busca nas tabelas Hash
void * buscar(int chave, tabelaHash *t1, tabelaHash *t2)
{
  int indice;
  void * result;
  indice = h1(chave);
  if(t1[indice].vazio == 1)
  {
    return NULL;
  }
  if(t1[indice].valor == chave)
  {
	return result = &indice;
  }
  else
  {
	indice = h2(chave);
	return result = &indice;
  }
}

//Função de inserção nas tabelas Hash
void inserir(int chave, tabelaHash *t1, tabelaHash *t2)
{
  int indice = h1(chave);
  if(t1[indice].vazio == 1)
  {
    t1[indice].valor = chave;
	t1[indice].vazio = 0;
  }
  else
  {
	int aux = t1[indice].valor;
	if(aux != chave)
	{
	  t1[indice].valor = chave;
	  indice = h2(aux); 
	  t2[indice].valor = aux;
	  t2[indice].vazio = 0;
    }
  }
}

//Função de remoção nas tabelas Hash
void remover(int chave, tabelaHash *t1, tabelaHash *t2)
{
  int indice = h2(chave);
  if(t2[indice].valor == chave)
  {
	t2[indice].valor = 0;
	t2[indice].vazio = 1;
  }
  else
  {	
	indice = h1(chave);
	t1[indice].valor = 0;
	t1[indice].vazio = 1;
  }
}

