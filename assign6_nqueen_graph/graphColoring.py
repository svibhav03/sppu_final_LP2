class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for _ in range(vertices)] for _ in range(vertices)]

    def is_safe(self, v, colour, c):
        for i in range(self.V):
            if self.graph[v][i] == 1 and colour[i] == c:
                return False
        return True

    def graph_colouring_util(self, m, colour, v):
        if v == self.V:
            return True
        for c in range(1, m + 1):
            if self.is_safe(v, colour, c):
                colour[v] = c
                if self.graph_colouring_util(m, colour, v + 1):
                    return True
                colour[v] = 0

    def graph_colouring(self, m):
        colour = [0] * self.V
        if not self.graph_colouring_util(m, colour, 0):
            return False
        print("Solution exists: Following are the assigned colours:")
        for c in colour:
            print(c, end=" ")
        return True


# Example usage:
g = Graph(4)
g.graph = [
    [0, 1, 1, 1],
    [1, 0, 1, 0],
    [1, 1, 0, 1],
    [1, 0, 1, 0]
]
m = 3  # Number of colors
g.graph_colouring(m)
