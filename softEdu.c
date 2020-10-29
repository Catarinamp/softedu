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
                puts("Opção inválida");
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
    system("cls");
    Aluno a;
    if(p == NULL)
    {
        return NULL;
        printf("Nao ha dados para serem removidos");
    }

    char nome[60], name2[60];
    printf("\nEntre com o nome que deseja remover: ");
    scanf("%c", nome);
    gets(nome);
    strlwr(nome);

    Lista *ant = NULL;
    Lista *aux = p;
    while(aux != NULL)
    {
        strcpy(name2, aux->info.nome);
        strlwr(name2);
        if(strcmp(nome, name2) == 0)
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
    system("pause");
    system("cls");
    return p;
}

Lista* busca (Lista* l, Aluno a)
{
    Lista* p;
    printf("Digite a matricula: ");
    scanf("%d", &a.matricula);
    for (p=l; p!=NULL; p=p->prox)
        if (p->info.matricula == a.matricula)
            printf("Matricula encontrada");
    return p;
    return NULL; /* não achou o elemento */
    printf("Matricula nao registrada\n");
    system("pause");

    system("cls");
}

void libera (Lista *l)
{
    Lista *p = l;
    while (p != NULL)
    {
        Lista *t = p->prox; /* guarda referência para o próximo elemento */
        free(p); /* libera a memória apontada por p */
        p = t; /* faz p apontar para o próximo */
    }
}
