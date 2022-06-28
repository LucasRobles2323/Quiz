# Quiz Interactivo Huachipato

Estudiantes PUCV curso: ICI2240-1  ESTRUCTURA DE DATOS

## **_Integrantes_**

- ### Ademir Muñoz: 


- ### Lucas Robles: 


- ### Gerard Espinoza: 


### ¡Grande Huachipato!

![Grande Huachipato](https://pbs.twimg.com/profile_images/1494832822099451910/NgCFzNKt_400x400.jpg)


## 1. Como compilar y ejecutar la tarea:

Clonar el repositorio en Desktop

    gcc main.c hashmap.c list.c global.c guardarDatos.c quiz.c treemap-answer.c -lwinmm -o QUIZ

Una vez creado el ejecutable.exe, se recomienda no ejecutarlo desde visual Studio Code, en cambio, debe dirigirse a la carpeta llamada
"Quiz" y seleccionar el archivo .exe llamado "QUIZ",  una vez seleccionado el programa procederá a ejecutarse.

Una vez ejecutado el programa procederá a generarse la imágen de presentación del equipo desarrollador del programa conocido como
"Huachipato", luego de mostrada la presentación se generará una advertencia y se desplegará el menú.

El menú en cuestión se compone de las siguientes opciones.

      -> Comenzar Juego    
         Cargar Juego
         Dificultad
         Top
         Salir

Como indica el ejemplo, una vez mostrado el menú, a su vez se generará una pequeña flecha que indica la opción que se seleccionará, siempre será,
generada en la primera opción, para elegir correctamente una opción debe apretarse la tecla "Enter".

Recomendación: Si se desea crear un usuario con nombre propio se debe seguir la siguiente ruta Quiz->Save->User, cambiando el nombre por defecto presente.

## 2. Las opciones que funcionan correctamente y las que no lo hacen indicando posibles causas

Las opciones Cargar juego, Dificultad, Top y Salir, funcionan de manera correcta. 

Comenzar Juego presenta algunas peculiaridades, una de ellas es cuando se inicia el cuestionario, inicia todas las preguntas y genera todas las respuestas de manera correcta pero,
de las 4 alternativas (siendo estas A, B C Y D) la "D" a demostrado tras muchos test ser la menos propensa a ser la verdadera, esto puede deberse a la función rand() y su gran dependencia
de la hora del computador en conjunto de la propia codificación de las funciones encargadas de realizar la tarea de aleatorizar las alternativas, es probable que solo se marque como verdadera en un segundo especifico del minuto presente y por ello sea tan poco probable que esta sea la alternativa correcta.

Otra pecualiaridad se encuentra en el funcionamiento de los comodines, en ocasiones, 1 tipo de comodín puede ser 2 veces utilizado en una misma pregunta, esto es un error, ya que cada tipo de comodín solo puede usarse 1 vez por pregunta. Esto puede deberse a una falencia en la condisinantes que restringen este uso inapropiado de los comodines.






