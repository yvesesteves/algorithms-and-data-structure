/*
    Yves Yan Esteves Pereira - 12021BCC022
    LAB01 - Exercicio 11 - Agenda
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Endereco{
  char rua[30], bairro[30], complemento[50], cidade[30], estado[30], pais[30];
  int numero, cep;
};

struct Telefone{
  int numero, ddd;
};

struct Aniversario{
  int dia, mes, ano;
};

struct Contact{
  char nome[50], email[30], observacao[50];
  struct Endereco endereco;
  struct Telefone telefone;
  struct Aniversario aniversario;
};
// estruturas pedidas no item (a)

typedef struct Contact Contact;


void mostraString(char *string)
{
  for (int i = 0; string[i] != '\0'; i++)
  {
    printf("%c", string[i]);
  }
}


void mostraStruct(Contact *c)
{
  printf("\n");
  printf("\nNome:");
  mostraString(c->nome);
  printf("\nAniversario: ");
  printf("%d/%d/%d", c->aniversario.dia, c->aniversario.mes, c->aniversario.ano);
 /* printf("\nDia: %d", c->aniversario.dia);
  printf("\nMes: ");
  printf("%d", c->aniversario.mes);
  printf("\nAno: ");
  printf("%d", c->aniversario.ano);
  */
  printf("\nemail: ");
  mostraString(c->email);
  printf("\nObs: ");
  mostraString(c->observacao);
  printf("\n");
  printf("Telefone: (%d)%d", c->telefone.ddd, c->telefone.numero);
  printf("\n--Endereco--");
  printf("\nRua: ");
  mostraString(c->endereco.rua);
  printf("\nNumero: ");
  printf("%d", c->endereco.numero);
  printf("\nBairro: ");
  mostraString(c->endereco.bairro);
  printf("\nComplemento: ");
  mostraString(c->endereco.complemento);
  printf("\nCidade: ");
  mostraString(c->endereco.cidade);
  printf("\nEstado: ");
  mostraString(c->endereco.estado);
  printf("\nPais: ");
  mostraString(c->endereco.pais);
  printf("\nCEP: ");
  printf("%d", c->endereco.cep);
  printf("\n\n");
}


char toUpperCase(char letter)
{
  if (letter >= 97 && letter <= 122)
  {
    return letter - 32;
  }
  else
  {
    return letter;
  }
}


void showNomeTelefoneEmail(Contact *c, int tam)
{
  for (int i = 0; i < tam; i++)
  {
    printf("\nNome: ");
    mostraString(c[i].nome);
    printf("\nE-mail: ");
    mostraString(c[i].email);
    printf("\n");
    printf("Telefone: (%d)%d", c[i].telefone.ddd, c[i].telefone.numero);
    printf("\n");
  }
}

void showAllContacts(Contact *c, int tam)
{
  for (int i = 0; i < tam; i++)
  {
    mostraStruct(&c[i]);
  }
}

void alfabeticOrder(Contact vet_contact[], int n_contact)
{
  Contact aux;
  int i, j, y = 0;
  for (y = n_contact; y >= 0; y--)
    for (i = 0; i < n_contact - 1; i++)
      for (j = i + 1; j < n_contact; j++)
      {
        if (toUpperCase(vet_contact[i].nome[y]) > toUpperCase(vet_contact[j].nome[y]))
        {
          aux = vet_contact[i];
          vet_contact[i] = vet_contact[j];
          vet_contact[j] = aux;
        }
      }
}

void createContact(Contact vet_contato[], int indice)
{
  printf("\n\nNome: ");
  fflush(stdin);
  gets(vet_contato[indice].nome);
  printf("\n--Aniversario--");
  printf("\nDia: ");
  scanf("%d", &vet_contato[indice].aniversario.dia);
  printf("\nMes(em numeral): ");
  scanf("%d", &vet_contato[indice].aniversario.mes);
  printf("\nAno: ");
  scanf("%d", &vet_contato[indice].aniversario.ano);
  printf("\nEmail: ");
  fflush(stdin);
  gets(vet_contato[indice].email);
  printf("\nObservacao: ");
  fflush(stdin);
  gets(vet_contato[indice].observacao);
  printf("\nDDD: ");
  scanf("%d", &vet_contato[indice].telefone.ddd);
  printf("\nNumero: ");
  scanf("%d", &vet_contato[indice].telefone.numero);
  printf("\nEndereco");
  printf("\nRua: ");
  fflush(stdin);
  gets(vet_contato[indice].endereco.rua);
  printf("\nNumero: ");
  scanf("%d", &vet_contato[indice].endereco.numero);
  printf("\nBairro: ");
  fflush(stdin);
  gets(vet_contato[indice].endereco.bairro);
  printf("\nComplemento: ");
  fflush(stdin);
  gets(vet_contato[indice].endereco.complemento);
  printf("\nCidade: ");
  fflush(stdin);
  gets(vet_contato[indice].endereco.cidade);
  printf("\nEstado: ");
  fflush(stdin);
  gets(vet_contato[indice].endereco.estado);
  printf("\nPais: ");
  fflush(stdin);
  gets(vet_contato[indice].endereco.pais);
  printf("\nCep: ");
  scanf("%d", &vet_contato[indice].endereco.cep);
  alfabeticOrder(vet_contato, indice);
  printf("\n<<Contato adicionado a lista>>\n\n");
}

int deleteContact(Contact vetor_contato[], int contador, char nome[])
{

  int aux = 0, indice_pessoa, op;
  for (int i = 0; i < contador; i++)
  {
    if (strcmp(nome, vetor_contato[i].nome) == 0)
    {
      aux = 1;
      indice_pessoa = i;
      printf("\nNome: ");
      mostraString(vetor_contato[i].nome);
      printf("\nE-mail: ");
      mostraString(vetor_contato[i].email);
      printf("\n");
    }
  }
  if (aux == 1)
  {
    printf("\n\nDeseja mesmo excluir o contato? Digite 1 para SIM ou 2 para NAO: ");
    scanf("%d", &op);
    if (op == 1)
    {
      for (int i = indice_pessoa; i < contador; i++)
        vetor_contato[i] = vetor_contato[i + 1];
      return contador - 1;
      printf("Pessoa deletada da lista\n");
    }
  }
  else
  {
    printf("\nPessoa não registrada.");
  }
  return contador;
}


int main(){
  Contact agenda[100];  // variavel pedida no item (b)
  int i, contador = 0, opc, tam = 101;
  char nome_pesquisa[100];
  int mes_pesquisa, dia_pesquisa;
  char nome_retirar[50];

  do{     // menu pedido na instrução (i)
    printf("-----------------MENU-----------------\n");
    printf("[1] - Insere pessoa\n");
    printf("[2] - Retira pessoa\n");
    printf("[3] - Busca por primeiro nome\n");
    printf("[4] - Busca por mes de aniversario\n");
    printf("[5] - Busca por dia e mes de aniversario\n");
    printf("[6] - Imprimir nome, telefone e email\n");
    printf("[7] - Imprimir todos os dados cadastrados\n");
    printf("[8] - Sair\n");
    printf("------------------------------------------\n");
    printf("Digite uma opcao: ");
    scanf("%d", &opc);
    printf("\n");

    switch(opc){   // instruções do item (f) (Função createContact e alfabeticOrder)
      case 1:
        createContact(agenda, contador);
        contador++;
          break;
        
      case 2:   // instruções do item (g) (Função deleteContact)       
        printf("\n");
        printf("Informe o nome da pessoa a ser excluida: ");
        fflush(stdin);
        gets(nome_retirar);
        contador = deleteContact(agenda, contador, nome_retirar);
          break;

      case 3:   // instruções pedida no item (c)
        printf("Informe o nome: ");
        scanf("%s", nome_pesquisa);
        for(i = 0; i < tam; i++){
            if(strcmp(nome_pesquisa, agenda[i].nome) == 0){
                printf("\n");
						  mostraStruct(&agenda[i]);
            }
        }
          break;

      case 4:   // instruções pedida no item (d)
        printf("Informe o mes (em forma de numeral) que deseja pesquisar: ");
        scanf("%d", &mes_pesquisa);
        for(i = 0; i < tam; i++){
          if(mes_pesquisa == agenda[i].aniversario.mes){
            mostraStruct(&agenda[i]);
          }
        }
          break;

      case 5:   // instruções pedidas no item (e)
        printf("Informe o dia e mes, respectivamente, que deseja pesquisar: ");
        scanf("%d", &dia_pesquisa);
        scanf("%d", &mes_pesquisa);
        for(i = 0; i< tam; i++){
          if(dia_pesquisa == agenda[i].aniversario.dia && mes_pesquisa == agenda[i].aniversario.mes){
            mostraStruct(&agenda[i]);  
          }
        }
          break;

      case 6:   // instrução do item (h - I), (função showTelefoneEmail)
        printf("----NOME, TELEFONE E EMAIL DOS CONTATOS CADASTRADOS:----\n");
        alfabeticOrder(agenda, contador);
        showNomeTelefoneEmail(agenda, contador);
          break;

        case 7:   // instrução do item (h - II), (função showAllContacts)
          printf("----TODOS OS DADOS CADASTRADOS----\n");
          alfabeticOrder(agenda, contador);
          showAllContacts(agenda, contador);
            break;
        
        case 8:
          printf("\n\n--Fim do programa---\n\n");
          opc = 8;
            break;

        default:
          if(opc != 8){
            printf("Opcao invalida, digite uma opcao de 1 a 8\n");
          }     
    }


  }while(opc != 8);
    printf("\n");

  return 0;
}