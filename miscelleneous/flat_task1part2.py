def validateString(str):
    str.strip()
    if(not((str[0] == '_') or (str[0]>='a' and str[0] <= 'z') or (str[0]>='A' and str[0] <= 'Z'))):
        return False
    for ch in str:
        if(not((ch == '_') or (ch>='a' and ch <= 'z') or (ch>='A' and ch <= 'Z') or (ch >= '0' and ch <= '9'))):
            return False
    return True

userIdentifiers = input("Enter the set of identifiers: ")

identifiers = userIdentifiers.strip().split(" ")
userIdentifiers = "".join(identifiers)
identifiers = userIdentifiers.split(",")

valid = True

for string in identifiers:
    
    isValid = validateString(string)
    if(not isValid):
        identifiers.remove(string)
        print("Error: invalid identifier [",string,"];")
        valid = False
        
if(valid):
    print("All identifiers are valid")
else:
    exit()

userExpression = input("Enter the expression: ")
ls = userExpression.strip().split(" ")
userExpression = "".join(ls)

i=0 
j=0
valid = True
operators = "*/+-"
expression = []

for symbol in userExpression:

    if(symbol in operators): # arithmetic symbol encountered
        if(len(expression) == 0):
            print("Error: expression starts with operator;")
            valid = False
            break
        
        top = expression[-1]
        if(top in operators): # current symbol as well the symbol on stack top are operators, hence invalid
            
            print("Error: invalid expression (adjacent occurrence of operators is not allowed);")
            valid = False
            break
        
        identifier = userExpression[i:j]
        if(identifier not in identifiers):
            try:
                temp = float(identifier)
                expression.append(temp)
            except (TypeError, ValueError):
                print("Error: undeclared identifier (", identifier, "is not declared );")
                valid = False
                break
        expression.append(symbol)
        j+=1
        i=j
            
    else:
        expression.append(symbol)
        j+=1
if valid:
    identifier = userExpression[i:j]
    if(identifier not in identifiers):
        try:
            temp = float(identifier)
            expression.append(temp)
        except (TypeError, ValueError):
            print("Error: undeclared identifier (", identifier, "is not declared );")
            valid = False
    
if valid:
    print("Expression is valid")
