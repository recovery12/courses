#!/usr/bin/python3

from PIL import Image

def img_to_pixel(a_fname, s_fname):
    img_file = Image.open(a_fname)
    img = img_file.load()
    img_file1 = Image.open(s_fname)
    img1 = img_file1.load()
    
    (width, height) = img_file.size
    print("Maximum no. of chars that can be entered is: ",(3*width*height)/8)
    
    [xs, ys] = img_file.size
    
    fout1 = open("a_pixval.txt", "w")
    fout2 = open("s_pixval.txt", "w")
    for x in range(0, xs):
        for y in range(0, ys):
            [r, g, b] = img[x, y]
            [r1, g1, b1] = img1[x, y]
            string = " ".join([str(r), str(g), str(b), "\n"])
            string1 = " ".join([str(r1), str(g1), str(b1), "\n"])
            fout1.write(string)
            fout2.write(string1)
    fout1.close()
    fout2.close()

    return (width, height)


img_to_pixel("lena_color_256.tif", "stego.tif")
f1 = open("a_pixval.txt")
f2 = open("s_pixval.txt")

bits = ""
for p1, p2 in zip(f1, f2):
    if p1 != p2:
        t1 = list(map(int, p1.split()))
        t2 = list(map(int, p2.split()))
        b1 = list(map(bin, t1))
        b2 = list(map(bin, t2))
        for i in range(3):
            for j in range(2, len(b1[i])):
                if int(b1[i][j])^int(b2[i][j]) == 1:
                    if b1[i][j] == b1[i][-1]:
                        bits = bits + b2[i][j]
                    else:
                        bits = bits + b2[i][j:]
for j in range(0, len(bits), 7):
    print(chr(int(bits[j:j+7], 2)))

