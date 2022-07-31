m=int(input("capacity:"))
n=int(input("Enter the no of objects:"))
profit=[]
weight=[]
knapsack=[]
for i in range(n):
    weight.append(int(input("Enter the weight of object " + str(i+1)+":")))
    profit.append(int(input("Enter the profit of object " + str(i + 1)+":")))
    knapsack.append(0)
res = [i / j for i, j in zip(profit,weight)]

dicti=dict(enumerate(res))

ressorted=sorted(res,reverse=True)
totalweight=0
totalprofit=0
rcap=m

for i in range(n):
    a=list(dicti.keys())[list(dicti.values()).index(ressorted[i])]
    if(knapsack[a]!=0):
        dicti[a]=-1
        a = list(dicti.keys())[list(dicti.values()).index(ressorted[i])]



    if rcap>0:

            if rcap>=weight[a]:
                knapsack[a]=1
                totalweight=totalweight+weight[a]
                totalprofit=totalprofit+profit[a]
                rcap = rcap - weight[a]
            else:
                knapsack[a]=rcap/weight[a]
                totalweight=totalweight+(rcap/weight[a])*weight[a]

                totalprofit=totalprofit+(profit[a]*(rcap/weight[a]))
                rcap = rcap -((rcap/weight[a])*(weight[a]))
    else:
        break
print(knapsack)
print(totalprofit)
print(totalweight)