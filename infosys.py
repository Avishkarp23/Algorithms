n=int(input())
k=int(input())
q=int(input())
inp=[]
arr=[]
for i in range(q):
    inp1 = list(map(int, input().split()))
    inp.append(inp1)
for i in range(n):
    if i!=k:
        arr.append(0)
    else:
        arr.append(1)
def query1(i,inp):
    k1=inp.index(1)
    if i<k1:
        if k1-i>i:
            del inp[i:k1]
        else:
            del inp[0:i+1]
    else:
        if i-k1>len(inp)-i:
            del inp[k1+1:i+1]
        else:
            del inp[i:]

def query2(l2,inp):
    inp.insert(l2,0)


for i in range(q):
    if(inp[i][0]==0):
        query1(inp[i][1],arr)

    else:
        query2(inp[i][1],arr)


print(arr.index(1))

