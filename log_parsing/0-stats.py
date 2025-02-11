#!/usr/bin/python3

import sys
import re
from collections import defaultdict

def print_stats(total_size, status_counts):
    """Affiche la taille totale des fichiers et le nombre de codes de statut."""
    print("File size: {}".format(total_size))
    for status_code in sorted(status_counts.keys()):
        print("{}: {}".format(status_code, status_counts[status_code]))

# Initialisation des variables
total_size = 0  # Taille totale des fichiers
status_counts = defaultdict(int)  # Compteur de codes de statut
line_count = 0  # Nombre de lignes traitées
valid_status_codes = {"200", "301", "400", "401", "403", "404", "405", "500"}

try:
    # Lecture de l'entrée standard ligne par ligne
    for line in sys.stdin:
        match = re.match(
            r'\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3} - \[[^\]]+\] "GET /projects/260 HTTP/1.1" (\d+) (\d+)',
            line
        )
        if match:
            status_code, file_size = match.groups()
            total_size += int(file_size)
            line_count += 1

            if status_code in valid_status_codes:
                status_counts[status_code] += 1

            # Affichage des statistiques toutes les 10 lignes
            if line_count % 10 == 0:
                print_stats(total_size, status_counts)

except KeyboardInterrupt:
    pass  # On ne fait rien et on continue à afficher les stats

finally:
    # Affichage des statistiques à la fin de l'exécution
    print_stats(total_size, status_counts)
