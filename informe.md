#Contenedores

##¿Que es?

Un _contenedor_ de la __STL__ es una clase genérica que puede instanciarse para representar diversos tipos de objetos.

Esta clase incluye ciertas operaciones sobre los objetos de su tipo. Naturalmente estas operaciones están representadas por funciones-miembro, incluyendo constructores y funciones-operador, que son a su vez funciones genéricas.

Una estructura de datos se dice que es contenedora si puede contener instancias de otras estructuras de datos. En concreto, la STL dispone de las estructuras indicadas en la tabla siguiente:


|Contenedores lineales|Conenedores Asociativos|Contenedores adaptados|
|:-:|:-:|:-:|
|_Vector_ ```vector<T>```|_Conjunto_ \\ ```set<T, compare>```|   |
|_Lista_ ```vector<T>```|_Multiconjunto_	```multiset<T, compare>```|   |
|_Doble cola_ ```deque<T>```|_Aplicacion_ 	```map<Key, T, compare>```|   |
||_Multiplicacion_ 		```multipam<Key, T, compare>```||
 



