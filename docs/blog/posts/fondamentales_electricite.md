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
| Résistance  | - |     ’opposition au passage du courant    | frottement de l'air |  R   | Ohm (Ω) |

Et l'électricité dans tout ça ?  
L'électricité est un tout, ce tableau représente ces composantes et permet de la décriire et la mesurer.

Attention puissance et force ne sont pas la même chose.  
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

L'énergie c'est la puissance * temps --> E = P * t      
c'est pour ça que les joules sont donnés en watts / heures  
La puissance c'est la tension * l'intensité --> P = U * I    
en mettant les deux équations en parallèle on obtient U * I = E / t  

1 herz = 1 oscilliation par seconde.  
1 MegaHerz = 1 million d'oscilliation par seconde.  
1 GigaHerz = 1 milliard d'oscilliation par seconde.  
La fréquence c'est le nombre d'oscilliation par seconde --> une fréquence de 50 Herz correspond à 50 cycles par seconde, un cycle correspondant au fait que l'onde revient à sa valeur initiale. f = 1/T  
La Période c'est la durée d'un cycle complet de l'onde. son unité est la seconde. T = 1/f  
La fréquence et la période sond donc liés, elles sont inversément proportionelles  

Le courant alternatif a une fréquence qui oscille. le courant continu n'a pas de fréquence.

à quoi sert la fréquence ?


## Formules mathématiques  

![layout mkdocs visualstudio code](mkdocs/loi_ohm.png)  
- **U = R * I**  --> tension = résistence * intensité  -->  c'est la loi d'Ohm  
- **P = U * I**  --> puissance = tension * intensité
