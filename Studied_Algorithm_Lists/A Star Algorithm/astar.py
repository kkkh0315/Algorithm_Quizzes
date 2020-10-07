import heapq

# Graph info in adjacency list type {departing node: {destination node: cost}}
distance_map = {
    1: {2: 2, 3: 5, 4: 1},
    2: {1: 2, 3: 3, 4: 2},
    3: {1: 5, 2: 3, 4: 3, 5: 1, 6: 5},
    4: {1: 1, 2: 2, 3: 3, 5: 1},
    5: {3: 1, 4: 1, 6: 2},
    6: {3: 5, 5: 2}
}


class Node:
    def __init__(self, name=None, parent=None):
        self.name = name
        self.parent = parent
        self.g = 0
        self.h = 0
        self.f = 0

    def __lt__(self, other):
        return self.f < other.f

    def __eq__(self, other):
        return self.name == other.name


def h(p1, p2):
    return abs(p1 - p2)


def astar(map_info, start, end):

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
            min_cost = 0
            while cur_node:
                path.append(cur_node.name)
                if cur_node.parent:
                    min_cost += distance_map[cur_node.parent.name].get(cur_node.name)
                cur_node = cur_node.parent
            print("Optimal path:", path[::-1], "\nMinimum cost:", min_cost)
            return path[::-1], min_cost

        # Loop through children
        for child, cost in map_info[cur_node.name].items():
            child_node = Node(child, cur_node)
            if child_node in closed_list:
                continue
            child_node.g = cur_node.g + cost
            child_node.h = h(child_node.name, end_node.name)
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


astar(distance_map, 1, 6))
