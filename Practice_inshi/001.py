import time


def euclidean_algorithm(m,n):
    if m % n == 0:
        return n
    else:
        return euclidean_algorithm(n,m%n)


def Binary_search(A,n):
    print(A)
    if len(A) == 0:
        return False
    if A[len(A)//2] == n:
        return True
    elif A[len(A)//2] < n:
        return Binary_search(A[len(A)//2 + 1:],n)
    else:
        return Binary_search(A[:len(A)//2],n)

def merge(array):
    mid = len(array)
    if mid > 1:
        left = merge(array[:(mid/2)])
        right = merge(array[(mid/2):])
        array = []
        while len(left) != 0 and len(right) != 0:
            if left[0] < right[0]:
                array.append(left.pop(0))
            else:
                array.append(right.pop(0))
        if len(left) != 0:
            array.extend(left)
        elif len(right) != 0:
            array.extend(right)
    return array

def find_max_array(A):

    def find_max_crossing_subarray(A,low,mid,high):

        left_sum = - float('inf')
        right_sum = - float('inf')
        max_left = low
        max_right = high

        for i in range(mid,-1,-1):
            temp_sum = sum(A[i:mid+1])
            if left_sum < temp_sum:
                left_sum = temp_sum
                max_left = i

        for i in range(mid+1,high+1):
            temp_sum = sum(A[mid+1:i+1])
            if right_sum < temp_sum:
                right_sum = temp_sum
                max_right = i

        return (max_left,max_right,left_sum + right_sum)

    def find_max_subarray(A,low,high):

        try:
            if low==high:
                return (low,high,A[low])
            else:
                mid = low + (high-low)//2
                left_low,left_high,left_sum = find_max_subarray(A,low,mid)
                right_low,right_hifh,right_sum = find_max_subarray(A,mid+1,high)
                cross_left,cross_right,cross_sum = find_max_crossing_subarray(A,low,mid,high)

                if left_sum > right_sum and left_sum > cross_sum:
                    return left_low,left_high,left_sum
                elif right_sum > left_sum and right_sum > cross_sum:
                    return right_low,right_hifh,right_sum
                else:
                    return cross_left,cross_right,cross_sum

        except:
            pass

    return find_max_subarray(A,0,len(A)-1)

def find_max_array_ex(A):
    max_sum = A[0]
    max_c = (0,0)

    c_temp = (0,0)
    sum_temp = A[0]

    for i in range(1,len(A)):

        if sum_temp > 0:
            sum_temp += A[i]
            c_temp = (c_temp[0],i)
        else:
            sum_temp = A[i]
            c_temp = (i,i)

        if sum_temp > max_sum:
            max_sum = sum_temp
            max_c = c_temp

    return (max_sum,max_c)

if __name__ == '__main__':
    # print(euclidean_algorithm(1633,355))
    # print(Binary_search([13,16,23,45,54,58,76,91],73))
    A = [13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7]
    A.extend([0]*10000)
    start = time.time()
    print(find_max_array_ex(A))
    print(time.time() -start)
