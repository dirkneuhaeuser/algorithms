def allPossiblePartitions(l): # l is the list whose possible partitions have to be found


    # to get all possible partitions, we consider the binary values from 0 to 2**len(l))//2-1
    """
    {123}       --> 000 (0)
    {12} {3}    --> 001 (1)
    {1} {2} {3} --> 010 (2)
    {1} {23}    --> 011 (3)  --> (0 to (2**3//2)-1)

    iterate over each possible partitions, 
    if there are partitions>=days and
    if that particular partition contains
    more than one element then take max of all elements under that partition
    ex: if the partition is {1} {23} then we take 1+3
    """
    for i in range(0,(2**len(l))//2):
            s = bin(i).replace('0b',"")
            s = '0'*(len(l)-len(s)) + s
            sublist = []
            prev = s[0]
            partitions = []
            k = 0
            for i in s:
                if (i == prev):
                    partitions.append(l[k])
                    k+=1
                else:
                    sublist.append(partitions)
                    partitions = [l[k]]
                    k+=1
                    prev = i
            sublist.append(partitions)
            print(sublist)



allPossiblePartitions([1,2,3,4,5,6,7,8,9,10,11,12,13,14])

