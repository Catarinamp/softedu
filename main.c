#include <stdio.h>
#include <stdlib.h>
#include "softEduHeader.h"

main()
{
    Aluno a;
    Lista *l, *p;
    l = NULL;
    int resp;

    do
    {
        puts("-------- Menu --------");
        puts("1 - Cadastrar");
        puts("2 - Exibir lista");
        puts("3 - Pesquisar");
        puts("0 - Sair");
        scanf("%d", &resp);

        switch(resp)
        {
        case 1:
            a = cadastrar();
            l = inserir(l, a);
            break;

        case 2:
            exibir(l);
            break;

        case 3:
            pesquisar(l);
            break;

        case 0:
            exit(1);
            break;

        default:
            puts("Opção inválida");
            break;
        }
    }
    while(1);

}

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
    scanf("%d", &d.matricula);
    printf("Disciplina: ");
    fflush(stdin);
    gets(d.disciplina);
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
