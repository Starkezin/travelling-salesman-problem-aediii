# TSP (Brute Force & Nearest Neighbor) em C++

- **Brute force** (força bruta) — gera todas as permutações para encontrar a solução ótima (usado apenas em instâncias muito pequenas).
- **Nearest Neighbor** (Vizinho Mais Próximo) — heurística gulosa que encontra uma solução rápida e aproximada.

---
## Estrutura e arquivos

- `tsp_bruteforce.cpp` — implementação por força bruta (testa todas as permutações). 
- `tsp_nearest_neighbor.cpp` — implementação da heurística Nearest Neighbor.

---
## Formato do arquivo de entrada

O arquivo deve conter a **matriz de adjacência NxN** de distâncias, uma linha por linha, valores inteiros separados por espaços.

--- 

## Compilando (exemplos com g++)

```bash
# Compilar brute force
g++ tsp_bruteforce.cpp -o tsp_bruteforce

# Compilar nearest neighbor
g++ tsp_nearest_neighbor.cpp -o tsp_nn
```

---

## Executando
**IMPORTANTE:** passe o arquivo de entrada como argumento da linha de comando.
Exemplos:

```bash
# Executar brute force
./tsp_bruteforce data/tsp1_253.txt

# Executar Nearest Neighbor
./tsp_nn data/tsp1_253.txt
```
---

## Saídas esperadas

- **Brute force:** imprimirá a menor distância encontrada (o custo ótimo) e o tempo de execução (ms).
- **Nearest Neighbor:** imprimirá a rota encontrada (começando pela cidade inicial) e a distância total aproximada, além do tempo de execução (ms).

Exemplo de saída (nearest neighbor):
```
Tempo de execucao: 0.004 ms
Rota encontrada (Nearest Neighbor): 0 8 7 2
Distancia total aproximada: 299
```

---


