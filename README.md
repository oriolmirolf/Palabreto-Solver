# Palabreto-Solver
Solver para el juego web [Palabreto] (https://www.palabreto.com)

## Nota
El código no está completo, por los siguientes motivos:
- El UI es tan solo con consola.
- El algoritmo a veces encuentra palabras que no están. Se debe a que la elección de palabras de la web es confusa, ya que existe un conjunto de reglas que no aplican siempre
- El algoritmo a veces no encuentra palabras que si están. Se cree que se debe a diferencias de dialectos. Se trabajará en ello cuando tenga tiempo.

## Como ejecutar el código
Simplemente compilar el código, con g++ por ejemplo:
```cpp
g++ -o exe palabreto.cc
./exe
```
