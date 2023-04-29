def Palindrome(strParam):

    arr = []
    for i in strParam:
        if i != " ":
            arr.append(i)
  # code goes here
    i = 0
    j = len(arr) - 1

    ok = 1
    while i<j:
        if arr[i] != arr[j]:
            ok = 0
            print(i, j)
            break

        i += 1
        j -= 1
        
    if ok:
        return True
    return False

# keep this function call here 
print(Palindrome("never odd or even"))
