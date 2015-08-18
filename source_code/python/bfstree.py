from collections import deque
from node import node

def bfstree(s0):
    # s0 = initial state

    # create the initial node
    n0 = node(s0, None, None, 0, 0) 

    # initizlize #visited nodes
    nvisited = 0
    
    # initialize the frontier list
    frontier = deque([n0])

    while True:
        # the search fails when the frontier is empty
        if not frontier:
            return (None, nvisited)
        else:
            # get one node from the frontier
            n = frontier.popleft()
            # count the number of visited nodes
            nvisited+=1
            # check if the state in n is a goal
            if n.state.isgoal():
                return (n, nvisited)
            else:
                # generate successor states
                S = n.state.successors()
                # create new nodes and add to the frontier
                for (s, a, c) in S:
                    p = node(s, n, a, n.cost+c, n.depth+1)
                    frontier.append(p)
