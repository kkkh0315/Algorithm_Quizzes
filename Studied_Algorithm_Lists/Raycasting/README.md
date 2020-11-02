# Raycasting with DDA(Digital Differential Analyzer) Algorithm and Minilibx
* **Raycasting** is a rendering technique to create a 3D perspective in a 2D map.  
In raycasting, virtual light rays are cast on their path frome the focal point of a camera thorugh each pexiel in the camera  
seonsor to determine what is visible along the ray in the 3D scene.  
* **DDA algorithm** is an incremental method of scan conversion of line.  
It is one of the most used line drawing algorithms typically used on squre grids to find which squares a line hits.
* **Minilibx** is a small graphics library, a X-Window programming API in C, designed for 42 students.  
It allows you to create a simple window, draw, and manage basic events.

## How it works
The code is written based on [Lode's Computer Graphics Tutorial: Raycasting](https://lodev.org/cgtutor/raycasting.html).  
Please, refer to the page for the detailed illustrations of how raycasting can be implemented by DDA algorithm.  
Note that the tutorial's codes are written in C++ whereas mine is in C.

## Install
Linux
~~~~
make
~~~~
