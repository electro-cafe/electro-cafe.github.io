---
date:
  created: 2025-03-09
categories:
  - Systeme de communication
tags:
  - Systeme de communication
authors:
  - thomas
slug: communication ESP32-composants
---

# ESP32 composants et communication
De quoi est composé l'ESP32 et comment fait elle pour échanger et recevoir des informations avec les composants, quels sont ils ?


<!-- more -->

## **Documentation**
liens vers la documentation : [ESP32 S3](https://www.espressif.com/sites/default/files/documentation/esp32-s3_datasheet_en.pdf?utm_source=chatgpt.com)

## **Langage binaire**

L’ESP32, comme tout microcontrôleur, fonctionne en langage binaire. Cela signifie qu'il ne comprend que des 0 et des 1, qui correspondent respectivement à des niveaux bas et hauts de tension électrique. Cette logique binaire est la base de la communication entre l’ESP32 et les composants électroniques connectés.

Les signaux binaires peuvent être envoyés sous différentes formes :

Numérique (digital) : soit un état haut (1), soit un état bas (0).

Analogique (PWM - Pulse Width Modulation) : un signal crénelé où la durée pendant laquelle le signal est haut ou bas permet de représenter des valeurs intermédiaires.

Un signal crénelé (ou signal PWM) est utilisé pour simuler une sortie analogique en modulant la durée des impulsions. Par exemple :

Si le signal est haut 80 % du temps, on considère que la valeur est 1.

Si le signal est haut 15 % du temps, on considère que la valeur est 0.  

En allumant 20ms puis éteignant 80ms une lumière on a l'impression qu'elle est allumée à 20%

## **Les bus de communication**

Pour échanger des informations avec des composants, l’ESP32 utilise des bus de communication. Ce sont des systèmes de transmission qui permettent l’échange de données entre le microcontrôleur et les périphériques connectés.

Types de bus courants

I2C (Inter-Integrated Circuit) : Utilisé pour connecter plusieurs composants avec seulement deux fils :

SDA (Serial Data Line) : pour envoyer et recevoir des données.

SCL (Serial Clock Line) : pour synchroniser l'envoi des données.

SPI (Serial Peripheral Interface) : Plus rapide que l'I2C, mais nécessite plus de fils.

UART (Universal Asynchronous Receiver-Transmitter) : Utilisé pour la communication série simple, comme entre un ordinateur et l'ESP32.

## **éléments de l'ESP 32** 

**Pin (ou broche) / GPIO** = Point de connexion physique sur le microcontrôleur. **G**eneral **P**urpose **I**nput **O**utput. Une pin peut être utilisée comme entrée (reçoit un signal), sortie (envoi un signal), ou pour des protocoles de communication spécifiques (ex. : I2C, SPI, UART, USB, etc.), selon la configuration choisie dans le code.  
👉 On se sert des pin pour piloter un composant, lire un composant, communiquer avec un capteur etc...   
Certaines GPIO ne sont sont **pas vraiment libres** : elles ont un rôle spécial.    

**Strapping pins** -> utilisées au démarrages, si on les utilise, l'ESP **ne peut plus démarrer correctement**  
**Flash** et **PSRAM** -> le CPU de l'esp32 ne contient pas le code, ce qu'il fait c'est executer le code (programme) stocké dans la mémoire flash, une puce mémoire soudé sur le PCB de l'ESP. Le CPU reçoit et envoi des signaux via les GPIO. Le GPIO Flash ne nous est pas disponible. PSRAM = mémoire volatile (perdue à l'extinction), contient les variables dynamiques (heap), les buffers (images, sons, etc), les gros tableaux ou objets et données en cours d’exécution. comme pour la flash il s'agit d'une puce mémoire soudé sur le PCB L'esp32 y accède via un bus SPI utilisant 4 fils (Quad SPI) ou 8 fils (Octal SPI).  
**UART**, **RX** et **TX** -> utilisé pour envoyer et recevoir des message entre l'ESP et un PC où une autre puce. RX = reçoit. TX = transmet.  
**USB** -> réservé pour communiquer directement en USB (Universal serial bus).  
**JTAG** -> utilisé par les développeurs pour analyser le code en temps réel, poser des points d'arrêt, lire la mémoire, etc... Doit être laissé libre si on compte déboguer le programme avec un outil externe.    
**I2C** -> réservé pour parler à plusieurs capteur et/ou périphérique via protocole. utilise 2 fils donc 2 pins: **SDA**(données) et **SCL**(horloge).

**GPIO (General Purpose Input/Output)** = Broche d'entrée/sortie à usage général. Les GPIO permettent à un microcontrôleur comme l’ESP32 de lire des signaux (en entrée) ou de contrôler des composants (en sortie). Chaque GPIO peut souvent être configuré pour différentes fonctions selon les besoins du projet.  
👉 Lorsqu'une pin est configurée comme GPIO, elle devient une interface directe entre le monde extérieur et le CPU du microcontrôleur.

Schéma représentant le liens entre pin et fonction  
![schéma pin fonction ](mkdocs/pin_functions.png)    

Schéma **pinout** détaillant les différentes fonctions disponibles sur les pins
![schéma pin ESP32 S3](mkdocs/ESP32_pinout.png)  

Il faut éviter les **strapping pin** ainsi que celles dédiées à la **mémoire**. À moins qu'on aie pas de bus de communication il faut éviter les pin **UART, I2C et RX - TX**
ici la doc pour l'esp32 S3 mini nous indique les [strapping pin](https://docs.espressif.com/projects/esp-idf/en/stable/esp32s3/api-reference/peripherals/gpio.html).


**CPU (Central Processing Unit)** = Le cœur du microcontrôleur, chargé d'exécuter les instructions du programme. Il communique avec des périphériques internes (minuteries, convertisseurs analogiques-numériques, UART...) ainsi qu’avec des périphériques externes via les pins configurées.  
👉 C’est lui qui pilote les GPIO, lit les capteurs, traite les données et prend les décisions.  



## **Connexion avec l’ESP32**

L’ESP32 envoie un signal PWM sur la broche Din de la LED pour modifier sa couleur. Voici un exemple de code pour allumer la LED en rouge, puis la faire passer au bleu :

```cpp
#include <Adafruit_NeoPixel.h>

#define LED_PIN 4  // GPIO où la LED est connectée  
#define NUM_LEDS 1 // Nombre de LED

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Éteindre les LED au démarrage
}

void loop() {
  strip.setPixelColor(0, strip.Color(255, 0, 0)); // Rouge
  strip.show();
  delay(1000);
  strip.setPixelColor(0, strip.Color(0, 0, 255)); // Bleu
  strip.show();
  delay(1000);
}
```

Dans cet exemple :

La LED est connectée au GPIO4.

La couleur est définie par une combinaison de valeurs Rouge (R), Vert (G) et Bleu (B).

La fonction setPixelColor() permet de modifier la couleur de la LED.

L’ESP32 envoie un signal binaire sous forme de pulses électriques pour commander les couleurs de la LED via le bus de communication.



