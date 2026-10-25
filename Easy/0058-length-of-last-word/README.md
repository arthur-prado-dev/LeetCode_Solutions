# 58. Length of Last Word

**Link do Problema:** [LeetCode - Length of Last Word](https://leetcode.com/problems/length-of-last-word/)  
**Dificuldade:** `Fácil`  
**Tópicos:** String  

---

## 📌 Enunciado Resumido

Dada uma string `s` constituída de palavras e espaços, retorne o comprimento da última palavra na string.

Uma palavra é um subconjunto maximal composto apenas por caracteres que não são espaços em branco.

---

## 💡 Abordagem / Lógica

Para resolver este problema de forma otimizada e limpa em C++, percorremos a string de trás para frente (do fim para o início) dividindo o processo em duas etapas:

1. **Ideia Principal:** Muitas vezes a string possui espaços em branco no final. Precisamos ignorá-los primeiro. Em seguida, contamos os caracteres da última palavra real até encontrar o próximo espaço ou o início da string.
2. **Passo a Passo:**
   - **Iniciação:** Posicionamos um índice `i` no último caractere da string (`s.size() - 1`) e inicializamos `counter = 0`.
   - **Primeiro Laço (`while`):** Ignoramos todos os espaços à direita decrementando `i` enquanto `s[i] == ' '`.
   - **Segundo Laço (`while`):** Contamos os caracteres da última palavra incrementando `counter` e decrementando `i` enquanto `i >= 0` e o caractere não for um espaço (`s[i] != ' '`).
   - **Retorno:** Ao sair do loop, o valor de `counter` representa exatamente o comprimento da última palavra.

---

## ⏳ Complexidade

- **Complexidade de Tempo:** $O(N)$ — Onde $N$ é o comprimento da string `s`. No pior caso (uma string sem espaços ou com uma única palavra), percorremos os caracteres uma única vez.
- **Complexidade de Espaço:** $O(1)$ — Nenhuma estrutura de dados adicional é utilizada, apenas variáveis auxiliares constantes.

---