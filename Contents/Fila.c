#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/// definição dqa estrutura do nodo a ser utilizado na leitura
/// o nodo é um tipo de dado definindo pelo usuário(não é um TAD pois não estamos trabalhando com POO)

struct nodo
{
    char info[128];
    struct nodo *elo;
};
//descrição da estrutura do descritor da fila

struct desc_fila
{
    struct nodo *frente;
    struct nodo *re;
    int tamanho;

};

///função que busca um determinado valor na fila, retornando seu endereço de memória ou NULL, caso não exista
struct nodo *busca(struct desc_fila fila, char VALOR[128])
{
    struct nodo *endereco;

    endereco = fila.frente;//começa no frente

    while(endereco != NULL)//continua até o re
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

    ///inicialização da fila (do descritor da fila)
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
        opcao = toupper(opcao);// transforma qualquer letra em maiuscula / tolower() faz o contrário
        system("cls");//cls limpa a tela em DOS

        switch(opcao)
        {
        case 'I':
            puts("\n INCLUSAO");


            printf("Digite o valor a ser incluido: ");
            fflush(stdin);
            scanf("%s", VALOR);

            ///obter um novo nodo na memória para adicionar o índice
            novo = malloc(sizeof(struct nodo));

            if (novo == NULL)
            {
                puts("\n *** Erro na alocação de memória");
            }
            else
            {
                strcpy(novo->info, VALOR);
                novo->elo = NULL;
                if (fila.frente == NULL)//testa se a fila está vazia
                {
                    fila.frente = novo;//se estiver, atualiza o início
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
                if (fila.frente == fila.re)///Único
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
                            ///eh necessario saber quem é o anterior do  nodo
                            anterior = fila.frente;
                            while(anterior->elo != endereco)
                                anterior = anterior->elo;

                            if (endereco == fila.re)///Último
                            {
                                fila.re = anterior;
                                fila.re->elo = NULL;
                            }
                            else ///Intermediário
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
                    printf("%s\n", endereco->info);//Quando a variável é um endereço não se usa "." , mas sim "->"
                    endereco = endereco->elo;//ex.: (endereço.info)!=(endereço->
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
