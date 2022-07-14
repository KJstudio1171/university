def inputAdd():
	sum = 0
	while True :
		print("continue?")
		c = input()
		if c == "yes":
			n = input()
			sum += int(n)
		else :
			print(sum)
			break

inputAdd()


