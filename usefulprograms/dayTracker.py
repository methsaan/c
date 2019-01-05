#! /usr/bin/python3

import subprocess as sp
import time
month = []
day = []
pa = []
duolingo = []
piano = []
mt = []
unfairday = []
reason = []
FOR = []

month.append(input("Enter month: (press ^C to show schedule) "))
day.append(input("Enter date: "))
pa.append(input("Enter whether you did physical activity (y/n): "))
duolingo.append(input("Enter whether you did duolingo (y/n): "))
piano.append(input("Enter whether you did piano (y/n): "))
mt.append(input("Enter whether you did theory (y/n): "))
unfairday.append(input("Was there anything unfair that affected whether you achieved the six requirements? (y/n): "))
reason.append(input("Reason: ('n' if nothing unfair happened): "))
FOR.append(input("What is the frequency of the reason? "))
open("dayTracker", "a").write(str(month));
open("dayTracker", "a").write("\t\t");
open("dayTracker", "a").write(str(day));
open("dayTracker", "a").write("\t\t");
open("dayTracker", "a").write(str(pa));
open("dayTracker", "a").write("\t\t");
open("dayTracker", "a").write(str(duolingo));
open("dayTracker", "a").write("\t\t");
open("dayTracker", "a").write(str(piano));
open("dayTracker", "a").write("\t\t");
open("dayTracker", "a").write(str(mt));
open("dayTracker", "a").write("\t\t");
open("dayTracker", "a").write(str(unfairday));
open("dayTracker", "a").write("\t\t");
open("dayTracker", "a").write(str(reason));
open("dayTracker", "a").write("\t\t\t\t");
open("dayTracker", "a").write(str(FOR));
open("dayTracker", "a").write("\n");
if input("Hit 'd' and enter to see your progress\n") == "d":
    for x in range(len(day)):
        print(open("dayTracker").read())
    x = input("Type 's' to stop showing: ")
    if x == "s":
        sp.call("clear", shell=True)
