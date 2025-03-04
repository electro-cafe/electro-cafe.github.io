---
date:
  created: 2025-03-02
categories:
  - Formules
tags:
  - introduction
authors:
  - thomas
slug: fondamental_electronique
---

# Fondamentales de l'électronique 

Cet article présente les définitions, concepts et formules du domaine de l'électronique.  

<!-- more -->

## Définitions  


| nom  | autre nomination | définition  | analogie chute d'une enclume | sympole math. | unité |
| :---------------| :-------------- |:---------------:| :---------------:| :-------:| -------:|
| Tension | Voltage, potentiel, courant   | différence de potentiel | hauteur de chute | U | Volt (V)|
| Intensité  | ampérage |       débit du courant électrique      | masse de l'enclume | I | Ampère (A) |
| Puissance  | - |       quantité d’énergie fournie ou consommée      | énergie lors de l'impact | P | Watt (W) |
| Résistance  | - |     opposition au passage du courant    | frottement de l'air |  R   | Ohm (Ω) |

Et l'électricité dans tout ça ?  
L'électricité est un tout, ce tableau représente ces composantes et permet de la décrire et la mesurer.

Attention force et puissance ne sont pas la même chose.  
La force mécanique F = m * a  
La puissance mécanique P = F * v ce qu'on peut décomposer en P = m * a * v   
On peut détailler avec a = (v1−v2) / t ce qui donne P = m * (v1−v2) / t * v  
La puissance électrique P = U * I

Attention la masse et le poid ne sont pas la même chose.
la masse se mesure en kg, c'est ce que l'on nomme le poid dans le language courant.  
le poid se mesure en Newton, c'est une force. c'est l'attraction exercée par la gravité de la planète sur la masse de l'objet. C'est également la force que l'objet exerce contre la planète.

Ce que je ne comprend pas c'est que si je pousse contre un mur rien ne bouge pourtant j'exerce une force et j'utilise ma puissance. comme rien ne bouge a = 0 donc F = 0 donc P = 0  
Peut-être qu'il n'y a pas de force car c'est un système et que le mur exerce une force dans le sens opposé.
Ma force est convertie en perte, c'est à dire en chaleur dans les muscles. 

L'énergie c'est la puissance * temps --> E = P * t    ex: 1 joule = 1W / 1s 
c'est pour ça que les joules sont donnés en watts / heures  
La puissance c'est la tension * l'intensité --> P = U * I    
c'est aussi l'énergie par unité de temps --> P = E / t   

1 herz = 1 oscilliation par seconde.  
1 MegaHerz = 1 million d'oscilliation par seconde.  
1 GigaHerz = 1 milliard d'oscilliation par seconde.  
La fréquence c'est le nombre d'oscilliation par seconde --> une fréquence de 50 Herz correspond à 50 cycles par seconde, un cycle correspondant au fait que l'onde revient à sa valeur initiale. f = 1/T  
La Période c'est la durée d'un cycle complet de l'onde. son unité est la seconde. T = 1/f  
La fréquence et la période sond donc liés, elles sont inversément proportionelles.  
2 Hz = 2 cycles par seconde.    
L'onde transporte de l'énergie sans que la matière se déplace de façon nette.   
L'onde est une variation de la tension. les oscilliation peuvent être utilisées pour mesurer le temps.

Le courant alternatif a une fréquence qui oscille. le courant continu n'a pas de fréquence.

Le coulon est l'unité de charge électrique. 1 C = 6.242 * 10^18 électrons. c'est donc une quantité d'électrons.  
On le défini comme l'intensité * le temps. Q = I * t.
L'ampère (A) est défini comme 1 coulomb par seconde.  
I = Q / t  
Le volt (V) est défini comme 1 joule par coulomb :
1V = 1J/1C  
L'énergie E, donnée en joules (J) est définie par les coulombs multipliés par volt  
E = Q*V
Le joule (J) est le travail d'une force de 1 Newton sur 1 mètre où la pression exercé sous l'effet de la gravité par une pomme de 100 g sur le sol.
1J = 1N * 1m  
c'est l'énergie d'un Coulon sous 1 Volt     
1J = 1C * 1V   
c'est l'énergie consommée par un appareil de 1 Watt fonctionnant pendant 1 seconde
1J = 1W * 1s  --> 1 kWh = 1000 W * 3600 s = 3,6 Méga Joules 



## Formules mathématiques  

![layout mkdocs visualstudio code](mkdocs/loi_ohm.png)  
- **U = R * I**  --> tension = résistence * intensité  -->  c'est la loi d'Ohm  
- **P = U * I**  --> puissance = tension * intensité
