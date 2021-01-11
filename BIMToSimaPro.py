# -*- coding: utf-8 -*-
"""
Created on Fri Jan  8 10:12:29 2021

@author: xu
"""

import re
import pandas as pd
import tkinter
from tkinter.tix import Tk, Control, ComboBox
from tkinter.messagebox import showinfo, showwarning, showerror
from tkinter import filedialog
global filepath

root = Tk()
root.title("BIMToSimaPro")
root.geometry("300x450")
root.resizable(width=False, height=False)


def selectfile():
    global filepath
    selectfile = filedialog.askopenfilename(initialdir = "/",title = "Select file",filetypes = (("txt files","*.txt"),("all files","*.*")))
    filename = selectfile
    filepath = filename
    Name = tkinter.Label(root, text = filename)
    Name.pack()
    Name.place(x = 90, y = 100)
    return filename


B1 = tkinter.Button(root, text = "Select File", height = 2, width=15, command = selectfile)
B1.pack()

B1.place(x = 90, y = 40)



def ExportFlatInformation():
    global filepath
    import pdb 
    pdb.set_trace()
    
    f = open(filepath)
    char1 =[]
    char2 =[]
    zidian = {}
    for line2 in f:
        if "IFCRELASSIGNSTOGROUP" in line2:
            seg = re.findall(r'[(][#](.*?)[)]', line2)[0]
            seg1 = re.findall(r'[$][,](.*?)[)][;]', line2)[0]
            seg1 = seg1.split(',')
            seg1 = seg1[-1]
            seg = "#" + seg
            seg =seg.split(",")
            char1.extend(seg) 
            for i in range(len(seg)):
                zidian[seg[i]] = seg1
            char2.append(seg1)
        else:
          continue
    shuju = []
    shuju1 =[]
    shuju2= []
    zidian1 = {}

    f = open(filepath)
    for line2 in f:
        try:
            re.findall(r'[#](.*?)[=]', line2)[0]
        except:
          continue
        else:
          seg = re.findall(r'[#](.*?)[=]', line2)[0]
          seg = "#" + seg
          if seg in char2:
            want= re.findall(r'[:](.*?)[:]', line2)[0]
            zidian1[seg] = want

    f = open(filepath)
    for line2 in f:
        try:
            re.findall(r'[#](.*?)[=]', line2)[0]
        except:
          continue
        else:
          seg = re.findall(r'[#](.*?)[=]', line2)[0]
          seg = "#" + seg
          if seg in char1:
            if "Precast" in line2 :
              want= re.findall(r'[(](.*?)[)]', line2)[0]
              want =  re.findall(r'[:](.*?)[\']', want)[0]
              want = want.split(":")
              want = want[0]  
              shuju.append(want)
              shuju1.append(zidian1[zidian[seg]])
              an = zidian1[zidian[seg]]
              ind = an.find("Flat")
              shuju2.append(int (an[ind+4:] ))
            else:
             want= re.findall(r'[:](.*?)[:]', line2)[0]
             shuju.append(want) 
             shuju1.append(zidian1[zidian[seg]])
             an = zidian1[zidian[seg]]
             ind = an.find("Flat")
             shuju2.append(int (an[ind+4:] ))
          else:
            continue
    df = pd.DataFrame({"1": shuju, "2":shuju1, "3":shuju2},columns = ['1','2','3'])
    df.sort_values(by='3',inplace=True)
    df = pd.DataFrame({"1":df['1'], "2":df["2"]})
    df.to_excel("Export_FlatLevel.xlsx" )





B2 = tkinter.Button(root, text = "Component", height = 2, width = 15)
B2.pack()
B2.place(x = 90, y = 150)

B3 = tkinter.Button(root, text = "Assembly", height = 2, width = 15)
B3.pack()
B3.place(x = 90, y = 210)

B4 = tkinter.Button(root, text = "Flat", height = 2, width = 15, command = ExportFlatInformation)
B4.pack()
B4.place(x = 90, y = 270)

B5 = tkinter.Button(root, text = "Building", height = 2, width = 15)
B5.pack()
B5.place(x = 90, y = 330)


root.mainloop()