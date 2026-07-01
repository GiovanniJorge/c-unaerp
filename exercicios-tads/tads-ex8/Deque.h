struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct deque Deque;

Deque* cria_Deque();
void libera_Deque(Deque* dq);

int insere_Inicio_Deque(Deque* dq, struct aluno al);
int insere_Final_Deque(Deque* dq, struct aluno al);

int remove_Inicio_Deque(Deque* dq);
int remove_Final_Deque(Deque* dq);

int consulta_Inicio_Deque(Deque* dq, struct aluno *al);
int consulta_Final_Deque(Deque* dq, struct aluno *al);

int tamanho_Deque(Deque* dq);
int Deque_vazia(Deque* dq);
void imprime_Deque(Deque* dq);