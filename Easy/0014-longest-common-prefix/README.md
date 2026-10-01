# 14. Longest Common Prefix

**Link do Problema:** [LeetCode - Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/)  
**Dificuldade:** `Fácil`  
**Tópicos:** Array, String, Trie  

---

## 📌 Enunciado Resumido

Escreva uma função para encontrar a string com o maior prefixo comum (*Longest Common Prefix*) em um array de strings. Se não houver um prefixo comum entre todas as strings, retorne uma string vazia `""`.

---

## 💡 Abordagem / Lógica

Para resolver este problema de forma altamente eficiente em C++, utilizamos o conceito de **Redução Horizontal com `std::string_view`**:

1. **Ideia Principal:** Definimos a primeira string do vetor como nosso candidato inicial a prefixo (`lcp`). Em seguida, iteramos pelas demais strings do vetor ajustando o tamanho desse prefixo a cada comparação. Para evitar cópias desnecessárias e alocações de memória na *Heap* durante as iterações, usamos `std::string_view` para manipular as fatias de texto com custo auxiliar de memória $O(1)$.
2. **Passo a Passo:**
   - Inicializamos uma variável `std::string_view lcp = strs[0];` que apenas aponta para o buffer da primeira string.
   - Entramos em um laço `for` a partir do segundo elemento (`i = 1` até `strs.size() - 1`):
     - Criamos uma view da string atual: `string_view current = strs[i];`.
     - Determinamos o comprimento máximo de comparação seguro usando `size_t minLen = std::min(lcp.size(), current.size());`.
     - Usamos um ponteiro/índice `k = 0` em um laço `while` para comparar caractere por caractere enquanto `k < minLen` e `lcp[k] == current[k]`.
     - Atualizamos o `lcp` usando o método `.substr(0, k)` da `std::string_view`, que apenas reajusta o ponteiro/tamanho interno sem alocar memória.
     - Se em algum momento `lcp.empty()` for verdadeiro (ou seja, o prefixo comum virou `""`), interrompemos o laço prematuramente com `break`.
   - Ao final, convertemos o `std::string_view` resultante de volta para uma `std::string` convencional no `return`.

---

## ⏳ Complexidade

- **Complexidade de Tempo:** `O(S)` — Onde $S$ é a soma de todos os caracteres de todas as strings contidas no vetor. No pior caso (todas as strings idênticas), percorremos todos os caracteres. No melhor caso, o algoritmo interrompe no início ao encontrar divergência.
- **Complexidade de Espaço:** `O(1)` — O uso de `std::string_view` garante que nenhuma alocação intermediária seja feita no *Heap* durante o loop. Apenas 1 alocação ocorre na criação da `std::string` final retornada pela função.

---

## 🧪 Casos de Teste Destacados

- **Prefixo parcial comum:** `strs = ["flower","flow","flight"]` $\rightarrow$ Retorno: `"fl"`
- **Sem prefixo comum:** `strs = ["dog","racecar","car"]` $\rightarrow$ Retorno: `""` (divergência logo no primeiro caractere)
- **Uma string contida na outra:** `strs = ["interstellar","internet","interval"]` $\rightarrow$ Retorno: `"inter"`