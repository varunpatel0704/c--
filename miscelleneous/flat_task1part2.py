def validateString(str):
    if(not((str[0] == '_') or (str[0]>='a' and str[0] <= 'z') or (str[0]>='A' and str[0] <= 'Z'))):
        return False
    for string in str:
        if(not((string[0] == '_') or (string[0]>='a' and string[0] <= 'z') or (string[0]>='A' and string[0] <= 'Z'))):
            return False
    return True

userIdentifiers = input("Enter the space separated set of identifiers: ")

identifiers = userIdentifiers.split(" ")
print(identifiers)
valid = True

for string in identifiers:
    isValid = validateString(string)
    if(not isValid):
        identifiers.remove(string)
        print(identifiers)
        print("Error: invalid identifier [",string,"];")
        valid = False
        
if(valid):
    print("All identifiers are valid")

userExpression = input("Enter the expression: ")
ls = userExpression.split(" ")
userExpression = "".join(ls)
i=0 
j=0
valid = True
operators = ['*', '/', '+', '-', '%']
expression = []

for symbol in userExpression:
    
    if(symbol in operators): # arithmetic symbol encountered
        length = len(expression)
        top = expression[length-1]
        
        if(top in operators): # current symbol as well the symbol on stack top are operators, hence invalid
            print("Error: invalid expression (adjacent occurence of operators is not allowed);")
            valid = False
            break
        
        identifier = userExpression[i:j]
        if(identifier not in identifiers):
            print("Error: undeclared identifier (", identifier, "is not declared);")
            valid = False
            break
        
        expression.append(symbol)
        j+=1
        i=j
            
    else:
        expression.append(symbol)
        j+=1
        
if valid:
    print("Expression is valid")
