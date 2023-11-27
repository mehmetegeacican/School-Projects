#!usr/bin/env python

from queue import PriorityQueue

class State(object):
    def __init__(self,value,parent,
                    start= 0,goal = 0, solver = 0):
        self.children = []
        self.parent = parent
        self.value = value
        self.dist = 0
        if parent:
            self.path = parent.path[:]
            self.path.append(value)
            self.start = parent.start
            self.goal = parent.goal

        else:
            self.path = [value]
            self.start = start
            self.goal = goal


    def get_distance(self):
        pass
    def create_children(self):
        pass

class State_String(State):
    def __init__(self,value,parent,
                 start = 0,
                 goal = 0):

        super(State_String, self).__init__(value, parent, start, goal)
        self.dist = self.get_distance()

    def get_distance(self):

        if self.value == self.goal:
            return 0
        dist = 0
        for i in range(len(self.goal)):
            letter = self.goal[i]
            try:
                dist += abs(i - self.value.index(letter))
            except:
                dist += abs(i - self.value.find(letter))
        return dist

    def create_children(self):
        if not self.children:
            for i in range(len(self.goal)-1):
                val = self.value
                val = val[:i] + val[i+1] + val[i] + val[i+2:]
                child = State_String(val, self)
                self.children.append(child)

class A_Star_Solver:
    def __init__(self, start , goal):
        self.path          = []
        self.visitedQueue  = []
        self.priorityQueue = PriorityQueue()
        self.start         = start
        self.goal          = goal

    def solve(self):
        startState = State_String(self.start,
                                  0,
                                  self.start,
                                  self.goal)

        count = 0
        self.priorityQueue.put((0,count,startState))

        while(not self.path and self.priorityQueue.qsize()):
            closestChild = self.priorityQueue.get()[2]
            closestChild.create_children()
            self.visitedQueue.append(closestChild.value)

            for child in closestChild.children:
                if child.value not in self.visitedQueue:
                    count +=1
                    if not child.dist:
                        self.path = child.path
                        break
                    self.priorityQueue.put((child.dist,count,child))

        if not self.path:
            print("Goal is not possible: ",(self.goal))

        return self.path

"""
if __name__ == "__main__":
    start_1 = "1265-4387"
    goal_1 = "12345678-"
    print("Starting")
    a = A_Star_Solver(start_1,goal_1)
    a.solve()
    for i in range(len(a.path)):
        print("Step",i,")", a.path[i])
"""
