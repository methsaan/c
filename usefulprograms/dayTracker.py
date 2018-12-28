#! /usr/bin/python3

import subprocess as sp
import time
month = []
day = []
pa = []
duolingo = []
piano = []
mt = []

month.append(input("Enter month: "))
day.append(input("Enter date: "))
pa.append(input("Enter whether you did physical activity (y/n): "))
duolingo.append(input("Enter whether you did duolingo (y/n): "))
piano.append(input("Enter whether you did piano (y/n): "))
mt.append(input("Enter whether you did theory (y/n): "))
open("textfile", "a").write(str(month));
open("textfile", "a").write("\t\t");
open("textfile", "a").write(str(day));
open("textfile", "a").write("\t\t");
open("textfile", "a").write(str(pa));
open("textfile", "a").write("\t\t");
open("textfile", "a").write(str(duolingo));
open("textfile", "a").write("\t\t");
open("textfile", "a").write(str(piano));
open("textfile", "a").write("\t\t");
open("textfile", "a").write(str(mt));
open("textfile", "a").write("\n");
if input("Hit 'd' and enter to see your progress\n") == "d":
    for x in range(len(day)):
        print(open("textfile").read())
    x = input("Type 's' to stop showing: ")
    if x == "s":
        sp.call("clear", shell=True)
