import serial
import time
import datetime
import csv

ser = serial.Serial('/dev/cu.usbmodem1411', 9600, timeout=0)
my_file = 'jared.csv'

f = open(my_file, 'wt')
writer = csv.writer(f)
writer.writerow(('dateTime', 'analogValue'))  # csv column headers

while True:
    try:
        # write a csv row
        writer.writerow((datetime.datetime.now(), ser.readline().strip()))

        # print out to screen
        # TODO: make the prints only once a second, stdout can't keep up
        analog_value = ser.readline().strip()
        if analog_value:
            line = '%s,%s\n' % (datetime.datetime.now(), analog_value)
            print line.strip()

        time.sleep(.001)

    except ser.SerialTimeoutException:
        print('Data could not be read')
        time.sleep(1)
