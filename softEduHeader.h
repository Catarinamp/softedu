struct aluno
{
    char nome[100];
    int matricula;
    char disciplina[50];
    float nota;
};
typedef struct aluno Aluno;

struct lista
{
    Aluno info;
    struct lista *prox;
};
typedef struct lista Lista;

Lista *inserir(Lista *l, Aluno a);
Aluno cadastrar();
void *exibir(Lista *l);
void *pesquisar(Lista *l);

