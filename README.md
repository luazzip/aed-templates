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
