from cs50 import get_int

# get cc number and length
cc_number = get_int("CC Number: ")
length = len(str(cc_number))

# build list of digits in cc number
cc_number_list = []
num = cc_number
for i in range(length):
    cc_number_list.insert(0, num % 10)
    num = int(num / 10)

#get every other number, add & store in 2 variables, check if double digit    
singles = 0
doubles = 0
num = cc_number
for i in range(length):
    index = length - i - 1
    if i % 2 == 0:
        singles += cc_number_list[index]
    else:
        d = cc_number_list[index] * 2
        if d > 9:
            doubles += (d % 10) + (int(d/10))
        else:
            doubles += d
#check if last number of sum is 0 & determine type of cc number
if (singles + doubles) % 10 == 0:
    if (length == 15 and cc_number_list[0] == 3) and (cc_number_list[1] == 4 or cc_number_list[1] == 7):
        print("AMEX")
    elif (length == 13 or length == 16) and cc_number_list[0] == 4:
        print("VISA")
    elif length == 16 and cc_number_list[0] == 5 and cc_number_list[1] > 0 and cc_number_list[1] < 6:
        print("MASTERCARD")
    else:
        print("INVALID")
else:
    print("INVALID")