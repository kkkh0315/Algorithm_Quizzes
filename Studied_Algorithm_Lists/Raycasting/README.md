# Raycasting with DDA(Digital Differential Analyzer) Algorithm and Minilibx
* **Raycasting** is a rendering technique to create a 3D perspective in a 2D map.  
In raycasting, virtual light rays are cast on their path from the focal point of a camera through each pixel in the camera  
sensor to determine what is visible along the ray in the 3D scene.  
* **DDA algorithm** is an incremental method of scan conversion of line.  
It is one of the most used line drawing algorithms typically used on square grids to find which squares a line hits.
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

<br>
<br>
<br>
<br>

# DDA 알고리즘과 Minilibx을 활용한 레이캐스팅
* **레이캐스팅**은 2D 맵에서 3D 시각을 표현하기 위한 렌더링 기술입니다.  
레이캐스팅은 가상의 광선을 만들어냅니다.  
그리고 3D 화면에서 이 광선이 지나가는 경로에 어떤 물체가 있는지 판별하기 위해 이 광선을 쏘아, 카메라의 초점에서부터 카메라 시야에 들어오는 매 픽셀을 확인합니다.  
* **DDA 알고리즘**은 연속적인 그래픽 객체를 개별 픽셀 모음으로 나타내는데 쓰이는 증분 방식입니다.  
선 그리기 알고리즘으로 유명하며, 선분이 어떤 사각형을 지나는지 찾기 위해 정사각형 그리드에서 자주 사용됩니다.  
* **Minilibx**는 42 학생들을 위해 만들어진, 작은 그래픽 라이브러리이자 C로 구현된 X-Window 프로그래밍 API입니다.  
간단한 창을 만들고, 그림을 그리고, 단순 이벤트들을 관리할 수 있게 해줍니다.  

## 작동 방식
코드는 [Lode's Computer Graphics Tutorial: Raycasting](https://lodev.org/cgtutor/raycasting.html)를 바탕으로 작성되었습니다.  
레이캐스팅을 DDA 알고리즘을 활용하여 구현하는 방식에 대한 자세한 설명은 위 페이지를 참고해주시면 감사하겠습니다.  
다만, 튜토리얼의 코드는 C++로 작성된 반면, 저의 코드는 C로 작성되었습니다.  

## 설치
리눅스
~~~~
make
~~~~
