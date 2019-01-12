#! /usr/bin/python3

import subprocess as sp
import time

atLeast18bananas = []
atLeast5perfectScheduleDaysWithTime = []
atLeast6perfectScheduleDaysWithoutTime = []
unfairday = []
reason = []

atLeast18bananas.append(input("Enter whether you ate at least 18 bananas this week: "))
atLeast5perfectScheduleDaysWithTime.append(input("At least 5 perfect schedule days with time (y/n): "))
atLeast6perfectScheduleDaysWithoutTime.append(input("At least 6 perfect schedule days (y/n): "))
unfairday.append(input("Was there anything unfair that affected whether you did the three requirements? (y/n): "))
reason.append(input("Reason ('n' if nothing happened): "))

open("weekTracker", "a").write(str(atLeast18bananas));
open("weekTracker", "a").write("\t\t\t\t\t");
open("weekTracker", "a").write(str(atLeast5perfectScheduleDaysWithTime));
open("weekTracker", "a").write("\t\t\t\t\t\t");
open("weekTracker", "a").write(str(atLeast6perfectScheduleDaysWithoutTime));
open("weekTracker", "a").write("\t\t\t\t\t\t");
open("weekTracker", "a").write(str(unfairday));
open("weekTracker", "a").write("\t\t\t");
open("weekTracker", "a").write(str(reason));
open("weekTracker", "a").write("\n");
