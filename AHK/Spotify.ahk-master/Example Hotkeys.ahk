#Include %A_ScriptDir%
#Include Spotify.ahk
global VolumePercentage
global VolumeStep := 5
global ShuffleMode
global RepeatMode := 0
spoofy := new Spotify
VolumePercentage := spoofy.Player.GetCurrentPlaybackInfo().Device.Volume
return

F13::
if(VolumePercentage - VolumeStep > 0)
  VolumePercentage -= VolumeStep
spoofy.Player.SetVolume(VolumePercentage) ; Decrement the volume percentage and set the player to the new volume percentage
return

F14::
VolumePercentage += VolumeStep
spoofy.Player.SetVolume(VolumePercentage) ; Increment the volume percentage and set the player to the new volume percentage
return 

F15::
ShuffleMode := !ShuffleMode
spoofy.Player.SetShuffle(ShuffleMode) ; Swap the shuffle mode of the player
return 

F16::
RepeatMode := RepeatMode + (RepeatMode = 0 ? 1 : (RepeatMode = 1 ? 1 : (RepeatMode = 2 ? 1 : -2)))
spoofy.Player.SetRepeatMode(RepeatMode) ; Cycle through the three repeat modes (1-2, 2-3, 3-1)
return 

F17::
spoofy.Player.SaveCurrentlyPlaying() ;
return

F18::
spoofy.Player.UnSaveCurrentlyPlaying() ;
return

F19::
TopArtists := Spotify.CurrentUser.GetTop("artists") ; Returns an array of top artists
TopArtistsAlbums := TopArtists[1].Albums ; Returns an array of number 1 top artist's ablums
Random, Rand, 1, % TopArtistsAlbums.Length() ; Gets a random number 1 - Artist's number of ablums
TopArtistsAlbums[Rand].Play() ; Plays the random album
return