from eightqueen import eightqueen

s = eightqueen()
print("State = " + str(s))
print("isgoal? ", s.isgoal())
for state,action,cost in s.successors():
    print(state)
print("=====")
s = eightqueen([2, 4, 6, 8, 1, 3, 5, 0], 7)
print("State = " + str(s))
print("isgoal? ", s.isgoal())
for state,action,cost in s.successors():
    print(state)
