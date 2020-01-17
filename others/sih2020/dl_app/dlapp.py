#!/usr/bin/python3

import tkinter as tk
from PIL import Image, ImageTk
from tkinter.ttk import Button, Frame
from tkinter.filedialog import askopenfile

# Global variables
global cvr

# Code for manipulating the main screen
root = tk.Tk()
root.title("Automated Land Classification using Deep learning.")
root.geometry('1200x1000')
root.config(bg = "#828481")
root.resizable(True, True)
root.update()

WIDTH = root.winfo_width()
HEIGHT = root.winfo_height()

leftFrame = Frame(root, width=WIDTH//2-40, height=HEIGHT//2, borderwidth=2)
leftFrame.pack(padx=10, pady=10, side='left')
leftFrame.place(x=10, y=100)

rightFrame = Frame(root, width=WIDTH//2-40, height=HEIGHT//2, borderwidth=2)
rightFrame.pack(padx=10, pady=10, side='right')
rightFrame.place(x=420, y=100)

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

        cvl = tk.Canvas(leftFrame, width = 350, height = 300)
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
        cvr = tk.Canvas(rightFrame, width = 350, height = 300)
        cvr.pack(side='top', fill='both', expand='yes')
        cvr.create_image(10, 10, image=photo, anchor='nw')
        tk.mainloop()

btn = Button(root, text='Upload', command= lambda:display_image())
btn.pack(side = tk.TOP, pady = 10)

btn = Button(root, text='Predict', command= lambda:predict_image())
btn.pack(side = tk.BOTTOM, pady = 10)

root.mainloop()