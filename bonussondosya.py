def check_array_name(array_name):
    if not array_name[0].isalpha():
        return False
    for c in array_name[1:]:
        if not c.isalnum():
            return False
    return True

def check_dimensions(bound):
    lower_bound, upper_bound = bound.split('..')
    if lower_bound[0] == '+' or lower_bound[0] == '-':
        lower_bound = lower_bound[1:]
    if upper_bound[0] == '+' or upper_bound[0] == '-':
        upper_bound = upper_bound[1:]
    if not lower_bound.isdigit() or not upper_bound.isdigit():
        return False


def parse_array_declaration(declaration):
    tokens = declaration.split(" ")
    if len(tokens) < 7 or tokens[1] != ':' or tokens[2] != 'array' or tokens[3][0] != '[' or tokens[-4][-1] != ']' or tokens[-3] != 'of' or tokens[-1] != ';':
        return None
    
    array_name = tokens[0]
    if not check_array_name(array_name):
        return None
    
    if tokens[2] != "array" or tokens[-1] != ";" or tokens[-2] != "integer" or tokens[-3] != "of":
        return None
    
    dimensions_str = ' '.join(tokens[3:-3])[1:-1]
    data_type = tokens[-2]
    
    dimensions = []
    bounds = dimensions_str.split(' , ')
    for bound in bounds:
        bound_tokens = bound.split('..')
        if len(bound_tokens) != 2:
            return None
        dimensions.append((bound_tokens[0], bound_tokens[1]))

    
    descriptor = [
        "Multidimensional array" if len(dimensions) > 1 else "Array",
        data_type,
        "Integer",  # Index type field
    ]

    if len(dimensions) > 1:
        descriptor.append(str(len(dimensions))),  # Number of dimensions)
        for bound in dimensions:
            descriptor.append([bound[0], bound[1]])
    else:
        descriptor.append(dimensions[0][0])
        descriptor.append(dimensions[0][1])

    descriptor.append("1000")  # Address field

    return descriptor


# input_declaration = "MYARR123 : array [10..15 , 6..9] of integer ;"
# input_declaration = "MYARR123 : array [+10..-15] of integer ;"

input_declaration = input("Enter an array declaration: ")

output = parse_array_declaration(input_declaration)

if output:
    print(output)
else:
    print("Invalid array declaration.")
