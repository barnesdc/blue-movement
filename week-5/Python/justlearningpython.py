# count = 0
# sum =0

# print('before', count, sum)
# for value in [9, 41, 12, 3,74, 14]:
#     count+=1
#     sum = sum + value
#     print(count, sum, value)
# print('after', count, sum, int(sum/count))

# #using yield and return 

# found = False
# print('before,' , found)
# for value in [9, 41, 12, 3,47, 15]:
#     if value == 3:
#         found = True
#         break
#     print(found, value)
# print('after', found)

# number = [9,41, 12, 3,74, 21]
# largest = -1
# print("before", largest)
# for num in number:
#     if num > largest:
#         if largest > num:
#             largest = num
#         largest = num
#     print(largest, num)
# print('afer', largest)

count = 0
whiteline =" "
xfile = open('projectText.txt')
for x in xfile:
    if whiteline == xfile.strip():
        count+=1
    print(x)
print(count)
