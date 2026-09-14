# Tarea: Algoritmos de exclusión mutua con Monte Carlo

## Objetivo

Implementar el mismo método de **Monte Carlo para calcular π**, modificando únicamente el mecanismo utilizado para proteger la variable compartida `puntosDentro`.

Cada equipo trabajará con uno de los siguientes algoritmos:

- Dekker
- Peterson
- Lamport (Bakery)
- Test-and-Set
- CAS (Compare-and-Swap)

## Instrucciones generales

1. Implemente el método de Monte Carlo para estimar **π** utilizando **múltiples hilos**.
2. Distribuya `100,000,000` puntos entre los hilos.
3. Cada hilo deberá generar sus puntos aleatorios y determinar si están dentro del círculo.
4. La variable `puntosDentro` será **compartida** entre los hilos.
5. Utilice **únicamente el algoritmo de exclusión mutua asignado a su equipo** para proteger:

   ```text
   puntosDentro++
   ```

6. Espere a que todos los hilos terminen antes de calcular π:

   ```text
   π = 4.0 * puntosDentro / totalPuntos
   ```

7. Mida el tiempo de ejecución.
8. Realice pruebas utilizando:

   ```text
   2, 4, 8 y 16 hilos
   ```

9. Registre los resultados obtenidos.

## Resultados

Cada equipo deberá entregar una tabla como la siguiente:

| Hilos |      Puntos | π calculado | Tiempo |
| ----: | ----------: | ----------: | -----: |
|     4 | 100,000,000 |             |        |
|     8 | 100,000,000 |             |        |
|    16 | 100,000,000 |             |        |

## Entregables

- Código fuente del algoritmo asignado.
- Tabla de resultados.
- Gráfica de **hilos vs. tiempo de ejecución**.
- Breve explicación de cómo funciona el algoritmo implementado.
- Conclusión sobre su rendimiento.

### Importante

Todos los equipos deberán utilizar **el mismo número de puntos, misma lógica de Monte Carlo y mismas cantidades de hilos**, de manera que posteriormente sea posible comparar el rendimiento de **Dekker, Peterson, Lamport, Test-and-Set y CAS** bajo condiciones equivalentes.
