from cs50 import get_int
        

def print_space(space):
    for j in range(space):
        print(" ", end="")


def print_hashmark(hashmark):
    for j in range(hashmark):
        print("#", end="")        


while True:
    height = get_int("Height(between 1-8): ")
    if height > 0 and height < 9:
        break
for i in range(height):
    space = height - i - 1
    hashmark = i + 1
    
    print_space(space)
    print_hashmark(hashmark)
    print("  ", end="")
    print_hashmark(hashmark)
    print()
    