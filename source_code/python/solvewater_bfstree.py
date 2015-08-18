from water import water
from bfstree import bfstree
from node import node

s0 = water(0, 0)
n, v = bfstree(s0)

if n:
    print("Solution")
    print("========")
    n.printsolution()
    print("========")
    print("Depth = %d, Cost = %d" % (n.depth, n.cost))
    print("No. of Visited Nodes = %d" % v)
