def validateString(str):
    if(not((str[0] == '_') or (str[0]>='a' and str[0] <= 'z') or (str[0]>='A' and str[0] <= 'Z'))):
        return False
    for string in str:
        if(not((string[0] == '_') or (string[0]>='a' and string[0] <= 'z') or (string[0]>='A' and string[0] <= 'Z'))):
            return False
    return True

# userIdentifiers = input("Enter the set of identifiers: ")
# identifiers = userIdentifiers.split(", ")
# # print(identifiers)

# for string in identifiers:
#     isValid = validateString(string)
#     if(not isValid):
#         print("Error: invalid identifier [",string,"];")

userExpression = input("Enter the expression: ")
expression = userExpression.split(" ")
print(expression)
