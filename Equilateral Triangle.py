def can_form_equilateral_triangle(length):
  if length % 3 == 0:
    print(f'Yes, you can make a equilateral triangle of side {length//3}.')
  else:
    print(f"No, You can't make a equilateral triangle.")
