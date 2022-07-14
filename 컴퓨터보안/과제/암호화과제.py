ip = [58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,62,54,46,
38,30,22,14,6,64,56,48,40,32,24,16,8,57,49,41,33,25,17,9,1,59,
51,43,35,27,19,11,3,61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7]

ip_inverse = [40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,38,
6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,36,4,44,12,52,20,60,28,
35,3,43,11,51,19,59,27,34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25]

key_permutation = [57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,
19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,
21,13,5,28,20,12,4]

key_shift = [1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1]


def TextToHexList(text):
    hex_text = str(format(int(text,16),'b'))
    length = (len(text)*4-len(hex_text))
    str_list = []
    for i in range(length):
        str_list.append('0')
    for i in range(len(hex_text)):
        str_list.append(hex_text[i])
    return str_list

class Key_Round:

    def Init(key_list,key_permutation):
        init_list = []
        for i in range(len(key_permutation)):
            init_list.insert(key_permutation[i]-1,key_list[i])
        return init_list

    def Shift(key_list,key_shift,round):
        shift_list = []
        for i in range(len(key_list)):
            if((i+key_shift[round-1])<len(key_list)):
                shift_list.append(key_list[i+key_shift[round-1]])
        for i in range(key_shift[round-1]):
            shift_list.append(key_list[i])
        return shift_list
    
        






class DES:

    def Init(plain_list,ip):
        init_list = [0 for i in range(len(plain_list))]
        for i in range(len(ip)):
            init_list[ip[i]-1]=plain_list[i]
        return init_list


text='0123456789ABCDEF'
key ='AABB09182736CCDD'
a = TextToHexList(text)
print(Key_Round.Shift(a[:len(a)//2],key_shift,1))
print(Key_Round.Shift(a[len(a)//2:],key_shift,1))


