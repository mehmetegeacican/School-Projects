A Star Search Algorithm

The Algorithm:
1) Generate a list of all possible next Steps toward goal from current position
2) Store Children in PriorityQueue based on distance to goal, closest first
3) Select closest child and Repeat until goal reached or no more Children

How does it work:
Step 1) Go to the file directory in your cmd (.... --> cd A_Star_Search)
Step 2) Run the code -> type "python a_star.py"

The Matrix 

Using the A Star Search Algorithm, We are trying to get from one order of the matrix to the final step of the matrix.
The Matrix is 3x3

The Goal State:
        [
          ["1","2","3"],
          ["4","5","6"],
          ["7","8","-"]
        ]

The Start State can be any combinations of these 9 characters