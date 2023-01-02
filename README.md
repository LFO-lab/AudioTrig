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
- "AUDIOTRIG" se trouve dans l’onglet "Plug-Ins" dans la catégorie "LFO LAB". (ableton-1)
- S’il n’y est pas, rescanner les plugins en ouvrant les préférences et en allant dans l’onglet "Plug-Ins". (ableton-2)
- Glisser "AUDIOTRIG" sur une piste audio. (ableton-3)
- Sur une piste MIDI, sélectionner la piste audio dans le menu "MIDI From". (ableton-4)
- La piste MIDI reçoit maintenant des notes MIDI en provenance de "AUDIOTRIG".
- Pour visualiser l’arrivée des messages MIDI, sélectionner "In" dans le menu "Monitor". (ableton-5)

## Utilisation avec REAPER (version REAPER v6.52/win64 sur Windows 11)
- Ajouter un plugiciel à une piste audio. (reaper-1)
- "AUDIOTRIG" se trouve dans l’onglet "VST3". (reaper-2)
- S’il n’y est pas, rescanner les plugins. (reaper-3)
- Cliquer sur le bouton "Route" de la track audio pour ajouter un envoi. (reaper-4)
- Créer un nouvel envoi vers la piste voulu. (reaper-5)
- Désactivé l’envoi audio. (reaper-6)
- Assurez-vous de que l’envoie MIDI est activé. (reaper-7)
- La piste MIDI peut maintenant recevoir des notes MIDI en provenance de "AUDIOTRIG".

## Logic Pro
Non supporté.

## Pro Tool
Non supporté.

