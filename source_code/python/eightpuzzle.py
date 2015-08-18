class eightpuzzle:
    def __init__(self, board, x, y):
        self.board = board
        self.x = x 
        self.y = y 

    def __str__(self):
        return str(self.board[0:3]) + '\n' + str(self.board[3:6]) + '\n' + str(self.board[6:]) 

    def isgoal(self):
        if self.board == [1,2,3,4,5,6,7,8,0]:
            return True
        return False

    def successors(self):
        cpos = self.y * 3 + self.x
        if (self.x-1 >= 0 and self.x-1 <= 2):
            nb = list(self.board)
            npos = self.y * 3 + (self.x-1)
            nb[npos], nb[cpos] = nb[cpos], nb[npos]
            yield eightpuzzle(nb, self.x-1, self.y)

        if (self.x+1 >= 0 and self.x+1 <= 2):
            nb = list(self.board)
            npos = self.y * 3 + (self.x+1)
            nb[npos], nb[cpos] = nb[cpos], nb[npos]
            yield eightpuzzle(nb, self.x+1, self.y)

        if (self.y-1 >= 0 and self.y-1 <= 2):
            nb = list(self.board)
            npos = (self.y-1) * 3 + self.x
            nb[npos], nb[cpos] = nb[cpos], nb[npos]
            yield eightpuzzle(nb, self.x, self.y-1)

        if (self.y+1 >= 0 and self.y+1 <= 2):
            nb = list(self.board)
            npos = (self.y+1) * 3 + self.x
            nb[npos], nb[cpos] = nb[cpos], nb[npos]
            yield eightpuzzle(nb, self.x, self.y+1)


s = eightpuzzle([1,2,3,4,5,6,7,8,0], 2, 2)
for l in s.successors():
    print(l)
    print('---------')
