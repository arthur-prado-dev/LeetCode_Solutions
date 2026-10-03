# 21. Merge Two Sorted Lists

**Link do Problema:** [LeetCode - Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)  
**Dificuldade:** `Fácil`  
**Tópicos:** Linked List, Recursion  

---

## 📌 Enunciado Resumido

Dadas as cabeças de duas listas encadeadas ordenadas, `list1` e `list2`, mescle as duas listas em uma única **lista encadeada ordenada**. A lista resultante deve ser feita entrelaçando os nós das duas primeiras listas.

Retorne a cabeça da lista encadeada mesclada.

---

## 💡 Abordagem / Lógica

Para resolver este problema de forma iterativa, eficiente e limpa em C++, utilizamos o conceito de **Nó Dummy (Âncora Fictícia na Stack)** e dois ponteiros para navegar pelas listas:

1. **Ideia Principal:** Iterar simultaneamente sobre `list1` e `list2`, comparando os valores atuais dos nós e ajustando os ponteiros `next` para encadear sempre o menor nó encontrado na lista final.
2. **Passo a Passo:**
   - **Tratamento de Casos Base:** Verificamos inicialmente se alguma das listas é nula (`list1 == nullptr` ou `list2 == nullptr`). Se sim, retornamos a outra lista imediatamente (*Early Return*).
   - **Nó Dummy na Stack:** Declaramos um nó local `head` (alocado na Stack) para servir como ponto fixo de partida, e um ponteiro `last` apontando para o seu endereço (`&head`), que acompanhará a cauda da nova lista encadeada.
   - **Laço de Iteração:** Enquanto ambas as listas possuírem elementos (`list1 != nullptr && list2 != nullptr`):
     - Comparados os valores `list1->val` e `list2->val`.
     - O ponteiro `last->next` recebe o nó que possui o menor valor.
     - O ponteiro da lista escolhida (`list1` ou `list2`) avança para o próximo nó (`->next`).
     - Avançamos o ponteiro de cauda `last` para o recém-conectado nó (`last = last->next`).
   - **Conexão Final:** Quando uma das listas esvazia, conectamos o restante da outra lista diretamente em `last->next` através do operador ternário `(list1 == nullptr) ? list2 : list1`.
   - **Retorno:** Retornamos `head.next`, que corresponde ao primeiro nó real da nova lista encadeada mesclada.

---

## ⏳ Complexidade

- **Complexidade de Tempo:** $O(N + M)$ — Onde $N$ e $M$ são os números de nós presentes em `list1` e `list2`, respectivamente. Percorremos cada nó de ambas as listas no máximo uma única vez.
- **Complexidade de Espaço:** $O(1)$ — A ordenação é feita reaproveitando e reencadeando os próprios nós existentes na memória, utilizando apenas espaço auxiliar constante (a variável `head` na Stack e o ponteiro `last`).

---

## 🧪 Casos de Teste Destacados

- **Listas do mesmo tamanho e valores misturados:** `list1 = [1, 2, 4]`, `list2 = [1, 3, 4]` $\rightarrow$ Retorno: `[1, 1, 2, 3, 4, 4]`
- **Listas vazias:** `list1 = []`, `list2 = []` $\rightarrow$ Retorno: `[]`
- **Uma das listas vazia:** `list1 = []`, `list2 = [0]` $\rightarrow$ Retorno: `[0]`
- **Listas de tamanhos diferentes:** `list1 = [1, 5, 6]`, `list2 = [2]` $\rightarrow$ Retorno: `[1, 2, 5, 6]`