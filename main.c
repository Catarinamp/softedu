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
        puts("-------- Sistema de gestao educacional --------");
        puts("1 - Cadastrar");
        puts("2 - Exibir lista");
        puts("3 - Pesquisar");
        puts("4 - Deletar lista");
        puts("5 - Buscar lista de dados");
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
        case 4:
            remover(l);
            break;
        case 5:
            busca(l);
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
