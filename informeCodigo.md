##Contenedores utilizados

Despues de buscar informacion y leer sobre el tema, pude observar que (en mi caso) el contenedor que cumplia con mis necesidades era ___map___, ya que por su estructura de _Key-Value_ me facilito las cosas al momento de enlazar o relacionar las __cuentas__ con los __eventos__ recibidos.

Decidi separar el problema en:

- Almacenamiento de __eventos__ 
- Almacenamiento de __cuentas__

Creando para cada uno un ___map___ y relacionandolos.

El ___map___ principal esta definido:
``` c++
map<string, eventTypeMap> logMap;
```
Este contiene un `string` que son las __cuentas__ y un `typedef eventTypeMap` que hace referecia a:
``` c++
typedef map<string, int> eventTypeMap;
```
Este contiene un `string` que son los __eventos__ recibidos y un `int` que es la cantidad de veces que se ha recibido ese evento.

Graficamente la estructura quedaria: `Cuenta -> (tipoEvento -> contador)`

Ese seria el almacenamiento principal.

Utilice tambien un almacenamiento auxiliar, para facilitar el manejo de datos al momento de mostrarlos.

`vector<pair<string, int>> accounts;` Almacena las cuentas con el numero total de eventos recibidos.

`vector<pair<string, int>> events;` Almacena los eventos con el numero total de llamadas.

Estos __vectores__ fueron utilizados para facilitar el ordenamiento de los datos.






