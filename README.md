# AUDIOTRIG

AUDIOTRIG est un plugiciel VST3 développé par Gabriel Lavoie Viau pour le [Laboratoire formes • ondes](https://lfo-lab.ca/). Sa fonction principale est d’envoyer une note MIDI lorsque le signal audio dépasse un seuil.

<img src="Images/Teaser.jpg">

### Limitations

AUDIOTRIG est un développement artisanal palliant un manque criant de VST voués à cette simple fonction de déclenchement MIDI basé sur le signal audio. Bien que testé sur plusieurs logiciels, il ne fonctionne malheureusement pas sur Logic Pro et Pro Tools. Si des utilisatrices/teurs le font fonctionner avec d’autres logiciels que ceux donnés en exemple dans ce document, merci de nous l’indiquer afin qu’il soit ajouté à notre liste de logiciels testés.

## Installation Windows
- Fermez votre logiciel.
- Allez dans le dossier "C:\Program Files\Common Files\VST3".
- S’il n’y a pas de dossier nommé "VST3" dans le dossier "Common Files", créez-le.
- Copiez "AUDIOTRIG.vst3" dans le dossier "VST3".
- Ouvrir votre logiciel.

## Installation Mac

- Fermez votre logiciel.
- Copiez "AUDIOTRIG.vst3" dans le dossier suivant:
"Macintosh HD/Library/Audio/Plugiciels/VST3"
- Note :
	- Si le dossier "VST3" n’existe pas dans le dossier "Plugiciel", créez-le.
	- Le répertoire "Library" peut être nommé "Bibliothèque" selon la langue de
votre système.
- Ouvrir votre logiciel.

### En cas de messages du système Mac OS

Si ce message s’affiche : "Impossible d’ouvrir 'AUDIOTRIG.vst3', car le développeur ne peut pas être vérifié." :

- N'acceptez pas l’option de placer le plugiciel dans la corbeille, cliquer plutôt sur annuler si l’option se présente.
- Allez dans les "Préférences Système", puis dans "Sécurité et confidentialité".
- Dans l’onglet "Général", à côté du message "L’utilisation de 'AUDIOTRIG.vst3' est bloqué, car l’application ne provient pas d’un développeur identifié.", cliquez sur "ouvrir quand même".
- Dans votre logiciel, *rescannez* les plugiciels.
- Si le message suivant s’affiche: "macOS ne peut pas vérifier le développeur de 'AUDIOTRIG.vst3'. Voulez-vous vraiment ouvrir cette app?", cliquez sur "ouvrir".
- Si, même en *rescannant* les plugiciels dans votre logiciel, le plugiciel ne s’affiche toujours pas:
	- Fermez votre logiciel.
	- Enlevez "AUDIOTRIG.vst3" du dossier "VST3".
	- Ouvrez votre logiciel, *rescannez* les plugiciels et refermez votre logiciel.
	- Remettez "AUDIOTRIG.vst3" dans le dossier "VST3".
	- Ouvrez votre logiciel, *rescannez* les plugiciels.

#### Si le plugiciel n’apparaît toujours pas dans votre logiciel :

- Ouvrir l’application "Terminal".
- Notez que le chemin proposé dans les commandes ci-bas est le chemin par défaut et peut différer selon l’endroit où vous avez installé le fichier "AUDIOTRIG.vst3".
- Dans le terminal tapez : 

`sudo xattr -rd com.apple.quarantine "/Library/Audio/Plugiciels/VST3/AUDIOTRIG.vst3"`

- Appuyer sur la touche de retour.
- Puis, taper : 

`spctl --add "/Library/Audio/Plugiciels/VST3/AUDIOTRIG.vst3"`

- Si, même en *rescannant* les plugiciels dans votre logiciel, le plugiciel ne s’affiche toujours pas:
	- Fermez votre logiciel.
	- Enlevez “AUDIOTRIG.vst3” du dossier “VST3”.
	- Ouvrez votre logiciel, *rescannez* les plugiciels et refermez votre logiciel.
	- Remettez “AUDIOTRIG.vst3” dans le dossier “VST3”.
	- Ouvrez votre logiciel, *rescannez* les plugiciels.

## Fonctionnement dans Ableton Live

#### Testé avec Ableton Live 11 sur Windows 11

- Dans les préférences, dans l’onglet "Plugiciels", assurez-vous que l’option "Utiliser dossier système VST3" est activée.
- "AUDIOTRIG" se trouve dans l’onglet "Plugiciels" dans la catégorie "LFO LAB". 

<img src="Images/ableton-1.png">

- S’il n’y est pas, *rescannez* les plugiciels en ouvrant les préférences et en allant dans l’onglet "Plugiciels".

<img src="Images/ableton-2.png">

- Glissez "AUDIOTRIG" sur une piste audio.

<img src="Images/ableton-3.png">

- Sur une piste MIDI, sélectionnez la piste audio dans le menu "MIDI From".

<img src="Images/ableton-4.png">

- La piste MIDI reçoit maintenant des notes MIDI en provenance de "AUDIOTRIG".
- Pour visualiser l’arrivée des messages MIDI, sélectionnez "In" dans le menu "Monitor".

<img src="Images/ableton-5.png">

## Fonctionnement dans Cubase

#### Testé avec Cubase Pro 12 sur Windows 11

- Ajoutez un plugiciel à une piste audio.
- "AUDIOTRIG" se trouve dans la section "VST Effect / Other". 

<img src="Images/Cubase-1.png">

- S’il n’y est pas, *rescannez* les plugiciels avec le VST Plugins Manager.

<img src="Images/Cubase-2.png">
<img src="Images/Cubase-3.png">

- Sélectionnez une piste MIDI ou Instrument et, dans l’onglet "Inspector", maximisez la première section du haut.

<img src="Images/Cubase-4.png">

- Dans la section "Input routing", sélectionnez "AUDIOTRIG – MIDI out".

<img src="Images/Cubase-5.png">

- Lorsque la piste MIDI ou Instrument est armé, elle reçoit maintenant des notes MIDI en provenance de "AUDIOTRIG".
- Il est possible de visualiser l’arrivée des messages MIDI avec le plugiciel "MIDI Monitor".

<img src="Images/Cubase-6.png">

## Fonctionnement dans REAPER

#### Testé avec REAPER v6.52/win64 sur Windows 11

- Ajoutez un plugiciel à une piste audio.

<img src="Images/reaper-1.png">

- "AUDIOTRIG" se trouve dans l’onglet "VST3".

<img src="Images/reaper-2.png">

- S’il n’y est pas, *rescannez* les plugiciels.

<img src="Images/reaper-3.png">

- Cliquez sur le bouton "Route" de la piste audio pour ajouter un envoi.

<img src="Images/reaper-4.png">

- Créez un nouvel envoi vers la piste voulue.

<img src="Images/reaper-5.png">

- Désactivez l’envoi audio.

<img src="Images/reaper-6.png">

- Assurez-vous de que l’envoie MIDI est activé.

<img src="Images/reaper-7.png">

- La piste MIDI peut maintenant recevoir des notes MIDI en provenance de "AUDIOTRIG".
