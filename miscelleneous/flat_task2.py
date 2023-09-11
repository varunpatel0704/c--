# Write a program to display set of Non-terminals and Terminals used to 
# represent Context Free Grammar from given set of production rules.
# Example:
# S→ ASB | ^
# A→ aAS | a
# B→ SbS | A | bb
# Output:
# Set of Non-terminals: {S, A, B}
# Set of Terminals {a, b, ^}

pr = input("Enter the set of production rules: ")

terminals = []
nonTerminals = []

for ch in pr:
    if(ch >= 'A' and ch <= 'Z'):
        if(ch not in nonTerminals):
            nonTerminals.append(ch)
    elif(ch >= 'a' and ch <= 'z') or (ch == '^'):
        if(ch not in terminals):
            terminals.append(ch)

print("\nSet of terminals:",terminals)
print("Set of non-terminals:",nonTerminals)