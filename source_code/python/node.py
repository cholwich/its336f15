class node:
    def __init__(self, state, parent, action, cost, depth):
        self.state = state
        self.parent = parent
        self.action = action
        self.cost = cost
        self.depth = depth

    def __str__(self):
        return '(' + ','.join([str(self.state), str(self.parent), str(self.action),
                str(self.cost), str(self.depth)]) + ')'

    def __repr__(self):
        return str(self)

    def __lt__(self, o):
        return self.cost < o.cost

    def printsolution(self):
        n = self
        l = []
        while n.parent:
            l.append(str(n.action))
            n = n.parent
        while l:
            print(l.pop())
