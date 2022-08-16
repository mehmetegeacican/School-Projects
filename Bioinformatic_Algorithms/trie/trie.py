
class TrieNode:

    # Trie node class
    def __init__(self):
        self.children = [None]*26

        # isLeaf shows whether we are at the leaf
        self.isLeaf = False
        

class Trie:

    #CONSTRUCTION
    def __init__(self):
        self.root = self.getTrieNode()

    def getTrieNode(self):

        # Returns new trie node (initialized to NULLs)
        return TrieNode()

   

    def indexer(self,ch):

        # private helper function
        # Converts key current character into index
        # use only 'a' through 'z' and lower case

        return ord(ch)-ord('a')
    
    def reverse_indexer(self,ch):
        return ord(ch) + ord('a')
#**************************************************************INSERTION*************************************************************************
    def insertTrieKey(self,key):
        iterNode = self.root
        #TRAVERSING WHILE WE DONT ENCOUNTER A DIFFERENT LETTER
        for depth in range(len(key)):
            index = self.indexer(key[depth])
            #IF A DIFFERENT CHAR HAS BEEN ENCOUNTERED
            if not iterNode.children[index]:
                iterNode.children[index] = self.getTrieNode() #A NEW NODE HAS BEEN ADDED TO THE TRIE
            iterNode = iterNode.children[index]
            iterNode.isLeaf = True
#***********************************************************INSERTION******************************************************************************
#************************************************************DELETION******************************************************************************
    def removeTrieKey(self,key):
        root = self.root

        for char in range(len(key)):
            index = self.indexer(key[char])

            #KEY WAS NOT FOUND
            if not root:
                return None

            root = root.children[index]
        #KEY WAS NOT FOUND
        if not root:
            return None
        else:
            root.isLeaf = False
            return 1
#************************************************************DELETION*****************************************************************************
#***********************************************************SEARCHING*****************************************************************************
    def searchTrieKey(self,key):
        iterNode = self.root
        if len(key) == 0:
            print("The trie is empty")
            return False

        for depth in range(len(key)):
            index = self.indexer(key[depth])
            if not iterNode.children[index]:
                return False
            iterNode = iterNode.children[index]

        return iterNode.isLeaf
#***********************************************************SEARCHING*****************************************************************************
#***********************************************************SUFFIX TREE***************************************************************************
    def makeSuffixTree(self,key):
        for i in range(len(key)):
            self.insertTrieKey(key[i:])
        
#***********************************************************SUFFIX TREE***************************************************************************
#***********************************************************PRINT TREE**************************************************************************
  
    
        

#***********************************************************PRINT TREE**************************************************************************