# # SPDX-FileCopyrightText: Copyright (C) Arduino s.r.l. and/or its affiliated companies
# #
# # SPDX-License-Identifier: MPL-2.0
# from arduino.app_utils import *
# from arduino.app_bricks.keyword_spotting import KeywordSpotting

# spotter = KeywordSpotting()

# def turn_on():
#     Bridge.call("light_on")

# def turn_off():
#     Bridge.call("light_off")

# spotter.on_detect("hey_arduino_turn_on_light", turn_on)
# spotter.on_detect("hey_arduino_turn_off_light", turn_off)

# App.run()







from arduino.app_utils import *
from arduino.app_bricks.keyword_spotting import KeywordSpotting

spotter = KeywordSpotting()

def turn_on():
    print("turn_on triggered")
    Bridge.call("light_on")
    print("turn_on: Bridge.call finished")

def turn_off():
    print("turn_off triggered")
    Bridge.call("light_off")
    print("turn_off: Bridge.call finished")

spotter.on_detect("hey_arduino_turn_on_light", turn_on)
spotter.on_detect("hey_arduino_turn_off_light", turn_off)

App.run()