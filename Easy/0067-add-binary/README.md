# 67. Add Binary

**Link do Problema:** [LeetCode - Add Binary](https://leetcode.com/problems/add-binary/)  
**Dificuldade:** `Fácil`  
**Tópicos:** Math, String, Bit Manipulation, Simulation  

---

## 📌 Enunciado Resumido

Dadas duas strings binárias `a` e `b`, retorne a soma entre elas também como uma string binária.

---

## 💡 Abordagem / Lógica

Para resolver este problema em C++ sem risco de *overflow* em tipos numéricos inteiros, simulamos a soma bit a bit da direita para a esquerda (do bit menos significativo para o mais significativo), utilizando dois ponteiros e uma variável de transporte (*carry*):

1. **Ideia Principal:** Percorremos ambas as strings simultaneamente de trás para frente, somando os bits correspondentes junto com o `carry` da posição anterior, calculando o bit resultante (`sum % 2`) e o novo transporte (`sum / 2`) na base 2.
2. **Passo a Passo:**
   - **Iniciação:** Posicionamos dois índices no final de cada string (`i = a.size() - 1` e `j = b.size() - 1`), inicializamos `carry = 0` e criamos uma string vazia `result`.
   - **Laço de Soma (`while`):** Continuamos iterando enquanto houver caracteres restantes em `a` (`i >= 0`), em `b` (`j >= 0`), ou um transporte pendente (`carry > 0`).
   - **Cálculo dos Bits:** Inicializamos `sum = carry`. Caso `i >= 0`, convertemos `a[i]` de `char` para `int` subtraindo `'0'` e somamos a `sum` (decrementando `i`). O mesmo é feito para `b[j]` caso `j >= 0`.
   - **Atualização do *Carry* e Dígito:** Calculamos o próximo transporte com `carry = sum / 2` e o bit atual com `currentDigit = sum % 2`.
   - **Construção do Resultado:** Convertemos `currentDigit` de volta para caractere (`+ '0'`) e o inserimos no início da string `result` (`result.insert(0, 1, ...)`).
   - **Retorno:** Ao finalizar o loop, retornamos `result` com a soma binária completa.

---

## ⏳ Complexidade

- **Complexidade de Tempo:** $O(\max(N, M)^2)$ — Onde $N$ e $M$ são os comprimentos das strings `a` e `b`. O laço executa $\max(N, M) + 1$ iterações, mas a operação `result.insert(0, ...)` desloca todos os caracteres já existentes na string a cada passo ($O(K)$ por inserção). *(Nota: Usar `push_back` seguido de `std::reverse` no final reduziria o tempo para $O(\max(N, M))$).*
- **Complexidade de Espaço:** $O(\max(N, M))$ — Para armazenar a string `result`, que terá no máximo $\max(N, M) + 1$ caracteres.

---