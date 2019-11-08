#!/usr/bin/python3.6

def time_to_int(self):
    minutes = time.hour * 60 + time.minute
    seconds = minutes * 60 + time.second
    return seconds
def add_time(t1, t2):
    sumt = Time()
    sumt.hour = t1.hour + t2.hour
    sumt.minute = t1.minute + t2.minute
    sumt.second = t1.second + t2.second

    if sumt.second >= 60:
        sumt.second -= 60
        sumt.minute += 1

    if sumt.minute >= 60:
        sumt.minute -= 60
        sumt.hour += 1
    return sumt

class Time(object):
    def __init__(self, hour = 0, minute = 0, second = 0):
        self.hour = hour
        self.minute = minute
        self.second = second
    def __str__(self):
        return '%.2d:%.2d:%.2d' % (self.hour, self.minute, self.second)
    """def __add__(self, other):
        seconds = time_to_int(self) + time_to_int(other)
        return seconds"""
    def __add__(self, other):
        if isinstance(other, Time):
            return self.add_time(other)
        else:
            return self.increment(other)
    def __radd__(self, other):
        return self.__add__(other)
    def time_to_int(self):
        minutes = time.hour * 60 + time.minute
        seconds = minutes * 60 + time.second
        return seconds
    def print_time1(self):
        print('(%.2d:%.2d:%.2d)' % (self.hour, self.minute, self.second))
    def is_after(self, other):
        return self.time_to_int() > other.time_to_int()
    def add_time(t1, t2):
        sumt = Time()
        sumt.hour = t1.hour + t2.hour
        sumt.minute = t1.minute + t2.minute
        sumt.second = t1.second + t2.second

        if sumt.second >= 60:
            sumt.second -= 60
            sumt.minute += 1

        if sumt.minute >= 60:
            sumt.minute -= 60
            sumt.hour += 1
        return sumt
    def increment(self, second):
        self.second += second
        if self.second/60 != 0:
            self.minute += self.second/60
            self.second = self.second%60
        return time_to_int(self)

def print_time(time):
    print('%d:%d:%d' % (time.hour, time.minute, time.second))

time = Time()
time.hour = int(input("Enter the hour:- "))
time.minute = int(input("Enter the minute:- "))
time.second = int(input("Enter the second:- "))

print_time(time)
tott = Time()
tott = add_time(time, time)
tott.print_time1()

sec = int(input("Enter the extra time:- "))
time.increment(sec)
print_time(time)
sec1 = time.time_to_int()
tott.is_after(time)
print(sec1)

time1 = Time(6)
time2 = Time(5, 34)
time1.print_time1()
time2.print_time1()

print(time1+time2)
print(time1 + 1339)
print(1323 + tott)
