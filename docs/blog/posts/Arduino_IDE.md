---
date:
  created: 2025-03-09
categories:
  - Logiciels
tags:
  - Logiciel
authors:
  - thomas
slug: Arduino IDE
---

# Arduino IDE set up et utilisatoin 
Initialisation de l'environnement de développement intégré Arduino pour notre ESP32 s3


<!-- more -->

## Set up   

Une fois l'[arduino IDE](https://www.arduino.cc/en/software) téléchargé, il va falloir lui indiquer quel modèle de microcontrôleur on utilise. On est sur un ESP32 S3. 
La nommination correcte est: carte de dévellopement - board - produite par Lolin intégrant un microcontrôleur dévellopé par espressif. 

Il faut télécharger les bibliothèques nécessaires à l'ESP32.  
File -> préférences -> https://dl.espressif.com/dl/package_esp32_index.json
![télécharger les librairies](mkdocs/board_manager_url.png)  
installer ESP32 by espressif system  
![choisir la librairie à installer](mkdocs/board_manager.png)  
puis dans tool -> board chercher notre modèle d'ESP32, ici le S3 de Lolin  
![Liste des pin du S3](mkdocs/board_selection.png)  
⚠️Reste à lui indiquer le port.  
tool -> port -> 
![Selection du port](mkdocs/port.png)    
On écrit notre code, ici on défini qu'on travaille avec la pin 4 et qu'on va allumer 500 ms puis éteindre 100ms en boucle  
![Selection du port](mkdocs/programme_clignoter_led.png)    
reste à uploader le code. Pour ça il est important de brancher l'ESP32 avec l'USB-C du bas. et de cliquer l'icône avec la flêche.  
![Upload du programme](mkdocs/Upload_code_arduino_ide.png)

## Pin ESP32  
sur le site wemos on retrouve les spécification techniques de tous les modèles d'ESP32

![Liste des pin du S3](mkdocs/ESP32_schema_pin.jpg)  
