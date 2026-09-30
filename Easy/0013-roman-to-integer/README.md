# 13. Roman to Integer

**Link do Problema:** [LeetCode - Roman to Integer](https://leetcode.com/problems/roman-to-integer/)  
**Dificuldade:** `Fácil`  
**Tópicos:** Hash Table, Math, String  

---

## 📌 Enunciado Resumido

Dada uma string `s` contendo um número romano, converta-o para um número inteiro. Os numerais romanos são representados pelos símbolos `'I'`, `'V'`, `'X'`, `'L'`, `'C'`, `'D'` e `'M'`. Normalmente, os símbolos são escritos do maior para o menor da esquerda para a direita. No entanto, quando um símbolo de menor valor antecede um de maior valor, o valor menor é subtraído (ex: `IV = 4`, `IX = 9`).

---

## 💡 Abordagem / Lógica

Para resolver este problema utilizando um mapeamento por array direto:

1. **Ideia Principal:** Mapeamos os valores inteiros correspondentes a cada símbolo romano usando um array fixo de tamanho 256 (`hash`). Ao iterar pela string, somamos o valor do símbolo atual e, caso detectemos uma regra de subtração (símbolo atual maior que o anterior), corrigimos a soma subtraindo o dobro do valor do símbolo anterior.
2. **Passo a Passo:**
   - Criamos um array `int hash[256] = {0};` para mapear o código ASCII de cada caractere romano ao seu respetivo valor numérico (ex: `hash['I'] = 1`, `hash['V'] = 5`, etc.).
   - Inicializamos a variável acumuladora `convertedValue` em `0`.
   - Entramos em um laço `for` que percorre cada caractere da string `s`:
     - Adicionamos o valor do símbolo atual `hash[s[i]]` a `convertedValue`.
     - Verificamos se `i > 0` e se o símbolo atual tem valor estritamente maior que o anterior (`hash[s[i]] > hash[s[i-1]]`).
     - Se essa condição for verdadeira (como no caso de `IV` ou `IX`), subtraímos `2 * hash[s[i-1]]` do acumulador. O fator 2 compensa a adição indevida realizada na iteração anterior.
   - Retornamos `convertedValue`.

---

## ⏳ Complexidade

- **Complexidade de Tempo:** `O(n)` — Onde $n$ é o comprimento da string `s`. Iteramos pela string exatamente uma vez e o acesso aos valores via array direto é feito em $O(1)$.
- **Complexidade de Espaço:** `O(1)` — Utilizamos um array de tamanho fixo (`256` inteiros) alocado na pilha, o que resulta em um consumo de memória constante e mínimo.

---

## 🧪 Casos de Teste Destacados

- **Adição simples:** `s = "III"` $\rightarrow$ Retorno: `3`
- **Subtração combinada:** `s = "LVIII"` $\rightarrow$ Retorno: `58` (`L = 50`, `V = 5`, `III = 3`)
- **Casos com subtrações complexas:** `s = "MCMXCIV"` $\rightarrow$ Retorno: `1994` (`M = 1000`, `CM = 900`, `XC = 90`, `IV = 4`)