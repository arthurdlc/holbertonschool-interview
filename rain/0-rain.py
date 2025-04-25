def rain(walls):
    if not walls or len(walls) < 3:
        return 0

    n = len(walls)
    water = 0

    # Create arrays to store the max height to the left/right of each bar
    left_max = [0] * n
    right_max = [0] * n

    # Fill in left_max
    left_max[0] = walls[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], walls[i])

    # Fill in right_max
    right_max[-1] = walls[-1]
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    # Calculate total trapped water
    for i in range(n):
        water += min(left_max[i], right_max[i]) - walls[i]

    return water
