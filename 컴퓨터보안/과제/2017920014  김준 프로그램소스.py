###2017920014 컴퓨터과학부 김준 컴퓨터 보안 DES 프로그램 

ip = [58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,62,54,46,
38,30,22,14,6,64,56,48,40,32,24,16,8,57,49,41,33,25,17,9,1,59,
51,43,35,27,19,11,3,61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7]

ip_inverse = [40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,38,
6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,36,4,44,12,52,20,60,28,
35,3,43,11,51,19,59,27,34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25]

expansion_permutation = [32,1,2,3,4,5,4,5,6,7,8,9,8,9,10,11,12,13,12,13,14,15,16,17,16,17,
18,19,20,21,20,21,22,23,24,25,24,25,26,27,28,29,28,29,30,31,32,1]

s_box = [[[14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7],
          [0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8],
          [4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0],
          [15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13]],
          [[15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10],
          [3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5],
          [0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15],
          [13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9]],
          [[10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8],
          [13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1],
          [13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7],
          [1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12]],
          [[7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15],
          [13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9],
          [10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4],
          [3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14]],
          [[2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9],
          [14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6],
          [4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14],
          [11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3]],
          [[12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11],
          [10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8],
          [9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6],
          [4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13]],
          [[4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1],
          [13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6],
          [1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2],
          [6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12]],
          [[13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7],
          [1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2],
          [7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8],
          [2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11]]]

p_box=[16,7,20,21,29,12,28,17,1,15,23,26,5,18,31,10,2,8,24,14,32,27,3,9,19,13,30,6,22,11,4,25]

key_permutation = [57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,
19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,
21,13,5,28,20,12,4]

key_shift = [1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1]

key_compression = [14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,
52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32]



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

    def __init__(self,key_list,key_permutation,key_shift,key_compression,key_round):
        self.key_result = []
        self.key_list = []
        self.key_permutation = key_permutation
        self.key_shift = key_shift
        self.key_compression = key_compression
        self.key_round = key_round
        for i in range(len(key_permutation)):
            self.key_list.insert(i,key_list[key_permutation[i]-1])
    

    def Shift(self,key_list,shift_round):
        shift_list = []
        for i in range(len(key_list)):
            if((i+self.key_shift[shift_round-1])<len(key_list)):
                shift_list.append(key_list[i+self.key_shift[shift_round-1]])
        for i in range(self.key_shift[shift_round-1]):
            shift_list.append(key_list[i])
        return shift_list
    
    def Compression(self,key_list):
        compression_list = []
        for i in range(len(self.key_compression)):
            compression_list.append(key_list[self.key_compression[i]-1])
        return compression_list
    
    def Key_Gen(self):
        left_list = self.key_list[:len(self.key_list)//2]
        right_list = self.key_list[len(self.key_list)//2:]
        for i in range(self.key_round):
            left_list = self.Shift(left_list,i+1)
            right_list = self.Shift(right_list,i+1)
            self.key_result.append(self.Compression(left_list+right_list))
        return self.key_result

class DES:

    def __init__(self,plain_list,key_list,ip,ip_inverse,expansion_permutation,s_box,p_box,DES_round):
        self.key_list=key_list
        self.ip = ip
        self.ip_inverse = ip_inverse
        self.expansion_permutation = expansion_permutation
        self.s_box = s_box
        self.p_box = p_box
        self.DES_round = DES_round
        self.plain_list = [0 for i in range(len(ip))]
        for i in range(len(self.ip)):
            self.plain_list[i] = plain_list[self.ip[i]-1]
                
    def Expansion(self,plain_list):
        expansion_list = []
        for i in range(len(self.expansion_permutation)):
            expansion_list.append(plain_list[self.expansion_permutation[i]-1])
        return expansion_list

    def Key_XOR(self,plain_list,key_list):
        xor_list = []
        if(len(plain_list)!=len(key_list)):
            print('error')
            return
        for i in range(len(plain_list)):
            xor_list.append(str(int(plain_list[i])^int(key_list[i])))
        return xor_list

    def Plain_XOR(self,left_list,right_list):
        xor_list = []
        if(len(left_list)!=len(right_list)):
            print('error')
            return
        for i in range(len(left_list)):
            xor_list.append(str(int(left_list[i])^int(right_list[i])))
        return xor_list

    def Substition(self,plain_list):
        substition_list = []
        for i in range(len(self.s_box)):
            num = self.s_box[i][int('0b'+plain_list[i*6]+plain_list[i*6+5],2)][int('0b'+plain_list[i*6+1]+plain_list[i*6+2]+plain_list[i*6+3]+plain_list[i*6+4],2)]
            num_str = str(format(num,'b'))
            for j in range(4-len(num_str)):
                substition_list.append('0')
            for k in range(len(num_str)):
                substition_list.append(num_str[k])
        return substition_list

    def permutation(self,plain_list):
        permutation_list = []
        for i in range(len(self.p_box)):
            permutation_list.append(plain_list[self.p_box[i]-1])
        return permutation_list
    
    def Result(self):
        result_list = [0 for i in range(len(self.ip_inverse))]

        left_list = self.plain_list[:len(self.plain_list)//2]
        right_list = self.plain_list[len(self.plain_list)//2:]
        k = []
        obj = Key_Round(self.key_list,key_permutation,key_shift,key_compression,self.DES_round)
        key_round = obj.Key_Gen()

        for i in range(self.DES_round):
            str_list = self.Expansion(right_list)
            str_list = self.Key_XOR(str_list,key_round[i])
            #print(hex(int('0b'+''.join(key_round[i]),2)))
            str_list = self.permutation(self.Substition(str_list))
            left_list, right_list = right_list, self.Plain_XOR(left_list,str_list)
             

        for i in range(len(self.ip_inverse)):
            result_list[i] = (right_list+left_list)[self.ip_inverse[i]-1]
        
        return ''.join(result_list)

plain_text='0123456789ABCDEF'
key_text ='85E813540F0AB405'
obj = DES(TextToHexList(plain_text),TextToHexList(key_text),ip,ip_inverse,expansion_permutation,s_box,p_box,16)

print("CYPER TEXT:")
print(obj.Result())
print(str(format(int('0b'+obj.Result(),2),'x')).upper())