import turtle
ninja=turtle.Turtle()
ninja.shape("turtle")
ninja.color("red")
kenar=int(input("Kenar:"))
for i in range(4):
  ninja.forward(kenar)
  ninja.right(90)
for i in range(3):
  ninja.forward(kenar)
  ninja.left(120)