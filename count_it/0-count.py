#!/usr/bin/python3
import requests


def count_words(subreddit, word_list, word_count={}, after=None):
    """Recursively count keywords in hot articles' titles from a subreddit"""

    if not word_list:
        return

    # Normalize word_list to lowercase and remove
    # duplicates while counting duplicates
    if not word_count:
        for word in word_list:
            lower = word.lower()
            word_count[lower] = word_count.get(lower, 0) + 0  # start at 0

    # Build URL and headers
    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {'User-Agent': 'Python/1.0'}
    params = {'limit': 100}
    if after:
        params['after'] = after

    # Make request
    try:
        response = requests.get(url, headers=headers, params=params,
                                allow_redirects=False)
        if response.status_code != 200:
            return
        data = response.json().get('data', {})
    except Exception:
        return

    # Parse and count words in titles
    children = data.get('children', [])
    for child in children:
        title = child.get('data', {}).get('title', '').lower().split()
        for word in title:
            if word.isalpha():  # only words, ignore punctuation
                if word in word_count:
                    word_count[word] += 1

    # Recurse if there's more data
    after = data.get('after')
    if after:
        return count_words(subreddit, word_list, word_count, after)

    # Once all data fetched, sort and print
    filtered = {k: v for k, v in word_count.items() if v > 0}
    for word, count in sorted(filtered.items(), key=lambda x: (-x[1], x[0])):
        print(f"{word}: {count}")
