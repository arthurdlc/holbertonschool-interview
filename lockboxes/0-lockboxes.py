def canUnlockAll(boxes):
    """
    Détermine si toutes les boîtes peuvent être ouvertes.
    :param boxes: Une liste de listes contenant des clés.
    :return: True si toutes les boîtes peuvent être ouvertes, False sinon.
    """
    n = len(boxes)  # Nombre de boîtes
    opened = [False] * n  # Toutes les boîtes sont fermées au départ
    opened[0] = True  # La première boîte est toujours ouverte
    keys = set(boxes[0])  # Clés récupérées dans la première boîte

    while keys:  # Tant qu'il reste des clés à traiter
        new_keys = set()
        for key in keys:
            if 0 <= key < n and not opened[key]:  # Clé valide et boîte fermée
                opened[key] = True  # On ouvre la boîte
                new_keys.update(boxes[key])  # On récupère les clés de la boîte ouverte
        keys = new_keys  # Mise à jour des clés à traiter

    return all(opened)  # Vérifie si toutes les boîtes sont ouvertes
def canUnlockAll(boxes):
    """
    Détermine si toutes les boîtes peuvent être ouvertes.
    :param boxes: Une liste de listes contenant des clés.
    :return: True si toutes les boîtes peuvent être ouvertes, False sinon.
    """
    n = len(boxes)  # Nombre de boîtes
    opened = [False] * n  # Toutes les boîtes sont fermées au départ
    opened[0] = True  # La première boîte est toujours ouverte
    keys = set(boxes[0])  # Clés récupérées dans la première boîte

    while keys:  # Tant qu'il reste des clés à traiter
        new_keys = set()
        for key in keys:
            if 0 <= key < n and not opened[key]:  # Clé valide et boîte fermée
                opened[key] = True  # On ouvre la boîte
                new_keys.update(boxes[key])  # On récupère les clés de la boîte ouverte
        keys = new_keys  # Mise à jour des clés à traiter

    return all(opened)  # Vérifie si toutes les boîtes sont ouvertes
