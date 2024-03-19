from subprocess import Popen, PIPE, STDOUT
from os import listdir
from os.path import isfile, join
import numpy as np
from generators import *

def runApp(app, input_data):
    pipe = Popen([app], stdout=PIPE, stdin=PIPE)
    out = pipe.communicate(input=bytes(input_data, "UTF-8"))
    return out[0].decode()

def runTest(app, generator):
    expression = ''.join(generator(3))
    result = 0
    try:
        print(expression)
        result = int(runApp(app, expression))
    except Exception as e:
        ...
    return result

def end_to_end(app): 
    print("Running tests...")
    for i in range(5): 
        result = runTest(app, gen_correct_expression)
        print(f'Result: {result}')
    print("Tests finished.")

app = "./paracl"
end_to_end(app)