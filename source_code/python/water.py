class water:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return '[%d, %d]' % (self.x, self.y)

    def __repr__(self):
        return str(self)

    def isgoal(self):
        if self.y == 4:
            return True
        else:
            return False

    def successors(self):
        if self.x > 0:
            yield (water(0, self.y), "Empty {3}", self.x)
        if self.y > 0:
            yield (water(self.x, 0), "Empty {5}", self.y)

        if self.x < 3:
            yield (water(3, self.y), "Fill up {3}", 3 - self.x)
        if self.y < 5:
            yield (water(self.x, 5), "Fill up {5}", 5 - self.y)

        a = 3 - self.x
        b = 5 - self.y

        if self.x < 3:
            if self.y >= a:
                yield (water(3, self.y-a), "Pour {5} -> {3}", a)
            elif self.y > 0:
                yield (water(self.x+self.y, 0), "Pour {5} -> {3}", self.y)
        if self.y < 5:
            if self.x >= b:
                yield (water(self.x-b, 5), "Pour {3} -> {5}", b)
            elif self.x > 0:
                yield (water(0, self.x+self.y), "Pour {3} -> {5}", self.x)
