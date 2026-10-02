# 20. Valid Parentheses

**Link do Problema:** [LeetCode - Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)  
**Dificuldade:** `Fácil`  
**Tópicos:** String, Stack  

---

## 📌 Enunciado Resumido

Dada uma string `s` contendo apenas os caracteres `'('`, `')'`, `'{'`, `'}'`, `'['` e `']'`, determine se a string de entrada é válida. Uma string é válida se:

1. Os parênteses/chaves/colchetes de abertura são fechados pelo mesmo tipo de caractere.
2. Os caracteres de abertura são fechados na ordem correta (LIFO).
3. Cada caractere de fechamento corresponde a um caractere de abertura do mesmo tipo.

---

## 💡 Abordagem / Lógica

Para resolver este problema de forma ideal e segura em C++, utilizamos uma **Pilha (`std::stack`)** auxiliada por um **Mapa Hash (`std::unordered_map`)**:

1. **Ideia Principal:** Uma estrutura do tipo LIFO (*Last In, First Out*) é perfeita para controlar aninhamentos, pois o último símbolo de abertura visto deve ser obrigatoriamente o primeiro a ser fechado.
2. **Passo a Passo:**
   - Criamos um `std::unordered_map<char, char>` mapeando cada caractere de fechamento para o seu respectivo caractere de abertura correspondente (`')' -> '('`, `']' -> '['`, `'}' -> '{'`).
   - Declaramos uma `std::stack<char>` que armazenará exclusivamente os caracteres de abertura.
   - Iteramos sobre cada caractere `c` da string `s`:
     - **Se `c` for um caractere de fechamento** (verificado via `map.count(c)` para garantir compatibilidade com versões anteriores ao C++20):
       - Verificamos se a pilha está vazia ou se o topo da pilha não corresponde ao par de abertura esperado (`stack.top() != map[c]`). Se qualquer uma dessas condições for verdadeira, a string é inválida e retornamos `false` imediatamente (*Early Return*).
       - Se for o par correto, removemos o elemento do topo com `stack.pop()`.
     - **Se `c` for um caractere de abertura**, empilhamos com `stack.push(c)`.
   - Ao final do laço, a string só será válida se todos os pares tiverem sido fechados perfeitamente, o que significa que a pilha deve estar vazia (`return stack.empty()`).

---

## ⏳ Complexidade

- **Complexidade de Tempo:** $O(N)$ — Onde $N$ é o comprimento da string `s`. Iteramos pela string exatamente uma vez e cada operação de pilha (`push`, `pop`, `top`) possui custo constante $O(1)$.
- **Complexidade de Espaço:** $O(N)$ — No pior caso (uma string composta inteiramente por caracteres de abertura como `"(({{[["`), a pilha armazenará todos os $N$ elementos na memória.

---

## 🧪 Casos de Teste Destacados

- **Parênteses simples bem formatados:** `s = "()"` $\rightarrow$ Retorno: `true`
- **Múltiplos tipos e aninhados:** `s = "()[]{}"` $\rightarrow$ Retorno: `true`
- **Tipos desalinhados:** `s = "(]"` $\rightarrow$ Retorno: `false` (divergência entre `'('` e `']'`)
- **Fechamento sem abertura (Pilha vazia):** `s = "])"` $\rightarrow$ Retorno: `false` (retorna na primeira iteração)
- **Abertura sem fechamento:** `s = "(("` $\rightarrow$ Retorno: `false` (pilha não fica vazia ao final)