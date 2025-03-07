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

  



<!-- | nom  | autre nomination | définition  | analogie chute d'une enclume | sympole math. | unité |
| :---------------| :-------------- |:---------------:| :---------------:| :-------:| -------:|
| Tension | Voltage, potentiel, courant   | différence de potentiel | hauteur de chute | U | Volt (V)|
| Intensité  | ampérage |       débit du courant électrique      | masse de l'enclume | I | Ampère (A) |
| Puissance  | - |       quantité d’énergie fournie ou consommée      | énergie lors de l'impact | P | Watt (W) |
| Résistance  | - |     opposition au passage du courant    | frottement de l'air |  R   | Ohm (Ω) |

Et l'électricité dans tout ça ?  
L'électricité est un tout, ce tableau représente ces composantes et permet de la décrire et la mesurer.

**Attention** : force et puissance ne sont pas la même chose.  

La **force mécanique** :  
$$ F = m \times a $$  

La **puissance mécanique** :  
$$ P = F \times v $$  
ce qu'on peut décomposer en :  
$$ P = m \times a \times v $$  

On peut détailler avec :  
$$ a = \frac{v_1 - v_2}{t} $$  
ce qui donne :  
$$ P = m \times \frac{(v_1 - v_2)}{t} \times v $$  

La **puissance électrique** :  
$$ P = U \times I $$  

---

**Attention** : la masse et le poids ne sont pas la même chose.  

- La **masse** se mesure en **kg**, c'est ce que l'on nomme le poids dans le langage courant.  
- Le **poids** se mesure en **Newton (N)**, c'est une **force**. C'est l'attraction exercée par la gravité de la planète sur la masse de l'objet. C'est également la force que l'objet exerce contre la planète.

---

Ce que je ne comprends pas, c'est que si je pousse contre un mur, rien ne bouge, pourtant j'exerce une force et j'utilise ma puissance.  
Comme rien ne bouge :  
$$ a = 0 \Rightarrow F = 0 \Rightarrow P = 0 $$  
Peut-être qu'il n'y a pas de force car c'est un **système** et que le mur exerce une force dans le sens opposé.  
Ma force est convertie en **perte d'énergie**, c'est-à-dire en **chaleur dans les muscles**.  

---

L'**énergie**, c'est la **puissance × temps** :  
$$ E = P \times t $$  
**Exemple** : 1 joule = 1 W × 1 s  

C'est pour ça que les joules sont donnés en **watts-heures**.  

La **puissance** :  
$$ P = U \times I $$  
C'est aussi l'**énergie par unité de temps** :  
$$ P = \frac{E}{t} $$  

---

### **Fréquence et Période**  

- **1 Hertz (Hz) = 1 oscillation par seconde.**  
- **1 MégaHertz (MHz) = 1 million d'oscillations par seconde.**  
- **1 GigaHertz (GHz) = 1 milliard d'oscillations par seconde.**  

La **fréquence** est le **nombre d'oscillations par seconde** :  
Une fréquence de **50 Hz** correspond à **50 cycles par seconde**, un cycle correspondant au fait que l'onde revient à sa valeur initiale :  
$$ f = \frac{1}{T} $$  

La **période** est la durée d'un cycle complet de l'onde, son unité est la seconde :  
$$ T = \frac{1}{f} $$  

La **fréquence et la période** sont donc liées, elles sont **inversément proportionnelles**.  
**Exemple** : 2 Hz = 2 cycles par seconde.  

L'**onde** transporte de l'énergie sans que la matière se déplace de façon nette.  
L'onde est une **variation de la tension**. Les oscillations peuvent être utilisées pour **mesurer le temps**.  

Le **courant alternatif** a une **fréquence** qui oscille.  
Le **courant continu** n'a **pas de fréquence**.  

---

### **Charge électrique et tension**  

Le **coulomb (C)** est l'unité de charge électrique :  
$$ 1C = 6.242 \times 10^{18} \text{ électrons} $$  
C'est donc une **quantité d'électrons**.  

On le définit comme :  
$$ Q = I \times t $$  

L'**ampère (A)** est défini comme **1 coulomb par seconde** :  
$$ I = \frac{Q}{t} $$  

Le **volt (V)** est défini comme **1 joule par coulomb** :  
$$ 1V = \frac{1J}{1C} $$  

L'**énergie (E)**, donnée en **joules (J)**, est définie par :  
$$ E = Q \times V $$  

Le **joule (J)** est le travail d'une force de **1 Newton sur 1 mètre** ou la pression exercée sous l'effet de la gravité par une pomme de 100 g sur le sol :  
$$ 1J = 1N \times 1m $$  

C'est aussi :  
- L'**énergie d'un coulomb sous 1 volt** :  
  $$ 1J = 1C \times 1V $$  
- L'**énergie consommée par un appareil de 1 Watt fonctionnant pendant 1 seconde** :  
  $$ 1J = 1W \times 1s $$  

Donc :  
$$ 1 kWh = 1000 W \times 3600 s = 3,6 \text{ MJ} $$  

---

## **Formules mathématiques**  

![layout mkdocs visualstudio code](mkdocs/loi_ohm.png)  

- **Loi d'Ohm** :  
  $$ U = R \times I $$  
  (*Tension = Résistance × Intensité*)  

- **Puissance électrique** :  
  $$ P = U \times I $$  
  (*Puissance = Tension × Intensité*)  
-->


# L'Électricité : Comprendre ses Composantes  

L'électricité est invisible, on ne peut observer que ces effets, ce tableau représente ces composantes et permet de la décrire et la mesurer  
## Tableau des concepts clés  

| **Nom**       | **Autre nomination**        | **Définition**                                           | **Analogie (chute d'une enclume)**  | **Symbole** | **Unité**   |
|--------------|----------------------------|----------------------------------------------------------|--------------------------------------|------------|------------|
| **Tension**  | Voltage, potentiel courant | Différence de potentiel                 | Hauteur de chute                    | \( U \)    | Volt (V)   |
| **Intensité** | Ampérage                   | Débit du courant électrique                             | Masse de l'enclume                  | \( I \)    | Ampère (A) |
| **Puissance** | -                           | Quantité d’énergie fournie ou consommée                 | Énergie lors de l’impact            | \( P \)    | Watt (W)   |
| **Résistance** | -                          | Opposition au passage du courant                        | Frottement de l'air                  | \( R \)    | Ohm (Ω)    |

---

## ⚠️ Force et Puissance  
Attention à ne pas les confondre. L'unité de la foce est le Newton (N), 1N correspond à la foce exercé par une pomme de 100g contre le sol du fait de la gravité. L'unité de la puissance est le watt (W). Les watts sont des joules par seconde.
 $$
  1W = \frac{J}{s}
  $$

- **Force mécanique F(N)**  

  \( F = m \cdot a \)  
  où \( m \) est la masse (kg) et \( a \) l'accélération (m/s²).    
  

- **Puissance mécanique P(W)**  
  $$
  P = F \cdot v = m \cdot a \cdot v
  $$
  avec \( v \) la vitesse (m/s).   
  Cela n'a pas d'utilité mais on peut dévelloper avec \( a = \frac{v_1 - v_2}{t} \), pour obtenir :  
  $$
  P = m \cdot \frac{v_1 - v_2}{t} \cdot v
  $$

- **Puissance électrique P(W)**  
  $$
  P = U \cdot I
  $$

---

## ⚡ Énergie et Puissance  

Attention à ne pas les confondre, l’**énergie** est la **puissance multipliée par le temps**, on la nomme aussi **travail**. Son unité est le Joule (J) :  
$$
E = P \cdot t
$$

**Exemple :**  
- **1 Joule** est l’énergie fournie par **1 Watt pendant 1 seconde** :  
  $$
  1J = 1W \cdot 1s
  $$
- Conversion des kilowatt-heures en joules :  
  $$
  1\, \text{kWh} = 1000\, \text{W} \cdot 3600\, \text{s} = 3,6\, \text{MJ}
  $$  
  1kilowatt-heure vaut 3,6 mégajoules

---

## ⚖️ Masse et Poids  
Attention à ne pas les confondre  
- La **Masse** \( m \) se mesure en kg, c'est ce que l'on nomme le poid dans le langage courant.  
- Le **Poids** \( P_{\text{grav}} \) : force gravitationnelle exercée sur un objet, mesurée en Newton (N).  

$$
P_{\text{grav}} = m \cdot g
$$

où \( g \approx 9,81 \, \text{m/s}^2 \) sur Terre. On a déjà vu ce type d'unité, il s'agit de celle de l'accélération. g = accélération de la gravité sur terre.

> **Exemple :** Une masse de 10 kg a un poids d’environ :  
> $$
> 10 \cdot 9,81 = 98 \, N
> $$

---

## 🔎 Pourquoi ne dépense-t-on pas de puissance en poussant un mur ?  

Si tu pousses contre un mur immobile :  
- Tu exerces une **force**, mais  
- Comme il n’y a **pas de mouvement**, alors :  
  $$
  a = 0 \Rightarrow F = 0 \Rightarrow P = 0
  $$
- La puissance c'est la quantité de travail effectué par unité de temps, se mesurant en watts (W). Le travail (ou énergie) se réalise uniquement si une force déplace un objet sur une distance, ce qui n'est pas notre cas. La force exercée est dissipée sous forme de chaleur dans les muscles. 
\( Puissance (P) = \frac{Travail(W)}{Temps (t)} \)   

- Énergie (E) : Symbole "E", unité joule (J).

- Travail (W) : Symbole "W", unité joule (J).

- Puissance (P) : Symbole "P", unité watt (W).

Il est important de noter que, bien que le symbole **"W"** soit utilisé pour représenter le **travail**, il ne doit pas être **confondu avec le watt**, unité de puissance.


---

## 📡 Fréquence et Période  

- **Fréquence** :  
  $$
  f = \frac{1}{T}
  $$
  La fréquence \( f \) c'est le nombre d’oscillations - cycles - par seconde (Hz).    

- **Période** :  
  $$
  T = \frac{1}{f}
  $$
  \( T \) est la durée d'un cycle, mesurée en secondes, en gros le temps que ça prend pour que l'onde revienne à son état de départ (après avoir passé par les valeurs + et -).

> **Remarque :** Le courant **alternatif** oscille à une fréquence donnée (ex. 50 Hz), tandis que le courant **continu** ne varie pas. Une source de tension comme une batterie fournit une tension continue.

---

## 🔋 Charge Électrique  

- **Le Coulomb (C)** représente un nombre d'électrons (un peu comme une mole) :  
  $$
  1\,C = 6,242 \times 10^{18} \text{ électrons}
  $$
- Comme les électrons sont négatifs, la charge électrique est donnée par Q :  
  $$
  Q = I \cdot t
  $$
- L’**ampère (A)** est défini comme **1 coulomb par seconde** :  
  $$
  I = \frac{Q}{t}
  $$

---

## 🔌 Tension et Énergie  

- Le **volt (V)** est défini comme l’énergie par charge :  
  $$
  1\,V = \frac{1J}{1C}
  $$
- L’**énergie électrique (E)** est l'énergie résultant du déplacement de charges électriques, son unité est la joule (J) :  
  $$
  E = Q \cdot U
  $$

---

## 💡 Travail et Joule  

- Le **joule (J)** est le travail d’une **force de 1 newton sur 1 mètre** :  
  $$
  1J = 1N \cdot 1m
  $$
- Il correspond aussi à l’énergie consommée par un appareil de **1 watt pendant 1 seconde** :  
  $$
  1J = 1W \cdot 1s
  $$

---

## 📜 Formules Mathématiques Essentielles  

![Loi d'Ohm](mkdocs/loi_ohm.png)  


- **Loi d'Ohm** :  
  $$
  U = R \cdot I
  $$
  *Tension = Résistance × Intensité*
  >⚠️ On Utilise **U** pour la tension aux borne d'un élément du circuit et **E** pour la tension de la source

- **Puissance électrique** :  
  $$
  P = U \cdot I
  $$
  *Puissance = Tension × Intensité*

- **Loi de kirshhoff - noeuds** :    
$$
∑I 
entrant
​
 =∑I 
sortant
$$
Dans un noeud, la somme de l'**Intensité** qui rentre = la somme de ce qui sort

- **Loi de kirshhoff - maille** :    
$$
∑I 
entrant
​
 =∑I 
sortant
$$
Dans une maille(boucle fermée), la somme des **tensions** = 0 car l'énergie fournie est toujours entièrement consommée.
> ce n'est pas nous qui choisissons la tension des résistance, c'est leur résistance, en fonction de celle ci elles vont se répartir la tension totale afin que la somme soit 0. 


exemple calcul de répartition des tension dans un système de 9V avec 2 résistances de 10Ω et 20Ω:   
$$  
I = \frac{9V}{10Ω + 20Ω} = 0.3A  
$$
U1 = 10Ω * 0.3A = 3V  
U2 = 20Ω * 0.3A = 6V

---

## ✏️ Schéma électrique vocabulaire 

![Schema circuit electrique](mkdocs/schema_circuit_electrique.gif)  

une **maille** c'est un chemin fermé dans un circuit.   
un **noeud** c'est une connexion ou arrivent plusieurs branches.
une **branche** c'est un chemin du circuit à un noeud.    
un **dipole** c'est  un composant électrique possédant deux bornes.
une **borne** c'est le point de connexion d'un composant électrique. 
  
    

## 🌐 Ressources 
Complément d'information: [université Lille 1](https://physique-enligne.univ-lille.fr/electrocinetique/co/chapitre1_1_1.html)  
youtube [Profcoudert](https://www.youtube.com/watch?v=hFzQDGhtpXA)
