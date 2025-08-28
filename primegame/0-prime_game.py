#!/usr/bin/python3


"""Prime Game - Maria and Ben"""


def isWinner(x, nums):
    """Determine the winner of the Prime Game"""
    if x < 1 or not nums:
        return None

    n = max(nums)

    # Crible d'Ératosthène pour trouver les nombres premiers jusqu'à n
    sieve = [True] * (n + 1)
    sieve[0] = sieve[1] = False

    for i in range(2, int(n ** 0.5) + 1):
        if sieve[i]:
            for j in range(i * i, n + 1, i):
                sieve[j] = False

    # prime_count[i] = nombre de nombres premiers <= i
    prime_count = [0] * (n + 1)
    count = 0
    for i in range(2, n + 1):
        if sieve[i]:
            count += 1
        prime_count[i] = count

    # Déterminer le gagnant pour chaque partie
    maria_wins = 0
    ben_wins = 0

    for num in nums:
        if prime_count[num] % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    return None
