# 9. Palindrome Number

**Link do Problema:** [LeetCode - Palindrome Number](https://leetcode.com/problems/palindrome-number/)  
**Dificuldade:** `Fácil`  
**Tópicos:** Math  

---

## 📌 Enunciado Resumido

Dado um inteiro `x`, retorne `true` se `x` for um palíndromo e `false` caso contrário. Um número é um palíndromo quando lido da mesma forma da esquerda para a direita e da direita para a esquerda.

---

## 💡 Abordagem / Lógica

Para resolver este problema reconstruindo o número invertido:

1. **Ideia Principal:** Podemos inverter matematicamente o número de trás para frente extraindo o último dígito a cada iteração (`x % 10`) e montando o número invertido. No final, comparamos o valor invertido com o valor original.
2. **Passo a Passo:**
   - Salvamos uma cópia do valor original `x` em `xCopy` para usar na comparação final.
   - Usamos uma variável `palindrome` do tipo `long` iniciada em `0` para evitar estouro de memória (*integer overflow*) durante a inversão.
   - Entramos em um laço `while` que roda enquanto `x > 0`:
     - Multiplicamos `palindrome` por $10$ e somamos o resto da divisão de `x` por $10$ (`x % 10`).
     - Dividimos `x` por $10$ (`x /= 10`) para remover o último dígito.
   - Retornamos o resultado da comparação `(int)palindrome == xCopy`. (Casos onde `x < 0` não entram no laço e retornam `false` diretamente, pois números negativos não são palíndromos devido ao sinal `-`).

---

## ⏳ Complexidade

- **Complexidade de Tempo:** `O(log10(n))` — O número de iterações no laço é proporcional à quantidade de dígitos do número $n$.
- **Complexidade de Espaço:** `O(1)` — Utilizamos apenas variáveis auxiliares simples para armazenar os valores temporários.

---

## 🧪 Casos de Teste Destacados

- **Número palíndromo positivo:** `x = 121` $\rightarrow$ Retorno: `true`
- **Número negativo:** `x = -121` $\rightarrow$ Retorno: `false`
- **Número terminado em zero:** `x = 10` $\rightarrow$ Retorno: `false`
- **Potencial overflow:** `x = 1234567899` $\rightarrow$ Retorno: `false`