# 🐱 Gato Runner - Juego de Plataformas 2D

Un emocionante juego de plataformas 2D donde controlas a un gato que debe esquivar obstáculos. Desarrollado usando SFML (Simple and Fast Multimedia Library) en C++.

## 🎮 Características Principales

- ✅ Control sencillo: Salta con la tecla **↑** y cae rápido con **↓**
- ✅ Sistema de puntuación basado en tiempo de supervivencia
- ✅ Pantalla de Game Over con opción de reinicio (presiona Enter)
- ✅ Música de fondo y efectos visuales atractivos
- ✅ Dificultad progresiva (los obstáculos aparecen más rápido con el tiempo)


## Como ejecutar

Instalar todas las dependencias descritas abajo y dentro de una terminal de vscode ejecutar:

> make run'NombreEjecutable'

Por ejemplo para ejecutar 'juego.cpp' correr el comando en la terminal de vscode:

> make runjuego


## Programas necesarios

### Visual estudio code
Descargar e instalar vscode en el siguiente [Enlace.](https://code.visualstudio.com/)

### MSYS2 (Windows)

Instalar Msys2 usando el siguiente [Enlace.](https://github.com/msys2/msys2-installer/releases/download/2023-05-26/msys2-x86_64-20230526.exe)

No modificar ningua opcion al momento de intalacion o podrian variar las configuraciones.

Una vez instalado es necesario agregar los siguientes directorios al path de windows y reiniciar.

> C:\msys64\mingw64\bin

> C:\msys64\usr\bin

### Github Desktop
Cliente de escritorio para clonar el repositorio, descargar usando el siguiente [enlace](https://desktop.github.com/).

### Git
Para poder realizar commits de vscode es necesario tener instalado Git, descargarlo del siguiente [enlace](https://git-scm.com/).


## Librerias utilizadas (Msys2)

Ejecutar los siguientes comandos en la terminal de msys2 para instalar las dependencias necesarias

### DevTools
Compiladores y herramientas necesarias para el desarrollo.

https://code.visualstudio.com/docs/cpp/config-mingw
> pacman -S --needed base-devel mingw-w64-x86_64-toolchain

### SFML
https://packages.msys2.org/package/mingw-w64-x86_64-sfml
> pacman -S mingw-w64-x86_64-sfml

### Box2D simulaciones de fisica - C++
https://box2d.org/documentation/
https://packages.msys2.org/package/mingw-w64-x86_64-box2d?repo=mingw64
pacman -S mingw-w64-x86_64-box2d

## Complementos necesarios VSCode

- Material Icon
- C/C++
- PlantUML
- GitGraph