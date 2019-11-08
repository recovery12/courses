#!/usr/bin/python3

"""
    Installation Commands
    Windows:
        conda install -c conda-forge pypdf2
    Linux
        sudo pip3 install pypdf2
"""

import os
import sys
try:
    from PyPDF2 import PdfFileReader, PdfFileWriter
except:
    print("check the documentation for installation commands")
    sys.exit()

def extractpdfs(dirpath: str) -> list:
    files = list()

    for f in os.listdir(dirpath):
        if f.endswith(".pdf"):
            files.append(f)

    if len(files) == 0:
        print("There are no pdf's to merge")
        sys.exit()

    print(files, "which are merged together.")
    return files

def mergepdfs(dirpath:str, files: list, fname: str) -> None:
    pdfw = PdfFileWriter()

    os.chdir(dirpath)
    for f in files:
        pdfr = PdfFileReader(f)
        for page in range(pdfr.getNumPages()):
            pdfw.addPage(pdfr.getPage(page))

    fhw = open(fname, "wb")
    pdfw.write(fhw)

    fhw.close()
    return

if __name__  == '__main__':
    dirpath = input("Enter the path(relative): ")
    fname = input("Enter the name of the file(merged): ")

    fs = extractpdfs(dirpath)
    mergepdfs(dirpath, fs, fname)
