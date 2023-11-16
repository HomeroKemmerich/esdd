#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/// defini��o dqa estrutura do nodo a ser utilizado na leitura]
/// o nodo � um tipo de dado definindo pelo usu�rio(n�o � um TAD pois n�o estamos trabalhando com POO)

struct nodo
{
    char info[128];
    struct nodo *elo;
};
//descri��o da estrutura do descritor da pilha

struct desc_pilha
{
    struct nodo *topo;
    struct nodo *base;
    int tamanho;

};

///fun��o que busca um determinado valor na pilha, retornando seu endere�o de mem�ria ou NULL, caso n�o exista
struct nodo *busca(struct desc_pilha pilha, char VALOR[128])
{
    struct nodo *endereco;

    endereco = pilha.topo;//come�a no topo

    while(endereco != NULL)//continua at� o base
    {
        if (strcmp(VALOR, endereco->info)==0)//se chegou no base
        {
            break;
        }
        endereco = endereco->elo;
    }
    return endereco;
}

int main(void)
{
    char opcao, opcao2, VALOR[128];
    struct desc_pilha pilha;
    struct nodo *endereco, *novo, *anterior;
    int existe;

    ///inicializa��o da pilha (do descritor da pilha)
    pilha.topo = NULL;
    pilha.base    = NULL;
    pilha.tamanho= NULL;

    do
    {
        puts("\n\n M E N U");
        puts("\n--------");
        puts("I - Incluir");
        puts("C - Consulta");
        puts("R - Retirar");
        puts("M - Mostrar");
        puts("F - Finalizar");
        puts("\nSua opcao:");
        fflush(stdin);
        scanf("%c", &opcao);
        opcao = toupper(opcao);// transforma qualquer letra em maiuscula / tolower() faz o contr�rio
        system("cls");//cls limpa a tela em DOS

        switch(opcao)
        {
        case 'I':


            printf("Digite o valor a ser incluido: ");
            fflush(stdin);
            scanf("%s", VALOR);

            ///obter um novo nodo na mem�ria para adicionar o �ndice
            novo = malloc(sizeof(struct nodo));

            if (novo == NULL)
            {
                puts("\n *** Erro na aloca��o de mem�ria");
            }
            else
            {
                strcpy(novo->info, VALOR);
                novo->elo = pilha.topo;
                if (pilha.topo == NULL)//testa se a pilha est� vazia
                    pilha.base = novo;//se estiver, atualiza o in�cio

                pilha.topo = novo;
                pilha.tamanho++;
                puts("\n ***Inclusao realizada com sucesso");
                system("pause");
            }



            system("pause");//"Pressione qualquer tecla para continuar..."
            break;

        case 'C':
            puts("\n CONSULTA");

            if(pilha.topo == NULL)
                puts("\n***Pilha vazia");
            else
            {
                printf("\nValor no topo: %s\n", pilha.topo->info);
            }
            system("pause");
            break;

        case 'R':
            puts("\n RETIRAR");
            if (pilha.topo == NULL)
            {
                puts("\n***Pilha vazia/underflow\n");
            }
            else
            {
                printf("\nInformacao retirada: %s", pilha.topo->info);
                endereco = pilha.topo;

                if (pilha.topo == pilha.base)///�nico
                    pilha.topo == pilha.base == NULL;
                else
                    pilha.topo = pilha.topo->elo;

                pilha.tamanho--;
                free(endereco);
                puts("\nRetirada realizada com sucesso");
            }

            system("pause");
            break;

        case 'M':
            puts("\n MOSTRAR");
            if (pilha.topo==NULL)
                puts("\n***pilha vazia");
            else
            {
                endereco = pilha.topo;
                while(endereco!= NULL)
                {
                    printf("%s\n", endereco->info);//Quando a vari�vel � um endere�o n�o se usa "." , mas sim "->"
                    endereco = endereco->elo;//ex.: (endere�o.info)!=(endere�o->
                }
            }

            system("pause");
            break;

        case 'F':
            puts("\n FINALIZAR");
            break;
        }
    }
    while(opcao != 'F');
    printf("\nTschuss\n");
    return 0;
}
