---
date:
  created: 2025-02-22
categories:
  - C++
  - Informatique
tags:
  - c++
authors:
  - thomas
slug: c++
---

# C++ 

Cet article explique les différents éléments du language C++  

<!-- more -->

## vocabulaire

**classe** = blueprint permettant de créer des objets.  
**objet** = instance d'une classe.  
**méthode** = fonction d'une classe.  
**attribut** = variable dans une classe.  
**constructeur** = méthode d'une classe instanciant un objet.  
  
**variable globale** = une variable déclaré à l'extérieur d'une classe où fonction. Utilisable partout dans le code cpp (mais seulement le fichier cpp où elle est déclarée). Stocké dans data. Stocké dans bss si non initialisée.    
**variable locale** = une variable déclarée dans une fonction. Elle n'existe pas en dehors de la fonction. Lorsque la fonction se termine elle est détruite.  
**variable globale static** = visible que dans le fichier cpp où elle est déclarée.  
**variable locale static** = n'est pas stocké dans la stack mais avec les variables globales. Elle est **visible que dans la fonction dans laquelle elle est déclarée**. Conserve sa valeur entre deux appels.   
**variable dynamique** = crée quand on appelle quelquechose avec **new**. n'existe pas à la compilation, sera cére lors de l'execution du code. Stocké dans la **Heap**, n'est pas effacée automatiquement, il faut appeller un delete pour l'effacer. 

## les 3 "etats" d'une fonction
**déclaration** = dit au compileur quelles fonctions, variable et classes existent. quand on déclare une classe on déclare également ses méthodes et attributs à l'intérieur  
**definition** = donne le corps de la fonctions et méthodes (ce qu'elles font). La définition peut être contenue dans la déclaration mais ça prend de la place donc généralement onf fait une définition hors de la déclaration.   
**appel** = exécute les fonctions. On peut appeler plusieurs fois la même fonction.  
  
exemple:  
```cpp
int add(int a, int b);   // Déclaration (prototype)

int add(int a, int b) {  // Définition
    return a + b;
}

int main() {
    cout << add(2, 3);   // Appel
}

```

## ⚠️ Attention à ne pas confondre  

|  **nom**   | **def** | **exemple** | 
|--------------|----------------------------|----------------------------------------------------------|
| **variablee**  | ce qui contient une valeur | int x = 5; |
| **parametre** | variable locale qui permet à une fonction de recevoir une donnée externe. elle est déclarée dans la signature de la fonction | calculateTax(float localImposition);  |  
| **parametre** | variable passées à la fonction lors de son appel | calculateTax(1.7); |  
| **attribut** | variable d'une class |    |
  
##⚠️ Static dans une fonction VS dans une classe.

| Fonction                                      | Classe                                         |
|----------------------------------------------|------------------------------------------------|
| Conserve la valeur entre les appels          | Partagé entre toutes les instances             |
| N'est initialisée qu'une seule fois          | Peut être accédé sans objet : Classe::membre   |
| Est locale en visibilité, globale en durée de vie | Partage la même valeur pour tous les objets |

##⚠️ Static VS const.
une variable static est initialisé une fois mais peut changer de valeur en fonction des opération qu'on lui fait subir. Elle n'est pas réinitialisée d'un appel à l'autre, c'est à dire qu'elle garde en mémoire sa valeur.  
à l'inverse une variable const ne peut être changée et sa valeur n'est pas conservée entre deux appels


```cpp
int counter(int number) {
    static int count = number;
    count++;
    return count;
}

main() {
  counter(4); // 5
  counter(99); // 6. car on ne peut pas initialiser 2x une var static
}
```
>Lors du premier appel, count est initialisé avec number (ex: 4), puis incrémenté à 5.  
Lors du deuxième appel, la ligne static int count = number; n’est pas réévaluée, donc number est ignoré, et count continue depuis sa dernière valeur (5), donc devient 6.
```cpp
int counter(int number) {
    const int count = number;
    count++; // ❌ erreur on ne peut pas modifier une variable const
    return count;
}

main() {
  counter(4); // ❌ erreur de compilation
  counter(99); // ❌ erreur de compilation
}
```

```cpp
int counter(int number) {
    const int count = number;
    return count + 3;
}

main() {
  counter(4); // 7
  counter(99); // 102
}
```

##🔎 différentes formes du constructeur

**constructeur local**:  
```cpp
class Animal {      // <-- Class 
public:             // <-- Access modifier
    int legs;       // <-- Attribute

    Animal(int l) { // <-- Constructor (same name as class, NO return type!)
        legs = l;
    }

    void roar() {   // <-- Method
        // Some code here to roar
    }
};

Animal monkey(4);   // <-- Object 'monkey' created with 4 legs
```  

**constructur hors classe**:  
Pour ne pas surcharger la déclaration d'une classe on peut définir sont constructeur en dehors. (Attention la déclaration de classe possède bien une déclaration de constructeur mais pas de définition de constructeur)  

```cpp
// Declaration inside the header or class  

class Stepper {
public:
    Stepper(); // Constructor declared but not defined !!
    void stepForward(); // Method declared
};
```
et on va la définir **en dehors de la classe**. pour se faire on utilise Stepper::Stepper() qui se lit (de droite à gauche) "c'est le constructeur Stepper() de la classe Stepper"

```cpp
// In the .cpp file:  

Stepper::Stepper() { // Constructor defined outside class
    // Constructor code here
}

void Stepper::stepForward() {
    // Method code here
}

```



**ce qui me perturbe c'est qu'on doit utiliser le nom de la class pour nommer le constructeur (dans sa déclaration) mais on utilise le nom que l'on veux lorsque on l'utilise ex:
Animal(int leg); //déclaration interne
Animal::Animal(int leg); //déclaration externe

Monkey(4); // création d'objet Monkey
Animal::Monkey(4)// création d'objet Monkey. -> je suis perdu es-ce que c'est juste ? quelle est la diférence

aussi les constructeur des classes sont ils utilisés pour créer des classes filles ?
les objets héritent ils des attributs et méthodes de la classe ?
et static dans tout ça ? dans une fonction c'est un mot clé pour appeler la variable que une fois je crois. dans les class c'est un attribut partagé par toutes les instances de la classe (donc les objets ?)**

##⚠️ Héritage   

|  **Visibilité**   | **Accessibilité par classe fille ?** | **Accessible de l'extérieur ?** | 
|--------------|----------------------------|----------------------------------------------------------|
| **public**  | oui | oui | 
| **protected** | non | non |  
| **private** | non | non |  

##🔎 Is-a VS Has-a

On utilise la question **is-a** / **has-a** pour savoir si une classe hérite d'une autre classe où possède une autre classe ou un objet d'une autre classe ??  

Is-a:
```cpp
class Vehicle {
    // common properties like speed, fuel, etc.
};

class Car : public Vehicle { //création d'une classe fille d'une autre classe
    // Car is-a vehicule because Car inherits everything from Vehicle 
};
```    
  
Has-a:
```cpp
class Engine {
    // Engine details
};

class Car {
public:
    Engine engine; // Car "has a" Engine
}; 
``` 
> attention c'est bien écrit sur 2 lignes  
>public:  //spécificateur d'accès  
>Engine engine;  
>et pas public: Engine engine;

## utilisation de la mémoire
Après compilation, le programme est stocké dans 3 zones de la mémoire:  

**data** = les variables globales initialisées  
**BSS** (block start by symbol) = les variables globales non initialisées où = à 0.   
ex:int speed;  
**RO**(read only) = les variables constantes (celles qui ont le mot clé **const** et ne peuvent être modifées).
Il y a aussi deux zones dynamiques qui se remplissent et se vident en fonction des besoins, c'est la **stack** et la **heap**. toutes les variables qui seront crées localement par des fonctions viendront dans la **stack**, les variables dynamiques créées avec new iront dans la **heap**.


  ![zone mémoire](mkdocs/memory_adresse.png)

La zone text contient le code compilé du programme, en lecture seule.

## Stack - Heap
  
La stack et la heap occupent et se partagent le reste de la mémoire, il n'y a pas 50% réservé pour la stack et 50% pour la heap, c'est en fonction de nos besoin. on peut se retrouver dans une situation où 80% c'est de la stack et 20% de la heap. Si on a trop de variables locale on peut se retrouver en stack overflow, c'est qu'on a plus de place pour les variables locales.
La **Stack** se remplie du haut vers le bas, il faut imaginer ça comme une pile de livre dont on peut retirer que le livre au sommet de la pile. Ainsi la 1ère variable que l'on entre sera la dernière que l'on sort. A contratio, la dernière variable ajoutée est la plus accessible, on dit **LIFO** "last in first out".

Chaque appelle de fonction vient remplir la stack avec ses variables locales. Chaque fonction terminé enlève les variables grâce au mot clé **return**.

## fonctions

Ce qui est important de savoir c'est **où la variable est stockée** et **où la variable est visible**

## class et objets synthaxe
on utilise le type class pour créer une classe. on lui donne le nom qu'on veut.
```cpp
class Animal {
public:
    int pattes;
    
    Animal(int p) {  // <-- constructeur avec argument
        pattes = p;
    }
};
```
```cpp
Animal Singe(4);  // Construction d'un objet Singe avec pattes = 4

```
> on a crée -on dit instancier- un objet nomé "Singe" à partir de la classe "Animal".  
> il hérite des méthode et attributs de son parent.

Dans ce cas le **constructeur** était défini **dans la classe**.   
Mais on peut aussi définir **le constructeur hors de la classe** pour gagner de la place. On définisse la classe dans le fichier .h et son constructeur dans le fichier .cpp:  
```cpp
Animal::Animal(int l){  //définition du constructeur hors déclaration
  legs = l;
}
```
Création de **classe** Monkey **à partir de la classe** Animal:
```cpp
class Monkey : public Animal {
  //méthodes et attributs aditionelles spécifiques à la classe Monkey
}; 
``` 
Ainsi Monkey hérite des méthodes et attributs de la classe animal tout en pouvant ajouter les méthodes et attributs spécifiques à sa classe  
>On pourrait créer une classe Monkey a partir de la class Animal et un objet Monkey à partir de la classe Animal mais ce n'est pas judicieux de leur donner le même nom, ça porte à confusion.  

exemple de création d'une classe à partir d'une classe (héritage) puis d'objet à partir de la classe fille. L'objet possède un attribut de la classe mère. le constructeur est un peu particulier
```cpp
class Animal {
public:
    Animal(int l) { legs = l; }
    int legs;
};

class Monkey : public Animal {
public:
    Monkey() : Animal(2) {} //constructeur référant le parant
};

Monkey george;  // george est un objet de la classe Monkey, qui hérite de Animal
```

on peut avoir un constructeur qui utilise le constructeur de la classe mère et initialise un attribut ou appelle une méthode spécifique à la classe fille:
```cpp 
  #include <iostream>
using namespace std;

class Animal {
public:
    int legs;

    Animal(int l) {
        legs = l;
        cout << "Animal created with " << legs << " legs\n";
    }
};

class Monkey : public Animal {
public:
    bool hasTail;

    // Constructeur de Monkey avec un paramètre
    Monkey(bool tail) : Animal(2) { // Appelle d'abord le constructeur Animal
        hasTail = tail;
        cout << "Monkey created with tail: " << (hasTail ? "yes" : "no") << "\n";

        // Appel d'une méthode de Monkey à la création
        speak();
    }

    void speak() {
        cout << "Ooh ooh aah aah!\n";
    }
};

int main() {
    Monkey george(true); // Création d’un objet de type Monkey avec queue
    return 0;
}
```