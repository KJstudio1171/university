def is_triangle(a, b, c):
	if a <= 0 or b <= 0 or c <= 0 :
		print("No")
		return
	max_side= max(a, b, c)
	if max_side <= a + b + c - max_side :
		print("Yes")
	else :
		print("No")

def user_input_is_triangle() :
	a = int(input())
	b = int(input())
	c = int(input())
	is_triangle(a, b, c)

user_input_is_triangle()