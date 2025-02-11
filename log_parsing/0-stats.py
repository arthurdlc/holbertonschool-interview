#!/usr/bin/python3

import sys
import re

# Initialisation des variables
total_size = 0  # Taille totale des fichiers
status_counts = {}  # Compteur de codes de statut
line_count = 0  # Nombre de lignes traitées

try:
    # Lecture de l'entrée standard ligne par ligne
    for line in sys.stdin:
        # Expression régulière pour extraire le code de statut et la taille du fichier
        match = re.match(r'\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3} - \[[^\]]+\] "GET /projects/260 HTTP/1.1" (\d+) (\d+)', line)
        if match:
            status_code = match.group(1)  # Extraction du code de statut
            file_size = int(match.group(2))  # Extraction de la taille du fichier

            total_size += file_size  # Mise à jour de la taille totale
            line_count += 1  # Incrémentation du nombre de lignes traitées

            # Comptage des codes de statut
            if status_code in ["200", "301", "400", "401", "403", "404", "405", "500"]:
                if status_code in status_counts:
                    status_counts[status_code] += 1
                else:
                    status_counts[status_code] = 1

            # Affichage des statistiques toutes les 10 lignes
            if line_count % 10 == 0:
                print_stats(total_size, status_counts)

except KeyboardInterrupt:
    # Affichage des statistiques en cas d'interruption par l'utilisateur
    print_stats(total_size, status_counts)

def print_stats(total_size, status_counts):
    # Affichage de la taille totale des fichiers
    print("File size: {}".format(total_size))
    # Affichage du nombre de lignes par code de statut
    for status_code in sorted(status_counts.keys()):
        print("{}: {}".format(status_code, status_counts[status_code]))