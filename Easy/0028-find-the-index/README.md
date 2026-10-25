# 28. Find the Index of the First Occurrence in a String

**Link do Problema:** [LeetCode - Find the Index of the First Occurrence in a String](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/)  
**Dificuldade:** `Fácil`  
**Tópicos:** Two Pointers, String, String Matching  

---

## 📌 Enunciado Resumido

Dadas duas strings `haystack` e `needle`, retorne o índice da primeira ocorrência de `needle` em `haystack`, ou `-1` se `needle` não fizer parte de `haystack`.

---

## 💡 Abordagem / Lógica

Para resolver este problema de forma eficiente e intuitiva em C++, aplicamos a técnica de **Janela Deslizante (Sliding Window)** combinada com dois ponteiros:

1. **Ideia Principal:** Testamos cada posição possível dentro de `haystack` onde a string `needle` poderia encaixar-se por completo.
2. **Passo a Passo:**
   - **Verificação Inicial:** Comparamos os tamanhos. Se `needle` for maior que `haystack`, é impossível ocorrer, logo retornamos `-1` imediatamente.
   - **Laço de Iteração:** Percorremos `haystack` com um ponteiro `i` indo de `0` até `h - n` (onde `h` é o tamanho do palheiro e `n` é o tamanho da agulha). Isso evita iterações desnecessárias onde a palavra não caberia mais.
   - **Validação de Caracteres:** Para cada posição `i`, inicializamos um ponteiro `j = 0` e usamos um loop `while` com curto-circuito (`j < n && haystack[i + j] == needle[j]`) para comparar os caracteres sequencialmente.
   - **Retorno de Sucesso:** Se o ponteiro `j` alcançar o tamanho total de `needle`, significa que encontramos a palavra exata, então retornamos o índice atual `i`.
   - **Retorno de Falha:** Se o loop externo terminar sem nenhuma correspondência bem-sucedida, retornamos `-1`.

---

## ⏳ Complexidade

- **Complexidade de Tempo:** $O(N \times M)$ no pior caso — Onde $N$ é o tamanho de `haystack` e $M$ é o tamanho de `needle`. Na prática, o algoritmo executa muito mais rápido devido às paradas antecipadas no loop interno.
- **Complexidade de Espaço:** $O(1)$ — A busca é feita diretamente na memória das strings originais, utilizando apenas variáveis auxiliares constantes.
