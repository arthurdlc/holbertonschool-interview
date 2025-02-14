#!/usr/bin/python3
import sys
import signal

"""
This script reads log entries from stdin, extracts status codes and file sizes,
and prints statistics every 10 lines or upon receiving a keyboard interrupt (CTRL + C).
"""

# Total file size counter
total_file_size = 0
# Number of lines processed
line_count = 0
# Allowed status codes
valid_status_codes = ['200', '301', '400', '401', '403', '404', '405', '500']
status_code_count = {code: 0 for code in valid_status_codes}

def print_metrics():
    """
    Prints the computed metrics to stdout.
    """
    print(f"File size: {total_file_size}")
    for status_code in sorted(valid_status_codes):
        if status_code_count[status_code] > 0:
            print(f"{status_code}: {status_code_count[status_code]}")

def signal_handler(sig, frame):
    """Handles keyboard interrupt (CTRL + C) by printing stats before exiting."""
    print_metrics()
    sys.exit(0)

# Attach signal handler for CTRL + C
signal.signal(signal.SIGINT, signal_handler)

if __name__ == "__main__":
    try:
        for line in sys.stdin:
            words = line.split()
            if len(words) < 2:
                continue
            
            status_code = words[-2]
            try:
                file_size = int(words[-1])
                global total_file_size
                total_file_size += file_size
            except ValueError:
                continue
            
            if status_code in status_code_count:
                status_code_count[status_code] += 1
            
            global line_count
            line_count += 1
            
            if line_count % 10 == 0:
                print_metrics()
    
        if line_count % 10 != 0:
            print_metrics()
    
    except KeyboardInterrupt:
        print_metrics()
        raise
