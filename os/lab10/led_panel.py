#!/usr/bin/python3

import tkinter as tk
import numpy as np
import time

exitf = False                   # Global variable to tell that IF is dead!
top = 0
def push_left(panel, px) :
    global exitf
    
    if not exitf :
        p = list(panel.find_withtag(px))
        for pbox in p :
            pbcoor = panel.coords(pbox)
            if pbcoor[0] >= 0 :
                pbcoor[0] -= 8
                pbcoor[2] -= 8
            panel.coords(pbox, pbcoor)
    return

def on_off() :
    global top
    global exitf
    
    w = top.nametowidget('fr.bon')
    p = top.nametowidget('fr.display')
    if w.cget('text') == 'OFF' :
        w.configure(text='ON')
        exitf = False
        clear_display(p)
        active_device(p)
    else :
        w.configure(text='OFF')
        clear_display(p)
        quit_app()
        
def clear_display(w) :
    p = list(w.find_withtag('px_ON'))
    for pbox in p :
        w.itemconfig(pbox, fill='#000000', outline='#606060')
    return

def quit_app() :
    global exitf
    exitf = True
    
alphabet_code = {'A': list([60, 10, 9, 10, 60]),
                 'B': list([63, 37, 37, 37, 26]),
                 'C': list([30, 33, 33, 33]),
                 'D': list([63, 33, 33, 33, 30]),
                 'E': list([63, 37, 37, 37, 33]),
                 'F': list([63, 5, 5, 5, 1]),
                 'G': list([30, 33, 37, 37, 28]),
                 'H': list([63, 4, 4, 4, 63]),
                 'I': list([33, 63, 33]),
                 'J': list([25, 33, 33, 33, 63]),
                 'K': list([63, 4, 10, 17, 32]),
                 'L': list([63, 32, 32, 32]),
                 'M': list([63, 2, 12, 2, 63]),
                 'N': list([63, 6, 12, 24, 63]),
                 'O': list([30, 33, 33, 33, 30]),
                 'P': list([63, 9, 9, 9, 6]),
                 'Q': list([14, 17, 21, 25, 46]),
                 'R': list([63, 5, 13, 21, 34]),
                 'S': list([18, 37, 37, 37, 24]),
                 'T': list([1, 1, 63, 1, 1]),
                 'U': list([31, 32, 32, 32, 31]),
                 'V': list([7, 24, 32, 24, 7]),
                 'W': list([63, 16, 12, 16, 63]),
                 'X': list([33, 18, 12, 18, 33]),
                 'Y': list([3, 4, 56, 4, 3]),
                 'Z': list([49, 41, 37, 37, 35]),
                 '.': list([32]),
                 ',': list([32, 24]),
                 '?': list([45, 5, 5, 2]),
                 '!': list([47]),
                 ':': list([20]),
                 '-': list([8, 8, 8]),
                 "'": list([4, 3]),
                 '0': list([30, 33, 37, 41, 30]),
                 '1': list([36, 34, 63, 32, 32]),
                 '2': list([50, 41, 37, 37, 34]),
                 '3': list([18, 33, 37, 37, 26]),
                 '4': list([8, 12, 10, 63, 8]),
                 '5': list([39, 37, 37, 25]),
                 '6': list([30, 37, 37, 24]),
                 '7': list([49, 9, 5, 3]),
                 '8': list([26, 37, 37, 37, 26]),
                 '9': list([6, 41, 41, 30]),
                 ' ': list([0, 0, 0]),
                 '$': list([0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0])}

def init_led_panel_if() :
    global exitf
    global top
    
    exitf = False
    top = tk.Tk()
    bfr = tk.Frame(top, name='fr')
    onb = tk.Button(bfr, text='OFF', command=on_off, bg="#ffffb0",
                    width=5, name='bon')
    onb.pack(side=tk.LEFT)
    panel = tk.Canvas(bfr, height=60, width=960,
                      name='display', relief=tk.SUNKEN)
    panel.pack(fill=tk.BOTH)
    bfr.pack()
    for i in range(6) :
        for j in range(120) :
            x_st = 8 * j
            y_st = 10 * i
            panel.create_rectangle(x_st, y_st, x_st + 8, y_st + 10, 
                                   fill='black', outline='#606060')

    return

def active_device(w) :
    global exitf
    global top
    
    try:
        with open('/dev/panel', 'r', encoding='latin1',
                  errors='ignore') as rfp :
            aby = rfp.readline()
            rfp.close()
    except IOError as e:
        print('Device error - you may not have the correct device driver!')
        print('You may have to insmod led_panel_driver.ko')
        top.destroy()
        return
    
    msg = aby[:-1]
    bby = list()
    for ab in msg :
        bby.append(alphabet_code[ab.upper()])
        bby.append(list([0]))
    for tt in range(8) :
        bby.append(alphabet_code['$'])
    num = 0
    while not exitf :
        subnum = 0
        while subnum < len(bby[num%len(bby)]) :
            by = bby[num%len(bby)][subnum]
#            print(by)
            for bn in range(6) :
                if by % 2 == 1 :
                    w.create_rectangle(952, 10 * bn, 
                                       960, 10 * (bn + 1),
                                       fill='lime', tags='px_ON')
                by = by >> 1
            subnum += 1
            w.update()
            push_left(w, 'px_ON')
            time.sleep(0.15)
        # End while
        num += 1

if __name__ == '__main__' :
    init_led_panel_if()
    top.mainloop()
    
