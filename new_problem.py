import os, sys

def add_include(filename): 
    
    new_file = os.path.join("./problems", filename)

    if not os.path.exists(new_file): 
        os.makedirs(new_file)

    filepath = os.path.join(new_file, filename + ".cpp")
    filepath_input = os.path.join(new_file, "input.txt")
        
    if os.path.exists(filepath): 
        print("File already exists")
        return

    if not os.path.exists("./problems/template.cpp"):
        print("Template folder not found")
        return

    with open("./problems/template.cpp", "r") as f:
        contents = f.read()

    with open(filepath, "w") as f: 
        f.write(contents)

    with open(filepath_input, "w") as f:
        f.write()

    print(f"Template folder created for problem {filename} in ./problems directory")


if __name__ == "__main__": 
    if len(sys.argv) != 2: 
        print("Usage: new_problem.py [problem number]")
    
    else: 
        add_include(sys.argv[1])



