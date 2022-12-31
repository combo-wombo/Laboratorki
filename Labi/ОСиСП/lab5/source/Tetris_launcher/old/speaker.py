from pydub import AudioSegment as pydub_audio
from pydub.playback import _play_with_simpleaudio as pydub_play
import os
import random

class Speaker():
    volume = 0
    current_dir = os.path.dirname (os.path.realpath(__file__))
    null                        = "null.wav"
    lvl1                        = "lvl1.wav"
    lvl2                        = "lvl2.wav"
    lvl3                        = "lvl3.wav"
    lvl4                        = "lvl4.wav"
    death1                      = "death_1.wav"
    death2                      = "death_2.wav"
    tick                        = "generic_scroll_01.wav"
    destroyed_row               = "row_deleted.wav"
    block_fallen                = "block_fallen.wav"
    rotate_fail                 = "rotate_fail.wav"
    mainmenu                    = "mainmenu.wav"
    mainmenu_1                  = "mainmenu_1.wav"
    one_up                      = "1_up.wav"
    cs_cancell                  = "cs_cancell.wav"
    cs_cursor                   = "cs_cursor.wav"
    cs_decision                 = "cs_decision.wav"
    cs_error                    = "cs_error.wav"
    cs_scroll                   = "cs_scroll.wav"
    deathcam_gg_01              = "deathcam_gg_01.wav"
    deathcam_gg_02              = "deathcam_gg_02.wav"
    deathcam_gg_03              = "deathcam_gg_03.wav"
    startround1                 = "startround_01.wav"
    startround2                 = "startround_02.wav"
    startround3                 = "startround_03.wav"
    dominating                  = "dominating.wav"
    enterperformancemode        = "enterperformancemode.wav"
    exitperformancemode         = "exitperformancemode.wav"
    generic_press_01            = "generic_press_01.wav"
    generic_scroll_01           = "generic_scroll_01.wav"
    menu_accept                 = "menu_accept.wav"
    menu_back                   = "menu_back.wav"
    menu_countdown              = "menu_countdown.wav"
    menu_focus                  = "menu_focus.wav"
    menu_invalid                = "menu_invalid.wav"
    pause                       = "pause.wav"
    showdetails                 = "showdetails.wav"
    stalagmite                  = "stalagmite.wav"
    taunt_bumper_car_quit       = "taunt_bumper_car_quit.wav"
    ui_menu_flip_single_01      = "ui_menu_flip_single_01.wav"
    ui_menu_flip_single_02      = "ui_menu_flip_single_02.wav"

    def scroll():
        sound = random.randint(1,2)
        if sound == 1:
            Speaker.playsound(Speaker.obj(Speaker.ui_menu_flip_single_01))
        if sound == 2:
            Speaker.playsound(Speaker.obj(Speaker.ui_menu_flip_single_02))

    def obj(name):
        return pydub_audio.from_wav(os.path.join(Speaker.current_dir, "sounds\\"+name))

    def playsound(wave_obj, volume = 0):
        wave_obj += volume
        pydub_play(wave_obj)

    def playsound_R(wave_obj, volume = 0):
        wave_obj += volume
        return pydub_play(wave_obj)

    def play_loaded():
        sound = random.randint(1,3)
        if sound == 1:
            return Speaker.playsound_R(Speaker.obj(Speaker.startround1), -10)
        if sound == 2:
            return Speaker.playsound_R(Speaker.obj(Speaker.startround2), -10)
        if sound == 3:
            return Speaker.playsound_R(Speaker.obj(Speaker.startround3), -10)
        
    def play_menu():
        sound = random.randint(1,2)
        if sound == 1:
            return Speaker.playsound_R(Speaker.obj(Speaker.mainmenu), -10)
        if sound == 2:
            return Speaker.playsound_R(Speaker.obj(Speaker.mainmenu_1), -10)
        
    def play_death():
        sound = random.randint(1,2)
        if sound == 1:
            Speaker.playsound(Speaker.obj(Speaker.death1), -10)
        if sound == 2:
            Speaker.playsound(Speaker.obj(Speaker.death2), -10)
