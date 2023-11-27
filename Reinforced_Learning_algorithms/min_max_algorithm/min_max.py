from sys import maxsize

#BUILD TREE
class Node(object):
  def __init__(self,i_depth,i_player_num,i_sticks_rem,i_val = 0):
    self.i_depth = i_depth
    self.i_player_num = i_player_num
    self.i_sticks_rem = i_sticks_rem
    self.i_val = i_val
    self.children = []
    self.create_children()

  def create_children(self):
    if self.i_depth >= 0:
      for i in range(1,3):
        v = self.i_sticks_rem - i
        self.children.append( Node(self.i_depth -1 ,
                              -self.i_player_num,
                              v,
                              self.real_val(v)))

  def real_val(self,value):
    if value == 0:
      return maxsize * self.i_player_num
    elif value < 0:
      return maxsize * -self.i_player_num
    return 0

#*****************************************
def min_max(node,i_depth,i_player_num):
  if(i_depth == 0) or (abs(node.i_val) == maxsize):
    return node.i_val

  i_best_val = maxsize * -i_player_num

  for i in range(len(node.children)):
    child = node.children[i]
    i_val = min_max(child,i_depth - 1,-i_player_num)

    if(abs(maxsize*i_player_num -i_val) < abs(maxsize*i_player_num - i_best_val)):
      i_best_val = i_val

    return i_best_val
#***********************************************
def check_win(i_sticks,i_player_num):
  if i_sticks == 0:
    print("*"*30)
    if i_player_num > 0:
      if i_sticks == 0:
        print("You win!!!!")
      else:
        print("Too many, you lost")
    else:
      if i_sticks == 0:
        print("Computer wins")
      else:
        print("Error")
    print("*"*30)
    return 0 
  return 1

if __name__ == '__main__':
  i_stick_total = 11
  i_depth = 4
  i_current_player = 1

  while(i_stick_total > 0):
    print(i_stick_total, " sticks remaining\n")
    i_choice = input("1 or 2:\n")
    #i_choice = 1
    i_stick_total -= int(float(i_choice))

    if check_win(i_stick_total,i_current_player):
      i_current_player *= -1
      node = Node(i_depth,i_current_player,i_stick_total)
      best_choice = -100
      i_best_val = -i_current_player*maxsize

      for i in range(len(node.children)):
        n_child = node.children[i]
        i_val = min_max(n_child,i_depth,-i_current_player)

        if(abs(i_current_player * maxsize -i_val) <= abs(i_current_player*maxsize -i_best_val)):
          i_best_val = i_val
          best_choice = i

      best_choice += 1
      print("Computer chooses ", str(best_choice))

      i_stick_total -= best_choice
      check_win(i_stick_total,i_current_player)
      i_current_player *= -1



