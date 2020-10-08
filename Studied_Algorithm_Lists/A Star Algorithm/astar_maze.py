import heapq


class Node:
    def __init__(self, position=None, parent=None):
        self.position = position
        self.parent = parent
        self.g = 0
        self.h = 0
        self.f = 0

    def __lt__(self, other):
        return self.f < other.f

    def __eq__(self, other):
        return self.position == other.position


# Manhattan distance
def h_manhattan(p1, p2):
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])


# Euclidean distance
def h_euclidean(p1, p2):
    return (p1[0] - p2[0])**2 + (p1[1] - p2[0])**2


def astar(maze_info, start, end):

    # Create start and end node
    start_node = Node(start, None)
    end_node = Node(end, None)

    # Initialize both open and closed list
    open_list = []              # Going to use as a priority queue
    closed_list = []            # To store visited nodes
    open_list.append(start_node)

    while open_list:
        cur_node = heapq.heappop(open_list)
        closed_list.append(cur_node)

        # When reached the goal
        if cur_node == end_node:
            path = []
            while cur_node:
                path.append(cur_node.position)
                cur_node = cur_node.parent
            print("Optimal path:", path[::-1])
            return path[::-1]

        # Create children list
        children = []
        for offset in [(0, -1), (0, 1), (-1, 0), (1, 0), (1, -1), (-1, -1), (-1, 1), (1, 1)]:
            new_pos = (cur_node.position[0] + offset[0], cur_node.position[1] + offset[1])
            if new_pos[0] > (len(maze_info) - 1) or new_pos[0] < 0:
                continue
            if new_pos[1] > (len(maze_info[0]) - 1) or new_pos[1] < 0:
                continue
            if maze[new_pos[0]][new_pos[1]] != 0:
                continue
            new_node = Node(new_pos, cur_node)
            children.append(new_node)

        # Loop through children
        for child_node in children:
            if child_node in closed_list:
                continue
            child_node.g = cur_node.g + 1
            child_node.h = h_manhattan(child_node.position, end_node.position)
            child_node.f = child_node.g + child_node.h

            for open_node in open_list:
                if child_node == open_node:
                    if child_node.g <= open_node.g:
                        open_list.remove(open_node)
                        heapq.heappush(open_list, child_node)
                        break
                    break
            else:
                heapq.heappush(open_list, child_node)


if __name__ == '__main__':
    maze = [[1, 1, 1, 1, 1, 1, 1, 1],
            [1, 0, 0, 1, 0, 1, 0, 1],
            [1, 1, 0, 0, 0, 0, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 1],
            [1, 1, 1, 1, 0, 1, 1, 1],
            [1, 0, 0, 0, 0, 0, 1, 1],
            [1, 0, 0, 0, 0, 0, 0, 1],
            [1, 1, 1, 0, 1, 0, 0, 1],
            [1, 1, 1, 1, 1, 1, 1, 1]]

    depart = (1, 1)
    destination = (7, 5)
    astar(maze, depart, destination)
