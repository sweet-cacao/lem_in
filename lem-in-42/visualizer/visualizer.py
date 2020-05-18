import PIL.Image, PIL.ImageTk
import math
from tkinter import *
import os
import sys
import time
from numpy import mod
from tkinter import colorchooser
from tkinter import messagebox  

comments = []
st = 0
ed = 0
obj = []
row = []



f = sys.stdin

try:
    ants = int(input())
except Exception:
    print("Wrong number of ants.\n")
    print("Usage: run without arguments and give in stdin valid output of lem-in.")
    exit(1)

class Ant(object):
    def __init__(self, name, rooms, cur_room, num_room, pack):
        self.name = name
        self.rooms = rooms #массив Node
        self.cur_room = cur_room #Node start
        self.num_room = num_room
        self.pack = pack
    def next_room(self):
        self.num_room += 1
        if (len(self.rooms) > self.num_room):
            self.cur_room = self.rooms[self.num_room]
            return 1
        return 0

def return_obj(line,obj):
    for i in range(len(obj)):
        if (obj[i].name == line):
            return obj[i]
    return 0

def return_coord(links, obj):
    for i in range(len(obj)):
        if (obj[i].name.rstrip() == links.rstrip()):
            return obj[i].x, obj[i].y
    return 0, 0

def define_size(obj):
    max1 = obj[0].x
    max2 = obj[0].y
    for i in range(len(obj)):
        k = obj[i].x
        t = obj[i].y
        if (k > max1):
            max1 = k
        if (t > max2):
            max2 = t
    multiple1 = int(1470 / max1)
    if (multiple1 == 0):
        multiple1 = 1470 / max1
    multiple2 = int(830 / max2)
    if (multiple2 == 0):
        multiple2 = 870 / max2
    multiple = multiple1 if (multiple1 < multiple2) else multiple2
    print("multiple = ", multiple)
    size_r = 10
    size_l = 5
    return multiple, size_r, size_l

class Node(object):
    def __init__(self, name, x, y, links):
        self.name = name
        self.x = x
        self.y = y
        self.links = links
    
    def print_obj(self):
        print(self.name, str(self.x), str(self.y), str(self.links))

try:
    for stroka in f:
        if (len(stroka) == 1):
            break
        if (stroka[0] == "#" and stroka[1] == "#" and (stroka.rstrip() == "##start")):
            st = 1
        elif (stroka[0] == "#" and stroka[1] == "#" and (stroka.rstrip() == "##end")):
            ed = 1
        elif (stroka[0] == "#"):
            comments.append(stroka)
        else:
            row = stroka.split()
            if (len(row) > 2):
                # print("here")
                new = Node(row[0], int(row[1])+1, int(row[2])+1, [])
                obj.append(new)
                if (st == 1):
                    start = Node(row[0], int(row[1])+1, int(row[2])+1, [])
                    st = 0
                if (ed == 1):
                    end = Node(row[0], int(row[1])+1, int(row[2])+1, [])
                    ed = 0
            else:
                row2 = stroka.split('-')
                for i in range(len(obj)):
                    if (obj[i].name == str(row2[0])):
                        obj[i].links.append(str(row2[1]))
except Exception:
    print("Wrong map.")
    print("Usage: run without arguments and give in stdin valid output of lem-in.")
    exit(1)
        
height = 900
width = 1500
def_color = "#02011c"
try:
    root = Tk()
    root.title("LEM-IN")
    canvas = Canvas(root, width=width, height=height, bg=def_color, bd=0, highlightthickness=0)
    canvas.pack()
except Exception:
    print("Unable to create window.")
    print("Usage: run without arguments and give in stdin valid output of lem-in.")
    exit(1)

diapason = 0
x2 = 0
y2 = 0

try:
    multiple, size_r, size_l = define_size(obj)
except Exception:
    print("Unable to calculate multiple.")
    print("Usage: run without arguments and give in stdin valid output of lem-in.")
    exit(1)

# отрисовка графа
try:
    for i in range(len(obj)):
        x = obj[i].x*multiple
        y = obj[i].y*multiple
        for j in range(len(obj[i].links)):
            x2, y2 = return_coord(obj[i].links[j], obj)
            x2 *= multiple
            y2 *= multiple
            canvas.create_line(x, y, x2, y2, width = size_l, fill='#db14e7')

    for i in range(len(obj)):
        x = obj[i].x*multiple
        y = obj[i].y*multiple
        canvas.create_oval(x-size_r, y-size_r, x+size_r, y+size_r, fill='aqua')

    canvas.create_oval(start.x*multiple-size_r, start.y*multiple-size_r, start.x*multiple+size_r, start.y*multiple+size_r, fill='green')
    canvas.create_oval(end.x*multiple-size_r, end.y*multiple-size_r, end.x*multiple+size_r, end.y*multiple+size_r, fill='red')

    img = PIL.Image.open('./imges/yellow_monster.png')
    maxsize = (20, 20)
    img.thumbnail(maxsize, PIL.Image.ANTIALIAS) 
    red_pack = PIL.ImageTk.PhotoImage(img)
except Exception:
    print("Unable to draw graph.")
    print("Usage: run without arguments and give in stdin valid output of lem-in.")
    exit(1)

schet = 0
# считывание результата
def read_result(ants, obj, red_pack):
    ants_buff = []
    rows = [] #двумерный массив с вводом
    nums = []
    for i in range(ants):
        ants_buff.append(Ant(i+1, [], start, 0,canvas.create_image(start.x*multiple , start.y*multiple, anchor=CENTER, image=red_pack)))
        ants_buff[i].rooms.append(start)
    for stroka in f:
        row = stroka.split()
        nums = []
        for i in range(len(row)):
            tmp = row[i].split('-')
            num = int(tmp[0][1:])-1
            nums.append(num)
            ants_buff[num].rooms.append(return_obj(tmp[1], obj))
        rows.append(nums)
    return ants_buff, rows

def count_step(packman, node_next, node_now):
    coordinates = canvas.coords(packman)
    x1 = coordinates[0]
    y1 = coordinates[1]
    x2 = node_next.x*multiple
    y2 = node_next.y*multiple
    x_z = x2 - x1
    y_z = y2 - y1
    if (x_z == 0) :
        if (y_z < 0):
            return 0, -1
        else:
            return 0, 1
    if (y_z == 0) :
        if (x_z < 0):
            return -1, 0
        else:
            return 1, 0
    if (abs(x_z) > abs(y_z)):
        if (x_z < 0):
            step_x = -1
        else:
            step_x = 1
        if (y_z < 0):
            step_y = abs((y_z/x_z))*-1
        else:
            step_y = abs((y_z/x_z))
    else:
        if (y_z < 0):
            step_y = -1
        else:
            step_y = 1
        if (x_z < 0):
            step_x = abs((x_z/y_z))*-1
        else:
            step_x = abs((x_z/y_z))
    return step_x, step_y

def move_pack(packman, node_next, node_now):
    step_x, step_y = count_step(packman, node_next, node_now)
    canvas.move(packman, step_x, step_y)
    coordinates = canvas.coords(packman)
    x = coordinates[0]
    y = coordinates[1]
    x1 = node_now.x*multiple
    y1 = node_now.y*multiple
    x2 = node_next.x*multiple
    y2 = node_next.y*multiple
    if (x1 < x2):
        k1 = x2-x
    else:
        k1 = x-x2
    if (y1 < y2):
        k2 = y2-y
    else:
        k2 = y-y2
    if (k1 > 1 or k2 > 1):
         return 1
    else:
        return 0


def move_result(ants_buff, rows, iter,here, ants_l, ants_ch):#rows-номера муравьев в каждой строчке
        i = iter
        ants_l2 = ants
        counter = 0
        for j in range(len(rows[i])):
            i = iter
            kolvo = 0
            node_now = ants_buff[rows[i][j]].cur_room
            coordinates = canvas.coords(ants_buff[rows[i][j]].pack)
            x = coordinates[0]
            y = coordinates[1]
            x2 = node_now.x*multiple
            y2 = node_now.y*multiple
            if (ants_buff[rows[i][j]].num_room > 0 and ants_buff[rows[i][j]].num_room < len(ants_buff[rows[i][j]].rooms)):
                x1 = ants_buff[rows[i][j]].rooms[ants_buff[rows[i][j]].num_room-1].x*multiple
                y1 = ants_buff[rows[i][j]].rooms[ants_buff[rows[i][j]].num_room-1].y*multiple
            else:
                x1 = 0
                y1 = 0
            if (x1 < x2):
                k1 = x2-x
            else:
                k1 = x-x2
            if (y1 < y2):
                k2 = y2-y
            else:
                k2 = y-y2
            if (here < len(rows[i])):
                here+=1
                ants_buff[rows[i][j]].next_room()
            node_next = ants_buff[rows[i][j]].cur_room
            node_now = ants_buff[rows[i][j]].rooms[ants_buff[rows[i][j]].num_room-1]
            coordinates = canvas.coords(ants_buff[rows[i][j]].pack)
            x = coordinates[0]
            y = coordinates[1]
            x1 = node_now.x*multiple
            y1 = node_now.y*multiple
            x2 = node_next.x*multiple
            y2 = node_next.y*multiple
            if (x1 < x2):
                k1 = x2-x
            else:
                k1 = x-x2
            if (y1 < y2):
                k2 = y2-y
            else:
                k2 = y-y2
            if ((k1 > 1 or k2 > 1) or (node_now.x == start.x and node_now.y == start.y)):
                if (move_pack(ants_buff[rows[i][j]].pack, node_next, node_now) == 1):
                    counter +=1

        for p in range(len(ants_buff)):
            if (ants_buff[p].cur_room.x == end.x and
            ants_buff[p].cur_room.y == end.y):
                ants_l2-=1    
        if (ants_l2 != ants_ch):
            canvas.create_rectangle(1170, 30, 1250, 50, fill="purple")
            canvas.create_text(1200,40,text=ants_l2, font="Verdana 15",justify=CENTER,fill="aqua")

        if (counter == 0):
            iter+=1
            here = 0
        if (iter < len(rows)):
            root.after(5, move_result, ants_buff, rows, iter, here, ants, ants_l2)
        

# def keypress(event):
#         try:
#             if (iter ==0):
#                 move_result(ants_buff, rows, iter, here, ants, ants)
            
#         except Exception:
#             print("Ants can't move. Sorry:((")
#             print("Usage: run without arguments and give in stdin valid output of lem-in.")
#             exit(1)
ch = 0
def run_prog():
    try:
        if (ants_buff[0].cur_room.x == start.x
        and ants_buff[0].cur_room.y == start.y):
            move_result(ants_buff, rows, iter, here, ants, ants)
        else:
            messagebox.showinfo('Error', 'Your ants already run!^_^') 
    except Exception:
        print("Ants can't move. Sorry:((")
        print("Usage: run without arguments and give in stdin valid output of lem-in.")
        exit(1)

try:
    if (schet == 0):
        ants_buff, rows = read_result(ants, obj, red_pack)
        schet = 1
        iter = 0
        p = 0

except Exception:
    print("Unable to read result.")
    print("Usage: run without arguments and give in stdin valid output of lem-in.")
    exit(1)

here = 0

# filename = PIL.ImageTk.PhotoImage(file = "yel_2.png")
# background_label = Label(root, image=filename)
# background_label.place(x=0, y=0, relwidth=1, relheight=1)


def func_choose_color():
   a = colorchooser.askcolor()[1]
   canvas.configure(bg=a)

button1 = Button(font="Verdana 15", text = "Change background", command =  func_choose_color, anchor = W, highlightthickness=0)
button1.configure(width = 16, activebackground = "purple", 	
fg = "aqua", bg = "#210E37", bd = 0)
button1_window = canvas.create_window(220, 10, anchor=NW, window=button1)

button2 = Button(font="Verdana 15", text = "Run", command =  run_prog, anchor = CENTER, highlightthickness=0)
button2.configure(width = 16, activebackground = "purple", 	
fg = "aqua", bg = "#210E37", bd = 0)
button2_window = canvas.create_window(10, 10, anchor=NW, window=button2)


canvas.create_text(725,20,text="LEM-IN",
          font="Verdana 20 italic bold",justify=CENTER,fill="aqua")

canvas.create_text(1410,40,text=" - start",
          font="Verdana 15",justify=CENTER,fill="aqua")
canvas.create_oval(1350, 35, 1365, 50, fill='green')
canvas.create_oval(1350, 55, 1365, 70, fill='red')
canvas.create_text(1410,60,text=" - end ",
          font="Verdana 15",justify=CENTER,fill="aqua")

canvas.create_rectangle(1170, 30, 1235, 50, fill="purple")
canvas.create_text(1200,40,text=ants,
          font="Verdana 15",justify=CENTER,fill="aqua")
canvas.create_text(1050,40,text="Number of ants left: ",
          font="Verdana 15",justify=CENTER,fill="aqua")
try:
    icon = PIL.ImageTk.PhotoImage(file = './imges/yel_2.png')
    root.iconphoto(False, icon) 
except Exception:
    print("No icon image, src: ./imges/yel_2.png")
    exit (1)

# root.bind('<Key>',keypress)

root.mainloop()
