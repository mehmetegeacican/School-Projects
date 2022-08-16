from trie import *

# Input keys (use only 'a' through 'z' and lower case)
keys = ["the","a","there","anaswe","any", "by","their"]
#THE CONSTRUCTION
t = Trie()
x = Trie()

#INSERTION
for i in range(len(keys)):
    t.insertTrieKey(keys[i])
t.insertTrieKey("asdasd")
print(t.searchTrieKey("the"))
print(t.searchTrieKey("asdasd"))
print(t.searchTrieKey("their"))
print(x.searchTrieKey("nn"))
t.removeTrieKey("asdasd")
print(t.searchTrieKey("th"))
t.makeSuffixTree("adffsdgsgsddsdasd")
