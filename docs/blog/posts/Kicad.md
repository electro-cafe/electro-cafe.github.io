---
date:
  created: 2025-05-19
categories:
  - Logiciels
tags:
  - Logiciels
authors:
  - thomas
slug: software_Kikad 
---

# Kicad

Prise en main de Kicad.  

<!-- more -->

## menu principale  

On retrouve:    

- **Editeur de Schéma** = la visualisation théorique de notre système  
- **Editeur de Symbole** = création d'éléments à intégrer au Schéma lorsqu'ils n'existent pas dans la bibliothèque du soft  
- **Editeur de PCB KiCad** = édition du circuit imprimé reliant les composants
- **Editeur d'empreinte** = délimitation des footprint des composants et paramètrage de leur propriétés
- **Editeur de fichier Gerber** = ?? Les fichiers Gerber sont les fichiers d'export utiles au fabricant
- **Convertisseur d'Image** = permet de passer une image en composant schématique pour l'intégrer au PCB (décoration)
- **Gestionnaire de Plugin** = sert à installer les extensions    

![Kicad_main_Menu](mkdocs/Kicad_main_Menu.png) 

## Editeur de Schéma  

C'est ici que l'on dessine le schéma de notre PCB, on ajoute les composants et indique comment ils sont reliés entre eux.    
Pour commencer on peut choisir le format de notre plan (A4 / A3 / ...) et son titre dans **fichier**-> **Ajustage page**  

![Kicad_main_Menu](mkdocs/Kicad_format_titre_page.png)     
![Kicad_main_Menu](mkdocs/Kicad_Ajustage_page.png)  


SHORTCUT:    
**esc** = outil sélection de base.
**box select** gauche à droite = sélectionne les objets complètement sélectionnés.  
**box select** droite à gauche = sélectionne les objets partiellements sélectionnés.    
**ctrl** + **left clic**= toggle selection state.  
**shift** + **left clic** = add to selection.  
**ctrl** + **left clic** = remove from selection.  
**ctrl** + **F1** = Affiche la liste des raccourcis.    
**mouse over component** + **m** = move component sans les wires.
**mouse over component** + **g** = move component avec les wires.
**r** = rotate component.  
**w** = switch to wiring mode.  
En wiring mode : **double clic** = finish drawing (!esc = cancel drawing)

EMPREINTE / FOOTPRINT  
Avec un **double clic sur un composant**, on défini leur propriété et charge leur empreinte.
L'empreinte détermine comment le robo qui va crée notre PCB doit préparer les zone sur lesquelles il va souder les composants. Elles contiennent les "cooper pads" qui matchent avec les pins du composant. 
![Kicad_main_Menu](mkdocs/Kicad_Propriete_Symbol.png)   

On peut aussi utiliser l'éditeur d'empreinte et ses filtres.  
Au milieu nos composant, à droite les empreintes dispo selon filtres.
![alt text](mkdocs/Kicad_assigner_empreinte.png)

L'outil **trace** et bus permettent de réaliser les connexions.  

![Kicad trace](mkdocs/Kicad_trace.png)    
 
Icone **non connexion**    


![Kicad_main_Menu](mkdocs/Kicad_pin_unused.png)   
Afin d'éviter d'avoir des connexions partout comme ci dessous voir pire, on utilise les labels paramétrés en entrée et sortie.
![Kicad wire](mkdocs/Kicad_wire.png)      
Quand on double clic sur un **label** on peut **choisir** si il s'agit d'une **entrée** ou d'une **sortie**  
![Kicad label](mkdocs/label_entree.png)    
Attention à ne pas se faire avoir. ce n'est pas le sens de la flèche qui détermine si c'est une entrée où une sortie mais si elle est relié par sa tête où son pied
![Kicad label](mkdocs/Kicad_label_IO.png)    
Les **entrées et sorties ayant le même nom sont connectées entre elles**.   
![Kicad label](mkdocs/Kicad_label.png)   
Une sortie peut être connectée à plusieurs entrées mais plusieurs sorties ne peuvent pas être conectés à une entrée.  
![Kicad label](mkdocs/regle_entree_sortie.png)   

  Lorsque l'on veut réaliser le schéma d'un élément comportant plusieurs composants on risque de ne pas le trouver dans la librairie. Il faut alors placer chaque composant pour le recréer.  
  Ici en exemple le driver des moteurs dont il faut lire la documentation pour découvrir qu'il est composé d'un chip ULN2003 et d'un connecteur JST (on a déterminé le modèle grâce au pitch = espace entre les connexions). Dans cet exemple on a pas gardé les led et leurs resistances, on en a pas besoin.  
![Kicad label](mkdocs/Driveur_moteur.png)    
  Mais juste voir le composant, bien que permettant de déterminer quellques indices sur les composants n'est pas suffisant. Il faut chercher des schéma du module. le mot clé dans la recharche google c'est le **nom du module + schematic**
![alt text](mkdocs/driver_moteur_schematic.png)

Pour se simplifier la vie au niveau des connections du GND et de l'alimentation on utilise les symboles GND et VCC, ça permet de rendre le schéma plus lisible car on a moins de conexions partout.
![alt text](mkdocs/Kicad_symbole_alimentation.png)  
![alt text](mkdocs/Kicad_Symbole_GND.png)  
Exemple schéma symboles placés:
![alt text](mkdocs/Kicad_GND_5v.png)    

Controle des règles électriques afin de savoir si il y a des erreurs.    
![alt text](mkdocs/Kicad_control_regle_electrique.png)    
//////Il reste à définir les zones d'exclusion autour des pin, ce sont des zones où aucun autre composant ne doit être placé. ces zones seront fait decuivre et serviront de base pour souder le composant.  

Une fois les zones symboles en place, les connexions effectuées, il faut trouver chaque composant sur le site [JLC PCB part](https://jlcpcb.com/parts/all-electronic-components) où [LCSC],(https://lcsc.com/) récupérer le numéro d'article et son package (=footprint/empreinte) afin de terminer la partie schématique. Ces deux site appartiennent au producteur de PCB à qui l'on va fournir les fichiers finaux. Il récupérera les composants dans ces stocks, les souderas sur le PCB et créera le circuit imprimé reliant les composants. 

Afin de trouver notre pièce il faut indiquer son type puis utiliser les nombreux filtre pour faire apparaître que les pièces qui nous intéressent. c'est fastidieux, suivant quoi il faut consulter des doc où mesurer pour avoir plus d'infos à entrer dans les filtres. Voici quelques termes afin de mieux s'y retrouver dans la nomenclature des composants.

VOC:    
**SMD - SMT** = surface mount. Pin soudé sur PCB.  
**TH - THT** = through hole. Pin traversante.  
**DIP** = Dual inline package / 2x TH.  
**AWG** American wire gauge, système de mesure de diamètre de câble.  
**V** = vertical.  
**R - RA** = horizontal / right angle.    

 ![alt text](mkdocs/JLC_PCB_search_1.png) 

filtre:
![alt text](mkdocs/JLCPCB_filtre.png) 


nr part et package.
![alt text](mkdocs/JLC_PCB_Part.png) 

Il faut maintenant ajouter ces 2 infos dans le symbol. Pour ce faire on double clique sur le composant pour faire apparaître l'éditeur de sympole et clique sur le **+** pour ajouter un champ qu'on nomme **LCSC** et on y met le **JLCPCB part #**. Dans **empreinte** on entre ce qu'on a trouvé comme **Package**   
![alt text](mkdocs/Kicad_LCSC_nr.png) 
  

Après avoir déplacé des symboles, leur nom (U1, U2, etc) ne sont plus dans un ordre logique et ça peut compliquer notre compréhension du schéma. On peut **renommer les composants dans l'ordre** dans **outils** -> **annotation de la schématique**
![alt text](mkdocs/Kicad_anotation_schematique.png)
On choisi si on trie de gauche à droite où haut en bas dans la section ordre.
![alt text](mkdocs/Kicad_anotation_schematique_2.png)   


BILL OF MATERIALS  
c'est notre liste de course, abrégé **BOM** ça dit au fabricant du PCB quels composant prendre dans ses stock.  
![alt text](mkdocs/Kicad_BOM.png)      

On peut voir plus modifier les préférence de la BOM dans l'onglet Editer. Cliquer sur exporter pour créer le fichier.
![alt text](mkdocs/Kicad_BOM_detail.png)      

Pour **visualiser la BOM** et changer les propiétés des éléments, on utilise l'**icône de spreadsheet** (nommée éditer champs des symboles) on a aussi la possibilité d'**exclure de la BOM**:
![alt text](mkdocs/Kicad_vue_composants.png)   
 
On peut aussi exclure un élément de la BOM en doublecliquant sur son symbol dans le schématic.
![alt text](mkdocs/Kicad_exclure_BOM.png)      
 

##   Editeur de PCB

C'est ici que l'on va définir la taille du PCB, définir l'emplacement des composants et relier les composants entre eux via les pistes (tracks en anglais).
accessible soit depuis le menu principale, soit depuis l'éditeur de schématique avec l'icone verte
> - fig 1
![alt text](mkdocs/Kicad_editeur_PCB.png) 
    
      
> - fig 2  
![alt text](mkdocs/Kicad_editeur_PCB_2.png) 

SHORTCUT:    

**x** = outil trace.  
**alt** + **3** = visu 3D  
**f** = flip component to the opposite side of PCB
**v** = insert un via   

VOCABULAIRE / ABREVIATION:  
  
**f.Cu** = Front Cooper -> face sup du PCB.  
**B.Cu** = Back Cooper -> face inf du PCB. 
**Ratsnest** = ligne bleu indiquant les connexion du schématic que l'on a pas encore tracé sur le PCB.  
**Through hole pad** = trous conducteur faisant partie de l'empreinte et permettant de connecté le dessus et le dessous du PCB.  
**Via** = trous conducteur permettant de connecté le dessus et le dessous du PCB.


Avant toute chose on va définir le format de la page: **File** -> **Page Settings/Ajustage page**.
Puis les caractéristiques (nbr couches) de notre PCB: **File** -> **Board Setup/Option du CI** -> **Couchess Physiques**. C'est ici qu'on défini le stackup = empilement de couches de PCB. On va en mettre 4, celles du haut et du bas sont pour les composants. On va mettre une masse GND et power sur les 2 du milieu.  
![alt text](mkdocs/Kicad_PCB_layer.png)

On va sélectionner le layer juste sous la couche supérieur.  
![kicad layer interne pcb](mkdocs/Kicad_layer_interne.png)  

Puis l'outil de traçage de zone remplie  
![kicad layer interne pcb](mkdocs/Kicad_zone_remplie.png)

au 1er clic une fenêtre s'ouvre et nous demande de choisir ce que la zone représentera. ici GND  
![kicad layer interne pcb](mkdocs/Kicad_option_zone_remplie.png)

Une fois le tracé dessiné il faut encore le remplir car il est vide. On utilise soit **b** soit **edition**->**remplissage des zones**
![kicad layer interne pcb](mkdocs/Kicad_fill_zone.png)
![kicad layer interne pcb](mkdocs/Kicad_remplissage_des_zones.png)

C'est un outil intéligent qui va éviter le contact avec les track de cuivre si il y en a sur la zone. à chaque mise à jour du schématic ou des tracé il faut utiliser **b** pour mettre à jour les zones remplies. 
Ici comme notre zone GND occupe tout notre 2ème layer. le but c'est d'utiliser des via pour créer le contact avec le GND. ça permet une optimisation de place sur les couches dédiées aux composants. Pour **établir la connexion des via** à la zone GND, **double clic sur le via**, et sélectionner GND où 5V dans le **dropdown Net name**. Une fois de plus, à chaque modification il faut faire **b** pour mettre à jour la zone remplie. Comme on le voit ici, le via est connecté.
![kicad layer interne pcb](mkdocs/Kicad_Via_connexion.png)

C'est également là qu'on pourra définir les **Net Classes** où règle d'Equipots en français, ce sont des groupes de réseaux de signaux qui peuvent être associés à des règles de conception spécifiques, comme la largeur de piste ou l'espacement entre pistes.

Overview des outils et fonctionalités.  
Il faut plus voir les calques comme des filtres, les différentes couches du PCB sont dans objet (voir plus bas "Issue"). 
![alt text](mkdocs/Kicad_editeur_PCB_overview.png)   

Pour l'instant on a que les composants et leur footprint. Pour **ajouter le PCB** il faut le dessiner dans le **calque Edge.Cuts**
Avec l'outil rectangle on dessine son contour. si on double clic avec la flèche noir sur le rectangle on peut définir précisément sa taille
![alt text](mkdocs/Kicad_editeur_PCB_draw_PCB.png)   

On peut changer la **snap grid** pour que les éléments soient magnétisés différement au fond
![alt text](mkdocs/Kicad_editeur_PCB_Snap_Grid.png)   

Comme on se trouve sur une **surface composée de plusieurs couches**, on peut déterminer sur laquelle notre piste où portion de notre piste va passer. Lors du dessin de la piste faire un clic droit où presser **v**  
![alt text](mkdocs/Kicad_editeur_PCB_trace_layer.png)  
  
Un objet placé sur le **dessus** est généralement **rouge**, il est **bleu** lorsqu'il est placé en **dessous** du PCB.  
![alt text](mkdocs/Kicade_up_down.png) 

Il est temps de relier les pads des différents composants qui doivent être connectés entre eux. Tant qu'il y a des ratsnest c'est qu'il y a des connexion à faire. On peut voir en bas à droite des stat intéressantes à ce sujet:  
![alt text](mkdocs/Kicad_stat.png) 
Utiliser l'outil pour rellier les composants avec une piste conductrice.   
![alt text](mkdocs/Kicad_route_piste_tool.png) 

Il est important de configurer la **largeur des pistes**. Une fois de plus on se rend dans **fichier** -> **Option du CI** -> **règles de conception** -> **taille prédéfinies**.  
Avec **w** on peut parcourir les différentes tailles de pistes.  
On utilise **0.4** pour les connexion **signal** et **0.7** pour l'**alimentation**.
![alt track size](mkdocs/Kicad_taille_predefinies.png) 
![alt track size](mkdocs/Kicad_track_size.png) 


Afin de s'assurer que tout est en ordre, un peu comme pour le schématique on peut utiliser l'outil de vérification (Design rule chechink aka DRC):  
![alt text](mkdocs/Kicad_design_rule_checking.png)
Cette option est aussi accessible sous **Inspecter**->**Contrôle des règles de conception**

Mon projet est synchronisé sur Github, afin de pousser la version local sur git il faut qu'elle passe les **github actions** que l'on a définies. Cela permet d'agir comme un filtre et de bloquer la synchronisation de fichiers non valides sur git. Pour ce faire le dossier doit contenir des dossier **.rpt**, il s'agit de rapport d'erreur du DRC et de l'ERC.
![alt text](mkdocs/Kicad_save_rpt_file.png)

On peut avoir un aperçu de notre PCB en 3D avec **affichage** -> **visu 3D**

Une fois le PCB termnié on va **générer le fichier Gerber** 
![alt text](mkdocs/Kicad_editeur_PCB_generate_Gerber_file.png)  
Ensuite il faut cliquer sur **plot** et **Generate Drill Files** -> **Generate Drill Files** puis **close**. On vient de créer les instruction de manufacture de notre PCB.

Avec les différents calques, les différentes couches et tous les symboles il peut être difficile de sélectionner ce que l'on veut. Pour ça il y a les **filtres de sélection** en bas à droite.
![alt text](mkdocs/Kicad_filtre.png)  


Issue: no component on PCB editor:
![alt text](mkdocs/Kicad_editeur_PCB_issue.png)  
Il faut activer la vue de la bonne couche du PCB:
![alt text](mkdocs/Kicad_editeur_PCB_level.png)    

## Ajout d'image
Dans l'onglet **convertisseur d'images** charger une image puis définir sa taille et l'enregistrer en tant qu'empreinte silkscreen (elle sera imprimé en blanc) et l'exporter.
![alt text](mkdocs/Kicad_image.png)    
Dans l'éditeur de projet, sous **préférences** -> **configurer les librairies d'Empreintes**, onglet **librairie spécifique au projet** on va charger le dossier dans lequel on a enregistré nos images.
![alt text](mkdocs/Kicad_charger_image.png)  
![alt text](mkdocs/Kicad_ajout_library_image.png)  
Pour importer l'image il faut utiliser l'outil symbole, chercher notre dossier d'image et placer l'image choisi comme n'importe quel symbol.  
![alt text](mkdocs/Kicad_empreinte_icon.png)   
![alt text](mkdocs/Kicad_custom_image.png)     

##   manage and control Gerber files

