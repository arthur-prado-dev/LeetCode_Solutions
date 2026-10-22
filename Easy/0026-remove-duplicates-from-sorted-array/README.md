# 26. Remove Duplicates from Sorted Array

**Link do Problema:** [LeetCode - Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)  
**Dificuldade:** `Fácil`  
**Tópicos:** Array, Two Pointers  

---

## 📌 Enunciado Resumido

Dado um vetor de inteiros `nums` ordenado em ordem não decrescente, remova os duplicados **in-place** (no próprio vetor) de forma que cada elemento único apareça apenas uma vez. A ordem relativa dos elementos deve ser mantida.

Retorne o número de elementos únicos em `nums` (chamado de `k`). Os primeiros `k` elementos do vetor devem conter os resultados finais. O que estiver após a posição `k` não importa.

---

## 💡 Abordagem / Lógica

Para resolver este problema de forma otimizada em C++, utilizamos a técnica de **Dois Ponteiros (Two Pointers)**, aproveitando o fato de que o vetor já está ordenado:

1. **Ideia Principal:** Mantemos um ponteiro `k` que indica a próxima posição onde um elemento único deve ser colocado. Percorremos o vetor com um segundo ponteiro `i` comparando cada elemento com o seu anterior.
2. **Passo a Passo:**
   - **Caso Base:** Se o vetor tiver 1 elemento (`nums.size() == 1`), retornamos `1`.
   - **Iniciação:** Como o primeiro elemento (`nums[0]`) é sempre único, começamos o ponteiro de controle `k` com o valor `1` e iteramos com `i` a partir de `1`.
   - **Laço de Iteração:** Para cada elemento em `nums[i]`:
     - Comparamos `nums[i]` com o elemento anterior (`nums[i - 1]`).
     - Se forem diferentes, significa que encontramos um novo valor único.
     - Atribuímos `nums[i]` à posição `nums[k]` e incrementamos `k` (`k++`).
   - **Retorno:** Ao final do loop, `k` representa exatamente a quantidade de elementos únicos no vetor.

---

## ⏳ Complexidade

- **Complexidade de Tempo:** $O(N)$ — Onde $N$ é o número de elementos em `nums`. Percorremos o vetor uma única vez em um loop linear.
- **Complexidade de Espaço:** $O(1)$ — A remoção e reorganização são feitas diretamente no vetor original (in-place), utilizando apenas espaço auxiliar constante para os ponteiros.

---

## 🧪 Casos de Teste Destacados

- **Vetor com múltiplos duplicados:** `nums = [1, 1, 2]` $\rightarrow$ Retorno: `k = 2`, `nums = [1, 2, _]`
- **Vetor maior com vários números repetidos:** `nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]` $\rightarrow$ Retorno: `k = 5`, `nums = [0, 1, 2, 3, 4, _, _, _, _, _]`
- **Vetor sem duplicatas:** `nums = [1, 2, 3]` $\rightarrow$ Retorno: `k = 3`, `nums = [1, 2, 3]`
- **Vetor com elemento único:** `nums = [1]` $\rightarrow$ Retorno: `k = 1`, `nums = [1]`