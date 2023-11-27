import random
import operator

size = 3
start_state = (size,size,1,0,0)
end_state = (0,0,0,size,size)


actions = [
    #1m 1c left to right
    (-1,-1,-1,1,1),
    #2m 0c left to right
    (-2,0,-1,2,0),
    #0m 2c left to right
    (0,-2,-1,0,2),
    #1m 0c left to right
    (-1,0,-1,1,0),
    #0m 1c left to right
    (0,-1,-1,0,1),
    #1m 1c right to left
    (1,1,1,-1,-1),
    #2m 0c right to left
    (2,0,1,-2,0),
    #0m 2c right to left
    (0,2,1,0,-2),
    #1m 0c right to left
    (1,0,1,0,-1),
    #0c 1m right to left
    (0,1,1,0,-1)

]


the_path = []
the_path.append(start_state)
past_states = []
past_states.append(start_state)


def check_conditions(state):

    if state[0] < 0 or state[1] < 0 or state[2] < 0 or state[3] < 0 or state[4] < 0:
        return False
    elif state[0] + state[3] > size or state[1] + state[4] > size:
        return False
    elif (state[0] < state[1] and state[0] != 0) or (state[3] < state[4] and state[3] != 0):
        return False
    else:
        return True

def check_no_loop(state):
    for past_state in past_states:
        if state == past_state:
            return False
    return True
def next_steps(state):
    next_states = []

    #IF THE DIRECTION IS FROM LEFT TO RIGHT
    if state[2] == 1:

        for i in range(0,5):
            possible_next_state = tuple(map(operator.add, state, actions[i]))
            #print(possible_next_state)
            if check_conditions(possible_next_state) and check_no_loop(possible_next_state):
                next_states.append(possible_next_state)


    #IF THE DIRECTION IS FROM RIGHT TO LEFT
    else:
        for i in range(5,10):
            possible_next_state_2 = tuple(map(operator.add, state, actions[i]))
            #print(possible_next_state_2)
            if(check_conditions(possible_next_state_2) and check_no_loop(possible_next_state_2)):
                next_states.append(possible_next_state_2)

    return next_states

def solve():
    
    while(len(the_path)) != 0:
        #print(the_path)
        nxy = next_steps(the_path[-1])
        #All possible outcomes have been tried
        if len(nxy) == 0:
            the_path.remove(the_path[-1])
        else:
            nx_state = random.choice(nxy)
            the_path.append(nx_state)
            past_states.append(nx_state)

            if nx_state == end_state:
                print(the_path)
                return the_path
    print("No solutions were found")


solve()







