# C - Unaerp
Exercícios em linguagem C usados nas aulas da Unaerp — coleção organizada por tópicos (manipulação de arquivos, strings, sub-rotinas e exercícios gerais). Ideal para estudantes que querem praticar sintaxe, controle de fluxo, manipulação de strings e entrada/saída de arquivos em C.

## Conteúdo principal
- Exercícios focados em problemas didáticos para aprendizagem de C.
- Estrutura simples por pastas que separa exercícios por tema.
- Exemplos que usam arquivos CSV como entrada/saída em alguns exercícios.

## Badges
- Licença: MIT (ver arquivo LICENSE)

## Sumário
- [Visão geral](#visão-geral)
- [Estrutura do repositório](#estrutura-do-repositório)
- [Como compilar e executar](#como-compilar-e-executar)
- [Boas práticas / recomendações de compilação](#boas-práticas--recomendações-de-compilação)
- [Contribuindo](#contribuindo)
- [Licença](#licença)
- [Autor / Contato](#autor--contato)

## Visão geral
Este repositório organiza pequenos programas em C que exemplificam conceitos de linguagem e resolução de problemas. Cada arquivo fonte normalmente resolve um exercício específico e está escrito com finalidade didática: leitura de dados, processos de transformação, uso de funções/sub-rotinas e manipulação de strings e arquivos.

## Estrutura do repositório
Top-level:
- .gitattributes
- LICENSE
- README.md
- exercicios-arquivos/       — exercícios envolvendo leitura/escrita de arquivos (CSV, etc.)
  - arquivos-ex1/            — exemplo com `alunos.csv`, `alunos_ordenados_por_nome.csv`, `código.c`
  - arquivos-ex2/            — exemplo com `nascar_champions.csv`, etc.
- exercicios-geral/         — exercícios diversos (ex.: `geral-ex1.c`, `geral-ex2.c`)
- exercicios-strings/       — exercícios com strings (`strings-ex1.c`, ..., `strings-ex8.c`)
- exercicios-subrotina/     — exercícios com funções/subrotinas (`subrotina-ex1.c`, ..., `subrotina-ex9.c`)

Como se encaixa:
- Cada arquivo .c é um programa independente (exercício). A forma usual de usar o repositório é compilar o arquivo que você quer executar.
- Arquivos CSV fornecem dados de exemplo para exercícios de I/O na pasta `exercicios-arquivos`.

## Como compilar e executar
Recomenda-se usar GCC (ou outro compilador compatível). Exemplos:

Compilar um exercício único:
```bash
gcc -std=c11 -Wall -Wextra -pedantic -O2 -g exercicios-geral/geral-ex1.c -o geral-ex1
./geral-ex1
```

Compilar um exercício na pasta de strings:
```bash
gcc -std=c11 -Wall -Wextra exercicios-strings/strings-ex3.c -o strings-ex3
./strings-ex3
```

Compilar todos os .c em uma pasta (rápido para testes):
```bash
# dentro da pasta correspondente
gcc -std=c11 -Wall -Wextra *.c -o exercicios
```

Executar um programa que lê de arquivo CSV (exemplo):
```bash
./arquivos-ex1/codigo       # quando o binário espera um arquivo como argumento
# ou, se o programa lê stdin:
./arquivos-ex1/codigo < exercicios-arquivos/arquivos-ex1/alunos.csv
```

Observação: alguns arquivos no repositório possuem nomes contendo caracteres acentuados (por ex. `código.c`). Para evitar problemas de portabilidade, é recomendável renomear para `codigo.c` e atualizar referências.

## Boas práticas / recomendações de compilação
- Use: `-std=c11 -Wall -Wextra -pedantic` para detectar avisos e manter portabilidade.
- Para depuração ativa: adicione `-g` e compile sem `-O2`.
- Para versão final de performance: adicione `-O2` ou `-O3`.
- Documente cada exercício no topo do arquivo (comentário explicando entrada esperada, saída e algoritmo).
- Prefira nomes de arquivos sem espaços/acentos para compatibilidade entre sistemas operacionais.

## Contribuindo
Contribuições são bem-vindas (ex.: correções, comentários, novos exercícios, testes). Fluxo sugerido:
1. Fork do repositório.
2. Criar branch com nome descritivo: `feature/exercicio-nome` ou `fix/readme`.
3. Fazer commits atômicos com mensagens claras.
4. Abrir Pull Request descrevendo as mudanças e, se aplicável, o motivo pedagógico.
5. Se possível, inclua casos de teste ou instruções para validar o exercício.

Sugestões adicionais:
- Adicione um pequeno README por pasta explicando o objetivo dos exercícios daquela pasta.
- Considere adicionar um Makefile com targets como `make all`, `make clean`, `make exercicio=exemplo`.

## Testes e automação (opcional)
- Poderia ser adicionado um Makefile para facilitar compilação em lote.
- Para verificação automática, adicionar um workflow (GitHub Actions) que compila cada .c para garantir que o repositório permaneça compilável.

## Licença
Este repositório utiliza a licença MIT — consulte o arquivo `LICENSE` na raiz.

## Autor / Contato
Autor: Giovanni Jorge  
Repositório: https://github.com/GiovanniJorge/c-unaerp
