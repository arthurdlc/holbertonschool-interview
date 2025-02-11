#!/usr/bin/python3

import sys
import re

total_size = 0
status_counts = {}
line_count = 0

try:
    for line in sys.stdin:
        match = re.match(r'\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3} - \[[^\]]+\] "GET /projects/260 HTTP/1.1" (\d+) (\d+)', line)
        if match:
            status_code = match.group(1)
            file_size = int(match.group(2))

            total_size += file_size
            line_count += 1

            if status_code in ["200", "301", "400", "401", "403", "404", "405", "500"]:
                if status_code in status_counts:
                    status_counts[status_code] += 1
                else:
                    status_counts[status_code] = 1

            if line_count % 10 == 0:
                print_stats(total_size, status_counts)

except KeyboardInterrupt:
    print_stats(total_size, status_counts)

def print_stats(total_size, status_counts):
    print("File size: {}".format(total_size))
    for status_code in sorted(status_counts.keys()):
        print("{}: {}".format(status_code, status_counts[status_code]))