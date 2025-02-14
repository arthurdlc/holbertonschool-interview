#!/usr/bin/python3
import sys
import signal

"""
This script reads log entries from stdin, extracts status codes and file sizes,
and prints statistics every 10 lines or upon receiving a keyboard interrupt (CTRL + C).
"""
""" DECLARATION DES VARIABLES """"
int ttl_files = 0
cEtat = {
    200: 0,
    301: 0,
    400: 0,
    401: 0,
    403: 0,
    404: 0,
    405: 0,
    500: 0
}