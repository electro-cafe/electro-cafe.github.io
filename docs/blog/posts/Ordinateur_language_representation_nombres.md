---
date:
  created: 2025-04-05
categories:
  - Math
  - Informatique
tags:
  - Math
authors:
  - thomas
slug: represantation-nombres-ordinateur-language
---

# L'ordinateur, language et représentation des nombre

Cet article explique comment convertir un nombre en base 2, comment l'ordinateur traite les nombres négatifs, à virgule etc.

<!-- more -->

##  Base 10  
On peut représenter un nombre tel que 456 comme étant:
>4 centaines  
>5 dizaines   
>6 unités  

avec une base 10 on peux créer ce tableau dont on peut utiliser chaque case 9 fois (le nombre de la base -1) pour définir le nombre donné.

| **puissance 10** | **\(10^2\)**       | **\(10^1\)**        | **\(10^0\)**    |
|--------------|--------------|--------------|--------------|
| | 100  | 10 | 1 |
|nombre de fois| 4  | 5 | 6 |

##  Base 2
| **puissance 2** | **\(2^8\)** | **\(2^7\)**  | **\(2^6\)**  | **\(2^5\)**  | **\(2^4\)**  | **\(2^3\)**  | **\(2^2\)**       | **\(2^1\)**        | **\(2^0\)**    |
|--------------|--------------|--------------|--------------|--------------|--------------|--------------|--------------|--------------|--------------|
|   | 256 | 128 | 64 | 32 | 16 | 8 | 4  | 2 | 1 |
|nombre de fois| 1 | 1 | 1 | 0 | 0 | 1 | 0 | 0 | 0 |

111001000 est la représentation **binaire** de 456.
Pour indiquer qu'un nombre est en base 2 on ajoute 0b devant. ainsi 0b456 = 111001000.

##  Base 16  
La base 16 est utilisée notement pour les hexacode, il s'agit d'un code représantant les valeurs RVB d'une couleur à l'écran.
Il reprend le principe de la base 10 et de la base 2, mais il ajoute une complexité: comme on ne dispose que de 10 chiffres distinctifs (0 à 9), la représentation des valeurs entre 10 et 15 portent à confusion, c'est 15 où 1 et 5 ? Il a donc fallu déterminer comment utiliser 1 seul caractère pour représenter une valeur à 2 chiffres. On a utilisé l'alphabet. A vaut 10, B 11, C 12, D 13, E 14 et F 16. Pour reprendre la représentation des couleurs par leur valeurs décimales, dans photoshop lorsque l'on travaille en xbit, on a 256 valeurs de teinte pour le rouge, pareil pour le vert, le bleu et le niveau de transparence.   
l'hexacode de la couleur est composée de 3 pack de 2 symboles, ces 2 symboles représentent la valeur de la nuance en base 16. Ainsi FF vaut 256. Voici comment cela se décompose: F étant égale à 16, on a 16 * 16^1 + 16 * 16^0, ce qui fait 15 * 16 + 15 * 1, soit 240 + 16 = 256.
Une dernière chose, pour indiquer qu'un nombre est hexadécimal et pas décimal on ajoute **0x** devant. 
>4 centaines  
>5 dizaines   
>6 unités  

avec une base 10 on peux créer ce tableau dont on peut utiliser chaque case 9 fois (le nombre de la base -1) pour définir le nombre donné.

| **puissance 10** | **\(10^2\)**       | **\(10^1\)**        | **\(10^0\)**    |
|--------------|--------------|--------------|--------------|
| | 100  | 10 | 1 |
|nombre de fois| 4  | 5 | 6 |

## Expressions régulières
Aussi connues sous le nom de Regular expressions où RegEx, Les expressions régulières sont des suites de caractères (nomé motif) combinés à des caractères spéciaux (quantificateurs), servant à la recherche de ces motifs selon les critères introduits à l'aide des caractères spéciaux dans un text.   
exemple: **^a** -> trouve les "a" en début de paragraphe.   
⚠️ À ne pas confondre avec les [opérateur bitwise et opérateur logiques](C++.md)


## bit, byte   
Ces termes à l'écriture et la prononciation proche peuvent préter à confusion.  
un **bit** c'est soit 0 soit 1, c'est la plus petite unité d'information dans un ordinateurs. Il peut valoir ""soit 1 soit 0"".  
un **byte** où octet en français c'est un **ensemble de 8 bits**. C’est l’unité de base utilisée pour mesurer la quantité de données.  
un byte c'est 256 valeurs possibles.  
  
un **word** = 32 bits = 4 bytes.  
un **half-word** = 16 bits = 2 bytes.


## nombres positifs et négatifs. - signé / non signé
afin de représenter les nombres négatifs on a pris la moitié d'un byte, soit 128 bits.
Les 128 premières valeurs sont réservés pour les nombres positifs, de la 129ème à la 256ème, pour les nombres négatifs.  
Le premier bit est le **bit de signature**, 1 = négatif. 0 = positif. nos 7 bits restants permettent de représenter 128 nombres.  
On parle de nombre **signé** si ils comprennent les négatifs, **non signé** si il comprennent que les positifs. 
Uint8 = non signé, 256 valeurs exprimants les nombres de 0 à 256 
int8 = signé, 256 valeurs allant de -128 à 127

**Uint8_t**  = un int de 8 bit, c'est garanti  
**int** = un int au nombre de bit variable

**règle de calcule des nombres négatifs**: si le 1er sign est 1, on a affaire à un nombre négatif. on va inverser les 7 bits suivants. on détermine le nombre et on rajoute - devant:    

👉 10110001  
👉 01001110 -> 78  
👉 -78

## floating numbers
ce sont les nombres à virgule flottante. le terme flottant fait référence au fait que la virgule n'occupe pas forcément la même place. Sa position dépend de l'exposant. voyons ça en détail:  

Les ordinateurs utilisent le standard **IEEE 754** pour stocker (se "représenter") les nombres flottants. il s'agit de 4 bytes, soit 32 bits.    

👉 le **1er bit** est le bit de **signature**. 0= positif. 1 = négatif.    
👉 les **8 prochains bits** sont réservés pour l'**Exposant**. ils déterminent la **position de la virgule**. l'échelle de l'exposant va de 0 à 255 mais comme on souhaite aussi inclure les nombres négatifs on l'a décallée pour qu'elle aille de -127 à 128. il suffit de lire sa valeur sans ce soucier de cette coupe et de soustraire 127 pour savoir quel nombre est représenté. Si je lit 137, on a en fait 10.    
👉 le **23 derniers bits** sont nommés **mantisse** et chaque bit représente une fraction de 1 sur 2 puissance X (x = position du bit dans la mantisse - 1). Ainsi le 1er bit de la mantisse représente 1/2^0 = 1, le 4ème bit 1/2^3 = 0.125.  
cela nous permet de représenter un nombre entre 1 et 2  

voici comment ce lit cette valeur de 32 bit:

**signe**----**exposant**------**mantisse**  
0-----------01011001-----10110110111000101001100111011001  

Ce qui est un peu embêtant c'est qu'en tant qu'human quand on représente le nombre sous forme factoriel on place l'exposant à droite et la mantisse à gauche alors que dans le code binaire la mantisse et à droite et l'exposant à gauche:  

$$
+/-  mantisse \times 2^{exposant}
$$  


Cette théorie contient quelques erreurs afin de ne pas trop compliquer le tout. en fait les bits réservés à l'exposant vont de -126 à 127 car les extrémités sont réservés pour des cas spécial et le premier bit de la mantisse qui vaut 1 est implicite. on ne le compte pas, de cette manière le 1er bit vaut 0.5. La mantisse représente un nombre entre 1 et presque 2, sans jamais atteindre 2.  

Dans notre exemple on a:  
  
+ pour le signe  
89 pour l'exposant, attention il faut soustraire 127. (on dit qu'on a un biais de 127) donc -38
La mantisse est normalisé, il y a un 1 implicite devant le tout, donc on a 1.10110110111000101001100 qui vaut 1.710093

$$
+  1.71093 \times 2^{-38} = 0.0000000000062
$$  

🎥 Vidéo explicative : [Comprendre les nombres flottants en IEEE 754 (YouTube)](https://www.youtube.com/watch?v=bbkcEiUjehk&list=TLPQMTMwNDIwMjXK1hjTbdUZMA&index=3)





## 4 types de languages

- Langage compilé vers du code machine  
> Le code est compilé directement en instructions machine, prêtes à être exécutées par le CPU.  
> + ultra rapide  
> - peu transportable
> C, C++, Rust, Go   

- language interprété  
> Le code source est lu ligne par ligne et exécuté directement par un interpréteur sans compilation  
> + facile à tester et modifier rapidement  
> - moins rapide, car 1 instruction génère 1 instruction, une loop va générer beaucoup d'instruction  
> Python, JavaScript, Ruby, PHP
  
- Langage compilé vers du bytecode  
> Le code est compilé en bytecode, un format intermédiaire qui sera ensuite interprété ou exécuté par une machine virtuelle.  
> + portabilité d'un système à un autre  
> - besoin d'une machine virtuelle
> Java, C#, Python, Lua  

- Langage transpileur
> le code est transformé vers un autre language de programmation.