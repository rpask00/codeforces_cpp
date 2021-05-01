import heapq
x = [
    (20, 1),
    (15, 6),
    (8, 13),
    (3, 19),
    (7, 14),
    (10, 11),
    (18, 4),
    (2, 17),
    (9, 12),
    (16, 5)
]

heapq.heapify(x)
for a in heapq.nsmallest(10,x):
    print(a)
