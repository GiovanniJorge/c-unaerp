# C - Unaerp

Exercícios em linguagem C usados nas aulas da Unaerp — coleção organizada por tópicos (manipulação de arquivos, strings, sub-rotinas, estruturas de dados e exercícios gerais). Ideal para estudantes que querem fixar os conceitos da linguagem, praticar a lógica de programação e entender a aplicação de estruturas de dados na prática.

## Conteúdo principal
- Exercícios focados em problemas didáticos para aprendizagem de C.
- Estrutura simples por pastas que separa exercícios por tema.
- Exemplos que usam arquivos CSV como entrada/saída em alguns exercícios.

## Badges
![Licença](https://img.shields.io/github/license/GiovanniJorge/c-unaerp?style=flat-square)

## Sumário
- [Visão geral](#visão-geral)
- [Estrutura do repositório](#estrutura-do-repositório)
- [Como compilar e executar](#como-compilar-e-executar)
- [Contribuindo](#contribuindo)
- [Licença](#licença)
- [Autor / Contato](#autor--contato)

## Visão geral
Este repositório organiza pequenos programas em C que exemplificam conceitos de linguagem e resolução de problemas. Cada arquivo fonte normalmente resolve um exercício específico e está escrito de forma limpa e comentada para fins pedagógicos.

## Estrutura do repositório
Top-level:
```text
├── .gitattributes
├── LICENSE
├── README.md
├── exercicios-arquivos/        # Exercícios envolvendo leitura/escrita de arquivos (CSV, etc.)
│   ├── arquivos-ex1/           # Exemplo com alunos.csv, alunos_ordenados_por_nome.csv, código.c
│   └── arquivos-ex2/           # Exemplo com nascar_champions.csv, etc.
├── exercicios-geral/           # Exercícios diversos (ex.: geral-ex1.c, geral-ex2.c)
├── exercicios-strings/         # Exercícios com strings (strings-ex1.c, ..., strings-ex8.c)
├── exercicios-subrotina/       # Exercícios com funções/subrotinas (subrotina-ex1.c, ..., subrotina-ex9.c)
└── exercicios-tads/            # Exercícios com tipos abstratos de dados (TADs)
```

### Como se encaixa:
- Cada arquivo `.c` é um programa independente (exercício). A forma usual de usar o repositório é compilar o arquivo que você quer executar.
- Arquivos CSV fornecem dados de exemplo para exercícios de I/O na pasta `exercicios-arquivos`.

## Como compilar e executar
Recomenda-se usar GCC (ou outro compilador compatível). Exemplos:

### Compilar um exercício único:
```bash
gcc -std=c11 -Wall -Wextra -pedantic -O2 -g exercicios-geral/geral-ex1.c -o geral-ex1
./geral-ex1
```

### Compilar um exercício na pasta de strings:
```bash
gcc -std=c11 -Wall -Wextra exercicios-strings/strings-ex3.c -o strings-ex3
./strings-ex3
```

### Compilar todos os .c em uma pasta (rápido para testes):
```bash
# Dentro da pasta correspondente
gcc -std=c11 -Wall -Wextra *.c -o exercicios
```

### Executar um programa que lê de arquivo CSV (exemplo):
Se o binário espera um arquivo como argumento:
```bash
./arquivos-ex1/codigo
```
Ou, se o programa lê do `stdin` (redirecionamento de entrada):
```bash
./arquivos-ex1/codigo < exercicios-arquivos/arquivos-ex1/alunos.csv
```

## Contribuindo
Contribuições são bem-vianor (ex.: correções, comentários, novos exercícios, testes). Fluxo sugerido:
1. Fork do repositório.
2. Criar branch com nome descritivo: `feature/exercicio-nome` ou `fix/readme`.
3. Fazer commits atômicos com mensagens claras.
4. Abrir Pull Request descrevendo as mudanças e, se aplicável, o motivo pedagógico.
5. Se possível, inclua casos de teste ou instruções para validar o exercício.

## Licença
Este repositório utiliza a licença MIT — consulte o arquivo [LICENSE](LICENSE) na raiz.

## Autor / Contato
- **Autor:** Giovanni Jorge  
- **Repositório:** [https://github.com/GiovanniJorge/c-unaerp](https://github.com/GiovanniJorge/c-unaerp)
