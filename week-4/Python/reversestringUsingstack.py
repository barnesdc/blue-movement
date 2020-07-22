from stack import Stack

def revers_string(stack, input_string):
    for i in range(len(input_string)):
        stack.Push(input_string[i])
    rev_string = ""
    while not stack.is_empty():
        rev_string += stack.pop()
    return rev_string

# converting int to decimal

# def int_to_dec(nums):
#     for i in range(nums):
#         remainder = nums // 2
#         stack.Push(remainder)
#     pop_num = []
#     while not stack.is_empty():
#         pop_num.append(stack)
#     return pop_num
def convert_int_to_bin(dec_num):
    s = Stack()

    while dec_num > 0:
        remainder = dec_num % 2
        s.Push(remainder)
        dec_num = dec_num // 2

    bin_num = ""
    while not s.is_empty():
        bin_num += str(s.pop())

    return bin_num
stack = Stack()
input_string = "Helloworld"
print(revers_string(stack, input_string))