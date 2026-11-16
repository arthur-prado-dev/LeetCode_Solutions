# 66. Plus One

**Link do Problema:** [LeetCode - Plus One](https://leetcode.com/problems/plus-one/)  
**Dificuldade:** `Fácil`  
**Tópicos:** Array, Math  

---

## 📌 Enunciado Resumido

Dado um número inteiro grande representado como um array de inteiros `digits`, onde cada `digits[i]` corresponde ao $i$-ésimo dígito do número (ordenado do mais significativo para o menos significativo, da esquerda para a direita), incremente o inteiro em uma unidade e retorne o array de dígitos resultante.

O número não contém nenhum zero à esquerda.

---

## 💡 Abordagem / Lógica

Para resolver este problema de forma otimizada e *in-place* em C++, simulamos a operação de soma manual percorrendo o vetor de trás para frente (do dígito menos significativo para o mais significativo):

1. **Ideia Principal:** Ao somar `1` ao último dígito, só precisamos propagar o "vai um" (*carry*) caso o dígito atual seja `9`. Se encontrarmos qualquer dígito menor que `9`, basta incrementá-lo e encerrar a execução imediatamente.
2. **Passo a Passo:**
   - **Iteração Reversa (`for`):** Iniciamos o índice `i` na última posição do vetor (`length - 1`) e percorremos até o início (`i >= 0`).
   - **Caso Base (Sem Propagação):** Se `digits[i] < 9`, incrementamos `digits[i]++` e retornamos o próprio vetor `digits` imediatamente, pois não há mais alterações necessárias à esquerda.
   - **Propagação de *Carry*:** Caso `digits[i] == 9`, a soma resulta em `10`, então definimos `digits[i] = 0` e deixamos o laço continuar para propagar o `+1` ao próximo dígito à esquerda.
   - **Estouro de Dígitos (Ex: `999` $\rightarrow$ `1000`):** Se o laço terminar sem retornar, significa que todos os dígitos originais eram `9` e foram zerados. Inserimos `1` no início do vetor (`digits.insert(digits.begin(), 1)`) e retornamos `digits`.

---

## ⏳ Complexidade

- **Complexidade de Tempo:** $O(N)$ — Onde $N$ é o tamanho do vetor `digits`. No pior caso (quando todos os dígitos são `9`), percorremos todo o vetor e realizamos uma inserção no início (`insert`), ambas operações lineares em $N$.
- **Complexidade de Espaço:** $O(1)$ — A modificação é feita *in-place* diretamente no vetor de entrada, sem alocação de estruturas auxiliares extras (exceto no pior caso onde o vetor cresce em $1$ posição para acomodar o dígito extra).

---