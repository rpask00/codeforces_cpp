import sys

for _ in range(int(input())):
    ss = input()
    l = len(ss)
    for i in range(l//2):
        if(ss[i] != 'a'):
            print('yes')
            print(ss[i:l-i-1] + 'a' + ss[l-i-1:])
            break
        if(ss[l-i-1] != 'a'):
            print('yes')
            print(ss[:i]+'a' + ss[i:])
            break
    else:
        print("no")
