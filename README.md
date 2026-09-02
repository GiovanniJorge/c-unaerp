# C - Unaerp

<p align="center">
  <img alt="C" src="https://img.shields.io/badge/C-11-00599C?logo=c&logoColor=white" />
  <img alt="GCC" src="https://img.shields.io/badge/GCC-MinGW%20%7C%20Linux-4EAA25?logo=gnu&logoColor=white" />
  <img alt="status" src="https://img.shields.io/badge/status-ativo-brightgreen" />
  <img alt="licença" src="https://img.shields.io/badge/licen%C3%A7a-MIT-blue" />
</p>

Repositório com exercícios em linguagem C organizados por tópicos, com foco em lógica de programação, estruturas de dados, manipulação de arquivos, strings e sub-rotinas. O objetivo principal é servir como material de estudo e prática para estudantes da Unaerp e para quem deseja reforçar conceitos fundamentais da linguagem C.

## Sumário

- [Descrição do Projeto](#descrição-do-projeto)
- [Arquitetura e Estrutura do Repositório](#arquitetura-e-estrutura-do-repositório)
- [Como Executar Localmente](#como-executar-localmente)
- [Uso e Exemplos](#uso-e-exemplos)
- [Troubleshooting / FAQ](#troubleshooting--faq)
- [Contribuição](#contribuição)
- [Autor](#autor)
- [Licença](#licença)

## Descrição do Projeto

Este repositório reúne programas didáticos em C desenvolvidos para apoiar a aprendizagem e a prática de conceitos fundamentais da linguagem. A organização por temas facilita a leitura e a execução dos exercícios, permitindo estudar cada assunto de forma isolada e progressiva.

Os principais temas abordados incluem:

- estruturas de dados;
- listas sequenciais e dinâmicas;
- manipulação de strings;
- sub-rotinas e funções;
- leitura e escrita de arquivos CSV;
- exercícios gerais de lógica e algoritmos.

A proposta do projeto é simples: cada arquivo `.c` representa um exercício ou exemplo específico, podendo ser compilado e executado de forma independente.

## Arquitetura e Estrutura do Repositório

A estrutura do projeto foi pensada para separar os conteúdos por categoria de estudo:

```text
c-unaerp/
├── LICENSE
├── README.md
├── .gitignore
├── algoritmos-e-otimizacao/
│   ├── tad-dinamica/
│   │   ├── lista-dinamica.c
│   │   ├── lista-dinamica.h
│   │   └── main.c
│   └── tad-sequencial/
│       ├── lista-sequencial.c
│       ├── lista-sequencial.h
│       └── main.c
├── exercicios-arquivos/
│   ├── arquivos-ex1/
│   │   ├── alunos.csv
│   │   ├── alunos_ordenados_por_nome.csv
│   │   └── codigo.c
│   └── arquivos-ex2/
│       ├── codigo.c
│       ├── nascar_champions.csv
│       └── nascar_champions_ordenado.csv
├── exercicios-geral/
│   ├── geral-ex1.c
│   └── geral-ex2.c
├── exercicios-strings/
│   ├── strings-ex1.c
│   ├── strings-ex2.c
│   ├── strings-ex3.c
│   ├── strings-ex4.c
│   ├── strings-ex5.c
│   ├── strings-ex6.c
│   ├── strings-ex7.c
│   └── strings-ex8.c
├── exercicios-subrotina/
│   ├── subrotina-ex1.c
│   ├── subrotina-ex2.c
│   ├── subrotina-ex3.c
│   ├── subrotina-ex4.c
│   ├── subrotina-ex5.c
│   ├── subrotina-ex6.c
│   ├── subrotina-ex7.c
│   ├── subrotina-ex8.c
│   └── subrotina-ex9.c
└── exercicios-tads/
    ├── tads-ex1/
    ├── tads-ex2/
    ├── tads-ex3/
    ├── tads-ex4/
    ├── tads-ex5/
    ├── tads-ex6/
    ├── tads-ex7/
    ├── tads-ex8/
    └── tads-ex9/
```

### Como o código se organiza

- Cada pasta representa uma categoria de exercício ou tema.
- Cada arquivo `.c` normalmente contém uma solução independente para um problema específico.
- Arquivos `.h` e `.c` são usados em exercícios de TADs e listas.
- Alguns exemplos usam arquivos CSV como entrada ou saída para demonstrar leitura e escrita em disco.

O fluxo principal é simples: o programa recebe entrada do usuário ou de um arquivo, processa a lógica em memória e exibe o resultado em console ou grava dados em arquivo.

## Como Executar Localmente

### Pré-requisitos

- GCC ou outro compilador C compatível com C11
- Terminal ou prompt de comando
- Ambiente Windows, Linux ou macOS

### Compilar e executar um exercício

Exemplo de compilação de um programa simples:

```bash
gcc -std=c11 -Wall -Wextra -pedantic -O2 exercicios-geral/geral-ex1.c -o geral-ex1
./geral-ex1
```

Exemplo com strings:

```bash
gcc -std=c11 -Wall -Wextra exercicios-strings/strings-ex3.c -o strings-ex3
./strings-ex3
```

Exemplo com TAD de lista sequencial:

```bash
gcc -std=c11 -Wall -Wextra -pedantic algoritmos-e-otimizacao/tad-sequencial/main.c algoritmos-e-otimizacao/tad-sequencial/lista-sequencial.c -o lista-sequencial
./lista-sequencial
```

### Compilar todos os arquivos de uma pasta

```bash
cd exercicios-strings
gcc -std=c11 -Wall -Wextra *.c -o exercicios
./exercicios
```

### Executar programas que usam CSV

Se o exercício lê dados de um arquivo CSV localmente:

```bash
./exercicios-arquivos/arquivos-ex1/codigo
```

Ou com redirecionamento de entrada:

```bash
./exercicios-arquivos/arquivos-ex1/codigo < exercicios-arquivos/arquivos-ex1/alunos.csv
```

> Este projeto não exige variáveis de ambiente, arquivos `.env` ou dependências externas para execução local básica.

## Uso e Exemplos

Depois de compilar um exercício, o uso mais comum é:

1. escolher o arquivo `.c` desejado;
2. compilar o programa;
3. executar no terminal;
4. analisar a lógica implementada;
5. modificar ou expandir a solução para praticar.

Exemplo prático:

```bash
gcc -std=c11 -Wall -Wextra exercicios-subrotina/subrotina-ex1.c -o subrotina-ex1
./subrotina-ex1
```

Esse estilo de uso é ideal para aprendizado, revisão de conteúdo e experimentação incremental.

## Troubleshooting / FAQ

### Erro de compilação: arquivo `.h` não encontrado

Isso geralmente acontece quando o comando de compilação é executado fora da pasta correta. Certifique-se de rodar o compilador na pasta do projeto ou ajustar os caminhos relativos.

### Erro de linkagem / referência indefinida

Em exercícios com TADs, pode ser necessário compilar também o módulo que implementa a estrutura. Verifique se o arquivo `.c` correspondente foi incluído no comando.

### Programa não encontra o arquivo CSV

Confirme se:

- o arquivo realmente existe na pasta indicada;
- o nome do arquivo foi informado corretamente no código;
- o programa está sendo executado a partir do diretório esperado.

### GCC não está disponível

No Windows, normalmente é necessário instalar o MinGW ou MSYS2 e garantir que o `gcc` esteja no `PATH`.

```bash
gcc --version
```

Se a mensagem indicar que o comando não foi encontrado, instale o compilador e tente novamente.

## Contribuição

Contribuições são bem-vindas, especialmente para:

- correções de exercícios;
- melhorias na organização do código;
- adição de novos exemplos;
- comentários e documentação explicativa;
- ajustes de leitura e funcionalidade.

Fluxo sugerido:

1. Faça um fork do repositório.
2. Crie uma branch com nome descritivo, como `feature/exercicio-nome` ou `fix/ajuste-readme`.
3. Faça commits claros e objetivos.
4. Abra um Pull Request explicando a alteração.

## Autor

- Nome: Giovanni Jorge
- GitHub: [@GiovanniJorge](https://github.com/GiovanniJorge)

## Licença

Este projeto está licenciado sob a licença MIT. Consulte o arquivo [LICENSE](LICENSE) para mais detalhes.
