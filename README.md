Projet RT
=========

Hiérarchie du projet :
------------------------

* __include__ - Tout les .h vont là
	* __data__ - Définition des structures de données
	* *rt_prototype.h* - contient les `typedef` pour les structures et les `#define` pour le projet, ce fichier doit être inclu dans tout les autres .h, après tout include système et avant tout include du projet
* __lib__ - Contient les bibliothèques externes
	* __libft__ - la ft
	* __mathex__ - extension de la lib math du système
	* __mglw__ - lib de gestion des fenêtres et de chargement d'images
* __src__ - les sources du projet
	* __gui__ - gestion de l'interface utilisateur
	* __object__ - gestion des différents types d'objets et de leurs données
	* __parser__ - les sources des différents parser dont on aura besoin, faire
	un dossier par type de fichier à parser
	* __raytracing__ - les fonctions génériques de raytracing
	* __render__ - la gestion du rendu
	* __thread__ - tout ce qui concerne la gestion du multi-threading
	* __tree__ - tout ce qui concerne la gestion de l'arborescence des objets
	dans les scènes (node tree, render tree et data tree)
	* __viewer__ - tout ce qui touche à l'affichage du RT et sa
	prévisualisation dans une fenêtre

Screen :
---------------------

![Image of Wolf3D 1](http://ak-map.me/pro/work/rt.jpg)

![Image of Wolf3D 1](http://ak-map.me/pro/work/rt2.jpg)

![Image of Wolf3D 1](http://ak-map.me/pro/work/rt3.jpg)


Here, have a flying unicorn !

                                . . . .
                                ,\`,`,`,`,
          . . . .               `\`\`\`\;
          `\`\`\`\`,            ~|;!;!;\!
           ~\;\;\;\|\          (--,!!!~`!       .
          (--,\\\===~\         (--,|||~`!     ./
           (--,\\\===~\         `,-,~,=,:. _,//
            (--,\\\==~`\        ~-=~-.---|\;/J,
             (--,\\\((```==.    ~'`~/       a |
               (-,.\\('('(`\\.  ~'=~|     \_.  \
                  (,--(,(,(,'\\. ~'=|       \\_;>
                    (,-( ,(,(,;\\ ~=/        \
                    (,-/ (.(.(,;\\,/          )
                     (,--/,;,;,;,\\         ./------.
                       (==,-;-'`;'         /_,----`. \
               ,.--_,__.-'                    `--.  ` \
              (='~-_,--/        ,       ,!,___--. \  \_)
             (-/~(     |         \   ,_-         | ) /_|
             (~/((\    )\._,      |-'         _,/ /
              \\))))  /   ./~.    |           \_\;
           ,__/////  /   /    )  /
            '===~'   |  |    (, <.
                     / /       \. \
                   _/ /          \_\
                  /_!/            >_\
