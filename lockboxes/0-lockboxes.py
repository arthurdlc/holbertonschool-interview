#!/usr/bin/python3
"""This module defines a function to determine if all boxes can be unlocked."""


def canUnlockAll(boxes):
    """
    Determines if all boxes can be unlocked.

    Args:
        boxes (list of list of int): A list where each sublist represents a box
                                     and contains keys for other boxes.

    Returns:
        bool: True if all boxes can be opened, False otherwise.
    """
    n = len(boxes)  # Number of boxes
    opened = [False] * n  # All boxes are initially closed
    opened[0] = True  # The first box is always open
    keys = set(boxes[0])  # Keys collected from the first box

    while keys:  # As long as there are keys to process
        new_keys = set()
        for key in keys:
            if 0 <= key < n and not opened[key]:  # Valid key and unopened box
                opened[key] = True  # Open the box
                new_keys.update(boxes[key])  # Collect keys from the opened box
        keys = new_keys  # Update keys to process

    return all(opened)  # Check if all boxes are opened
