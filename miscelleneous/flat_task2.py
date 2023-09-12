pr = input("Enter the set of production rules: ")

terminals = []
nonTerminals = []

for ch in pr:
    if(ch >= 'A' and ch <= 'Z'):
        if(ch not in nonTerminals):
            nonTerminals.append(ch)
    elif(ch >= 'a' and ch <= 'z') or (ch == '^') or (ch>= '0' and ch<='9'):
        if(ch not in terminals):
            terminals.append(ch)

print("\nSet of terminals:",terminals)
print("Set of non-terminals:",nonTerminals)