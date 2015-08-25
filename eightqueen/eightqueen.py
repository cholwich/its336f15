class eightqueen:
    def __init__(self, *args, **kwargs):
        if len(args)==2:
            self.board = list(args[0])
            self.lastqueen = args[1]
        else:
            self.board = list([0, 0, 0, 0, 0, 0, 0, 0])
            self.lastqueen = 0
    
    def __str__(self):
        return str(self.board)

    def __repr__(self):
        return str(self)

    def isgoal(self):
        if self.lastqueen == 8:
            return True
        return False

    def successors(self):
        return []
