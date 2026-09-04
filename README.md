# Estructura de datos
## Linked Lists
- **Single Linked List**
  #### Complejidad de Operaciones

  | Operación | Complejidad Temporal | Notas |
  | :--- | :---: | :--- |
  | **`push_front`** | $O(1)$ | Inserción al inicio constante. |
  | **`push_back`** | $O(1)$ | Gracias al puntero `tail`. |
  | **`pop_front`** | $O(1)$ | Eliminación del primer nodo directa. |
  | **`pop_back`** | $O(n)$ | Requiere recorrer la lista para actualizar `tail`. |
  | **`contains`** | $O(n)$ | Búsqueda lineal en el peor de los casos. |
  | **`remove(x)`** | $O(n)$ | Requiere buscar el elemento antes de eliminarlo. |

## Stack
| Operación |     Complejidad |
| --------- | --------------: |
| `push(x)` | O(1) amortizado |
| `pop()`   |            O(1) |
| `top()`   |            O(1) |
| `empty()` |            O(1) |
| `size()`  |            O(1) |

## Queue
| Operación    |     Complejidad |
| ------------ | --------------: |
| `enqueue(x)` | O(1) amortizado |
| `dequeue()`  |            O(1) |
| `front()`    |            O(1) |
| `empty()`    |            O(1) |
| `size()`     |            O(1) |

## Dequeue
| Operación      |     Complejidad |
| -------------- | --------------: |
| `push_front()` | O(1) amortizado |
| `push_back()`  | O(1) amortizado |
| `pop_front()`  |            O(1) |
| `pop_back()`   |            O(1) |
| `front()`      |            O(1) |
| `back()`       |            O(1) |
| `empty()`      |            O(1) |
| `size()`       |            O(1) |



