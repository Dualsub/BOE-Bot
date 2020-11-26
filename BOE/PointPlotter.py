import matplotlib.pyplot as plt
import sys

# Plottar resultatet av data-insamlingen av BOE-Boten.
def main():

    if(len(sys.argv) < 1):
        print("Not enough arguments.")
        return

    inp_file = open(sys.argv[1])

    points = []
    maxDistance = 0.0

    for line in inp_file:
        if("D:" in line):
            maxDistance = float(line.split(":")[1])
        if("," in line):
            values = line.split(",")
            x = float(values[0])
            y = float(values[1])
            points.append([x,y])
    
    inp_file.close()

    for point in points:
        plt.plot(point[0],point[1], 'ro')


    plt.plot()
    plt.show()


if __name__ == "__main__":
    main()