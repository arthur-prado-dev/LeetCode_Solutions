# 27. Remove Element

**Link do Problema:** [LeetCode - Remove Element](https://leetcode.com/problems/remove-element/)  
**Dificuldade:** `Fácil`  
**Tópicos:** Array, Two Pointers  

---

## 📌 Enunciado Resumido

Dado um vetor de inteiros `nums` e um valor inteiro `val`, remova todas as ocorrências de `val` em `nums` **in-place** (no próprio vetor). A ordem dos elementos pode ser alterada.

Retorne o número de elementos em `nums` que são diferentes de `val` (chamado de `k`). Os primeiros `k` elementos do vetor devem conter os resultados finais (os valores diferentes de `val`). O que estiver após a posição `k` no vetor não importa.

---

## 💡 Abordagem / Lógica

Para resolver este problema de forma otimizada utilizando C++, aplicamos a técnica de **Dois Ponteiros (Two Pointers)**:

1. **Ideia Principal:** Mantemos um ponteiro `k` que rastreia a posição onde o próximo elemento válido (diferente de `val`) deve ser colocado. Percorremos o vetor com um segundo ponteiro `i` avaliando cada elemento.
2. **Passo a Passo:**
   - **Iniciação:** Declaramos `k = 0` para indicar a primeira posição do vetor.
   - **Laço de Iteração:** Percorremos o vetor com um loop `for` onde `i` vai de `0` até o tamanho do vetor (`nums.size()` - 1):
     - Verificamos se o elemento atual `nums[i]` é diferente de `val`.
     - Se for diferente, significa que é um elemento que desejamos manter.
     - Atribuímos `nums[i]` à posição `nums[k]` e incrementamos `k` (`k++`).
     - Se for igual a `val`, simplesmente ignoramos o elemento.
   - **Retorno:** Ao final do loop, o valor de `k` representa exatamente a quantidade de elementos que não são iguais a `val`.

---

## ⏳ Complexidade

- **Complexidade de Tempo:** $O(N)$ — Onde $N$ é o número de elementos em `nums`. Percorremos o vetor uma única vez linearmente.
- **Complexidade de Espaço:** $O(1)$ — A remoção e reorganização são feitas diretamente no vetor original (in-place), utilizando apenas espaço auxiliar constante.

---

## 🧪 Casos de Teste Destacados

- **Remoção de múltiplos elementos:** `nums = [3, 2, 2, 3]`, `val = 3` $\rightarrow$ Retorno: `k = 2`, `nums = [2, 2, _, _]`
- **Vetor com vários elementos repetidos e misturados:** `nums = [0, 1, 2, 2, 3, 0, 4, 2]`, `val = 2` $\rightarrow$ Retorno: `k = 5`, `nums = [0, 1, 4, 0, 3, _, _, _]`
- **Nenhum elemento encontrado:** `nums = [1, 2, 3]`, `val = 5` $\rightarrow$ Retorno: `k = 3`, `nums = [1, 2, 3]`
- **Vetor com apenas um elemento igual a `val`:** `nums = [1]`, `val = 1` $\rightarrow$ Retorno: `k = 0`, `nums = [_]`