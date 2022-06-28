#! /usr/bin/python3

import math
import random

from datetime import timedelta, date

from tkinter import *
tk = Tk()
canvas = Canvas(tk, width=1000, height=800, bg="aqua")
canvas.pack()

def daterange(date1, date2):
    for n in range(int((date2-date1).days)+1):
        yield date1 + timedelta(n)

reqReader = open("reqTracker", "r")

lines = reqReader.readlines()
activities = []
tempDayActivities = []
tempDates = []
dates = []
addedFirst = False

tempReqMet = {"PA" : 0, "ST" : 0, "PP" : 0, "MT" : 0, "D" : 0, "BL" : 0}
activitiesPerDay = []
reqPerDay = []

for x in range(1, len(lines)):
    if lines[x][0] == '-':
        continue
    elif lines[x-1][0] == '-':
        tempDates.append(lines[x])
        if not addedFirst:
            dates.append(lines[x])
            addedFirst = True
        if tempDates[len(tempDates)-1] != tempDates[len(tempDates)-2]:
            activities.append(tempDayActivities)
            tempDayActivities = []
            dates.append(lines[x])
    else:
        tempDayActivities.append(lines[x])

activities.append(tempDayActivities)

for x in range(len(dates)):
    activitiesPerDay.append(dict(tempReqMet))

reqActivities = list(tempReqMet.keys())

for x in reqActivities:
    for y in range(len(dates)):
        activitiesPerDay[y][x] = activities[y].count(x+"\n")

canvas.create_line(100, 700, 700, 700, width=6)
canvas.create_line(100, 100, 100, 700, width=6)

horizontalDistPerPoint = 600/len(dates)
verticalDistPerPoint = 0
maxActPerDay = 0

for x in range(len(dates)):
    if max(activitiesPerDay[x].values()) > verticalDistPerPoint:
        verticalDistPerPoint = max(activitiesPerDay[x].values())
        maxActPerDay = max(activitiesPerDay[x].values())

verticalDistPerPoint = 600/verticalDistPerPoint

reqOccurences = dict(tempReqMet)
for x in range(len(reqActivities)):
    reqOccurences[reqActivities[x]] = [0]

for x in range(len(reqActivities)):
    for y in range(len(dates)):
        reqOccurences[reqActivities[x]].append(activitiesPerDay[y][reqActivities[x]])

reqWeeklyOccurences = dict(reqOccurences)
for x in range(len(reqActivities)):
    reqWeeklyOccurences[reqActivities[x]] = [0, 0]

for x in range(len(reqActivities)):
    cnt = 1
    cnt2 = 0
    for y in range(len(reqOccurences[reqActivities[x]])):
        reqWeeklyOccurences[reqActivities[x]][cnt] += reqOccurences[reqActivities[x]][y]
        cnt2 += 1
        if cnt2 == 7:
            cnt += 1
            cnt2 = 0
            reqWeeklyOccurences[reqActivities[x]].append(0)

horizontalDistPerPoint2 = 600/int(math.ceil(len(dates)/7))
verticalDistPerPoint2 = 0
maxActPerDay2 = 0

for x in range(len(reqActivities)):
    if max(reqWeeklyOccurences[reqActivities[x]]) > verticalDistPerPoint2:
        verticalDistPerPoint2 = max(reqWeeklyOccurences[reqActivities[x]])
        maxActPerDay2 = max(reqWeeklyOccurences[reqActivities[x]])

verticalDistPerPoint2 = 600/verticalDistPerPoint2

colors = ["red", "orange", "blue", "green", "white", "purple", "pink", "grey", "yellow", "violet", "dark blue", "light green", "dark grey"]
colors2 = ["red", "orange", "blue", "green", "white", "purple", "pink", "grey", "yellow", "violet", "dark blue", "light green", "dark grey"]
random.shuffle(colors)
random.shuffle(colors2)
colors = colors[:len(reqActivities)]

option = int(input("Enter data to display (weekly all (1), weekly individual (2), daily all (3), daily individual (4)): "))

if option == 1:
    for a in range(maxActPerDay2+1):
        canvas.create_text(85, 700-verticalDistPerPoint2*a, text=str(a), font=("tahoma", 14))
    for x in range(len(reqActivities)):
        canvas.create_text(850, 100+x*30, text="\u2588\u2588 = %s" % reqActivities[x], fill=colors[x], font=("tahoma", 15))
        for y in range(1, len(reqWeeklyOccurences[reqActivities[x]])-1):
            canvas.create_line(100+horizontalDistPerPoint2*(y-1), 700-verticalDistPerPoint2*reqWeeklyOccurences[reqActivities[x]][y-1], 100+horizontalDistPerPoint2*y, 700-verticalDistPerPoint2*reqWeeklyOccurences[reqActivities[x]][y], fill=colors[x], width=3)
            canvas.create_oval(96+horizontalDistPerPoint2*y, 696-verticalDistPerPoint2*reqWeeklyOccurences[reqActivities[x]][y], 104+horizontalDistPerPoint2*y, 704-verticalDistPerPoint2*reqWeeklyOccurences[reqActivities[x]][y], fill=colors[x], outline=colors[x])
elif option == 2:
    x = input("Enter requirement: ")
    cnt = 0
    for a in range(maxActPerDay2+1):
        canvas.create_text(85, 700-verticalDistPerPoint2*a, text=str(a), font=("tahoma", 14))
    while x != "-":
        canvas.create_text(850, 100+cnt*30, text="\u2588\u2588 = %s" % x, fill=colors[reqActivities.index(x)], font=("tahoma", 15))
        for y in range(1, len(reqWeeklyOccurences[x])-1):
            canvas.create_line(100+horizontalDistPerPoint2*(y-1), 700-verticalDistPerPoint2*reqWeeklyOccurences[x][y-1], 100+horizontalDistPerPoint2*y, 700-verticalDistPerPoint2*reqWeeklyOccurences[x][y], fill=colors[reqActivities.index(x)], width=3)
            canvas.create_oval(96+horizontalDistPerPoint2*y, 696-verticalDistPerPoint2*reqWeeklyOccurences[x][y], 104+horizontalDistPerPoint2*y, 704-verticalDistPerPoint2*reqWeeklyOccurences[x][y], fill=colors[reqActivities.index(x)], outline=colors[reqActivities.index(x)])
        cnt += 1
        x = input("Enter requirement ('cl' to clear, '-' to quit): ")
elif option == 3:
    for a in range(maxActPerDay+1):
        canvas.create_text(90, 700-verticalDistPerPoint*a, text=str(a), font=("tahoma", 16))
    for x in range(len(reqActivities)):
        canvas.create_text(850, 100+x*30, text="\u2588\u2588 = %s" % reqActivities[x], fill=colors[x], font=("tahoma", 15))
        for y in range(1, len(reqOccurences[reqActivities[x]])):
            canvas.create_line(100+horizontalDistPerPoint*(y-1), 700-verticalDistPerPoint*reqOccurences[reqActivities[x]][y-1], 100+horizontalDistPerPoint*y, 700-verticalDistPerPoint*reqOccurences[reqActivities[x]][y], fill=colors[x], width=3)
            canvas.create_oval(96+horizontalDistPerPoint*y, 696-verticalDistPerPoint*reqOccurences[reqActivities[x]][y], 104+horizontalDistPerPoint*y, 704-verticalDistPerPoint*reqOccurences[reqActivities[x]][y], fill=colors[x], outline=colors[x])
elif option == 4:
    x = input("Enter requirement: ")
    cnt = 0
    for a in range(maxActPerDay+1):
        canvas.create_text(90, 700-verticalDistPerPoint*a, text=str(a), font=("tahoma", 16))
    while x != "-":
        canvas.create_text(850, 100+cnt*30, text="\u2588\u2588 = %s" % x, fill=colors[reqActivities.index(x)], font=("tahoma", 15))
        for y in range(1, len(reqOccurences[x])):
            canvas.create_line(100+horizontalDistPerPoint*(y-1), 700-verticalDistPerPoint*reqOccurences[x][y-1], 100+horizontalDistPerPoint*y, 700-verticalDistPerPoint*reqOccurences[x][y], fill=colors[reqActivities.index(x)], width=3)
            canvas.create_oval(96+horizontalDistPerPoint*y, 696-verticalDistPerPoint*reqOccurences[x][y], 104+horizontalDistPerPoint*y, 704-verticalDistPerPoint*reqOccurences[x][y], fill=colors[reqActivities.index(x)], outline=colors[reqActivities.index(x)])
        cnt += 1
        x = input("Enter requirement ('cl' to clear, '-' to quit): ")

schedReader = open("schedTracker", "r")

lines2 = schedReader.readlines()

earliestDateRead = lines2[0][:-3]
latestDate = date.today()

months = ["Jan.", "Feb.", "Mar.", "Apr.", "May.", "Jun.", "Jul.", "Aug.", "Sep.", "Oct.", "Nov.", "Dec."]

startDate = date(int(earliestDateRead.split(" ")[2]), months.index(earliestDateRead.split(" ")[0])+1, int(earliestDateRead.split(" ")[1]))
endDate = date(latestDate.year, latestDate.month, latestDate.day)
dateRangeList = []

for x in daterange(startDate, endDate):
    dateRangeList.append(months[int(x.strftime("%m"))-1] + " " + x.strftime("%d") + " " + x.strftime("%Y"))

performanceAvgPerDay = dict.fromkeys(dateRangeList, 0)

tempPerformance = []

for x in range(len(dateRangeList)):
    for y in range(len(lines2)):
        if dateRangeList[x] == lines2[y][:-3]:
            tempPerformance.append(int(lines2[y][-2:-1]))
    performanceAvgPerDay[dateRangeList[x]] = sum(tempPerformance)/len(tempPerformance) if tempPerformance != [] else 0
    tempPerformance = []

performanceAvgPerDay = {**{"-" : 0}, **performanceAvgPerDay}
dateRangeList = ["-"] + dateRangeList
 
horizontalDistPerPoint3 = 600/int(math.ceil(len(dateRangeList)))
verticalDistPerPoint3 = 300

tk2 = Tk()
canvas2 = Canvas(tk2, width=800, height=800, bg="aqua")
canvas2.pack()

canvas2.create_line(100, 700, 700, 700, width=6)
canvas2.create_line(100, 100, 100, 700, width=6)

for x in range(9):
    canvas2.create_text(80, 700-75*x, text=str(x/4), font=("tahoma", 12))

for x in range(1, len(dateRangeList)):
    canvas2.create_line(100+horizontalDistPerPoint3*(x-1), 700-verticalDistPerPoint3*performanceAvgPerDay[dateRangeList[x-1]], 100+horizontalDistPerPoint3*x, 700-verticalDistPerPoint3*performanceAvgPerDay[dateRangeList[x]], width=3, fill=colors2[-1])
    canvas2.create_oval(96+horizontalDistPerPoint3*x, 696-verticalDistPerPoint3*performanceAvgPerDay[dateRangeList[x]], 104+horizontalDistPerPoint3*x, 704-verticalDistPerPoint3*performanceAvgPerDay[dateRangeList[x]], fill=colors2[-1], outline=colors2[-1])

tk.lift()
tk2.lift()

canvas.mainloop()
canvas2.mainloop()
