from water import water

s = water(0, 0)
print("isgoal? ", s.isgoal())
for l in s.successors():
    print(l)
print('-----')
s = water(3, 0)
for l in s.successors():
    print(l)
