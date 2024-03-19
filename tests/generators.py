import random

def gen_correct_expression(num_terms):
    operators = ['+', '-', '*']
    expression = str(random.randint(1, 3)) 
    for _ in range(num_terms):  
        operator = random.choice(operators)
        term = f'{operator}{random.randint(1, 3)}'
        expression +=  term
    return expression
