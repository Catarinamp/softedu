#include <conio.h>
#include <stdio.h>
#include "softEduHeader.h"

Lista *inserir(Lista *l, Aluno a)
{
    Lista *novo;
    novo = (Lista *)malloc(sizeof(Lista));
    novo -> info = a;
    novo -> prox = l;
    return novo;
}

Aluno cadastrar()
{
    Aluno d;
    printf("Nome do aluno: ");
    fflush(stdin);
    gets(d.nome);
    printf("Matricula: ");
    fflush(stdin);
    scanf("%d", &d.matricula);
    printf("Disciplina: ");
    fflush(stdin);
    gets(d.disciplina);
    printf("Nota: ");
    fflush(stdin);
    scanf("%f", &d.nota);
    return d;
}

void *exibir(Lista *l)
{
    Lista *p;
    system("cls");
    puts("------ Exibindo Itens da Lista -------");
    for (p = l; p != NULL; p = p -> prox)
    {
        printf("Nome: %s \n", p -> info.nome);
        printf("Matricula: %d \n", p -> info.matricula);
        printf("Disciplina: %s \n", p -> info.disciplina);
        printf("Nota: %.2f \n", p->info.nota);
        puts("---------------------------------------");
    }
    system("pause");
    system("cls");
}

void *pesquisar(Lista *l)
{
    Lista *p;
    int resp;
    system("cls");
    do
    {
        puts("Pesquisar por: ");
        puts("1 - Nome");
        puts("2 - Matricula");
        puts("3 - Disciplinas");
        puts("0 - Sair");
        scanf("%d", &resp);

        if (resp != 0)
        {
            system("cls");
            switch(resp)
            {
            case 1:
                puts("----- Lista dos alunos cadastrados -------");
                for(p = l; p != NULL; p = p -> prox)
                {
                    printf("%s \n", p -> info.nome);
                }
                break;

            case 2:
                puts("----- Lista das matriculas -------");
                for(p = l; p != NULL; p = p -> prox)
                {
                    printf("%d \n", p -> info.matricula);
                }
                break;

            case 3:
                puts("----- Lista das Disciplinas -------");
                for(p = l; p != NULL; p = p -> prox)
                {
                    printf("%s \n", p -> info.disciplina);
                }
                break;

            default:
                puts("Op��o inv�lida");
                break;
            }
        }
        system("pause");
        system("cls");
    }
    while(resp != 0);
}

Lista *remover(Lista *p)
{
    if(p == NULL)
    {
        return NULL;
        printf("Nao ha dados para serem removidos");
    }

    char name[60], name2[60];
    printf("\nEntre com o nome que deseja remover: ");
    gets(name);
    strlwr(name);

    Lista *ant = NULL;
    Lista *aux = p;
    while(aux != NULL)
    {
        strcpy(name2, aux->info.nome);
        strlwr(name2);
        if(strcmp(name, name2) == 0)
            break;
        ant = aux;
        aux = aux->prox;
    }

//se caso, for o primeiro elemento
    if(ant == NULL)
    {
        p = p->prox;
        printf("\n\tNome removido com sucesso!\n\n");
        free(aux);
    }

    else if(aux != NULL)
    {
        ant = aux->prox;
        printf("\n\tNome removido com sucesso!\n\n");
        free(aux);
    }
    free(aux);

    return p;
}
