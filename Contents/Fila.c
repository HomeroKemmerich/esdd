#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/// defini��o dqa estrutura do nodo a ser utilizado na leitura
/// o nodo � um tipo de dado definindo pelo usu�rio(n�o � um TAD pois n�o estamos trabalhando com POO)

struct nodo
{
    char info[128];
    struct nodo *elo;
};
//descri��o da estrutura do descritor da fila

struct desc_fila
{
    struct nodo *frente;
    struct nodo *re;
    int tamanho;

};

///fun��o que busca um determinado valor na fila, retornando seu endere�o de mem�ria ou NULL, caso n�o exista
struct nodo *busca(struct desc_fila fila, char VALOR[128])
{
    struct nodo *endereco;

    endereco = fila.frente;//come�a no frente

    while(endereco != NULL)//continua at� o re
    {
        if (strcmp(VALOR, endereco->info)==0)//se chegou no re
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
    struct desc_fila fila;
    struct nodo *endereco, *novo, *anterior;
    int existe;

    ///inicializa��o da fila (do descritor da fila)
    fila.frente = NULL;
    fila.re    = NULL;
    fila.tamanho= NULL;

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
            puts("\n INCLUSAO");


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
                novo->elo = NULL;
                if (fila.frente == NULL)//testa se a fila est� vazia
                {
                    fila.frente = novo;//se estiver, atualiza o in�cio
                }
                else
                    fila.re->elo = novo;
                fila.re = novo;//atualiza a re da fila
                fila.tamanho++;
                puts("\n ***Inclusao realizada com sucesso");
                system("pause");
            }


            system("pause");//"Pressione qualquer tecla para continuar..."
            break;

        case 'C':
            puts("\n CONSULTA");

            if(fila.frente == NULL)
                puts("\n***Pilha vazia");
            else
            {
                printf("\nValor na frente: %s\n", fila.frente->info);
            }
            system("pause");
            break;

        case 'R':
            puts("\n RETIRAR");
            if (fila.frente == NULL)
            {
                puts("\n***fila vazia\n");
            }
            else
            {
                printf("\nInformacao retirada: %s", fila.frente->info);
                endereco = fila.frente;
                if (fila.frente == fila.re)///�nico
                {
                    fila.frente == fila.re == NULL;
                }
                else
                {
                    fila.frente = fila.frente->elo;
                }
            }
            /*else
            {

                    /*else
                    {
                        if (endereco == fila.frente)///Primeiro
                            fila.frente = fila.frente->elo;
                        else
                        {
                            /// como tanto ptanto para o caso ultimo quanto para o intermediario
                            ///eh necessario saber quem � o anterior do  nodo
                            anterior = fila.frente;
                            while(anterior->elo != endereco)
                                anterior = anterior->elo;

                            if (endereco == fila.re)///�ltimo
                            {
                                fila.re = anterior;
                                fila.re->elo = NULL;
                            }
                            else ///Intermedi�rio
                                anterior->elo = endereco->elo;
                        }
                    }*/
            fila.tamanho--;
            free(endereco);
            puts("\nRetirada realizada com sucesso");
            system("pause");
            break;

        case 'M':
            puts("\n MOSTRAR");
            if (fila.frente==NULL)
                puts("\n***fila vazia");
            else
            {
                endereco = fila.frente;
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
