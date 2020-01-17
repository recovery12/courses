#!/usr/bin/python3

import tkinter as tk
from PIL import Image, ImageTk
from tkinter.ttk import Button, Frame
from tkinter.filedialog import askopenfile

# Code for manipulating the main screen
root = tk.Tk()
root.title("Automated Land Classification using Deep learning.")
root.geometry('1200x1000')
root.config(bg = "#828481")
root.resizable(True, True)
root.update()

WIDTH = root.winfo_width()
HEIGHT = root.winfo_height()

topFrame = Frame(root, width=WIDTH, height=40)
topFrame.pack(pady=10, side='top')

leftFrame = Frame(root, width=WIDTH//2-40, height=HEIGHT//2, borderwidth=2)
leftFrame.pack(padx=10, pady=10, side='left')

rightFrame = Frame(root, width=WIDTH//2-40, height=HEIGHT//2, borderwidth=2)
rightFrame.pack(padx=10, pady=10, side='right')

bottomFrame = Frame(root, width=WIDTH, height=40)
bottomFrame.pack(pady=10, side='bottom')

def upload_file():
    try:
        file = askopenfile(mode="r", filetypes=[('Image files', '*.png')])
        return file.name
    except:
        print("File not uploaded")
        return None

def display_image():
    file_name = upload_file()

    if file_name is not None:
        img = Image.open(file_name)
        global photo
        photo = ImageTk.PhotoImage(img)

        cvl = tk.Canvas(leftFrame, width= WIDTH//2-40, height= HEIGHT//2)
        cvl.pack(side='top', fill='both', expand='yes')
        cvl.create_image(10, 10, image=photo, anchor='nw')
        tk.mainloop()
    else:
        print("There is no image to display")

def predict_image():
    try:
        value = None or cvr
        del value
        print("Image is already present")
    except:
        cvr = tk.Canvas(rightFrame, width= WIDTH//2-40, height= HEIGHT//2)
        cvr.pack(side='top', fill='both', expand='yes')
        cvr.create_image(10, 10, image=photo, anchor='nw')
        tk.mainloop()

btn = Button(topFrame, text='Upload', command= lambda:display_image())
btn.pack(side = tk.TOP, pady = 10)

btn = Button(bottomFrame, text='Predict', command= lambda:predict_image())
btn.pack(side = tk.BOTTOM, pady = 10)

root.mainloop()