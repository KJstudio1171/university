def inputEval():
	result = None
	while True :
		print("input:", end= ' ')
		n = input()
		if n == "done":
			return result
		else :
			result = eval(n)
			print(eval(n))

print(inputEval())