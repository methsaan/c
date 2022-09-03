#! /usr/bin/python3

import time
import random

from tkinter import *
tk = Tk()
canvas = Canvas(tk, width=1500, height=900, bg="#%02x%02x%02x" % (0, 100, 160))
canvas.pack()

class timeBlockBar:
    def __init__(self, arg, arg2):
        self.arg = arg
        self.arg2 = arg2
    def callBack(self, event):
        canvas.itemconfig(performText, text=self.arg, fill=self.arg2)
        tk.update()
    def getText(self):
        temp = self.arg.replace(" ", "")
        temp = temp.replace("\n", "")
        return temp
    def getColor(self):
        return self.arg2

class timeBlock:
    def __init__(self, mon1, date1, year1, hr1, min1, mon2, date2, year2, hr2, min2, activity):
        self.startMonth = mon1
        self.startDate = date1
        self.startYear = year1
        self.startHr = hr1
        self.startMin = min1
        self.endMonth = mon2
        self.endDate = date2
        self.endYear = year2
        self.endHr = hr2
        self.endMin = min2
        self.activity = activity
    def __minutesFromZero(self, mon, date, year, hr, minutes):
        daysInMons = [31, (29 if year % 4 == 0 else 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        daysInMon = sum(daysInMons[:mon-1]) if mon != 0 else 0
        return minutes + hr*60 + (date-1)*1440 + daysInMon*1440 + (year*527040 if year % 4 == 0 else year*525600)
    def length(self):
        return self.__minutesFromZero(self.endMonth, self.endDate, self.endYear, self.endHr, self.endMin)-self.__minutesFromZero(self.startMonth, self.startDate, self.startYear, self.startHr, self.startMin)
    def getActivity(self):
        return self.activity
    def getStartDate(self):
        return "%02d/%02d/%d %02d:%02d" % (self.startMonth, self.startDate, self.startYear, self.startHr, self.startMin)
    def getEndDate(self):
        return "%02d/%02d/%d %02d:%02d" % (self.endMonth, self.endDate, self.endYear, self.endHr, self.endMin)

def varieties(l):
    cnt = 0
    unique = []
    for x in l:
        if x not in unique:
            unique.append(x)
            cnt += 1
    return cnt

schedTrackReader = open("schedTracker", "r")

lines = schedTrackReader.readlines()

timeBlocks = []

for x in range(len(lines)-1):
    temp = lines[x].split()
    temp2 = lines[x+1].split()
    months = ["Jan.", "Feb.", "Mar.", "Apr.", "May.", "Jun.", "Jul.", "Aug.", "Sep.", "Oct.", "Nov.", "Dec."]
    timeBlocks.append(timeBlock(months.index(temp[0])+1, int(temp[1]), int(temp[2]), int(temp[3].split(":")[0]), int(temp[3].split(":")[1]), months.index(temp[5])+1, int(temp[6]), int(temp[7]), int(temp[8].split(":")[0]), int(temp[8].split(":")[1]), float(temp[9])))
    timeBlocks.append(timeBlock(months.index(temp[5])+1, int(temp[6]), int(temp[7]), int(temp[8].split(":")[0]), int(temp[8].split(":")[1]), months.index(temp2[0])+1, int(temp2[1]), int(temp2[2]), int(temp2[3].split(":")[0]), int(temp2[3].split(":")[1]), None))
    if x == len(lines)-2:
        timeBlocks.append(timeBlock(months.index(temp2[0])+1, int(temp2[1]), int(temp2[2]), int(temp2[3].split(":")[0]), int(temp2[3].split(":")[1]), months.index(temp2[5])+1, int(temp2[6]), int(temp2[7]), int(temp2[8].split(":")[0]), int(temp2[8].split(":")[1]), float(temp2[9])))

firstLineData = lines[0].split()
lastLineData = lines[len(lines)-1].split()
months = ["Jan.", "Feb.", "Mar.", "Apr.", "May.", "Jun.", "Jul.", "Aug.", "Sep.", "Oct.", "Nov.", "Dec."]
totalLengthMin = timeBlock(months.index(firstLineData[0])+1, int(firstLineData[1]), int(firstLineData[2]), int(firstLineData[3].split(":")[0]), int(firstLineData[3].split(":")[1]), months.index(lastLineData[5])+1, int(lastLineData[6]), int(lastLineData[7]), int(lastLineData[8].split(":")[0]), int(temp[8].split(":")[1]), None).length()

unit = 1300/totalLengthMin

barLen = 0

performText = canvas.create_text(200, 230, text="Click area to see schedule performance", font=("helvetica", 12, "bold"))

for x in range(len(timeBlocks)):
    dateRange = timeBlocks[x].getStartDate() + " - " + timeBlocks[x].getEndDate()
    activity = timeBlockBar((str(timeBlocks[x].getActivity()/3)[:4]+"%" if timeBlocks[x].getActivity() != None else "No Activity") + "\n" + dateRange, (("#%02x%02x%02x" % (255, int(timeBlocks[x].getActivity()*85), 0)) if timeBlocks[x].getActivity() != None else "gray"))
    r = canvas.create_rectangle(barLen+100, 100, barLen+100+unit*timeBlocks[x].length(), 200, fill=activity.getColor(), tags=" ".join(activity.getText().split()))
    canvas.tag_bind(" ".join(activity.getText().split()), "<Button-1>", activity.callBack)
    tk.update()
    if timeBlocks[x].getActivity() != None:
        if unit*timeBlocks[x].length() > 50:
            canvas.create_text(barLen+100+(unit*timeBlocks[x].length())/2, 150, text=str(timeBlocks[x].getActivity()/3)[:4]+"%", font=("courier", 12))
    barLen += unit*timeBlocks[x].length()
tk.update()

reqTrackReader = open("reqTracker", "r")

lines = reqTrackReader.readlines()
temp = None
tempReqTrackArr = []

for x in range(len(lines)):
    if x%3 == 1:
        temp = lines[x]
    elif x%3 == 2:
        tempReqTrackArr.append([temp, lines[x]])
        temp = None

requirements = []
reqTrackArr = []

for x in range(len(tempReqTrackArr)):
    if tempReqTrackArr[x][0] != temp:
        reqTrackArr.append([tempReqTrackArr[x][0], [tempReqTrackArr[x][1]]])
        temp = tempReqTrackArr[x][0]
    else:
        reqTrackArr[-1][1].append(tempReqTrackArr[x][1])

for x in range(len(reqTrackArr)):
    reqTrackArr[x][0] = reqTrackArr[x][0].split()
    reqTrackArr[x][0][0] = months.index(reqTrackArr[x][0][0])+1
    reqTrackArr[x][0][1] = int(reqTrackArr[x][0][1])
    reqTrackArr[x][0][2] = int(reqTrackArr[x][0][2])

for x in range(len(reqTrackArr)+2):
    if reqTrackArr[x][1] != None:
        dayDist = timeBlock(int(reqTrackArr[x][0][0]), reqTrackArr[x][0][1], reqTrackArr[x][0][2], 0, 0, int(reqTrackArr[x+1][0][0]), reqTrackArr[x+1][0][1], reqTrackArr[x+1][0][2], 0, 0, None)
        if dayDist.length()/1440 == 1:
            continue
        else:
            reqTrackArr.insert(x+1, [dayDist.length()/1440, None])
    else:
        continue

allReq = []

for x in range(len(reqTrackArr)):
    if reqTrackArr[x][1] != None:
        allReq.extend(reqTrackArr[x][1])

boxHeight = (400-varieties(allReq)*10)/varieties(allReq)
boxWidth = (1100-len(reqTrackArr)*10)/len(reqTrackArr)

canvas.create_line(300, 300, 300, 700, width=2)
canvas.create_line(300, 700, 1400, 700, width=2)

reqUnique = []
for x in allReq:
    if x not in reqUnique:
        reqUnique.append(x)

colors = ["red", "orange", "green", "aqua", "light green", "turquoise", "pink", "purple", "brown", "gray", "dark orange", "maroon", "yellow", "light yellow", "navy"]
random.shuffle(colors)
colors = colors[:varieties(allReq)]

for x in range(len(reqTrackArr)):
    if reqTrackArr[x][1] != None:
        for y in range(len(reqTrackArr[x][1])):
            canvas.create_rectangle(310+x*boxWidth+x*10, 700-(y+1)*boxHeight-(y+1)*10, 310+(x+1)*boxWidth+x*10, 700-y*boxHeight-(y+1)*10, fill=colors[reqUnique.index(reqTrackArr[x][1][y])])
            canvas.create_text(310+(x+0.5)*boxWidth+x*10, 700-(y+0.5)*boxHeight-y*10, text=reqTrackArr[x][1][y], font=("helvetica", 10, "bold"))
        canvas.create_text(310+(x+0.5)*boxWidth+x*10, 745, text=("%02d-%02d-%04d" % (reqTrackArr[x][0][0], reqTrackArr[x][0][1], reqTrackArr[x][0][2])), font=("helvetica", 8, "bold"), angle=90)
    else:
        canvas.create_text(310+(x+0.5)*boxWidth+x*10, 730, text=str(int(reqTrackArr[x][0]))+"d", font=("helvetica", 8, "bold"))
        canvas.create_line(310+x*boxWidth+x*10, 715, 310+(x+1)*boxWidth+x*10, 715, width=2)
        canvas.create_polygon(300+x*boxWidth+x*10, 715, 310+x*boxWidth+x*10, 710, 310+x*boxWidth+x*10, 720)
        canvas.create_polygon(320+(x+1)*boxWidth+x*10, 715, 310+(x+1)*boxWidth+x*10, 710, 310+(x+1)*boxWidth+x*10, 720)

for x in range(len(reqUnique)):
    canvas.create_oval(85, 385+(x*40), 115, 415+(x*40), fill=colors[x])
    canvas.create_text(160, 415+(x*40), text="= "+reqUnique[x], font=("helvetica", 20))

canvas.mainloop()
