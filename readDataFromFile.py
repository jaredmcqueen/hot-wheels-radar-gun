import csv
import time

my_file = "data.csv"
f = open(my_file, 'rt')



try:
    reader = csv.reader(f)
    for row in reader:
        print row
        time.sleep(.2)
finally:
    f.close()
