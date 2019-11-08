t = int(input())

for i in range(t):
    typ = input()
    if typ in ['B', 'b']:
        print("BattleShip")
    elif typ in ['C', 'c']:
        print("Cruiser")
    elif typ in ['D', 'd']:
        print("Destroyer")
    elif typ in ['F', 'f']:
        print("Frigate")
