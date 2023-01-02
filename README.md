# AUDIOTRIG

A VST that sends a MIDI note when the audio input volume pass beyond the threshold.

<img src="Images/Teaser.jpg">

## Installation Windows
- Aller dans le dossier "C:\Program Files\Common Files\VST3".
- S’il n’y a pas de dossier nommé "VST3" dans le dossier "Common Files", créer le.
- Copier "AUDIOTRIG.vst3" dans le dossier "VST3".

## Installation Mac

- Aller dans le dossier "Macintosh HD/Bibliothèque/Audio/Plug-Ins/VST3".
- S’il n’y a pas de dossier nommé "VST3" dans le dossier "Plug-Ins", créer le.
- Copier "AUDIOTRIG.vst3" dans le dossier "VST3".

Si ce message s’affiche : "Impossible d’ouvrir 'AUDIOTRIG.vst3', car le développeur ne peut pas être vérifié." :

- N'acceptez pas l’option de placer le plug-in dans la corbeille, cliquer plutôt sur annuler si l’option se présente.
- Allez dans les "Préférences Systèmes", puis dans "Sécurité et confidentialité".
- Dans l’onglet "Général", à côté du message "L’utilisation de 'AUDIOTRIG.vst3' est bloqué, car l’application ne provient pas d’un développeur identifié.", cliquer sur "ouvrir quand même".
- Dans votre DAW, rescanner les plug-ins.
- Si le message suivant s’affiche: "macOS ne peut pas vérifier le développeur de 'AUDIOTRIG.vst3'. Voulez-vous vraiment ouvrir cette app?", cliquer sur "ouvrir".
- Si, même en rescannant les plug-ins dans votre DAW, le plug-in ne s’affiche toujours pas:
	- Fermer votre DAW.
	- Enlever "AUDIOTRIG.vst3" du dossier "VST3".
	- Rouvrer votre DAW, rescanner les plug-ins et refermer votre DAW.
	- Remetter "AUDIOTRIG.vst3" dans le dossier "VST3".
	- Rouvrer votre DAW, rescanner les plugin.

### Si le plug-in n’apparaît toujours pas dans votre DAW :

- Ouvrir l’application "Terminal".
- Taper : `sudo xattr -rd com.apple.quarantine "/chemin/vers/AUDIOTRIG.vst3"`
- Puis, taper: `spctl --add "/chemin/vers/AUDIOTRIG.vst3"`
- Si vous avez copié le plugin dans le dossier VST3 du système, le chemin est probablement : "/Library/Audio/Plug-Ins/VST3/AUDIOTRIG.vst3". Les message à inscrire dans le terminal sont donc: 
	- `sudo xattr -rd com.apple.quarantine "/Library/Audio/Plug-Ins/VST3/AUDIOTRIG.vst3"`
	- `spctl --add "/Library/Audio/Plug-Ins/VST3/AUDIOTRIG.vst3"`
	- Si, même en rescannant les plug-ins dans votre DAW, le plug-in ne s’affiche toujours pas:
		- Fermer votre DAW
		- Enlever “AUDIOTRIG.vst3” du dossier “VST3”
		- Rouvrer votre DAW, rescanner les plugin et refermer votre DAW.
		- Remetter “AUDIOTRIG.vst3” dans le dossier “VST3”
		- Rouvrer votre DAW, rescanner les plugin

## Utilisation avec Cubase (version Cubase Pro 12 sur Windows 11):
- Ajouter un plugiciel à une piste audio.
- "AUDIOTRIG" se trouve dans la section "VST Effect / Other". 

<img src="Images/Cubase-1.png">

- S’il n’y est pas, rescanner les plugins avec le VST Plugins Manager.

<img src="Images/Cubase-2.png">
<img src="Images/Cubase-3.png">

- Sélectionner une track MIDI ou Instrument et, dans l’onglet "Inspector", maximiser la première section du haut.

<img src="Images/Cubase-4.png">

- Dans la section "Input routing", sélectionner "AUDIOTRIG – MIDI out".

<img src="Images/Cubase-5.png">

- Lorsque la piste MIDI ou Instrument est armé, elle reçoit maintenant des notes MIDI en provenance de "AUDIOTRIG".
- Il est possible de visualiser l’arrivée des message MIDI avec le plugin "MIDI Monitor".

<img src="Images/Cubase-6.png">

## Utilisation avec Ableton Live (version Ableton Live 11 sur Windows 11)
- Dans les préférences, dans l’onglet "Plug-Ins", assurez-vous que l’option "Utiliser dossier système VST3" est activé.
- "AUDIOTRIG" se trouve dans l’onglet "Plug-Ins" dans la catégorie "LFO LAB". 

<img src="Images/ableton-1.png">

- S’il n’y est pas, rescanner les plugins en ouvrant les préférences et en allant dans l’onglet "Plug-Ins".

<img src="Images/ableton-2.png">

- Glisser "AUDIOTRIG" sur une piste audio.

<img src="Images/ableton-3.png">

- Sur une piste MIDI, sélectionner la piste audio dans le menu "MIDI From".

<img src="Images/ableton-4.png">

- La piste MIDI reçoit maintenant des notes MIDI en provenance de "AUDIOTRIG".
- Pour visualiser l’arrivée des messages MIDI, sélectionner "In" dans le menu "Monitor".

<img src="Images/ableton-5.png">

## Utilisation avec REAPER (version REAPER v6.52/win64 sur Windows 11)
- Ajouter un plugiciel à une piste audio.

<img src="Images/reaper-1.png">

- "AUDIOTRIG" se trouve dans l’onglet "VST3".

<img src="Images/reaper-2.png">

- S’il n’y est pas, rescanner les plugins.

<img src="Images/reaper-3.png">

- Cliquer sur le bouton "Route" de la track audio pour ajouter un envoi.

<img src="Images/reaper-4.png">

- Créer un nouvel envoi vers la piste voulu.

<img src="Images/reaper-5.png">

- Désactivé l’envoi audio.

<img src="Images/reaper-6.png">

- Assurez-vous de que l’envoie MIDI est activé.

<img src="Images/reaper-7.png">

- La piste MIDI peut maintenant recevoir des notes MIDI en provenance de "AUDIOTRIG".

## Logic Pro
Non supporté.

## Pro Tool
Non supporté.

