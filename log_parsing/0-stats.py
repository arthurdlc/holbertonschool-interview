#!/usr/bin/python3
import sys
import signal

"""
This script reads log entries from stdin, extracts status codes and file sizes,
and prints statistics every 10 lines or upon receiving a keyboard interrupt (CTRL + C).
"""

# Dictionary to store count of status codes
status_counts = {}
# Total file size counter
total_size = 0
# Number of lines processed
line_count = 0

# Allowed status codes
valid_status_codes = {200, 301, 400, 401, 403, 404, 405, 500}

def print_stats():
    """Prints the accumulated metrics."""
    print(f"File size: {total_size}")
    for code in sorted(status_counts.keys()):
        print(f"{code}: {status_counts[code]}")

def signal_handler(sig, frame):
    """Handles keyboard interrupt (CTRL + C) by printing stats before exiting."""
    print_stats()
    sys.exit(0)

# Attach signal handler for CTRL + C
signal.signal(signal.SIGINT, signal_handler)

try:
    for line in sys.stdin:
        parts = line.split()
        if len(parts) < 9:
            continue  # Ignore malformed lines
        
        try:
            status_code = int(parts[-2])
            file_size = int(parts[-1])
            
            total_size += file_size
            line_count += 1
            
            if status_code in valid_status_codes:
                status_counts[status_code] = status_counts.get(status_code, 0) + 1
            
            if line_count % 10 == 0:
                print_stats()
        except ValueError:
            continue  # Ignore lines where status code or file size is not an integer
except KeyboardInterrupt:
    print_stats()
    sys.exit(0)
