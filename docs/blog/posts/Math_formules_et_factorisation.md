---
date:
  created: 2025-04-18
categories:
  - Math
tags:
  - Math
authors:
  - thomas
slug: math_factorisation
---

# Math, formules et factorisation
La factorisation les identités remarquables et quelques méthodes mathématiques permettent de ré-écrire les équations afin de se simplifier la vie et les rendre plus lisibles


<!-- more -->

## Division et puissance négatives
Contrairement aux multiplication, l'ordre dans lequel on effectue les division à son importance. Avant de foir les méthodes de simplification et conversion, nous aurons besoins de quelques "outils".

Puissances négatives
$$
x^{-1} = \frac{1}{x^{1}}
$$
  
$$
x^{-2} = \frac{1}{x^{2}}
$$

> cela signifie qu’une multiplication par une puissance négative revient à diviser par la puissance correspondante.  on peut donc passer des divisions aux multiplication et vice versa  
  

Multiplication par 0.xxx

$$
x \times 0.1 = x \times 10^{-1} = x \times \frac{1}{10^{1}} = \frac{x}{10}
$$

> 0.1 revient à écrire 10^-1

## double division
contrairement aux multiplication, les divisions ne sont pas commutatives. L'ordre a son importance.
J'attire votre attention sur la longueur de la barre de division.

$$
\frac{a}{\frac{b}{c}} =  a \times \frac{c}{b} = \frac {a \times c}{b}
$$

$$
\frac{\frac{a}{b}}{c}  = \frac{a}{b} \times \frac{1}{c} =  \frac{a}{b \times c}
$$

> divisier par une fraction revient à multiplier par son inverse

## factorielle

la factorielle c'est multiplier un nombre par chaque membre de la suite de nombre allant de 1 au nombre en question. 
Elle se note n!   
  
3! = 1 * 2 * 3  
voici la version dévelloppée :  
fact(3) = 3 * fact(2)   
fact(2) = 2 * fact(1)  
fact(1) = 1 * fact(0)  
fact(0) = 1  

l'on peut l'écrire **fact(n)** où **n!**  
c'est une fonction **récursive** (= qui s'appelle elle même) car fact(n) = n * fact(n-1) on déclare la factorielle avec la factorielle. fact(n-1) = n-1 * fact(n-1-1) puis fact(n-1-1) = n-1-1 * fact(n-1-1-1).  
Quand s'arrêter ? lorsqu'on atteint fact(0), 0! = 1
La factorielle augmente plus vite que les puissances.

