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

# ESP IDF set up et utilisatoin 
Initialisation de l'environnement de développement intégré ESP


<!-- more -->

## Set up 
dans visual studio code, simplement installer l'extension ESP IDF
![extension ESP-IDF](mkdocs/ESP_IDF_extension.png)  

choisir le mode express
![extension ESP-IDF](mkdocs/ESP_IDF_installation_Express.png)  

Choisir le chemin où enregistrer les fichiers relatifs à ESP-IDF
![extension ESP-IDF](mkdocs/ESP_IDF_path.png)  

De mon côté ça ne fonctionnait pas encore et il a fallu encore localiser le fichier de commande **install.Bat** et l'exécuter pour réinstaller les dépendances.
![extension ESP-IDF](mkdocs/ESP_IDF_install_bat.png) 

## ouvrir terminal de commande
quand on utilise des commande dans la barre de recherche (palette de commande) il faut mettre > devant la commande. 
![extension ESP-IDF](mkdocs/ESP_IDF_commande.png)   
Si on utilise **ctrl** + **shift** + **p** ça met notre curseur dans la palette de commande pour que l'on puisse écrire notre commande, le > est déjà inclu.   
![extension ESP-IDF](mkdocs/ESP_IDF_ctrl_shift_p.png)     
il faut utiliser la commande **ESP-IDF: Open ESP-IDF Terminal** pour ouvrir le terminal ESP IDF.


## connexion à l'ESP 32
j'ai un ESP32 S3 mini, je le connecte au PC via le câble USB-C, il me faut connaitre son serial port, pour ce faire chercher Ports
![extension ESP-IDF](mkdocs/ESP_IDF_port.png)  

En bas de notre page on a les boutons pour ce qui est de compiler le code et le téléverser vers l'ESP.
On va choisir UART comme flash méthode, sélectioner le port, faire build et flash
![extension ESP-IDF](mkdocs/ESP_IDF_boutons.png)  
Afin de voir le code s'executer (ici un hello world qui tourne en boucle) il faut encore cliquer sur monitor device afin de le voir dans le terminal.  
![extension ESP-IDF](mkdocs/ESP_IDF_monitor_device.png)  
![extension ESP-IDF](mkdocs/ESP_IDF_code_running.png) 

## commandes
Les commandes idf.py sont disponible dans les répertoires (directories en anglais = dossiers) contenant un fichier CMakeList.txt  
On parle de CLI: Command Line Interface (Interface en ligne de commande), cela permet de se passer des menus et interface graphique.

>idf.py build -> revient à cliquer sur l'icone de clée à molette pour build le projet.  
>idf.py menuconfig -> configurer les paramètres système de l'ESP tel que la fréquence du tick (fréquence FreeRTOS)  
>idf.py update-dependencies -> met à jour le projet au niveau des dépendances.  
>idf.py create-project -> crée un nouveau projet ESP IDF.  
>idf.py create component -> crée un nouveau component.  
>idf.py set-target -> définir le type de processeur sur lequel on va flasher notre programme.

## ESP Registry
C'est un [site](https://components.espressif.com/) permettant de télécharger des bibliothèques pour faire fonctionner des composants comme les leds WS2812.
On peut aussi créer nos propres component et les partager sur ESP Registry.


## Récupérer un component sur ESP Registry et l'intégrer à un projet / Architecture dossiers
le code principale que l'on écrit se situe dans le dossier main.
Chaque composant sur ESP.Registry comprent une commande permettant de télécharger les fichiers dans notre dossier de projet au sein d'un sous-dossier nommé **managed_components**.  

Pour commencer il faut ouvrir le terminal ESP_IDF (ctrl + shift + p -> Open ESP IDF terminal) et y coller la commande du component que l'on souhaite ajouter au projet, récupérée d'ESP Registry. Autre manière: coller > + la commande du component dans la barre de recherche de Visual studio Code.  
![extension ESP-IDF](mkdocs/ESP_IDF_Registry.png)   
> comande à récupérer sur ESP Registry.


Par exemple: **idf.py add-dependency "supcik/status_led^2.0.0"** ça va créer un fichier idf.component.yml au sein du dossier main. le fichier .yml est comme une liste de course lisible/compréhensible par l'ordinateur et l'humain que CMake va interpréter pour télécharger les fichiers voulu lorsque l'on lance la commande **idf.py build**. Si le composant n'est pas ajouté on peut essayer **idf.py reconfigure** qui fait une sorte de refresh.



Résumé des actions de la commande prise sur esp-Registry et idf-py build:   

- créer le fichier .yml qui est une liste de ce dont on a besoin pour intégrer le Component.     

- CMake va traduire la liste pour qu'elle soit lisible par Ninja.    

- Ninja va compiler et executer les instructions.  

- les fichiers du component sont téléchargé dans le dossier managed_component  

J'ai été bloqué à cette étape, je n'avais pas de dossier managed_component. Le problème a pu etre résolu grâce à la commande **idf.py update-dependencies** qui a fait une sorte de rafraichissement, retéléchargé ce qui me manquais, mis à jour les fichiers.  
Attention: Lors de la création de mon projet de test ESP IDF "hello-world" j'ai du cocher une option qui m'a ajouté des component Arduino, ça complique les choses, j'en ai pas besoin pour le moment, j'efface le dossier arduino.

[Création de component et upload sur ESP-Registry](ESP_Registry_creation_de_component.md)

## Clang
Ce compilateur va nous permettre de changer la mise en page de notre code pour qu'elle respecte les règles d'indentation ainsi que nos préférences en matière de longueur de lignes etc. C'est possible car en plus d'être un compilateur il vient avec clang format, outil de formatage de text.
On va commencer par [télécharger Clang pour windows 64](https://github.com/llvm/llvm-project/releases/tag/llvmorg-18.1.8) puis **ajouter l'extension Clang** dans visual studio code, puis dans **file**->**préférences**->**extensions**->**C/C++**->**Formatting** choisir le formatage **clangFormat**.  
![extension ESP-IDF](mkdocs/clang_format_setting.png)   
Ensuite dans **file**->**preference**->**settings**->**save** cocher **format on save** pour qu'à chaque constrôle S, Clang corrige la mise en page.  
Enfin on ajoute un fichier .clang-format à la racine de notre dossier. Voici son contenu:  

```cpp
---
BasedOnStyle: Google
IndentWidth: 4    
---
Language: Cpp
ColumnLimit: 100
DerivePointerAlignment: false
PointerAlignment: Left
BinPackArguments: false
BinPackParameters: false
```



## FreeRTOS
Système d'exploitation temps réel intégré dans ESP-IDF. c'est l'acronyme de Real Time Operating System.
Permet de créer des tâches indépendentes qui vont dialoguer entre elles. Elles tournent en concurrences, c'est à dire que FreeRTOS gère le temps de processeur alloué à chaqu'une, ce qui donne une illusion de parallèlisme (temps réel). Exemple: la 1ère tâche à droit à 20 milisecondes de processeur avant qu'elle soit mise en pause et que la 2ème tâche ait à son tour droit à 20 milisecondes, si elle a besoin de moins elle passe la main dès la fin de ses opérations à la 3ème tâche. La plupart du temps les tâchent prennent moins de temps que le temps à disposition. elles passent donc la main.  
Le scheduleur (ordonnanceur en français) est la partie du programme qui décide quelle est la tâche qui tourne actuellement. Les tâches sont gérées dans une queue.
Le fait d'allouer du temps disponible par tâche est nommé système préemptif, c'est à dire que le système peut arrêter une tâche en cour pour passer à une autre. L'autre forme de système est nommé coopératif, une tâche bloque tout le monde tant qu'elle n'est pas terminé, ça à l'aventage d'être plus rapide dans certains cas mais l'inconvénient de ne pas pouvoir faire de temps réel.
Sur esp-idf le temps alloué par tâche est libre, ex: 1000 Herz, ça veux dire qu'une tâche dure 1'000ème de seconde, soit 1 miliseconde. Plus la valeur est élevé moins elle dure longtemps/plus elle la durée est courte.
On peut modifier cette valeur grace à la commande **idf.py menuconfig** -> Component config -> FreeRTOS -> Kernel    
Les ESP32 et ESP32-S3 ont un système dual core.

## tuto Arduino IDE    
Je me réfère à ce blog: [randomnerdtutorial FreeRTOS](https://randomnerdtutorials.com/esp32-freertos-arduino-tasks/)
TaskHandle_t MyTaskHandleName = NULL; = variable pointant vers une tâche FreeRTOS, nous permettant de controler (reprendre / stopper / effacer) la tâche. [Arduino IDE]
Les tâches  sont des fonctions de type void qui doivent avoir un unique argument (à ce moment ce n'est pas encore une tâche, il nous faudra appeller la fonction xTaskCreatePinnedToCore() avec un set d'argument définissant la tâche que l'on souhaite créer pour faire de notre fonction de type void une tâche). Dans la fonction on construit une loop infinie avec "for (;;) {xxxx}", dans cette loop on utilise "vTaskDelay(1000 / portTICK_PERIOD_MS);" pour introduire une pause si on le veut (ex led clignotante), cette pause n'est pas perdue, d'autres fonctions tourneront durant ce temps. Sur ESP-32 chaque tick dure typiquement 1ms (on utilise portTICK_PERIOD_MS). Dans notre exemple on a donc une pause d'un millième de seconde.
Pour que notre fonction soit effectivement une tâche il faut utiliser cette fonction: "xTaskCreatePinnedToCore()". Les arguments servent à décrire la tâche et à l'identifier.

xTaskCreatePinnedToCore(
  BlinkTask,      // Task function
  "BlinkTask",   // Task name
  10000,           // Stack size (bytes)
  NULL,            // Parameters.  Mettre ici le paramètre de la tâche, si elle n'en a pas mettre NULL
  1,                   // Priority.  Plus le nombre est grand plus la tâche est prioritaire.
  &BlinkTaskHandle,  // Task handle
  1                  // Core 1. le core sur lequel la tâche va tourner
);

On verra plus tard comment calculer la taille de la mémoir à attribuer à notre tâche.

Pour plusieurs tâche il suffit de créer une nouvelle tache et nouvelle TaskHandle_t et définire la nouvelle tâche comme on a fait avec la première. Rien d'autre.

## Mettre en pause et reprendre une tâche ex un bouton qui contrôle une tâche.

Il nous faut définir les **volatile varaibles**, elles seront utiles au **ISR** (interrupt service routine).

```cpp
// Volatile variables for ISR
volatile bool taskSuspended = false;  // bool déterminant si la tâche est suspendue
volatile uint32_t lastInterruptTime = 0; // track le temps depuis la dernière interuption
const uint32_t debounceDelay = 100; // debounce period, suivant les contact d'un bouton, il faut un petit moment pour être sur que le circuit est fermé ou ouvert
```  

la fonction buttonISR() va utiliser les volatile variable. Son rôle est de faire en sorte que le debounce time soit respecté, d'updater les volatile variable et d'appeler la fonction de suspention d'activité où de reprise d'activité.  On a ajouté **IRAM_ATTR** à la définition de la fonction pourqu'elle s'execute sur la RAM.   
On commence par attendre le délais défini par debounceDelay. une fois atteint on met à jour le lastInterruptTime et on inverse la valeur du boolean taskSuspended.
```cpp
void IRAM_ATTR buttonISR() {
  // Debounce
  uint32_t currentTime = millis();
  if (currentTime - lastInterruptTime < debounceDelay) {   // si le temps depuis la dernière interuption - le temps actuel est plus petit que debounceDelay quitte la fonction buttonISR car on va avoir des problème vu que le debounce n'est pas respecté (action du bouton plus rapide que le temps qu'il lui faut pour changer d'état)
    return;
  }
  lastInterruptTime = currentTime;   // met à jour le lastInteruptionTime

  // Toggle task state
  taskSuspended = !taskSuspended;  //change l'état du bool taskSuspended
  if (taskSuspended) {
    vTaskSuspend(BlinkTaskHandle);    //suspend la tâche. On utilise le taskHandle_t BlinkTaskHandle comme argument
    Serial.println("BlinkTask Suspended");
  } else {
    vTaskResume(BlinkTaskHandle);   //reprend la tâche
    Serial.println("BlinkTask Resumed");
  }
}
```
On défini également le bouton comme ceci dans setup()  [arduino IDE]: 

```cpp
attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), buttonISR, FALLING);
```

le tout ensemble ça donne ceci [Arduino IDE]:

```cpp
#define LED1_PIN 2
#define BUTTON_PIN 23

// Task handle
TaskHandle_t BlinkTaskHandle = NULL;

// Volatile variables for ISR
volatile bool taskSuspended = false;
volatile uint32_t lastInterruptTime = 0;
const uint32_t debounceDelay = 100; // debounce period

void IRAM_ATTR buttonISR() {
  // Debounce
  uint32_t currentTime = millis();
  if (currentTime - lastInterruptTime < debounceDelay) {
    return;
  }
  lastInterruptTime = currentTime;

  // Toggle task state
  taskSuspended = !taskSuspended;
  if (taskSuspended) {
    vTaskSuspend(BlinkTaskHandle);
    Serial.println("BlinkTask Suspended");
  } else {
    vTaskResume(BlinkTaskHandle);
    Serial.println("BlinkTask Resumed");
  }
}

void BlinkTask(void *parameter) {
  for (;;) { // Infinite loop
    digitalWrite(LED1_PIN, HIGH);
    Serial.println("BlinkTask: LED ON");
    vTaskDelay(1000 / portTICK_PERIOD_MS); // 1000ms
    digitalWrite(LED1_PIN, LOW);
    Serial.println("BlinkTask: LED OFF");
    Serial.print("BlinkTask running on core ");
    Serial.println(xPortGetCoreID());
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(115200);


  // Initialize pins
  pinMode(LED1_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Internal pull-up resistor

  // Attach interrupt to button
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), buttonISR, FALLING);

  // Create task
  xTaskCreatePinnedToCore(
    BlinkTask,         // Task function
    "BlinkTask",       // Task name
    10000,             // Stack size (bytes)
    NULL,              // Parameters
    1,                 // Priority
    &BlinkTaskHandle,  // Task handle
    1                  // Core 1
  );
}

void loop() {
  // Empty because FreeRTOS scheduler runs the task
}
```
## adaptation espIDF
https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/system/freertos_idf.html  

http://tvaira.free.fr/esp32/esp32-freertos.html

https://github.com/DiegoPaezA/ESP32-freeRTOS/blob/master/Task_FreeRTOS/main.c  

https://github.com/DiegoPaezA/ESP32-freeRTOS/blob/master/Task_FreeRTOS/main.c  

On va commencer par inclure les bibliothèques nécessaires:  

```cpp
#include <stdio.h>
#include "freertos/FreeRTOS.h"  //fonctions de freeRTOS
#include "freertos/task.h"    //fonctions de freeRTOS
#include "esp_system.h"
#include "driver/gpio.h"  //contrôle des gpio (les pins)

```  

Définir la notre pin. 
```cpp
#define BLINK_GPIO 2  // define est une macro, c'est a dire une sorte de programme qui s'exécute avant que le programme ne soit compilé et s'exécute à son tour. son role est de chercher toutes les occurence de "BLINK_GPIO" et de les remplacer par 2. On aurait aussi pu faire une variable. L'avantage de #define c'est qu'il n'y a pas de problème de portée.
```  

On va définir les fonctions des tâche. La création de la tâche viendra plus tard:

```cpp
void hello_task(void *pvParameter)  //les tâches sont des fonctions de type void et prennent un pointeur de type void qui va nous permettre de charger nimporte quel type d'argument quand on créera la tâche
//pv signifie pointer void. 
{
	while(1)  //sur arduino ide on utilisait for(;;), c'est dans cett boucle qu'on définit ce que va faire la fonction
	{
	    printf("Hello world!\n");
	    vTaskDelay(100 / portTICK_RATE_MS);  //diviser par portTICK_PERIOD_MS permet d'avoir des milisecondes.
	}
}
```


Voyons définition d'une autre tâche, ici une tâche qui utilise les GPIO:

```cpp
void blinky(void *pvParameter)
{
    gpio_config(BLINK_GPIO); //cette fonction prend comme paramètre un int correspondant au numéro de la pin. ici on a utilisé une macro. elle sert à s'assurer que la pin choisie est bien une sortie GPIO et n'est pas utilisée pour autre chose (ex communication I2C)
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT); // Une fois qu'on a défini la pin comme GPIO il faut encore définir son état. On est obligé d'utilisé ces 2 donctions en combinaison.
    while(1) {
        gpio_set_level(BLINK_GPIO, 0);  //prend comme argument le numéro du pin et l'état qu'on souhaite lui attribuer.
        vTaskDelay(1000 / portTICK_RATE_MS);
        gpio_set_level(BLINK_GPIO, 1);
        vTaskDelay(1000 / portTICK_RATE_MS);
    }
}
```

Pour créer nos tâches il faut les appeler dans la fonction principale avec les bons arguments.

```cpp
void app_main()
{
    xTaskCreate(&hello_task, "hello_task", 2048, NULL, 5, NULL); //la fonction xTaskCreate prend comme argument: l'adresse de la fonction de la tâche, on donne un nom à cette tâche, on définit la taille qu'on lui alloue dans la stack, le paramètre à passer à la tâche, si il n'y en a pas on met NULL, un pointeur vers TaskHandle_t si une tâche peut stopper une autre tâche.
    // Il n'y a pas vraiment de méthode pour définir la taille à allouer. on peut utiliser uxTaskGetStackHighWaterMark() pune fois l'application en marche pour voir la quantité d'espace libre puis tâtoner.
    xTaskCreate(&blinky, "blinky", 512,NULL,5,NULL );
}

```

C'était un exemple basique qui ne comprenait pas de **taskHandle**, de tâche prenant des **paramètre** (il y en a lors de la création de la tâche mais pas de paramètre externe utilisés par la tâche ), de **sémaphore** et de **mutex**

On va maintenant voir comment gérer une tâche qui utilise des paramètres. On peut passer un seul paramètre mais il y a une astuce permettant de passer plusieurs paramètres malgrès cette restriction. On va voir les 2 façons de faire:  


```cpp
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"

const int speed = 42; //si on utilise pas de const, une variable global qui est reprise dans des fonctions pourrait y être modifiée ce qui pose problème. 2 tâches pourraient utiliser la même variable mais elle pourrait avoir des valeurs différentes. comportement imprévisible. 

// Définition de la tâche
void hello_task(void *pvParameter)
{
    // 1. Casting du pointeur générique pvParameter en int* (donc en pointeur vers une variable de type int)
     const int* speed_ptr = static_cast<const int*>(pvParameter);


    while(1)
    {
        // 2. Déréférencement du pointeur pour afficher la valeur qu'il contient et non son adresse.
        printf("Vitesse : %d\n", *speed_ptr); //%d sert à insérer un élément de type non char (text)
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    
    // 3. 
    
    vTaskDelete(nullptr); //si le paramètre est nullptr, cette fonction supprime la task qui l'a appellé, donc cette tâche. On peut aussi utiliser un handle comme paramètre. Dans ce cas c'est la tâche à laquelle le handle se réfère qui sera supprimée
                          //ici quand on est hors de la boucle on met fin à la tâche avec vTaskDelete(nullptr).
}

// Fonction principale
// Fonction principale
extern "C" void app_main()  //externe "C" permet de faire en sorte que le paramètre passé à la task fonctionne, en fait FreeRTOS utilise C et pas C++, on est obligé d'ajouter ça avant la fonction app_main() pour ne pas rencontrer de problème
{
    // Création de la tâche en passant l'adresse de la variable globale constante.
    // L'opérateur & permet d'obtenir l'adresse de la variable.
    xTaskCreate(
        hello_task,
        "hello_task",
        2048,
        static_cast<void*>(const_cast<int*>(&speed)), // On ne peut pas simplement mettre void et le nom du paramètre. Le compilateur a un problème si il ne connait pas le type de l'argument car il a besoin de lui allouer le bon nombre de bit de mémoire, de ce fait il ne   sait pas combien d'octets lire ou écrire à l'adresse du pointeur.
                                                      // Ici, on fait une conversion de type compliquée pour une bonne raison :
// FreeRTOS a été écrit en C et ne comprend pas le concept de "const" (valeur constante).
// Il attend un pointeur générique `void*`. Notre variable `speed` est `const int`,
// donc son adresse est un pointeur `const int*`. Le compilateur C++ est plus strict
// et ne nous laisse pas passer un `const int*` directement à une fonction C qui s'attend
// à un `void*`, car il ne peut pas garantir que cette fonction ne va pas modifier la valeur constante.
//
// Pour contourner ça, on fait un "truc" en deux étapes :
//
// Étape 1: const_cast<int*>(&speed)
// On prend l'adresse de notre variable `speed` (`&speed`). Le compilateur voit que c'est un
// `const int*`. `const_cast` est l'outil spécial qui dit au compilateur : "ignore cette
// constance pour cette fois". On récupère donc un pointeur temporaire de type `int*`,
// qui pointe vers la même adresse que `speed`, mais le compilateur fait comme s'il n'était
// pas constant. C'est ça qui fait que l'étape d'après va fonctionner.
//
// Étape 2: static_cast<void*>(...)
// On prend le résultat de l'étape 1 (le pointeur `int*`) et on le convertit en `void*`
// comme le veut FreeRTOS. C'est l'opération de cast la plus simple. Apparement static_cast est la manière sécurisée de faire un cast. ça n'a rien à voir avec le mot clé static.
        5,
        nullptr
    );
}
```

Voici la méthode pour passer plusieurs arguments grâce à un struct.

```cpp
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"

// On utilise le nom que vous avez choisi pour la structure.
struct packOfParameter {
    const char* message; // Le message à afficher
    int delay_ms;        // Le délai d'attente en millisecondes
};

// Définition de la tâche
void hello_task_multiple_params(void *pvParameter)
{
    // pvParameter est le pointeur générique reçu par la tâche.
    // On le caste vers le type de notre structure pour pouvoir l'utiliser.
    packOfParameter* packOfParameterPointerForCasting = static_cast<packOfParameter*>(pvParameter); //ce pointeur est uniquement utilisé pour le casting (= passer du type void à struct)

    while(1)
    {
        // On utilise le pointeur casté pour accéder aux membres de la structure.
        printf("%s\n", packOfParameterPointerForCasting->message);
        vTaskDelay(packOfParameterPointerForCasting->delay_ms / portTICK_PERIOD_MS);
    }
    
    // Si la tâche s'arrêtait...
    // delete packOfParameterPointerForCasting;
    // vTaskDelete(nullptr);
}

// Fonction principale
extern "C" void app_main()
{
    // On crée une première instance de notre structure sur le tas avec new.
    // On crée un pointeur pour acceder à cette instance.
    packOfParameter* packOfParameterPointerForSelecting_1 = new packOfParameter; //ce pointeur est utilisé pour récupérer les éléments du struct
    packOfParameterPointerForSelecting_1->message = "Bonjour depuis la tâche 1 !";
    packOfParameterPointerForSelecting_1->delay_ms = 500;

    // On crée la tâche 1 et on lui passe le pointeur vers notre structure.
    xTaskCreate(
        hello_task_multiple_params,
        "hello_task_multi_1",
        4096,
        static_cast<void*>(packOfParameterPointerForSelecting_1),
        5,
        nullptr
    );

    // On crée une deuxième instance pour la deuxième tâche.
    packOfParameter* packOfParameterPointerForSelecting_2 = new packOfParameter;
    packOfParameterPointerForSelecting_2->message = "Deuxième tâche en cours...";
    packOfParameterPointerForSelecting_2->delay_ms = 1000;

    xTaskCreate(
        hello_task_multiple_params,
        "hello_task_multi_2",
        4096,
        static_cast<void*>(packOfParameterPointerForSelecting_2),
        4,
        nullptr
    );
}
```  

On peut aussi utiliser une classe plutôt qu'un struct. Cela permet d'encapsuler les données (attributs) et la logique (méthode) dans une seul entité

```cpp
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"

// 1. On définit une classe pour encapsuler la logique de la tâche.
class TaskExecutor {
public:
    TaskExecutor(const char* msg, int delay) :
        message(msg), delay_ms(delay) {}

    // 2. La méthode de la tâche qui contient la boucle principale.
    void run() {
        while (1) {
            printf("%s\n", message);
            vTaskDelay(delay_ms / portTICK_PERIOD_MS);
        }
    }

private:
    const char* message;
    int delay_ms;
};

// 3. La fonction de trampoline (passerelle). Elle doit être `static`
// pour ne pas avoir le pointeur `this` et être compatible avec l'API C de FreeRTOS.
// Elle reçoit le pointeur d'objet en tant que `pvParameter`.
void taskTrampoline(void* pvParameter) {
    TaskExecutor* executor = static_cast<TaskExecutor*>(pvParameter);
    executor->run();
    // Normalement, on ne devrait pas atteindre cette ligne avec une boucle infinie.
    // Si la tâche devait se terminer, on pourrait libérer l'objet ici.
    // delete executor;
    vTaskDelete(nullptr);
}

// Fonction principale
extern "C" void app_main()
{
    // On crée une instance de notre classe sur le tas.
    TaskExecutor* my_executor_1 = new TaskExecutor("Bonjour depuis la classe 1 !", 500);
    TaskExecutor* my_executor_2 = new TaskExecutor("Bonjour depuis la classe 2 !", 1000);

    // On crée la première tâche et on lui passe le pointeur vers l'objet.
    xTaskCreate(
        taskTrampoline,
        "task_1_cpp",
        4096,
        static_cast<void*>(my_executor_1),
        5,
        nullptr
    );

    // On crée la deuxième tâche et on lui passe le pointeur vers le deuxième objet.
    xTaskCreate(
        taskTrampoline,
        "task_2_cpp",
        4096,
        static_cast<void*>(my_executor_2),
        4,
        nullptr
    );
}


```





xTaskCreate()        // crée une tache, la mémoire est allouée automatiquement.
xTaskCreateStatic()  // crée une tache, la mémoire est allouée par le user.

Mais dans un système multicore il faut attacher les tâches à un coeur. on utilise donc plutôt:
xTaskCreatePinnedToCore()           // crée une tache affiliée à un coeur, la mémoire est allouée automatiquement.
xTaskCreateStaticPinnedToCore()     // crée une tache, affiliée à un coeur, la mémoire est allouée par le user.  

 Dans les paramètre on donne 0, 1 où tskNO_AFFINITY pour affilier la tâche à un coeur spécifique ou les deux.
## queue 
https://esp32tutorials.com/esp32-esp-idf-freertos-queue-tutorial/?utm_source=chatgpt.com


## Task Management  
Créer, suspendre, reprendre et effacer des tâches. Une tâche est une fonction indépendante, ayant sa propre zone mémoire allouée et possédant un état (en cours / pret / bloqué / suspendue).  
es

## Scheduling  
donner des priorités aux tâches pour qu'elles s'exécutent dans un ordre précis. Il peut intérompre une tâche de basse priorité pour passer la main à une tâche de haute priorité. la priorité est donnée sous forme de nombre entier.  

## communication inter tâches  

-----------------
MQTT = protocole efficace pr dialogue entre appareils.
Publisher = partage
SUbscriber = reçoit

un client peut faire les 2

structure organisé autour de topic (sujet)

broker = c'est le cerveau qui redirige les infos dans les topics.  

SDK =  Software Development Kit, sorte de boîte à outil de développeurs contenant des bibliothèques, des exemples et des utilitaires. ESP-IDF est le SDK d'Espressif pour programmer l'ESP32  

Framework = à la manière d'utiliser un CMS plutôt que de coder son site web. un framework est une sorte de structure pré-construite. Srduino est un framework, la partie timer est gérée automatiquement, nous on fournit juste setup() et loop().  

Firmware = Programme spécial qui est chargé directement dans un microcontrôleur, c'est le code que l'on flash vers notre ESP32, le programme compilé qui "vit" le microcontrôleur

API = Application Programming Interface (Interface de programation). Ce n’est pas une interface graphique (UI = User Interface), mais une interface logicielle : un ensemble de fonctions, de classes, de protocoles, qui définissent comment un programme ou une bibliothèque peut être utilisé par un autre programme.  

Kernel = noyeau, c'est le coeur du système d'exploitation de l'ordinateur. Il établit la communication entre la partie hardware et software de l'ordinateur. Le scheduler est une partie du Kernel.  

Core = processor (CPU: Control Prosessing Unit = cerveau de la machine)

Node-RED = programme qui permet d'implémenter la logique générale inter appareil, c'est comme une map des actions à faire en fonction des messages retournés par les différents appareils.  

SoC = System on Chip , signifie qu'il n'y a qu'un composant, la puce ESP32 par exemple, qui intègre plusieurs choses. CPU, mémoires, périphériques etc. comme un mini ordinateur sur une puce.   

SMP = Symmetric Multi-Processing, plusieurs coeurs et un système capable de gérer les tâches sur n'importe quelle coeur de manière équitable. N'importe quelle tâche peut être gérée par nimporte quel coeur.

Un petit raspberry pi peut être un serveur à - de 100.-
un Nass - network attak ? storage marque synologie.

--------------------------------

projet hello world: C:\Users\thoma\Documents\Github\Timer_code\Test_decouverte-_ESP_IDF\main
Cmake installed by espIDF extension: C:\Users\thoma\esp\v5.4.2\esp-idf\tools\cmake
