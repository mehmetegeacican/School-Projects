from a_star import *
import random

#FOR DEMONSTRATION
matrix = [
          ["1","2","3"],
          ["4","5","6"],
          ["7","8","-"]
          ]

#THE POSSIBLE MATRIX GENERATIONS
pos_list = []

def print_matrix_values(matrix):
    for row in matrix:
        print(row)

def set_matrix_values(number_order):

    row_1 = [number_order[0],number_order[1],number_order[2]]
    row_2 = [number_order[3],number_order[4],number_order[5]]
    row_3 = [number_order[6],number_order[7],number_order[8]]

    matrix = [row_1,row_2,row_3]

    #print_matrix_values(matrix)

    return matrix

def get_matrix_values(matrix):
    string_value = ""
    for row in matrix:
        for x in range(len(row)):
            string_value += row[x] 
    return str(string_value)

def generate_matrix_values(one_state):

    while len(pos_list) < 30:
        num = list(one_state)
        random.shuffle(num)
        result = ''.join(num)
        if result not in pos_list:
            pos_list.append(result)
    
    return pos_list


def use_A_star(matrix,goal):

    matrix_state = get_matrix_values(matrix)
    
    a = A_Star_Solver(matrix_state,goal)
    a.solve()
    for i in range(len(a.path)):
        x = a.path[i]
        print("Step",i,")",a.path[i])
        matrice = set_matrix_values(x)
        print_matrix_values(matrice)



if __name__ == "__main__":

    #GENERATING MATRIX VALUES
    end_1 = "12345678-"
    start_states = generate_matrix_values(end_1)
    for start_state in start_states:
        print("Starting state: ",start_state,"***************" )
        s_matrix = set_matrix_values(start_state)
        start_i = get_matrix_values(s_matrix)
        use_A_star(start_i,end_1)


    

    

    
        
