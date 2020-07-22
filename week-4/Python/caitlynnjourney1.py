counts = [ int(x) for x in input().split(' ') ]
stones = [ int(x) for x in input().split(' ') ]
queries = [ int(x) for x in input().split(' ') ]

#Prompt 1:
def find_day(query):
    total_stones = 0
    for stone in stones:
        total_stones += stone
        if total_stones >= query:
            current_days = stones.index(stone) + 1
            return current_days

for query in queries:
   current_days = find_day(query)
   print(current_days)