<p>
  <img src="img/icono.png" align="right"  width="60" height="60" />
</p>


# MarioCraft v2
#### Autores:
- Jorge Cárdenas Cárdenas
- Ricardo Antonio Hernández Torres
- Samuel Arturo Garrido Sánchez

### Manual de Usuario

Consulte el [manual de usuario](ManualUsuario.md) para obtener una descripcion del funcionamiento del juego.

![](img/ImagenPrincipal.png)

### Instrucciones para compilar y ejecutar:

**Paso 1:**

Abrir la solución de Visual Studio (MarioCraft.sln)

**Paso 2:**

**SELECCIONAR ARQUITECTURA x86**, si se elige x64 habrá un error inicial.

**Paso 3:**

Compilar el subproyecto **CGALib**.

**Paso 4:**

Seleccionar el subproyecto **MarioCraft** y ejecutar una nueva instancia.

### Objetivo del juego

MarioCraft v2 se trata de un entorno gráfico 3D en forma de juego donde se encuentran
elementos de los juegos: Minecraft, Mario y Spiderman. El objetivo es reunir 50 monedas que se
encuentran dispersas a lo largo del escenario. Existe un laberinto en el que se encuentran activadas
una serie de rocas que giran hacia el personaje principal, si el personaje hace colisión con alguna
de las rocas, este pierde una de sus vidas (5 en total).

Adicionalmente existen 4 maquinas de refrescos que le permiten al jugador obtener
ventajas dentro del mismo, las funciones de estas son las siguientes: duplicar la cantidad máxima
de vidas, recuperar las vidas perdidas, poder correr más rápido y aumentar la altura de salto.

### Diseño
De manera general se considera un plano con las texturas de pasto tipo Minecraft, a la par
se considera una pista para que próximos vehículos puedan circular en ella a manera de otro modo
de juego o un minijuego. Se colocan las casas de Toad, los árboles y algunas casas de tipo
Minecraft entre las cuáles se encuentra una torre y una casa blanca. En el norte podemos encontrar 
el castillo de Peach el cuál oculta un easter-egg y como agregado se considera reemplazar una
arboleda con un laberinto en el cual se pueden encontrar monedas para recolectar.

El personaje principal se considera a un Spiderman que se le agregan 5 animaciones:
- Ganar
- Morir
- Correr
- Saltar
- Mirar alrededor

### Plan de trabajo

Durante la realización de este proyecto se utilizó Jira como principal programa de planeación de
proyectos de tal manera que, por medio de épicas, historias de usuario y tareas pudimos resolver
los requerimientos del proyecto. Las fases del proyecto que elegimos fueron:

- Fase 1: 

Búsqueda, animación y texturas de modelos en Blender: Colocar texturas a los
modelos descargados de internet y/o modificarlos para que puedan ser utilizados, asi como
animar al personaje principal.
- Fase 2: 

Escenario: Colocar luces, blending, sombras, partículas, coliders, skybox y los
modelos correspondientes en el lugar que le corresponda con respecto al diseño planteado.

- Fase 3: 

Lógica del juego: Colocar al personaje principal con sus respectivas animaciones
y que este vaya interactuando con las monedas, subirse a plataformas, perder vidas o ganar
puntuación.

- Fase 4: 

GUI: Generar los menús de interacción como el inicio del juego y las pantallas de
juego ganado o perdido.

- Fase 5: 

OpenAL: Editar y colocar los audios espaciales que correspondan

- Fase 6: 
Documentación: Generar la documentación requerida en el videojuego.

### Licenciamiento

Los modelos utilizados mayormente pertenecen a páginas de
Sketfab, TurboSquid, etc. La mayoría están bajo el licenciamiento de
creative commons. Los links de referencia los dejamos a continuación

#### Modelos implementados (con link)

- Escenario - [Link](https://skfb.ly/6VFZK)
- Casa Toad  - [Link](https://3dwarehouse.sketchup.com/model/5909ca01-6452-4743-a96a-2da59de4d93f/Mario-Toad-House)
- Castillo  - [Link](https://skfb.ly/BKKG)
- Monedas  - [Link](https://skfb.ly/6YUOC)
- Mobs de Minecraft en General  - [Link](https://sketchfab.com/vinceyanez)
- Árbol  - [Link](https://free3d.com/es/modelo-3d/minecraft-simple-tree-4959.html)
- CasaMinecraft1  - [Link](https://3dwarehouse.sketchup.com/model/4f179c1a5075703749568b6dc5d39ae5/Minecraft-Village-House?hl=en)
- CasaMinecraft2  - [Link](https://3dwarehouse.sketchup.com/model/4f179c1a5075703749568b6dc5d39ae5/Minecraft-Village-House?hl=en)
- CasaMinecraft3  - [Link](https://skfb.ly/6vpUF)
- CasaMinecraft4  - [Link](https://sketchfab.com/3d-models/minecraft-simple-house-0ae7f28a376d4758abf9f9de30b989c1)

#### Música 
Los sonidos son provenientes de la [página](https://www.mariomayhem.com/downloads/sounds/new_super_mario_bros_wii_sound_effects.php)


## Precio Estimado

Para obtener el precio estimado del videojuego se consideraron los siguientes insumos y
precios para de producción por todo el proyecto. Debido a que la mayoría del software se paga en
dólares, la cotización se mantuvo en dólares también.
- Estimación de costo por modelo: $30 usd x 33 = $ 990 usd
- Estimación de costo por audio: $5 usd x 8 = $ 40 usd
- Salario de modelador: $1500 usd x 1 = $1500 usd
- Salario de desarrollador: $1200 usd x 2 = $2400 usd
- Licencia de Visual Studio: $100 x 3 usd = $300 usd
- Luz eléctrica promedio: $50 x3 usd = $150 usd
- Gasto de equipo de cómputo: $1500 usd x computadora (3) = $4500 usd
- Internet: $30 x 3 = $90 usd
- GitHub Pro: $5 x 3 = $15 usd
- Jira Software: $100 usd
- Licencia de steam: $ 100 usd

Total

Costo total = **$ 10, 185 usd** = **207381.88 MXN**

Costo + Ganancia = **$ 13,240 usd** = **269455.18 MXN**

Precio de venta = **$ 10 usd.**
*Redituable a las 1300 descargas*.

### Resultados y trabajo Futuro

Para mayor detalle se adjunta el siguiente [video](https://drive.google.com/file/d/1-yQnlTqSEcMGmUVBc9AiwUP8OUNu-5Tw/view) 
que muestra la funcionalidad del videojuego:


Como parte del trabajo fututo para el desarrollo del videojuego se encuentran la integración
de enemigos con inteligencia artificial, como por ejemplo la capacidad de perseguir por el
escenario, o por parte de él, al jugador, así como la lanzar misiles o proyectiles que puedan restarle
vida al jugador, de tal manera que éste tenga que estar pendiente de los diversos enemigos en el
mapa, mientras que cumple con la misión de recolectar todas las monedas. También se planea la
implementación de diferentes niveles de dificultad cada uno con su propio mapa y enemigos
particulares.
