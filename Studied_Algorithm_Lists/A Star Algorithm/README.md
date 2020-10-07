# A-Star Algorithm
A-Star algorithm is a path finding algorithm which finds you the shortest path from a start point to the end point.  
A-Star algorithm is similar to Dijkstra algorithm, except it adopts heuristic method to decide which next point to visit first.  
Therefore, despite of its high space complexity, it's considered as one of the fastest, and reasonable path finding algorithms.  

## How it works 
~~~~
f(n) = g(n) + h(n)
~~~~
**g(n): The cost of the path from the start node to *n*.**  
**h(n): The result of a heuristic function that estimates the cost of the cheapest path from *n* to the end node.**  
1. Decide the start node and the end node.  
2. Calculate all the g, h, and f values of the adjacent nodes you haven't moved to but you can move to.  
Be sure to record from which node the adjacent nodes have been scrutinized.  
3. If any adjacent node has a bigger g value compared to the newly calculated one, update.    
4. Repeat 2~3 until you reach the end node.   
5. Trace back from the end node to the first node based on the record you made in every 2.  

## Example 1

Print and return the lowest cost and the path of that case when moving from 1 to 6.  
*e.g. The lowest cost when moving from 1 to 3 is 3 when traveling through 4 and 5.*  
<br>
<img src="https://user-images.githubusercontent.com/60923302/94100688-2ab8d980-fe69-11ea-8bdb-2e9f8b113520.png" width="500" height="500">

  **Implementation**  
   [A-Star algorithm for undirected weighted graph](https://github.com/kkkh0315/Algorithms/blob/master/Studied_Algorithm_Lists/A%20Star%20Algorithm/astar.py)  
   
## Example 2
Print the shortest path from the departure to the destination in the maze.  
<br>
<img src="https://user-images.githubusercontent.com/60923302/95332404-56ff3c00-08e6-11eb-8b25-f9fa0dc5b55e.png" width="500" height="562.5">

**Implementation**  
[A-Star algorithm for rectangular-shaped maze](https://github.com/kkkh0315/Algorithms/blob/master/Studied_Algorithm_Lists/A%20Star%20Algorithm/astar_maze.py)

<br>
<br>
<br>
<br>



# 에이스타 알고리즘
에이스타 알고리즘은 한 지점에서 다른 한 지점으로의 최단 거리를 찾아주는 알고리즘입니다.  
다익스트라 알고리즘과 비슷하나 휴리스틱값을 이용해 다음으로 탐색할 지점을 결정한다는 점에서 다릅니다.  
따라서, 공간복잡도는 다소 높아도 가장 빠르고 합리적인 경로 탐색 알고리즘 중 하나입니다.

## 기본 개념
~~~~
f(n) = g(n) + h(n)
~~~~
**g(n): 시작 노드에서 *n*까지의 비용.**  
**h(n): 휴리스틱 함수에 의해 계산된 *n*에서 끝 노드까지의 추정 비용.**  
1. 시작 노드와 끝 노드를 결정한다.  
2. 아직 방문하지 않았고 해당 노드로 움직일 수 있는 인접 노드들의 g, h, f값을 계산한다.  
이 때, 인접 노드의 부모 노드를 기록해두어야한다.
3. 인접 노드들 중 새롭게 계산한 g값보다 큰 g값을 가진 노드가 있다면, 노드를 새로운 것으로 업데이트한다.
4. 끝 노드에 도달할 때까지 2~3을 반복한다.  
5. 2에서 저장한 부모 노드에 대한 기록을 바탕으로 끝 노드에서 시작 노드로 거슬러 올라가며 최적 경로를 찾아낸다.  

## 예제 1

1번 지점에서 6번 지점으로 갈 때의 최소 비용과 그 때의 경로를 계산하여 각각 출력하고 반환하시오.  
*(예시) 1번에서 3번으로 가는 최소 비용은 4번과 5번을 거쳤을 때의 3이 된다.*  
<br>
<img src="https://user-images.githubusercontent.com/60923302/94100688-2ab8d980-fe69-11ea-8bdb-2e9f8b113520.png" width="500" height="500">

  **구현 방법**  
   [A-Star algorithm for undirected weighted graph](https://github.com/kkkh0315/Algorithms/blob/master/Studied_Algorithm_Lists/A%20Star%20Algorithm/astar.py)  
   
## 예제 2 
미로 안의 출발점에서 도착점까지의 최단 경로를 출력하시오.  
<br>
<img src="https://user-images.githubusercontent.com/60923302/95332404-56ff3c00-08e6-11eb-8b25-f9fa0dc5b55e.png" width="500" height="562.5">

**구현 방법**  
[A-Star algorithm for rectangular-shaped maze](https://github.com/kkkh0315/Algorithms/blob/master/Studied_Algorithm_Lists/A%20Star%20Algorithm/astar_maze.py)
