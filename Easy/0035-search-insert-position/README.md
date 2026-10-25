# 35. Search Insert Position

**Link do Problema:** [LeetCode - Search Insert Position](https://leetcode.com/problems/search-insert-position/)  
**Dificuldade:** `Fácil`  
**Tópicos:** Array, Binary Search  

---

## 📌 Enunciado Resumido

Dado um vetor de inteiros ordenados `nums` e um valor alvo `target`, retorne o índice se o alvo for encontrado. Se não for, retorne o índice onde ele seria inserido de forma ordenada.

Você deve escrever um algoritmo com complexidade de tempo de execução $O(\log n)$.

---

## 💡 Abordagem / Lógica

Para resolver este problema de forma eficiente utilizando C++, aplicamos a técnica de **Busca Binária (Binary Search)**:

1. **Ideia Principal:** Como o vetor está ordenado, dividimos repetidamente o espaço de busca pela metade utilizando dois ponteiros (`l` e `r`), comparando o elemento do meio (`m`) com o `target`.
2. **Passo a Passo:**
   - **Iniciação:** Definimos `l = 0` (início do vetor) e `r = nums.size() - 1` (fim do vetor).
   - **Laço de Busca (`while`):** Enquanto `l <= r`:
     - Calculamos o índice do meio de forma segura para evitar *overflow*: `m = l + (r - l) / 2`.
     - Se `nums[m] == target`, encontramos o elemento exato e retornamos o índice `m`.
     - Se `nums[m] < target`, o alvo está na metade direita, então movemos o limite inferior: `l = m + 1`.
     - Se `nums[m] > target`, o alvo está na metade esquerda, então movemos o limite superior: `r = m - 1`.
   - **Retorno:** Se o loop terminar sem encontrar o elemento exato, o ponteiro `l` apontará exatamente para a posição correta onde o `target` deve ser inserido para manter a ordenação.

---

## ⏳ Complexidade

- **Complexidade de Tempo:** $O(\log n)$ — Onde $n$ é o número de elementos em `nums`. A cada iteração, o espaço de busca é reduzido pela metade.
- **Complexidade de Espaço:** $O(1)$ — A busca é feita diretamente no vetor de forma iterativa, utilizando apenas variáveis auxiliares constantes.

---