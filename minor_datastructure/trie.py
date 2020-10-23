trie = lambda: defaultdict(tree)
root = trie()


# creation
for word in words:
    curr = root
    for c in word:
    curr = curr[c]
    curr.setdefault("_end", None)

# lookup
def exist_word(trie, word):
    curr = trie
    for w in word:
        if w not in curr:
            return False
        curr = curr[w]
    return '_end' in curr

