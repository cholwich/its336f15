from node import node
from heapq import heappush, heappop

def ucsgraph(s0):
    # s0 = initial state

    # create the initial node
    n0 = node(s0, None, None, 0, 0) 

    # initizlize #visited nodes
    nvisited = 0
    
    # initialize the frontier list
    frontier = [n0]

    # initialize the explored set
    explored = set()

    while True:
        # the search fails when the frontier is empty
        if not frontier:
            return (None, nvisited)
        else:
            # get one node from the frontier
            n = heappop(frontier)
            # add the state to the expolored set
            explored.add(str(n.state))
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
                    if str(s) not in explored:
                        idx = find_state(s, frontier)
                        p = node(s, n, a, n.cost+c, n.depth+1)
                        if  idx > 0 and frontier[idx].cost > p.cost: 
                            frontier[idx] = p
                            heapify(frontier)
                        else:
                            heappush(frontier, p)

def find_state(s, l):
    for i,n in enumerate(l):
        if str(n.state) == str(s):
            return i
    return -1
