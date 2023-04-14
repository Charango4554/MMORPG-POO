# MMORPG-POO
Le programme implémente un jeu de combat textuel en C++, où deux personnages armés s'affrontent jusqu'à ce qu'un des deux soit mort.

J'ai re travailler sur un sujet de Programmation Orientée Objet que j'avais réalisé en Python au lycée , mais cette fois-ci je l'ai refait en C++.

SUJET:

On demande pour cette exercice d'implémenter plusieurs classes qui pourront interragir entre elles.

1. Une classe `Personnage` ayant pour attributs `_nom` et `_points_de_vie`, ce dernier étant un entier naturel. Les méthodes à implémenter sont:
  * `nom(self)` qui renvoie le nom du personnage;
  * `points_de_vie(self)` qui renvoie le nombre de points de vie restant;
  * `est_vivant()` qui n'a nul besoin d'une description. Le personnage est mort lorsqu'il n'a plus de points de vie;
  * `blesse(pv)` qui retire `pv` points de vie au personnage.
2. Une classe `Arme` ayant pour attributs `_nom` et `_dégâts_min` et `_dégâts_max`, ces derniers étant des entiers naturels (dans le bon ordre évidemment). Les méthodes à implémenter sont:
  * `nom(self)` qui renvoie le nom de l'arme;
  * `dégât_aléatoire(self)` qui renvoie un nombre aléatoire de dégâts entre les deux bornes définissant cette arme
3. Rajouter la possibilité de donner une arme à un personnage: il faudra un attribut supplémentaire, ainsi que redéfinir le constructeur et ajouter quelques méthodes (faites appel à votre bon sens);
4. Une classe `Arbitre` ayant pour attributs deux personnages armés `_p1` et `_p2`. Les méthodes à implémenter sont:
  * `personnage1(self)` et `personnage2(self)` qui renvoient les deux personnages respectivement.
  * `un_round(self)` qui effectue un round de combat entre les deux personnages. Dans un round, un seul personnage tape alternativement sur l'autre (et on échange les rôles au round suivant), en utilisant son arme et en infligeant un nombre aléatoire de dégâts à son adversaire. Par quel mécanisme peut-on alterner entre les deux personnages d'un round à l'autre ? Le personnage n° 1 frappera toujours en premier (ou alors, vous pouvez décider de faire ce choix aléatoirement, à vous de voir);
  * `combat(self)` qui simulera un combat complet, c'est-à-dire une alternance de rounds jusqu'à ce que l'un des personnage perde la vie. On affichera le détail des combats dans la console (à l'aide de `print`).
