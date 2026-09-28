# 1. Two Sum

**Link do Problema:** [LeetCode - Two Sum](https://leetcode.com/problems/two-sum/)  
**Dificuldade:** `Fácil`  
**Tópicos:** Hash Table, Array  

---

## 📌 Enunciado Resumido

Dado um array de inteiros `nums` e um inteiro `target`, retorne os índices dos dois números cuja soma seja igual a `target`.

---

## 💡 Abordagem / Lógica

Para resolver este problema de forma eficiente:

1. **Ideia Principal:** Em vez de comparar todos os pares com dois loops ($O(n^2)$), podemos usar uma **Tabela Hash (std::unordered_map)** para armazenar os valores que já vimos e seus respectivos índices.
2. **Passo a Passo:**
   - Iteramos pelo array `nums`.
   - Para cada elemento `x`, calculamos o complemento necessário: `complemento = target - x`.
   - Verificamos se o `complemento` já existe no nosso hash map:
     - **Se existir:** Encontramos o par! Retornamos o índice do complemento e o índice atual.
     - **Se não existir:** Adicionamos o valor atual e seu índice no mapa (`map[x] = i`) e continuamos a iteração.

---

## ⏳ Complexidade

- **Complexidade de Tempo:** `O(n)` — Passamos pelo array apenas uma vez. As buscas e inserções na Tabela Hash levam tempo médio `O(1)`.
- **Complexidade de Espaço:** `O(n)` — No pior caso, armazenamos até $n$ elementos na Tabela Hash.

---

## 🧪 Casos de Teste Destacados

- **Caso base:** `nums = [2, 7, 11, 15]`, `target = 9` $\rightarrow$ Retorno: `[0, 1]`
- **Valores duplicados:** `nums = [3, 3]`, `target = 6` $\rightarrow$ Retorno: `[0, 1]`